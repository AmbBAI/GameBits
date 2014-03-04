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
	render_char_buff_.resize(wtext.length());
	font->begin_write(&(render_char_buff_[0]), render_char_buff_.size());
	font->write_text(wtext.c_str(), 0, 0, false);
	int cnt = font->end_write();

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

