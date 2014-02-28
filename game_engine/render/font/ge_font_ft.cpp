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
, glyph_buff_(NULL)
, buff_size_(0)
, buff_offset_(0)
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

	if (glyph_buff_ == NULL) return false;

	FT_GlyphSlot slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_UInt pre_glyph_index = 0;
	FT_Bool use_kerning = false; 
	int pen_x = 0;
	int pen_y = 0;

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
				glyph_index = FT_Get_Char_Index(ft_face_, text[i]);

				int ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_RENDER);
				if (ret != 0) continue;

				if ( use_kerning && pre_glyph_index && glyph_index )
				{
					FT_Vector delta;

					FT_Get_Kerning( ft_face_, pre_glyph_index, glyph_index, 
						FT_KERNING_DEFAULT, &delta );

					pen_x += delta.x >> 6;
				}

				ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_DEFAULT); 
				if ( ret != 0 ) continue;

				ret = FT_Get_Glyph(ft_face_->glyph, &glyph_buff_[buff_offset_].image);
				if ( ret != 0 ) continue;

				glyph_buff_[buff_offset_].pos.x = pen_x + (slot->metrics.horiBearingX >> 6);
				glyph_buff_[buff_offset_].pos.y = pen_y + ((ft_face_->ascender - slot->metrics.horiBearingY) >> 6);

				pen_x += slot->metrics.horiAdvance >> 6;
				pre_glyph_index = glyph_index;

				++ buff_offset_;
				if (buff_offset_ >= buff_size_) return true;
			}
			break;
		}

	}
	return true;
}

bool GEFontFT::begin_write( PGlyph char_buff, int buff_size )
{
	if (glyph_buff_ != NULL) return false;
	glyph_buff_ = char_buff;
	buff_size_ = buff_size;
	buff_offset_ = 0;
	return true;
}

int GEFontFT::end_write()
{
	glyph_buff_ = NULL;
	buff_size_ = 0;
	int n_ret = buff_offset_;
	buff_offset_ = 0;
	return n_ret;
}




}

