#include "geo_text_ft.h"
#include "../../common/ge_engine.h"
#include "../../object/geo_atlas_render.h"
#include "../../render/texture/ge_texture.h"

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
	GE_QUAD out_quad;

	GE_VERTEX* vertex_ptr[4];
	vertex_ptr[0] = &(out_quad.tl);
	vertex_ptr[1] = &(out_quad.tr);
	vertex_ptr[2] = &(out_quad.br);
	vertex_ptr[3] = &(out_quad.bl);

	for (int i=0; i<4; ++i)
	{
		vertex_ptr[i]->set_decl(render_object_->get_vertex_decl());
		vertex_ptr[i]->set_color(0xffffffff);
	}

	float min_x = (float)0;
	float min_y = (float)0;
	float max_x = (float)render_size_.width;
	float max_y = (float)render_size_.height;

	out_quad.tl.set_position(min_x, -min_y, 0.f);
	out_quad.tr.set_position(max_x, -min_y, 0.f);
	out_quad.br.set_position(max_x, -max_y, 0.f);
	out_quad.bl.set_position(min_x, -max_y, 0.f);

	out_quad.tl.set_texcoords(0.f, 0.f);
	out_quad.tr.set_texcoords(1.f, 0.f);
	out_quad.br.set_texcoords(1.f, 1.f);
	out_quad.bl.set_texcoords(0.f, 1.f);

	out_quad.texture = 0;

	render_object_->clear_quads();
	render_object_->add_quad(out_quad);

	need_update_quad_ = false;
	return true;
}

bool GEOTextFT::update_text()
{
	if (render_object_ == NULL) return false;

	GEFontFT* font = (GEFontFT*)font_obj_;
	if (font == NULL) return false;

	glyph_buff_.resize(text_.length());
	font->begin_write(&(glyph_buff_[0]), glyph_buff_.size());
	font->write_text(text_.c_str(), 0, 0, false);
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

