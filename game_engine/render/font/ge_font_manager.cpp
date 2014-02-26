#include "ge_font_manager.h"
#include "ge_font.h"
#include "ge_font_bm.h"
#include "ge_font_ft.h"

namespace ge
{

GEFontManager::GEFontManager()
{

}

GEFontManager::~GEFontManager()
{
}

GEFontManager* GEFontManager::get_instance()
{
	static GEFontManager _global_ge_font_manager;
	return &_global_ge_font_manager;
}

GEFont* GEFontManager::create_font( GEFontType font_type )
{
	GEFontManager* font_manager = GEFontManager::get_instance();
	if (font_manager == NULL) return NULL;
	return font_manager->new_font(font_type);
}

void GEFontManager::release_font( GEFont* ptr_font )
{
	GEFontManager* font_manager = GEFontManager::get_instance();
	if (font_manager == NULL) return;
	font_manager->delete_font(ptr_font);
}

GEFont* GEFontManager::new_font( GEFontType font_type )
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

void GEFontManager::delete_font( GEFont* ptr_font )
{
	if (ptr_font == NULL) return;
	ptr_font->destory();
	font_set_.erase(ptr_font);
}

}

