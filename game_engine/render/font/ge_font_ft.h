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

	static GEFreeType* get_instance();

public:
	bool init();
	void destory();

	bool init_font(GEFontFT* font_ft, const char* font_name);

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
	virtual bool init(const char* face, int size);
	virtual void destory();

	virtual bool set_size(int size);

public:
	bool begin_write(PGlyph char_buff, int buff_size);
	int end_write();
	
	bool write_text(const wchar_t* text, int width, int height, bool wrap);

protected:
	bool _set_ft_face(FT_Face ft_face);

private:
	FT_Face		ft_face_;
	int			face_size_;

	PGlyph		glyph_buff_;
	int			buff_size_;
	int			buff_offset_;
};

} // namespace ge

#endif // _GAME_ENGINE_FREETYPE_FONT_H_