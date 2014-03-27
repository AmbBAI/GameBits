#ifndef _GAME_ENGINE_OBJECT_TEXT_BM_H_
#define _GAME_ENGINE_OBJECT_TEXT_BM_H_

#include "../ge_object.h"
#include "../../render/font/bm_font/bm_font.h"
#include "../../render/font/ge_font_bm.h"
#include "../../render/draw/ge_atlas_draw.h"
#include "geo_text.h"

namespace ge
{

class GEAtlasDraw;
class GEREffect;
class GE_API GEOTextBM : public GEOText
{

	DLL_MANAGE_CLASS(GEOTextBM);

	GEOTextBM();
	virtual ~GEOTextBM();

public:
	static const unsigned fvf;

	virtual bool set_font(GEFont* font);
	virtual bool set_text(const char* text);

	virtual void update(time_t delta);
	virtual bool update_font();
	virtual bool update_text();
	virtual bool update_quad();

protected:
	void _clear_render_chars();
	void _render_char_to_quad(GE_QUAD_EX& out_quad, const bmfont::SCharRenderObject& render_char);

private:
	typedef std::vector<bmfont::SCharRenderObject>	RENDER_CHAR_LIST;

	GEAtlasDraw*				render_object_;
	RENDER_CHAR_LIST			render_chars_;
	int							render_char_cnt_;

	bool						need_update_text_;
	bool						need_update_font_;
	bool						need_update_quad_;

	GEREffect*					effect_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXT_BM_H_