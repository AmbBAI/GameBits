#ifndef _GAME_ENGINE_OBJECT_FONT_H_
#define _GAME_ENGINE_OBJECT_FONT_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"
#include "common/ge_engine.h"
#include "ge_font_manager.h"

namespace ge
{

class GE_API GEFont
{
public:
	GEFont();
	virtual ~GEFont();

public:
	virtual void destory();

protected:
	virtual bool _init_font();

public:
	GEFontType	type_;

	char		face_[32];
	int			size_;
	int			charset_;
	int			weight_;
	bool		italic_;
	bool		underline_;
	bool		strikeout_;
};

class GE_API GED3DXFont : public GEFont, GED3DDeviceObject
{
public:
	GED3DXFont();
	virtual ~GED3DXFont();

	virtual void on_lost_device();
	virtual void on_reset_device();

public:
	bool init(const char* font, int size);
	LPD3DXFONT get_d3dx_obj();

	virtual void destory();

protected:
	virtual bool _init_font();

private:
	D3DXFONT_DESC	d3dx_font_desc_;
	LPD3DXFONT		d3dx_font_;
};

class GE_API GEGDIFont : public GEFont
{
public:
	GEGDIFont();
	virtual ~GEGDIFont();

public:
	bool init(const char* font, int size);
	HFONT get_gdi_obj();

	virtual void destory();

protected:
	virtual bool _init_font();

private:
	LOGFONT			gdi_font_desc_;
	HFONT			gdi_font_;
};


} // namespace ge

#endif // _GAME_ENGINE_OBJECT_FONT_H_