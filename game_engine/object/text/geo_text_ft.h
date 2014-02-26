#ifndef _GAME_ENGINE_OBJECT_TEXT_FT_H_
#define _GAME_ENGINE_OBJECT_TEXT_FT_H_

#include "geo_text.h"
#include "../../render/font/ge_font_ft.h"

namespace ge
{



class GE_API GEOTextFT : public GEOText
{
	DLL_MANAGE_CLASS(GEOTextFT);

public:
	GEOTextFT();
	virtual ~GEOTextFT();

public:
	//virtual void render(time_t delta);

	//virtual bool set_rect(GE_IRECT& rect);
	//virtual bool set_text_style(GE_TEXT_STYLE& style, const char* font_path);
	virtual bool set_text(const char* text);
	virtual bool set_font(GEFont* font);
	
	virtual bool update_font();
	virtual bool update_text();


private:

	typedef std::vector<TGlyph> GLYPH_LIST;
	GLYPH_LIST	glyph_buff_;

	bool		need_update_text_;
	bool		need_update_font_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXT_FT_H_