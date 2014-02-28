#include "geo_text_ft.h"
#include "../../common/ge_engine.h"
#include "../../object/geo_atlas_render.h"
#include "../../render/texture/ge_texture.h"
#include "../../utility/ge_unicode.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEOTextFT);

const unsigned GEOTextFT::fvf = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);


GEOTextFT::GEOTextFT()
: need_update_text_(true)
, need_update_font_(true)
, need_update_quad_(true)
, render_object_(NULL)
, glyph_buff_()
{

}

GEOTextFT::~GEOTextFT()
{

}

bool GEOTextFT::set_font( GEFont* font )
{
	if (font == NULL) return false;
	if (font->type_ != FontType_FTFont) return false;
	return GEOText::set_font(font);
}

bool GEOTextFT::set_text( const char* text )
{
	bool b_ret = GEOText::set_text(text);
	need_update_text_ = true;
	return b_ret;
}

bool GEOTextFT::set_size( GE_ISIZE& size )
{
	render_size_ = size;

	if (!render_object_)
	{
		render_object_ = GEOAtlasRender::create();
		render_object_->set_vertex_fvf(fvf);
	}
	if (!render_object_->get_texture())
	{
		render_object_->add_texture();
	}

	if (render_object_ 
		&& render_object_->get_texture()
		&& size.width > 0 && size.height > 0)
	{
		GETexture* ptr_texture = NULL;
		ptr_texture = render_object_->get_texture();
		ptr_texture->init(size.width, size.height, D3DFMT_A8R8G8B8);
	}

	return true;
}

bool GEOTextFT::_update_quad()
{
	render_object_->clear_quads();
	render_object_->add_quad();

	need_update_quad_ = false;
	return true;
}

bool GEOTextFT::update_text()
{
	if (render_object_ == NULL) return false;

	GEFontFT* font = (GEFontFT*)font_obj_;
	if (font == NULL) return false;

	std::wstring wtext = _mbcs_to_unicode(text_.c_str());
	glyph_buff_.resize(wtext.length());
	font->begin_write(&(glyph_buff_[0]), glyph_buff_.size());
	font->write_text(wtext.c_str(), 0, 0, false);
	int cnt = font->end_write();

	GETexture* texture = render_object_->get_texture();


	if (texture)
	{
		HDC h_dc = NULL;
		texture->begin_dc(h_dc);
		Gdiplus::Graphics* panel = Gdiplus::Graphics::FromHDC(h_dc);
		panel->Clear(Gdiplus::Color::Transparent);
		delete panel;
		texture->end_dc(h_dc);

		for (int i=0; i<cnt; ++i)
		{
			FT_Error err = FT_Glyph_To_Bitmap(
				&glyph_buff_[i].image,
				FT_RENDER_MODE_NORMAL,
				NULL, true);

			if (err)
			{
				
			}
			
			FT_BitmapGlyph bmp_glyph = (FT_BitmapGlyph)glyph_buff_[i].image;

			GE_IRECT rect;
			rect.right = bmp_glyph->bitmap.width;
			rect.bottom = bmp_glyph->bitmap.rows;
			rect.move_to(glyph_buff_[i].pos.x, glyph_buff_[i].pos.y);
			texture->draw_bitmap((void*)bmp_glyph->bitmap.buffer, rect);
		}
	}

	need_update_text_ = false;
	return true;
}

bool GEOTextFT::update_font()
{
	need_update_font_ = false;
	return true;
}

void GEOTextFT::render( time_t delta )
{
	if (need_update_quad_) _update_quad();
	if (need_update_font_) update_font();
	if (need_update_text_) update_text();

	if (render_object_)
	{
		render_object_->prepare_render();
		render_object_->draw_quads();
	}

}

}

