#ifndef _GAME_ENGINE_OBJECT_TEXT_GDI_H_
#define _GAME_ENGINE_OBJECT_TEXT_GDI_H_

#include "object/ge_object.h"
#include "utility/ge_type.h"
#include "render/font/ge_font.h"
#include "object/text/geo_text.h"

namespace ge
{

class GEAtlasDraw;

class GE_API GEOTextGDI : public GEOText
{
	DLL_MANAGE_CLASS(GEOTextGDI);

public:
	GEOTextGDI();
	virtual ~GEOTextGDI();

public:
	static const unsigned fvf;

	virtual bool set_font(GEFont* font);

	virtual bool set_rect(GE_IRECT& rect);
	virtual bool set_text_style(GE_TEXT_STYLE& style);

	virtual bool set_text(const char* text);

	virtual bool update_text();
	virtual bool update_text_ex();

public:
	virtual void render(time_t delta);

protected:
	virtual bool _init_render_object();
	virtual bool _init_bitmap(int width, int height);
	virtual bool _init_dc(int width, int height);
	virtual void _destory_bitmap();
	virtual void _destory_dc();
	virtual bool _update_quad();

private:
	std::wstring	wtext_;

	GE_IRECT		rect_;
	GE_TEXT_STYLE	text_style_;

	HBITMAP			h_bitmap_;
	HDC				h_dc_;

	GEAtlasDraw*	render_object_;

	bool			need_update_quad_;
	bool			need_update_text_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXT_GDI_H_