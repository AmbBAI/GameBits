#ifndef _GAME_ENGINE_FREETYPE_FONT_H_
#define _GAME_ENGINE_FREETYPE_FONT_H_

#include "../../common/ge_include.h"
#include "../../render/texture/ge_texture_manager.h"
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

typedef struct _GE_FTBuffChar
{
	unsigned	index;
	short		page;
	float		uvs[4];

	int			_bearing_x;
	int			_bearing_y;
	int			_advance;
} GE_FTBuffChar;

typedef struct _GE_FTRenderChar
{
	int			index;
	float		xys[4];
	short		page;
	float		uvs[4];
} GE_FTRenderChar;

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

	bool init_texture_group();
	GETextureGroup* get_texture_group();

	virtual bool set_size(int size);

public:
	bool begin_write(GE_FTRenderChar* char_buff, int buff_size);
	int end_write();
	
	bool write_text(const wchar_t* text, int width, int height, bool wrap);

protected:
	bool _set_ft_face(FT_Face ft_face);
	GE_FTBuffChar* _buff_char_glyph(wchar_t ch);
	GE_FTBuffChar* _write_bitmap_glyph(FT_UInt glyph_index, FT_BitmapGlyph bmp_glyph);
	GE_FTBuffChar* _save_buff_char(FT_UInt glyph_index, FT_BitmapGlyph bmp_glyph);
	bool _init_write_pen(int width, int height);
	bool _update_write_pen(int width, int height);
	int _create_buff_page();

private:
	FT_Face				ft_face_;
	int					face_size_;

	GE_FTRenderChar*	render_char_buff_;
	int					buff_size_;
	int					buff_offset_;

	typedef std::map<FT_UInt, GE_FTBuffChar*> FT_BUFFCHAR_MAP;
	FT_BUFFCHAR_MAP		buff_char_map_;

	GETextureGroup*		texture_group_;
	GETexture*			current_page_;
	int					current_page_id_;
	int					pen_x_;
	int					pen_y_;

	const int			page_width_;
	const int			page_height_;
};

} // namespace ge

#endif // _GAME_ENGINE_FREETYPE_FONT_H_