#include "ge_font_manager.h"
#include "ge_font.h"
#include "ge_font_bm.h"
#include "ge_font_ft.h"

namespace ge
{

GEFontManager::GEFontManager()
: font_set_()
{
}

GEFontManager::~GEFontManager()
{
	destory();
}

GEFontManager* GEFontManager::get_instance()
{
	static GEFontManager _global_ge_font_manager;
	return &_global_ge_font_manager;
}

bool GEFontManager::init()
{
	GEFreeType* freetype = GEFreeType::get_instance();
	if (freetype) freetype->init();

	ULONG_PTR* ptr_gdiplus_token = &(GEFontManager::get_instance()->gdiplus_token_);
	Gdiplus::GdiplusStartupInput startup_input;
	Gdiplus::GdiplusStartup(ptr_gdiplus_token, &startup_input, NULL);
	return true;
}

void GEFontManager::destory()
{
	ULONG_PTR gdiplus_token = (GEFontManager::get_instance()->gdiplus_token_);
	Gdiplus::GdiplusShutdown(gdiplus_token);
}

GEFont* GEFontManager::create_font( GEFontType font_type )
{
	GEFontManager* font_manager = GEFontManager::get_instance();
	if (font_manager == NULL) return NULL;
	return font_manager->_create_font(font_type);
}

void GEFontManager::release_font( GEFont* ptr_font )
{
	GEFontManager* font_manager = GEFontManager::get_instance();
	if (font_manager == NULL) return;
	font_manager->_release_font(ptr_font);
}

GEFont* GEFontManager::_create_font( GEFontType font_type )
{
	switch (font_type)
	{
	case FontType_Default:
		{
			GEFont* font_ptr = new GEFont();
			font_set_.insert(font_ptr);
			return font_ptr;
		}
	case FontType_D3DXFont:
		{
			GED3DXFont* font_ptr = new GED3DXFont();
			font_set_.insert(font_ptr);
			return font_ptr;
		}
	case FontType_GDIFont:
		{
			GEGDIFont* font_ptr = new GEGDIFont();
			font_set_.insert(font_ptr);
			return font_ptr;
		}
	case FontType_BMFont:
		{
			GEFontBM* font_ptr = new GEFontBM();
			font_set_.insert(font_ptr);
			return font_ptr;
		}
	case FontType_FTFont:
		{
			GEFontFT* font_ptr = new GEFontFT();
			font_set_.insert(font_ptr);
			return font_ptr;
		}
	}
	return NULL;
}

void GEFontManager::_release_font( GEFont* ptr_font )
{
	if (ptr_font == NULL) return;
	ptr_font->destory();
	font_set_.erase(ptr_font);
}

}

