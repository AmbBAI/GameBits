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

GEFontFT* GEFreeType::create_font( const char* font_path )
{
	GEFontFT* font_ft = GEFontFT::create();
	if (font_ft == NULL) return NULL;
	
	FT_Face ft_face = NULL;
	FT_New_Face(freetype_, font_path, 0, &ft_face);
	font_ft->_set_ft_face(ft_face);
	return font_ft;
}

void GEFreeType::release_font( GEFontFT** font_ft )
{
	GEFontFT::release(font_ft);
}




DLL_MANAGE_CLASS_IMPLEMENT(GEFontFT);

GEFontFT::GEFontFT()
: ft_face_(NULL)
{
}

GEFontFT::~GEFontFT()
{
	destory();
}

void GEFontFT::destory()
{
	if (ft_face_ == NULL) return;
	FT_Done_Face(ft_face_);
	ft_face_ = NULL;
}

bool GEFontFT::_set_ft_face( FT_Face ft_face )
{
	destory();
	ft_face_ = ft_face;
	return true;
}

bool GEFontFT::write_text( const char* text, int width, int height, bool wrap )
{
	if (text == NULL) return false;

	int text_len = strlen(text);

	FT_GlyphSlot slot = ft_face_->glyph;
	FT_UInt glyph_index = 0;
	FT_UInt pre_glyph_index = 0;
	FT_Bool use_kerning = false; 
	int pen_x = 0;
	int pen_y = 0;

	for (int i=0; i<text_len; ++i)
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

		/* 保存当前笔位置 */ 
		glyph_buff_[i].pos.x = pen_x;
		glyph_buff_[i].pos.y = pen_y;

		ret = FT_Load_Glyph(ft_face_, glyph_index, FT_LOAD_DEFAULT); 
		if ( ret != 0 ) continue;

		ret = FT_Get_Glyph(ft_face_->glyph, &glyph_buff_[i].image); 
		if ( ret != 0 ) continue;
	}
	return true;
}

bool GEFontFT::begin_write( PGlyph char_buff, int buff_size )
{
	if (glyph_buff_ != NULL) return false;
	glyph_buff_ = char_buff;
	buff_size_ = buff_size;
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

