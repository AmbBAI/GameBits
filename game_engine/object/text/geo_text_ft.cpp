#include "geo_text_ft.h"
#include "common/ge_app.h"
#include "common/ge_engine.h"
#include "render/ge_render.h"
#include "render/font/ge_font_ft.h"
#include "render/texture/ge_texture.h"
#include "utility/ge_unicode.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEOTextFT);

const unsigned GEOTextFT::fvf = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);


GEOTextFT::GEOTextFT()
: need_update_text_(true)
, need_update_font_(true)
, need_update_quad_(true)
, render_object_(NULL)
, render_char_buff_()
, font_buff_stamp_(-1)
{

}

GEOTextFT::~GEOTextFT()
{
	GE_RELEASE(render_object_);
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
	if (text_ != text) need_update_text_ = true;
	bool b_ret = GEOText::set_text(text);
	return b_ret;
}

bool GEOTextFT::set_rect( GE_IRECT& rect )
{
	render_rect_ = rect;
	need_update_quad_ = true;
	return true;
}

bool GEOTextFT::update_text()
{
	if (render_object_ == NULL) return false;

	GEFontFT* font = (GEFontFT*)font_obj_;
	if (font == NULL) return false;

	std::wstring wtext = _mbcs_to_unicode(text_.c_str());
	render_char_buff_.resize(wtext.length());
	font_buff_stamp_ = font->begin_write(&(render_char_buff_[0]), render_char_buff_.size());
	font->write_text(wtext.c_str(), 0, 0, false);
	render_char_cnt_ = font->end_write();

	need_update_quad_ = true;
	need_update_text_ = false;
	return true;
}

bool GEOTextFT::update_font()
{
	GEFontFT* font_ft = (GEFontFT*)font_obj_;
	if (font_ft == NULL) return false;

	if (!render_object_)
	{
		render_object_ = GEAtlasDraw::create();
		if (render_object_)
		{
			render_object_->set_vertex_fvf(fvf);
		}
	}
	if (!render_object_) return false;

	GETextureGroup* texture_group = font_ft->get_texture_group();
	if (texture_group == NULL) return false;
	render_object_->set_texture_group(texture_group);

	need_update_text_ = true;
	need_update_font_ = false;
	return true;
}

bool GEOTextFT::update_quad()
{
	if (render_object_ == NULL) return false; 

	render_object_->clear_quads();
	for (int i=0; i<render_char_cnt_; ++i)
	{
		if (i >= (int)render_char_buff_.size()) return false;
		GE_QUAD quad;
		_render_char_to_quad(quad, render_char_buff_[i]);
		if (_is_char_visible(quad))
			render_object_->add_quad(quad);
	}
	need_update_quad_ = false;
	return true;
}

void GEOTextFT::_render_char_to_quad( GE_QUAD& out_quad, const GE_FTRenderChar& render_char, U32 color/* = 0xffffffff*/ )
{
	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return;
	GETexture* texture = texture_group->get_texture(render_char.page);
	if	(texture == NULL) return;

	out_quad.texid = render_char.page;
	out_quad.color = color;
	out_quad.rhw = 1.f;

	for (int i=0; i<4; ++i)
	{
		int xi = (((i >> 1) & 1) ^ (i & 1)) << 1; // 00 10 10 00
		int yi = (((i >> 1) & 1) << 1) | 1; // 01 01 11 11
		
		out_quad.xys[i<<1] = render_char.xys[xi] + render_rect_.left;
		out_quad.xys[i<<1|1] = render_char.xys[yi] + render_rect_.top;

		out_quad.uvs[i<<1] = render_char.uvs[xi];
		out_quad.uvs[i<<1|1] = render_char.uvs[yi];
	}

	return;
}

void GEOTextFT::update( time_t delta )
{
	GEFontFT* font = (GEFontFT*)font_obj_;
	if (font == NULL) return;
	if (!font->is_valid(font_buff_stamp_))
	{
		need_update_text_ = true;
		need_update_quad_ = true;
	}

	if (need_update_font_) update_font();
	if (need_update_text_) update_text();
	if (need_update_quad_) update_quad();

	GERender::push_render(render_object_);
}

bool GEOTextFT::_is_char_visible( GE_QUAD& quad )
{
	GE_IRECT& wnd_rect = GEApp::get_instance()->get_game_rect();
	bool x_in = false;
	bool y_in = false;

	for (int i=0; i<8; i+=2)
	{
		if (quad.xys[i] > wnd_rect.left && quad.xys[i] < wnd_rect.right)
		{
			x_in = true;
			break;
		}
	}
	if (!x_in) return false;

	for (int i=1; i<8; i+=2)
	{
		if (quad.xys[i] > wnd_rect.top && quad.xys[i] < wnd_rect.bottom)
		{
			y_in = true;
			break;
		}
	}

	return y_in;
}

}

