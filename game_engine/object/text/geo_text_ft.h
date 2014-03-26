#ifndef _GAME_ENGINE_OBJECT_TEXT_FT_H_
#define _GAME_ENGINE_OBJECT_TEXT_FT_H_

#include "geo_text.h"
#include "../../render/font/ge_font_ft.h"
#include "../../render/draw/ge_draw_atlas.h"

namespace ge
{

class GE_API GEOTextFT : public GEOText
{
	DLL_MANAGE_CLASS(GEOTextFT);

	GEOTextFT();
	virtual ~GEOTextFT();

public:
	static const unsigned fvf;

public:
	virtual bool set_text(const char* text);
	virtual bool set_font(GEFont* font);
	virtual bool set_rect(GE_IRECT& rect);

	virtual void render(time_t delta);

protected:
	virtual bool update_font();
	virtual bool update_text();
	virtual bool update_quad();

protected:
	virtual void _render_char_to_quad(GE_QUAD& out_quad, const GE_FTRenderChar& render_char);

private:
	typedef std::vector<GE_FTRenderChar> FT_RENDER_CHAR_LIST;
	FT_RENDER_CHAR_LIST		render_char_buff_;
	int						render_char_cnt_;

	bool					need_update_text_;
	bool					need_update_font_;
	bool					need_update_quad_;

	GEDrawAtlas*			render_object_;
	GE_IRECT				render_rect_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXT_FT_H_