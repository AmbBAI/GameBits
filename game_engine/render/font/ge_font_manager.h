#ifndef _GAME_ENGINE_FONT_MANAGER_H_
#define _GAME_ENGINE_FONT_MANAGER_H_

#include "common/ge_include.h"

namespace ge
{

enum GE_API GEFontType
{
	FontType_Default = 0,
	FontType_D3DXFont,
	FontType_GDIFont,
	FontType_BMFont,
	FontType_FTFont,
};

class GEFont;
class GE_API GEFontManager
{
	typedef std::set<GEFont*>	GE_FONT_SET;

	GEFontManager();
	virtual ~GEFontManager();
	
	static GEFontManager* get_instance();

public:
	static bool init();
	static void destory();

	static GEFont* create_font(GEFontType font_type);
	static void release_font(GEFont* ptr_font);

protected:
	GEFont* _create_font(GEFontType font_type);
	void	_release_font(GEFont* ptr_font);

private:
	GE_FONT_SET				font_set_;
	ULONG_PTR				gdiplus_token_;
};

} // namespace ge

#endif // _GAME_ENGINE_FONT_MANAGER_H_