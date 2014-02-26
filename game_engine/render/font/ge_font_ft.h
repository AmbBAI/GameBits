#ifndef _GAME_ENGINE_FREETYPE_FONT_H_
#define _GAME_ENGINE_FREETYPE_FONT_H_

#include "../../common/ge_include.h"
#include "ge_font.h"

#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H

namespace ge
{

class GEFontFT;
class GE_API GEFreeType
{
public:
	GEFreeType();
	virtual ~GEFreeType();

public:
	bool init();
	void destory();

	GEFontFT* create_font(const char* font_name);
	void release_font(GEFontFT** font_ft);

private:
	FT_Library freetype_;
};

typedef struct  TGlyph_
{
	FT_UInt    index;  /* glyph index                  */
	FT_Vector  pos;    /* glyph origin on the baseline */
	FT_Glyph   image;  /* glyph image                  */

} TGlyph, *PGlyph;

class GE_API GEFontFT : public GEFont
{
	DLL_MANAGE_CLASS(GEFontFT);

	friend GEFreeType;

public:
	GEFontFT();
	virtual ~GEFontFT();

public:
	//virtual bool init();
	virtual void destory();

public:
	bool begin_write(PGlyph char_buff, int buff_size);
	int end_write();
	
	bool write_text(const char* text, int width, int height, bool wrap);

protected:
	bool _set_ft_face(FT_Face ft_face);

private:
	FT_Face		ft_face_;

	PGlyph		glyph_buff_;
	int			buff_size_;
	int			buff_offset_;
};

} // namespace ge

#endif // _GAME_ENGINE_FREETYPE_FONT_H_