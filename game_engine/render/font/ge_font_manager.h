#ifndef _GAME_ENGINE_FONT_MANAGER_H_
#define _GAME_ENGINE_FONT_MANAGER_H_

#include "../../common/ge_include.h"

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
protected:
	typedef std::set<GEFont*>	GE_FONT_SET;

	GEFontManager();
	virtual ~GEFontManager();

public:
	static GEFontManager* get_instance();
	static GEFont* create_font(GEFontType font_type);
	static void release_font(GEFont* ptr_font);

public:
	GEFont* new_font(GEFontType font_type);
	void	delete_font(GEFont* ptr_font);

protected:
	GE_FONT_SET				font_set_;
};

} // namespace ge

#endif // _GAME_ENGINE_FONT_MANAGER_H_