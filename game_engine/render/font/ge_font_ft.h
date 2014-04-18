#ifndef _GAME_ENGINE_FREETYPE_FONT_H_
#define _GAME_ENGINE_FREETYPE_FONT_H_

#include "../../common/ge_include.h"
#include "../../render/texture/ge_texture_manager.h"
#include "ge_font.h"

#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_STROKER_H

namespace ge
{

struct GE_FTSpan
{
	int	x;
	int y;
	int len;
	int coverage;
};

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
	
	bool span_render(GEFontFT* font_obj, FT_GlyphSlot glyph_slot);
	bool span_render_outline(GEFontFT* font_obj, FT_GlyphSlot glyph_slot);
	
	static void raster_callback(const int y,
		const int count,
		const FT_Span * const spans,
		void * const user);

private:
	FT_Library freetype_;

	FT_Raster_Params params_;
};

struct GE_FTBuffChar
{
	unsigned	index;
	short		page;
	float		uvs[4];

	int			width;
	int			height;

	int			_bearing_x;
	int			_bearing_y;
	int			_advance;
};

struct GE_FTRenderChar
{
	int			index;
	float		xys[4];
	short		page;
	float		uvs[4];
};


class GE_API GEFontFT : public GEFont
{
	DLL_MANAGE_CLASS(GEFontFT);

	friend GEFreeType;

public:
	GEFontFT();
	virtual ~GEFontFT();

public:
	bool init(const char* face, int size);
	virtual void destory();

	bool init_texture_group();
	GETextureGroup* get_texture_group();
	bool clear_font_buff();

	bool set_size(int size);
	void set_outline_weight(float weight);
	float get_outline_weight();

public:
	int begin_write(GE_FTRenderChar* char_buff, int buff_size);
	int end_write();
	
	bool is_valid(int stamp);

	bool write_text(const wchar_t* text, int width, int height, bool wrap);

protected:
	bool _set_ft_face(FT_Face ft_face);

	GE_FTBuffChar* _get_buff_char(wchar_t ch);
	GE_FTBuffChar* _render_bitmap_glyph(FT_UInt glyph_index, FT_BitmapGlyph bmp_glyph);
	GE_FTBuffChar* _build_buff_char(FT_UInt glyph_index, int width, int height);
	
	bool _init_write_pen(int width, int height);
	bool _update_write_pen(int width, int height);
	int _create_buff_page();

	GE_FTBuffChar* _get_buff_char_with_outline(wchar_t ch);
	void _clear_span_list();

	typedef std::vector<GE_FTSpan> FT_SPAN_LIST;
	FT_SPAN_LIST* _get_span_list();
	FT_SPAN_LIST* _get_outline_span_list();

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

	FT_SPAN_LIST		span_list_;
	FT_SPAN_LIST		outline_span_list_;
	float				outline_weight_;

	int					valid_stamp_;
	bool				is_buff_dirty_;
};

} // namespace ge

#endif // _GAME_ENGINE_FREETYPE_FONT_H_