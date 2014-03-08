#ifndef _GAME_ENGINE_OBJECT_TEXT_FT_H_
#define _GAME_ENGINE_OBJECT_TEXT_FT_H_

#include "geo_text.h"
#include "../../render/font/ge_font_ft.h"
#include "../../render/ge_atlas_render.h"

namespace ge
{

class GEAtlasRender;
class GE_API GEOTextFT : public GEOText
{
	DLL_MANAGE_CLASS(GEOTextFT);

public:
	GEOTextFT();
	virtual ~GEOTextFT();

	static const unsigned fvf;

public:
	virtual bool set_text(const char* text);
	virtual bool set_font(GEFont* font);
	
	virtual bool update_font();
	virtual bool update_text();

	virtual void render(time_t delta);

	virtual bool set_size(GE_ISIZE& size);

	virtual bool _update_quad();
	virtual void _render_char_to_quad(GE_QUAD_EX& out_quad, const GE_FTRenderChar& render_char);


private:

	//typedef std::map<FT_UInt, TGlyph> GLYPH_MAP;
	//GLYPH_MAP		glyph_buff_;

	typedef std::vector<GE_FTRenderChar> FT_RENDER_CHAR_LIST;
	FT_RENDER_CHAR_LIST		render_char_buff_;

	bool			need_update_text_;
	bool			need_update_font_;
	bool			need_update_quad_;

	GEAtlasRender*	render_object_;
	GE_ISIZE		render_size_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXT_FT_H_