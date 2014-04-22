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

	memset(&params_, 0, sizeof(params_));
	params_.flags = FT_RASTER_FLAG_AA | FT_RASTER_FLAG_DIRECT;
	params_.gray_spans = raster_callback;

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

bool GEFreeType::span_render( GEFontFT* font_obj, FT_GlyphSlot glyph_slot )
{
	if (font_obj == NULL) return false;
	if (glyph_slot == NULL) return false;
	if (glyph_slot->format != FT_GLYPH_FORMAT_OUTLINE) return false;

	FT_Error ret = 0;

	params_.user = font_obj->_get_span_list();
	ret = FT_Outline_Render(freetype_, &(glyph_slot->outline), &params_);
	if (ret != 0) goto fail_end;

	return true;

fail_end:
	return false;
}

bool GEFreeType::span_render_outline( GEFontFT* font_obj, FT_GlyphSlot glyph_slot )
{
	if (font_obj == NULL) return false;
	if (font_obj->get_outline_weight() <= 0.f) return false;
	if (glyph_slot == NULL) return false;
	if (glyph_slot->format != FT_GLYPH_FORMAT_OUTLINE) return false;

	FT_Stroker stroker = NULL;
	FT_Glyph out_glyph = NULL;
	FT_Error ret = 0;

	FT_Stroker_New(freetype_, &stroker);
	if (stroker)
	{
		FT_Stroker_Set(stroker,
			(int)(font_obj->get_outline_weight() * 64),
			FT_STROKER_LINECAP_ROUND,
			FT_STROKER_LINEJOIN_ROUND,
			0);
	} else return false; 

	ret = FT_Get_Glyph(glyph_slot, &out_glyph);
	if ( ret != 0 ) goto fail_end;

	ret = FT_Glyph_StrokeBorder(&out_glyph, stroker, 0, 1);
	if (stroker) FT_Stroker_Done(stroker);
	stroker = NULL;

	FT_OutlineGlyph outline_glyph = (FT_OutlineGlyph)out_glyph;

	params_.user = font_obj->_get_outline_span_list();

	ret = FT_Outline_Render(freetype_, &(outline_glyph->outline), &params_);
	if (ret != 0) goto fail_end;

	if (out_glyph) FT_Done_Glyph(out_glyph);
	out_glyph = NULL;
	return true;

fail_end:
	if (out_glyph) FT_Done_Glyph(out_glyph);
	if (stroker) FT_Stroker_Done(stroker);
	out_glyph = NULL;
	stroker = NULL;
	return false;
}

void GEFreeType::raster_callback( const int y, const int count, const FT_Span * const spans, void * const user )
{
	GEFontFT::FT_SPAN_LIST* span_list = (GEFontFT::FT_SPAN_LIST*)user;
	if (span_list)
	{
		for (int i=0; i<count; ++i)
		{
			GE_FTSpan span;
			span.x = spans[i].x;
			span.y = y;
			span.len = spans[i].len;
			span.coverage = spans[i].coverage;
			span_list->push_back(span);
		}
	}
}



DLL_MANAGE_CLASS_IMPLEMENT(GEFontFT);

GEFontFT::GEFontFT()
: ft_face_(NULL)
, face_size_(0)
, render_char_buff_(NULL)
, buff_size_(0)
, buff_offset_(0)
, page_width_(1024)
, page_height_(1024)
, texture_group_(NULL)
, current_page_(NULL)
, pen_x_(0)
, pen_y_(0)
, outline_weight_(0.f)
, valid_stamp_(0)
, is_buff_dirty_(false)
{
	type_ = FontType_FTFont;
}

GEFontFT::~GEFontFT()
{
	destory();
}

bool GEFontFT::init( const char* face, int size )
{
	destory();

	GEFreeType* freetype = GEFreeType::get_instance();
	if (!freetype->init_font(this, face)) return false;
	return set_size(size);
}

void GEFontFT::destory()
{
	if (ft_face_ == NULL) return;
	FT_Done_Face(ft_face_);
	ft_face_ = NULL;

	clear_font_buff();
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

	if (ft_face_ == NULL) return false;
	if (render_char_buff_ == NULL) return false;
	
	FT_GlyphSlot slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_UInt pre_glyph_index = 0;
	FT_Bool use_kerning = false;

	int ascender = ft_face_->ascender >> 6;
	int face_height = ft_face_->size->metrics.height >> 6;

	int pen_x = 0;
	int pen_y = face_height;

	for (int i=0; '\0' != text[i]; ++i)
	{
		switch (text[i])
		{
		case '\n':
		case '\r':
			{
				pen_x = 0;
				pen_y += face_height;
			}
			break;
		default:
			{
				GE_FTBuffChar* ptr_char = NULL;
				ptr_char = _get_buff_char_with_outline(text[i]);

				if (ptr_char == NULL) continue;

				glyph_index = ptr_char->index;
				pre_glyph_index = glyph_index;
				pen_x += ptr_char->_advance;
				
				if (ptr_char->page == -1) continue;

				render_char_buff_[buff_offset_].index = glyph_index;
				render_char_buff_[buff_offset_].xys[0] = (float)pen_x + ptr_char->_bearing_x;
				render_char_buff_[buff_offset_].xys[1] = (float)pen_y - ptr_char->_bearing_y - ascender;
				render_char_buff_[buff_offset_].xys[2] = render_char_buff_[buff_offset_].xys[0] + ptr_char->width;
				render_char_buff_[buff_offset_].xys[3] = render_char_buff_[buff_offset_].xys[1] + ptr_char->height;
				render_char_buff_[buff_offset_].page = ptr_char->page;
				render_char_buff_[buff_offset_].uvs[0] = ptr_char->uvs[0];
				render_char_buff_[buff_offset_].uvs[1] = ptr_char->uvs[1];
				render_char_buff_[buff_offset_].uvs[2] = ptr_char->uvs[2];
				render_char_buff_[buff_offset_].uvs[3] = ptr_char->uvs[3];
				++ buff_offset_;
				if (buff_offset_ >= buff_size_) return true;
			}
			break;
		}

	}
	return true;
}

int GEFontFT::begin_write( GE_FTRenderChar* char_buff, int buff_size )
{
	if (is_buff_dirty_) clear_font_buff();
	if (is_buff_dirty_) return -1;

	if (render_char_buff_ != NULL) return -1;
	render_char_buff_ = char_buff;
	buff_size_ = buff_size;
	buff_offset_ = 0;
	return valid_stamp_;
}

int GEFontFT::end_write()
{
	render_char_buff_ = NULL;
	buff_size_ = 0;
	int n_ret = buff_offset_;
	buff_offset_ = 0;
	return n_ret;
}


GE_FTBuffChar* GEFontFT::_get_buff_char( wchar_t ch )
{
	FT_GlyphSlot glyph_slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_Glyph out_glyph = NULL;

	glyph_index = FT_Get_Char_Index(ft_face_, ch);

	FT_BUFFCHAR_MAP::iterator char_itor = buff_char_map_.find(glyph_index);
	if (char_itor != buff_char_map_.end()) return char_itor->second;

	FT_Error ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_DEFAULT);
	if (ret != 0) goto fail_end;

	ret = FT_Get_Glyph(glyph_slot, &out_glyph);
	if ( ret != 0 ) goto fail_end;

	ret = FT_Glyph_To_Bitmap(&out_glyph, FT_RENDER_MODE_NORMAL, NULL, true);
	if ( ret != 0) goto fail_end;

	GE_FTBuffChar* out_char = _render_bitmap_glyph(glyph_index, (FT_BitmapGlyph)out_glyph);
	if (out_char)
	{
		out_char->_advance = glyph_slot->metrics.horiAdvance >> 6;
		out_char->_bearing_x = glyph_slot->metrics.horiBearingX >> 6;
		out_char->_bearing_y = glyph_slot->metrics.horiBearingY >> 6;
	}
	if (out_glyph) FT_Done_Glyph(out_glyph);

	return out_char;

fail_end:
	if (out_glyph) FT_Done_Glyph(out_glyph);
	return NULL;
}

GE_FTBuffChar* GEFontFT::_render_bitmap_glyph( FT_UInt glyph_index, FT_BitmapGlyph bmp_glyph )
{
	if (bmp_glyph == NULL) return NULL;

	bool b_ret = true;
	int width = bmp_glyph->bitmap.width;
	int height = bmp_glyph->bitmap.rows;

	b_ret = _init_write_pen(width, height);
	if (!b_ret) return NULL;

	GE_IRECT rect(0, 0, width, height);
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
			int pos = i * pitch / 2 + j;
			if (val)
			{
				buff[pos << 1] = 0xff;
				buff[pos << 1 | 1] = val;
			}
			else
			{
				buff[pos << 1] = 0xff;
				buff[pos << 1 | 1] = 0x00;
			}
		}
	}
	b_ret = current_page_->unlock_rect();
	if (!b_ret) return NULL;

	GE_FTBuffChar* buff_char = _build_buff_char(glyph_index, width, height);

	b_ret = _update_write_pen(width, height);
	if (!b_ret) return buff_char;

	return buff_char;
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

	pen_x_ += 1;

	if (texture_group_ == NULL)
	{
		init_texture_group();
		if (texture_group_ == NULL) return false;
	}

	if (0 == texture_group_->get_texture_cnt()
		&& current_page_ == NULL)
	{
		int page_id = _create_buff_page();
		current_page_ = texture_group_->get_texture(page_id);
		current_page_id_ = page_id;
		pen_x_ = 1;
		pen_y_ = 1;
	}

	if (pen_x_ + width > page_width_)
	{
		pen_y_ += (ft_face_->size->metrics.height >> 6) + 1;
		pen_x_ = 1;
	}

	if (pen_y_ + height > page_height_)
	{
		int page_id = _create_buff_page();
		current_page_ = texture_group_->get_texture(page_id);
		current_page_id_ = page_id;
		if (current_page_ == NULL)
		{
			current_page_id_ = -1;
			pen_x_ = old_pen_x;
			pen_y_ = old_pen_y;
			return false;
		}
		pen_x_ = 1;
		pen_y_ = 1;
	}

	if (current_page_ == NULL
		|| pen_x_ + width > page_width_
		|| pen_y_ + height > page_height_)
	{
		current_page_id_ = -1;
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

GE_FTBuffChar* GEFontFT::_build_buff_char( FT_UInt glyph_index, int width, int height )
{
	FT_BUFFCHAR_MAP::iterator char_itor = buff_char_map_.find(glyph_index);
	if (char_itor != buff_char_map_.end()) return char_itor->second;

	if (!texture_group_) return false;

	GE_FTBuffChar* buff_char = new GE_FTBuffChar();
	if (buff_char == NULL) return NULL;

	buff_char_map_[glyph_index] = buff_char;
	buff_char->index = glyph_index;

	if (width == 0 || height == 0)
	{
		buff_char->page = -1;
		return buff_char;
	}

	buff_char->page = current_page_id_;
	buff_char->width = width + 1;
	buff_char->height = height + 1;

	GETexture* page = texture_group_->get_texture(current_page_id_);
	if (page)
	{
		int img_width = 0;
		int img_height = 0;
		page->get_size(img_width, img_height);
		if (img_width > 0 && img_height > 0)
		{
			buff_char->uvs[0] = (float)(pen_x_ - 0.5f) / img_width;
			buff_char->uvs[1] = (float)(pen_y_ - 0.5f) / img_height;
			buff_char->uvs[2] = (float)(pen_x_ + 0.5f + width) / img_width;
			buff_char->uvs[3] = (float)(pen_y_ + 0.5f + height) / img_height;
		}
	}

	return buff_char;
}

GETextureGroup* GEFontFT::get_texture_group()
{
	return texture_group_;
}

bool GEFontFT::init_texture_group()
{
	if (texture_group_ == NULL)
		texture_group_ = GETextureGroup::create();
	else
		return true;

	if (texture_group_ == NULL) return false;
	else texture_group_->retain();
	return true;
}

void GEFontFT::_clear_span_list()
{
	span_list_.clear();
	outline_span_list_.clear();
}

GE_FTBuffChar* GEFontFT::_get_buff_char_with_outline( wchar_t ch )
{
	FT_GlyphSlot glyph_slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;

	glyph_index = FT_Get_Char_Index(ft_face_, ch);

	FT_BUFFCHAR_MAP::iterator char_itor = buff_char_map_.find(glyph_index);
	if (char_itor != buff_char_map_.end()) return char_itor->second;

	FT_Error ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_DEFAULT);
	if (ret != 0) return false;

	_clear_span_list();
	GEFreeType::get_instance()->span_render(this, glyph_slot);
	GEFreeType::get_instance()->span_render_outline(this, glyph_slot);

	if (span_list_.empty())
	{
		GE_FTBuffChar* buff_char = _build_buff_char(glyph_index, 0, 0);
		if (buff_char)
		{
			buff_char->_advance = glyph_slot->metrics.horiAdvance >> 6;
			buff_char->_bearing_x = glyph_slot->metrics.horiBearingX >> 6;
			buff_char->_bearing_y = glyph_slot->metrics.horiBearingY >> 6;
		}
		return buff_char;
	}

	GE_IRECT span_rect;
	span_rect.move_to(span_list_.front().x, span_list_.front().y);
	FOR_EACH (FT_SPAN_LIST, span_list_, span_itor)
	{
		span_rect.expand(span_itor->x, span_itor->y);
		span_rect.expand(span_itor->x + span_itor->len - 1, span_itor->y);
	}
	FOR_EACH (FT_SPAN_LIST, outline_span_list_, span_itor)
	{
		span_rect.expand(span_itor->x, span_itor->y);
		span_rect.expand(span_itor->x + span_itor->len - 1, span_itor->y);
	}

	int width = span_rect.width() + 1;
	int height = span_rect.height() + 1;

	bool b_ret = true;
	b_ret = _init_write_pen(width, height);
	if (!b_ret) return NULL;

	GE_IRECT rect(0, 0, width, height);
	rect.move_to(pen_x_, pen_y_);
	unsigned char* buff = NULL;
	int pitch = 0;

	b_ret = current_page_->lock_rect(rect, (void*&)buff, pitch);
	if ((!b_ret) || buff == NULL) return NULL;

	for (int i=0; i<rect.height(); ++i)
	{
		for (int j=0; j<rect.width(); ++j)
		{
			int pos = i * pitch / 2 + j;
			buff[pos << 1] = 0x00;
			buff[pos << 1 | 1] = 0x00;
		}
	}

	FOR_EACH (FT_SPAN_LIST, outline_span_list_, span_itor)
	{
		int x = span_itor->x - span_rect.left;
		int y = height - 1 - (span_itor->y - span_rect.top);
		for (int i=0; i<span_itor->len; ++i)
		{
			int pos = y * pitch / 2 + x + i;
			buff[pos << 1] = 0x00;
			buff[pos << 1 | 1] = span_itor->coverage;
		}
	}

	FOR_EACH (FT_SPAN_LIST, span_list_, span_itor)
	{
		int x = span_itor->x - span_rect.left;
		int y = height - 1 - (span_itor->y - span_rect.top);
		for (int i=0; i<span_itor->len; ++i)
		{
			int pos = y * pitch / 2 + x + i;
			int old_c = buff[pos << 1];
			int old_a = buff[pos << 1 | 1];
			buff[pos << 1] = (int)(old_c + (0xff - old_c) * span_itor->coverage / 255.f);
			buff[pos << 1 | 1] = min(0xff, old_a + span_itor->coverage);
		}
	}

	b_ret = current_page_->unlock_rect();
	if (!b_ret) return NULL;

	GE_FTBuffChar* buff_char = _build_buff_char(glyph_index, width, height);
	if (buff_char)
	{
		buff_char->_advance = glyph_slot->metrics.horiAdvance >> 6;
		buff_char->_bearing_x = glyph_slot->metrics.horiBearingX >> 6;
		buff_char->_bearing_y = glyph_slot->metrics.horiBearingY >> 6;
	}
	b_ret = _update_write_pen(width, height);
	if (!b_ret) return buff_char;

	return buff_char;
}

GEFontFT::FT_SPAN_LIST* GEFontFT::_get_span_list()
{
	return &span_list_;
}

GEFontFT::FT_SPAN_LIST* GEFontFT::_get_outline_span_list()
{
	return &outline_span_list_;
}

void GEFontFT::set_outline_weight( float weight )
{
	if (fabs(outline_weight_ - weight) >= FLT_EPSILON)
	{
		clear_font_buff();
		outline_weight_ = weight;
	}
}

float GEFontFT::get_outline_weight()
{
	return outline_weight_;
}

bool GEFontFT::clear_font_buff()
{
	is_buff_dirty_ = true;
	if (render_char_buff_ != NULL) return false;
	if (texture_group_) texture_group_->release_all_texture();
	FOR_EACH (FT_BUFFCHAR_MAP, buff_char_map_, itor)
	{
		if (GE_FTBuffChar* buff_char = itor->second)
		{
			delete buff_char;
		}		
	}
	buff_char_map_.clear();

	current_page_ = NULL;
	current_page_id_ = -1;
	pen_x_ = 0;
	pen_y_ = 0;

	is_buff_dirty_ = false;
	++ valid_stamp_;
	return true;
}

bool GEFontFT::is_valid( int stamp )
{
	return stamp >= valid_stamp_;
}

}

