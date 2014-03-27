#include "geo_text_bm.h"
#include "../../common/ge_engine.h"
#include "../../render/texture/ge_texture_manager.h"
#include "../../render/ge_render.h"
#include "../../render/ger_effect.h"
#include "../../utility/ge_unicode.h"

namespace ge
{
DLL_MANAGE_CLASS_IMPLEMENT(GEOTextBM);

const unsigned GEOTextBM::fvf = (D3DFVF_XYZB1 | D3DFVF_LASTBETA_UBYTE4 | D3DFVF_DIFFUSE | D3DFVF_TEX1);

GEOTextBM::GEOTextBM()
: render_object_(NULL)
, need_update_font_(true)
, need_update_text_(true)
, effect_(NULL)
{
}

GEOTextBM::~GEOTextBM()
{
}

bool GEOTextBM::set_font( GEFont* font )
{
	if (font == NULL) return false;
	if (font->type_ != FontType_BMFont) return false;
	bool ret = GEOText::set_font(font);
	need_update_font_ = true;
	return ret;
}

bool GEOTextBM::set_text( const char* text )
{
	if (text == NULL) text_.clear();
	else text_ = _mbcs_to_utf8(text);
	need_update_text_ = true;
	return true;
}

bool GEOTextBM::update_font()
{
	if (render_object_ == NULL)
	{
		render_object_ = GEAtlasDraw::create();
	} else render_object_->destory();

	GEFontBM* bm_font = (GEFontBM*)font_obj_;
	if (bm_font == NULL) return false;

	int page_cnt = bm_font->get_page_cnt();
	if (render_object_ == NULL) return false;
	render_object_->init_texture_group();
	render_object_->set_vertex_decl(GEVertexDecl::get_vertex_decl(fvf));
	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return false;
	texture_group->release_all_texture();
	for (int i=0; i<page_cnt; ++i)
	{
		char page_path[MAX_PATH];
		bm_font->get_page_path(page_path, i);
		int png_id = texture_group->add_texture_from_file(page_path);
		assert(png_id == i);
	}
	effect_ = bm_font->get_effect();
	if (effect_) effect_->set_matrix("WORLD", get_world_transform());
	need_update_font_ = false;
	return true;
}

bool GEOTextBM::update_text()
{
	GEFontBM* bm_font = (GEFontBM*)font_obj_;
	if (bm_font == NULL) return false;

	if (render_object_ == NULL) return false;

	render_chars_.resize(text_.length());

	bm_font->begin_write(&(render_chars_[0]), render_chars_.max_size());
	bm_font->write_text(text_.c_str(), 400, 0, true);
	render_char_cnt_ = bm_font->end_write();

	need_update_quad_ = true;
	need_update_text_ = false;
	return true;
}

bool GEOTextBM::update_quad()
{
	render_object_->clear_quads();
	for (int i=0; i<render_char_cnt_; ++i)
	//FOR_EACH (RENDER_CHAR_LIST, render_chars_, char_itor)
	{
		if (i > (int)render_chars_.size()) return false;
		GE_QUAD_EX quad;
		_render_char_to_quad(quad, render_chars_[i]);
		render_object_->add_quad(quad);
	}
	need_update_quad_ = false;
	return true;
}

void GEOTextBM::_clear_render_chars()
{
	render_chars_.clear();
}

void GEOTextBM::_render_char_to_quad( GE_QUAD_EX& out_quad, const bmfont::SCharRenderObject& render_char )
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
		vertex_ptr[i]->set_blend(render_char.chnl);
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

void GEOTextBM::update( time_t delta )
{
	if (need_update_font_) update_font();
	if (need_update_text_) update_text();
	if (need_update_quad_) update_quad();

	if(effect_)
	{
		if (GEFontBM* bm_font = (GEFontBM*)font_obj_)
			bm_font->update_effect();
		
		effect_->set_technique("RenderWithOutline");
		render_object_->set_effect(effect_);
	}

	GERender::push_render(render_object_);
}

}

