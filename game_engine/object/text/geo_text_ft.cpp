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
, render_char_buff_()
{

}

GEOTextFT::~GEOTextFT()
{

}

bool GEOTextFT::set_font( GEFont* font )
{
	if (font == NULL) return false;
	if (font->type_ != FontType_FTFont) return false;
	bool b_ret = GEOText::set_font(font);
	need_update_font_ = true;
	return b_ret;
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

	return true;
}

bool GEOTextFT::_update_quad()
{
	//render_object_->clear_quads();
	//render_object_->add_quad();

	need_update_quad_ = false;
	return true;
}

bool GEOTextFT::update_text()
{
	if (render_object_ == NULL) return false;

	GEFontFT* font = (GEFontFT*)font_obj_;
	if (font == NULL) return false;

	std::wstring wtext = _mbcs_to_unicode(text_.c_str());
	render_char_buff_.resize(wtext.length());
	font->begin_write(&(render_char_buff_[0]), render_char_buff_.size());
	font->write_text(wtext.c_str(), 0, 0, false);
	int cnt = font->end_write();

	if (cnt)
	{
		render_object_->clear_quads();
		FOR_EACH (FT_RENDER_CHAR_LIST, render_char_buff_, char_itor)
		{
			GE_QUAD quad;
			_render_char_to_quad(quad, *char_itor);
			render_object_->add_quad(quad);
		}
	}

	need_update_text_ = false;
	return true;
}

bool GEOTextFT::update_font()
{
	if (!render_object_)
	{
		render_object_ = GEOAtlasRender::create();
		if (render_object_)
		{
			render_object_->set_vertex_fvf(fvf);
		}
	}
	if (!render_object_) return false;

	GEFontFT* font_ft = (GEFontFT*)font_obj_;
	GETextureGroup* texture_group = font_ft->get_texture_group();
	if (texture_group == NULL) return false;
	render_object_->set_texture_group(texture_group);

	need_update_quad_ = true;
	need_update_font_ = false;
	return true;
}

void GEOTextFT::_render_char_to_quad( GE_QUAD& out_quad, const GE_FTRenderChar& render_char )
{
	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return;
	GETexture* texture = texture_group->get_texture(render_char.page);
	if	(texture == NULL) return;

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

	float min_x = render_char.xys[0];
	float min_y = render_char.xys[1];
	float max_x = render_char.xys[2];
	float max_y = render_char.xys[3];

	out_quad.tl.set_position(min_x, min_y, 0.f);
	out_quad.tr.set_position(max_x, min_y, 0.f);
	out_quad.br.set_position(max_x, max_y, 0.f);
	out_quad.bl.set_position(min_x, max_y, 0.f);

	float u1 = render_char.uvs[0];
	float v1 = render_char.uvs[1];
	float u2 = render_char.uvs[2];
	float v2 = render_char.uvs[3];

	out_quad.tl.set_texcoords(u1, v1);
	out_quad.tr.set_texcoords(u2, v1);
	out_quad.br.set_texcoords(u2, v2);
	out_quad.bl.set_texcoords(u1, v2);

	out_quad.texid = render_char.page;

	return;
}

void GEOTextFT::render( time_t delta )
{
	if (need_update_font_) update_font();
	if (need_update_quad_) _update_quad();
	if (need_update_text_) update_text();

	if (render_object_)
	{
		render_object_->prepare_render();
		render_object_->draw_quads();
	}

}

}

