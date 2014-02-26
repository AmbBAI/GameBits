#include "ge_font.h"
#include "ge_font_bm.h"

namespace ge
{

GEFont::GEFont()
: type_(FontType_Default)
, size_(0)
, charset_(DEFAULT_CHARSET)
, weight_(400)
, italic_(false)
, underline_(false)
, strikeout_(false)
{
	memset(face_, '\0', sizeof(face_));
}

GEFont::~GEFont()
{

}

bool GEFont::init( const char* face, int size )
{
	strcpy(face_, face);
	size_ = size;
	return _init_font();
}

bool GEFont::_init_font()
{
	return true;
}

void GEFont::destory()
{

}


GED3DXFont::GED3DXFont()
: d3dx_font_(NULL)
{
	type_ = FontType_D3DXFont;
	GEEngine::get_instance()->register_device_object(this);
}

GED3DXFont::~GED3DXFont()
{
	destory();
	GEEngine::get_instance()->unregister_device_object(this);
}

LPD3DXFONT GED3DXFont::get_d3dx_obj()
{
	return d3dx_font_;
}

bool GED3DXFont::_init_font()
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return false;

	ZeroMemory(&d3dx_font_desc_, sizeof(D3DXFONT_DESC));
	d3dx_font_desc_.Height	= size_;
	d3dx_font_desc_.Weight	= weight_;
	d3dx_font_desc_.CharSet	= charset_;
	d3dx_font_desc_.Italic	= italic_;
	d3dx_font_desc_.Quality	= ANTIALIASED_QUALITY;
	strcpy(d3dx_font_desc_.FaceName, face_);

	destory();
	HRESULT h_res = D3DXCreateFontIndirect(p_d3d_device, &d3dx_font_desc_, &d3dx_font_);
	return SUCCEEDED(h_res);
}

void GED3DXFont::destory()
{
	D3D_RELEASE(d3dx_font_)
}

void GED3DXFont::on_lost_device()
{
	if(d3dx_font_)
	{
		d3dx_font_->OnLostDevice();
	}
}

void GED3DXFont::on_reset_device()
{
	if(d3dx_font_)
	{
		d3dx_font_->OnResetDevice();
	}
}


GEGDIFont::GEGDIFont()
: gdi_font_(NULL)
{
	type_ = FontType_GDIFont;
}

GEGDIFont::~GEGDIFont()
{
}

bool GEGDIFont::_init_font()
{
	ZeroMemory(&gdi_font_desc_, sizeof(LOGFONT));
	gdi_font_desc_.lfHeight		= size_;
	gdi_font_desc_.lfWeight		= weight_;
	gdi_font_desc_.lfCharSet	= charset_;
	gdi_font_desc_.lfItalic		= italic_;
	gdi_font_desc_.lfStrikeOut	= strikeout_;
	gdi_font_desc_.lfUnderline	= underline_;
	gdi_font_desc_.lfQuality	= ANTIALIASED_QUALITY;
	strcpy_s(gdi_font_desc_.lfFaceName, face_);

	destory();
	gdi_font_ = CreateFontIndirect(&gdi_font_desc_);
	return INVALID_HANDLE_VALUE != gdi_font_;
}

void GEGDIFont::destory()
{
	if (gdi_font_) CloseHandle(gdi_font_);
	gdi_font_ = NULL;
}

HFONT GEGDIFont::get_gdi_obj()
{
	return gdi_font_;
}

}