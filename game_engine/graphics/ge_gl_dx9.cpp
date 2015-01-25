#include "ge_gl_dx9.h"

#define D3D_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } } 

namespace ge
{

bool GL_DX9::initialize(int width, int height, bool is_windowed, bool vsync)
{
	if (is_initialized) finalize();

	HRESULT h_res = S_OK;

	LPDIRECT3D9 p_d3d = NULL;
	p_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (NULL == p_d3d) return false;

	UINT adapter_type = D3DADAPTER_DEFAULT;
	D3DDEVTYPE dev_type = D3DDEVTYPE_HAL;
	D3DCAPS9 d3d_caps;
	h_res = p_d3d->GetDeviceCaps(adapter_type, dev_type, &d3d_caps);
	if (FAILED(h_res))
	{
		dev_type = D3DDEVTYPE_REF;
		h_res = p_d3d->GetDeviceCaps(adapter_type, dev_type, &d3d_caps);

		if (FAILED(h_res))
		{
			D3D_RELEASE(p_d3d);
			return false;
		}
	}

	LONG vertex_proc_type = 0L;
	if (d3d_caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vertex_proc_type = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vertex_proc_type = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	HWND p_wnd = NULL;

	ZeroMemory(&d3d_present_param_, sizeof(d3d_present_param_));
	d3d_present_param_.BackBufferWidth = width;
	d3d_present_param_.BackBufferHeight = height;
	d3d_present_param_.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3d_present_param_.BackBufferCount = 2;
	d3d_present_param_.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3d_present_param_.MultiSampleQuality = 0;
	d3d_present_param_.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3d_present_param_.hDeviceWindow = p_wnd;
	d3d_present_param_.Windowed = is_windowed;
	d3d_present_param_.EnableAutoDepthStencil = TRUE;
	d3d_present_param_.AutoDepthStencilFormat = D3DFMT_D24X8;
	d3d_present_param_.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
	d3d_present_param_.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	// vsync
	if (vsync)
	{
		d3d_present_param_.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	}
	else
	{
		d3d_present_param_.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	}
	
	h_res = p_d3d->CreateDevice(D3DADAPTER_DEFAULT,
		dev_type, p_wnd, vertex_proc_type,
		&d3d_present_param_, &d3d_device_);

	if (FAILED(h_res))
	{
		D3D_RELEASE(p_d3d);
		return false;
	}

	D3D_RELEASE(p_d3d);
	is_initialized = true;
	return true;
}

void GL_DX9::finalize()
{
	if (is_initialized)
	{
		D3D_RELEASE(d3d_device_);
		d3d_device_ = NULL;
		is_initialized = false;
	}
}


bool GL_DX9::_d3d_begin_scene()
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	HRESULT h_res = d3d_device_->BeginScene();
	return SUCCEEDED(h_res);
}

bool GL_DX9::_d3d_end_scene()
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	HRESULT h_res = d3d_device_->EndScene();
	return SUCCEEDED(h_res);
}

bool GL_DX9::_d3d_clear(bool clear_depth, bool clear_color, const Color& background_color, float depth /*= 1.0f*/)
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	DWORD flags = 0;
	if (clear_color) flags |= D3DCLEAR_TARGET;
	if (clear_depth) flags |= D3DCLEAR_ZBUFFER;

	HRESULT h_res = d3d_device_->Clear(
		0,
		NULL,
		flags,
		(D3DCOLOR)Color32(background_color).argb,
		depth,
		0L);
	return SUCCEEDED(h_res);
}

bool GL_DX9::_d3d_present()
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	HRESULT h_res = d3d_device_->Present(NULL, NULL, NULL, NULL);
	return SUCCEEDED(h_res);
}

bool GL_DX9::change_resolution(int width, int height)
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	unsigned old_width = d3d_present_param_.BackBufferWidth;
	unsigned old_height = d3d_present_param_.BackBufferHeight;

	if (width <= 0) width = 1;
	if (height <= 0) height = 1;

	if (width != old_width || height != old_height)
	{
		d3d_present_param_.BackBufferWidth = (unsigned)width;
		d3d_present_param_.BackBufferHeight = (unsigned)height;

		if (!_d3d_reset()) return false;
	}
	return true;
}

bool GL_DX9::change_windowed(bool is_windowed)
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;
	
	bool old_is_windowed_ = !!d3d_present_param_.Windowed;

	if (is_windowed != old_is_windowed_)
	{
		d3d_present_param_.Windowed = is_windowed;

		if (!_d3d_reset()) return false;
	}
	return true;
}

bool GL_DX9::_d3d_reset()
{
	_on_lost_device();
	if (_on_reset_present_param())
	{
		_on_reset_device();
		return true;
	}
	return false;
}

bool GL_DX9::_d3d_check()
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	HRESULT h_res = d3d_device_->TestCooperativeLevel();

	if (h_res == D3DERR_DEVICELOST)
	{
		return false;
	}
	else if (h_res == D3DERR_DEVICENOTRESET)
	{
		return _d3d_reset();
	}
	else if (FAILED(h_res))
	{
		return false;
	}
	return true;
}

bool GL_DX9::_on_reset_present_param()
{
	if (!is_initialized) return false;
	if (d3d_device_ == NULL) return false;

	if (d3d_device_ == NULL) return false;
	HRESULT h_res = d3d_device_->Reset(&d3d_present_param_);
	return SUCCEEDED(h_res);
}

bool GL_DX9::_on_lost_device()
{
	if (!is_initialized) return false;

	typedef std::hash_map<void*, void_callback> CallbackHashset;
	FOR_EACH(CallbackHashset, lost_device_functions, itor)
	{
		if (itor->second != nullptr)
		{
			(itor->second)();
		}
	}
	return true;
}

bool GL_DX9::_on_reset_device()
{
	if (!is_initialized) return false;

	typedef std::hash_map<void*, void_callback> CallbackHashset;
	FOR_EACH(CallbackHashset, reset_device_functions, itor)
	{
		if (itor->second != nullptr)
		{
			(itor->second)();
		}
	}
	return true;
}

void GL_DX9::register_d3d_device_object(void* obj, void_callback lost_device_func, void_callback reset_device_func)
{
	lost_device_functions[obj] = lost_device_func;
	reset_device_functions[obj] = reset_device_func;
}

void GL_DX9::unregister_d3d_device_object(void* obj)
{
	lost_device_functions.erase(obj);
	reset_device_functions.erase(obj);
}



}
