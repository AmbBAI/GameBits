#include "geo_text_gdi.h"
#include "../../common/ge_engine.h"
#include "../../render/texture/ge_texture_manager.h"
#include "../geo_atlas_render.h"
#include "../../utility/ge_unicode.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEOTextGDI);

const unsigned GEOTextGDI::fvf = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

GEOTextGDI::GEOTextGDI()
: h_bitmap_(NULL)
, h_dc_(NULL)
, render_object_(NULL)
, need_update_text_(true)
, need_update_quad_(true)
{
}

GEOTextGDI::~GEOTextGDI()
{
	text_.clear();
	if (render_object_)
	{
		GEOAtlasRender::release(&render_object_);
	}
}

bool GEOTextGDI::set_rect( GE_IRECT& rect )
{
	rect_ = rect;

	_init_dc(rect.width(), rect.height());
	_init_bitmap(rect.width(), rect.height());
	need_update_quad_ = true;
	return true;
}

bool GEOTextGDI::set_font( GEFont* font )
{
	if (font == NULL) return false;
	if (font->type_ != FontType_GDIFont) return false;
	need_update_text_ = true;
	return GEOText::set_font(font);
}

bool GEOTextGDI::set_text_style( GE_TEXT_STYLE& style )
{
	text_style_ = style;
	need_update_text_ = true;
	return true;
}

bool GEOTextGDI::set_text( const char* text )
{
	bool b_ret = GEOText::set_text(text);
	wtext_ = _mbcs_to_unicode(text_.c_str());
	need_update_text_ = true;
	return b_ret;
}

void GEOTextGDI::render( time_t delta )
{
	if (need_update_quad_) _update_quad();
	if (need_update_text_) update_text_ex();

	render_object_->prepare_render();
	render_object_->draw_quads();
}

bool GEOTextGDI::_init_render_object()
{
	if (!render_object_)
	{
		render_object_ = GEOAtlasRender::create();
		render_object_->init_texture_group();
		render_object_->set_vertex_fvf(fvf);
	}
	if (render_object_)
	{
		GETextureGroup* texture_group = render_object_->get_texture_group();
		if (texture_group == NULL) return false;
		if (texture_group->get_texture() == NULL) texture_group->add_texture();
		return true;
	}
	else return false;
}

bool GEOTextGDI::_init_bitmap( int width, int height )
{
	_destory_bitmap();

	if (width > 0 && height > 0)
	{
		h_bitmap_ = CreateBitmap(width, height, 1, 32, NULL);
	}
	return (h_bitmap_ != NULL);
}

bool GEOTextGDI::_init_dc( int width, int height )
{
	_destory_dc();
	_init_render_object();

	if (render_object_ 
		&& width > 0 && height > 0)
	{
		GETextureGroup* texture_group = render_object_->get_texture_group();
		if (texture_group == NULL) return false;
		GETexture* ptr_texture = NULL;
		ptr_texture = texture_group->get_texture();
		if (ptr_texture) ptr_texture->init(width, height, D3DFMT_A8R8G8B8);
	}
	return (h_dc_ != NULL);
}

void GEOTextGDI::_destory_bitmap()
{
	if (h_bitmap_)
	{
		DeleteObject(h_bitmap_);
		h_bitmap_ = NULL;
	}
}

void GEOTextGDI::_destory_dc()
{
	if (h_dc_)
	{
		CloseHandle(h_dc_);
		h_dc_ = NULL;
	}
}

bool GEOTextGDI::_update_quad()
{
	render_object_->clear_quads();
	render_object_->add_quad();

	need_update_quad_ = false;
	return true;
}

bool GEOTextGDI::update_text()
{
	GEGDIFont* font_obj = (GEGDIFont*)font_obj_;
	if (font_obj == NULL) return false;

	HFONT h_font = font_obj->get_gdi_obj();
	if (h_font == NULL) return false;

	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return false;
	GETexture* texture = texture_group->get_texture();
	if (texture == NULL) return false;

	texture->begin_dc(h_dc_);

	// draw text
	HGDIOBJ h_old_font = SelectObject(h_dc_, h_font);
	HGDIOBJ h_old_bitmap = SelectObject(h_dc_, h_bitmap_);

	GE_IRECT rect = rect_;
	rect.move_to(0, 0);

	HBRUSH h_brush = CreateSolidBrush(RGB(0, 0, 0));
	FillRect(h_dc_, &rect, h_brush);
	DeleteObject(h_brush);

	SetBkMode(h_dc_, TRANSPARENT);
	SetTextColor(h_dc_, RGB(255, 255, 255)); // white color

	// draw text
	int ret = 0;
	ret = DrawText(h_dc_,
		text_.c_str(), text_.length(),
		&rect, text_style_.format);

	SelectObject(h_dc_, h_old_bitmap);
	SelectObject(h_dc_, h_old_font);

	texture->end_dc(h_dc_);

	need_update_text_ = false;
	return ret != 0;
}

bool GEOTextGDI::update_text_ex()
{
	GEGDIFont* font_obj = (GEGDIFont*)font_obj_;
	if (font_obj == NULL) return false;

	HFONT h_font = font_obj->get_gdi_obj();
	if (h_font == NULL) return false;

	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return false;
	GETexture* texture = texture_group->get_texture();
	if (texture == NULL) return false;

	texture->begin_dc(h_dc_);

	bool ret = true;

	std::wstring unicode_text;
	unicode_text.assign(mbcs_to_unicode(text_.c_str()), '\0');

	Gdiplus::Graphics* panel = Gdiplus::Graphics::FromHDC(h_dc_);

	if (panel)
	{
		Gdiplus::SolidBrush brush(Gdiplus::Color((Gdiplus::ARGB)0xffffffff));
		Gdiplus::Font font(h_dc_, h_font);

		Gdiplus::StringFormat format;
		format.SetAlignment(Gdiplus::StringAlignmentNear);

		GE_IRECT rect = rect_; rect.move_to(0, 0);
		Gdiplus::RectF rectf((Gdiplus::REAL)rect.left, (Gdiplus::REAL)rect.top,
			(Gdiplus::REAL)rect.width(), (Gdiplus::REAL)rect.height());

		panel->SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
		panel->SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
		panel->SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAliasGridFit);
		panel->SetPixelOffsetMode(Gdiplus::PixelOffsetModeHighQuality);

		// clean
		panel->Clear(Gdiplus::Color::Transparent);
		// draw
		Gdiplus::Status gdi_ret = panel->DrawString(
			wtext_.c_str(), -1,
			&font, rectf, &format, &brush);

		delete panel;
	}

	texture->end_dc(h_dc_);
	need_update_text_ = false;
	return ret;
}

}

