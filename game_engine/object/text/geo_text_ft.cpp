#include "geo_text_ft.h"
#include "../../common/ge_engine.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEOTextFT);

GEOTextFT::GEOTextFT()
{

}

GEOTextFT::~GEOTextFT()
{

}

bool GEOTextFT::set_font( GEFont* font )
{
	if (font == NULL) return false;
	if (font->type_ != FontType_FTFont) return false;
	return GEOText::set_font(font);
}

bool GEOTextFT::set_text( const char* text )
{
	bool b_ret = GEOText::set_text(text);
	need_update_text_ = true;
	return b_ret;
}

bool GEOTextFT::update_text()
{
	need_update_text_ = false;
	return true;
}

bool GEOTextFT::update_font()
{
	need_update_font_ = false;
	return true;
}



}

