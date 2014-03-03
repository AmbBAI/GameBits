#include "ge_font_ft.h"

namespace ge
{

GEFreeType::GEFreeType()
: freetype_(NULL)
{
}

GEFreeType::~GEFreeType()
{
	destory();
}

GEFreeType* GEFreeType::get_instance()
{
	static GEFreeType _global_ge_freetype;
	return &_global_ge_freetype;
}

bool GEFreeType::init()
{
	int ret = FT_Init_FreeType(&freetype_);
	if (ret != 0) return false;
	if (freetype_ == NULL) return false;

	return true;
}

void GEFreeType::destory()
{
	if (freetype_)
	{
		FT_Done_FreeType(freetype_);
		freetype_ = NULL;
	}
}

bool GEFreeType::init_font( GEFontFT* font_ft, const char* font_name )
{
	FT_Face ft_face = NULL;
	FT_New_Face(freetype_, font_name, 0, &ft_face);
	return font_ft->_set_ft_face(ft_face);
}



DLL_MANAGE_CLASS_IMPLEMENT(GEFontFT);

GEFontFT::GEFontFT()
: ft_face_(NULL)
, face_size_(0)
//, glyph_buff_(NULL)
, buff_size_(0)
, buff_offset_(0)
, page_width_(512)
, page_height_(512)
, texture_group_(NULL)
{
	type_ = FontType_FTFont;
}

GEFontFT::~GEFontFT()
{
	destory();
}

bool GEFontFT::init( const char* face, int size )
{
	GEFreeType* freetype = GEFreeType::get_instance();
	if (!freetype->init_font(this, face)) return false;
	return set_size(size);
}

void GEFontFT::destory()
{
	if (ft_face_ == NULL) return;
	FT_Done_Face(ft_face_);
	ft_face_ = NULL;
}

bool GEFontFT::set_size( int size )
{
	FT_Error ft_err = FT_Set_Pixel_Sizes(ft_face_, 0, size);
	return ft_err == 0;
}

bool GEFontFT::_set_ft_face( FT_Face ft_face )
{
	if (ft_face == NULL) return false;
	destory();
	ft_face_ = ft_face;
	return true;
}

bool GEFontFT::write_text( const wchar_t* text, int width, int height, bool wrap )
{
	if (text == NULL) return false;

	FT_GlyphSlot slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_UInt pre_glyph_index = 0;
	FT_Bool use_kerning = false; 
	int pen_x = 0;
	int pen_y = 0;
	int ascender = ft_face_->ascender >> 6;

	for (int i=0; '\0' != text[i]; ++i)
	{
		switch (text[i])
		{
		case '\n':
		case '\r':
			{
				pen_x = 0;
				pen_y += ft_face_->height >> 6;
			}
			break;
		default:
			{
				FT_BUFFCHAR_MAP::iterator itor_char = buff_char_map_.find(text[i]);
				GE_FTBuffChar* ptr_char = NULL;
				if (itor_char == buff_char_map_.end())
					ptr_char = _buff_char_glyph(text[i]);
				else ptr_char = itor_char->second;

				if (ptr_char == NULL) continue;

				glyph_index = ptr_char->index;

				//glyph_buff_[buff_offset_].pos.x = pen_x + ptr_char->_bearing_x;
				//glyph_buff_[buff_offset_].pos.y = pen_y + ptr_char->_bearing_y + ascender;

				pen_x += ptr_char->_advance >> 6;
				pre_glyph_index = glyph_index;

				++ buff_offset_;
				if (buff_offset_ >= buff_size_) return true;
			}
			break;
		}

	}
	return true;
}

bool GEFontFT::begin_write( GE_FTRenderChar* char_buff, int buff_size )
{
	if (render_char_buff_ != NULL) return false;
	render_char_buff_ = char_buff;
	buff_size_ = buff_size;
	buff_offset_ = 0;
	return true;
}

int GEFontFT::end_write()
{
	render_char_buff_ = NULL;
	buff_size_ = 0;
	int n_ret = buff_offset_;
	buff_offset_ = 0;
	return n_ret;
}

GE_FTBuffChar* GEFontFT::_buff_char_glyph( wchar_t ch )
{
	FT_GlyphSlot slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_Glyph out_glyph = NULL;

	glyph_index = FT_Get_Char_Index(ft_face_, ch);

	FT_Error ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_RENDER);
	if (ret != 0) goto fail_end;

	ret = FT_Get_Glyph(ft_face_->glyph, &out_glyph);
	if ( ret != 0 ) goto fail_end;

	ret = FT_Glyph_To_Bitmap(&out_glyph, FT_RENDER_MODE_NORMAL, NULL, true);
	if ( ret != 0) goto fail_end;

	GE_FTBuffChar* out_char = _write_bitmap_glyph(glyph_index, (FT_BitmapGlyph)out_glyph);
	if (out_glyph) FT_Done_Glyph(out_glyph);
	return out_char;

fail_end:
	if (out_glyph) FT_Done_Glyph(out_glyph);
	return NULL;
}

GE_FTBuffChar* GEFontFT::_write_bitmap_glyph( FT_UInt glyph_index, FT_BitmapGlyph bmp_glyph )
{
	if (bmp_glyph == NULL) return NULL;

	bool b_ret = true;
	int width = bmp_glyph->bitmap.width;
	int height = bmp_glyph->bitmap.rows;


	b_ret = _init_write_pen(width, height);
	if (!b_ret) return NULL;

	GE_IRECT rect(0, 0, bmp_glyph->bitmap.width, bmp_glyph->bitmap.rows);
	rect.move_to(pen_x_, pen_y_);
	unsigned char* buff = NULL;
	int pitch = 0;

	b_ret = current_page_->lock_rect(rect, (void*&)buff, pitch);
	if ((!b_ret) || buff == NULL) return NULL;

	for (int i=0; i<rect.height(); ++i)
	{
		int width = rect.width();
		for (int j=0; j<width; ++j)
		{
			unsigned char val = '\0';
			val = ((unsigned char*)bmp_glyph->bitmap.buffer)[i * width + j];
			if (val)
			{
				int pos = i * pitch / 2 + j;
				buff[pos] = 0xff;
				buff[pos] = val;
			}
		}
	}
	b_ret = current_page_->unlock_rect();
	if (!b_ret) return NULL;

	b_ret = _update_write_pen(width, height);
	if (!b_ret) return NULL;

	return NULL;
}

int GEFontFT::_create_buff_page()
{
	int page_id = texture_group_->add_texture();
	GETexture* page = texture_group_->get_texture(page_id);	
	if (page == NULL) return -1;
	bool b_ret = page->init(page_width_, page_height_, D3DFMT_A8L8);
	if (!b_ret) return -1;
	return page_id;
}

bool GEFontFT::_init_write_pen( int width, int height )
{
	int old_pen_x = pen_x_;
	int old_pen_y = pen_y_;

	if (texture_group_ == NULL) return false;

	if (0 != texture_group_->get_texture_cnt()
		&& current_page_ == NULL)
	{
		int page_id = _create_buff_page();
		current_page_ = texture_group_->get_texture(page_id);
		pen_x_ = 0;
		pen_y_ = 0;
	}

	if (pen_x_ + width > page_width_)
	{
		pen_y_ += ft_face_->height >> 6;
		pen_x_ = 0;
	}

	if (pen_y_ + height > page_height_)
	{
		int page_id = _create_buff_page();
		current_page_ = texture_group_->get_texture(page_id);
		if (current_page_ == NULL)
		{
			pen_x_ = old_pen_x;
			pen_y_ = old_pen_y;
			return false;
		}
		pen_x_ = 0;
		pen_y_ = 0;
	}

	if (current_page_ == NULL
		|| pen_x_ + width > page_width_
		|| pen_y_ + height > page_height_)
	{
		pen_x_ = old_pen_x;
		pen_y_ = old_pen_y;
		return false;
	}

	return true;
}

bool GEFontFT::_update_write_pen( int width, int height )
{
	pen_x_ += width;
	
	return true;
}

GETextureGroup* GEFontFT::get_texture_group()
{
	return texture_group_;
}

bool GEFontFT::init_texture_group()
{
	if (texture_group_ == NULL)
		texture_group_ = GETextureGroup::create();

	if (texture_group_ == NULL) return false;
	return true;
}

}

