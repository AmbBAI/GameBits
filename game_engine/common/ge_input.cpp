#include "ge_input.h"
#include "ge_app.h"

namespace ge
{
Input::Input()
: p_input_(NULL)
, p_keyboard_device_(NULL)
, p_mouse_device_(NULL)
, current_state_(0)
{

}

Input::~Input()
{
	destory_input();
}

Input* Input::get_instance()
{
	static Input _global_ge_input_;
	return &_global_ge_input_;
}

bool Input::init_input()
{
	Application* p_app = Application::get_instance();
	if (p_app == NULL) return false;
	HINSTANCE h_app_inst = p_app->get_app_inst();
	if (h_app_inst == NULL) return false;
	HWND h_wnd = p_app->get_app_wnd();
	if (h_wnd == NULL) return false;

	HRESULT h_res = S_OK;
	h_res = DirectInput8Create(h_app_inst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&p_input_, NULL);

	if (FAILED(h_res)) return false;

	h_res = p_input_->CreateDevice(GUID_SysKeyboard, &p_keyboard_device_, NULL);
	h_res = p_keyboard_device_->SetDataFormat(&c_dfDIKeyboard);
	h_res = p_keyboard_device_->SetCooperativeLevel(h_wnd, DEFINE_INPUT_DISL);
	h_res = p_keyboard_device_->Acquire();

	h_res = p_input_->CreateDevice(GUID_SysMouse, &p_mouse_device_, 0);
	h_res = p_mouse_device_->SetDataFormat(&c_dfDIMouse2);
	h_res = p_mouse_device_->SetCooperativeLevel(h_wnd, DEFINE_INPUT_DISL);
	h_res = p_mouse_device_->Acquire();

	return SUCCEEDED(h_res);
}

void Input::destory_input()
{
	if (p_keyboard_device_) p_keyboard_device_->Unacquire();
	if (p_mouse_device_) p_mouse_device_->Unacquire();

	if (p_keyboard_device_) p_keyboard_device_->Release();
	p_keyboard_device_ = nullptr;
	if (p_mouse_device_) p_mouse_device_->Release();
	p_mouse_device_ = nullptr;
	if (p_input_) p_input_->Release();
	p_input_ = nullptr;
}

void Input::update_input()
{
	HRESULT h_res = S_OK;
	unsigned _cs = (current_state_ ^= 1);

	if (p_keyboard_device_ != NULL)
	{
		h_res = p_keyboard_device_->GetDeviceState(sizeof(keyboard_state_[_cs]), (void**)&(keyboard_state_[_cs]));
		if (FAILED(h_res))
		{
			h_res = p_keyboard_device_->Acquire();
			h_res = p_keyboard_device_->GetDeviceState(sizeof(keyboard_state_[_cs]), (void**)&(keyboard_state_[_cs]));
			if (FAILED(h_res))
			{
				memset(keyboard_state_[_cs], 0, sizeof(keyboard_state_[_cs]));
				h_res = p_keyboard_device_->Acquire();
			}
		}
	}

	if (p_mouse_device_ != NULL)
	{
		h_res = p_mouse_device_->GetDeviceState(sizeof(mouse_state_[_cs]), (void**)&mouse_state_[_cs]);
		if (FAILED(h_res))
		{
			h_res = p_mouse_device_->Acquire();
			h_res = p_mouse_device_->GetDeviceState(sizeof(mouse_state_[_cs]), (void**)&mouse_state_[_cs]);
			if (FAILED(h_res))
			{
				memset(&mouse_state_[_cs], 0, sizeof(mouse_state_[_cs]));
				h_res = p_mouse_device_->Acquire();
			}
		}
	}
}

bool ge::Input::get_mouse_move( int& delta_x, int& delta_y, int& delta_z )
{
	delta_x = mouse_state_[current_state_].lX;
	delta_y = mouse_state_[current_state_].lY;
	delta_z = mouse_state_[current_state_].lZ;
	return true;
}

bool Input::get_mouse_pos( int& pos_x, int& pos_y )
{
	POINT mouse_pos;
	GetCursorPos(&mouse_pos);
	
	HWND h_wnd = Application::get_instance()->get_app_wnd();
	if (h_wnd != NULL) ScreenToClient(h_wnd, &mouse_pos);

	pos_x = mouse_pos.x;
	pos_y = mouse_pos.y;
	return true;
}

bool Input::get_key_down(GEKeyCode key)
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (keyboard_state_[_cs][key] & 0x80);
	bool old_on = 0 != (keyboard_state_[1^_cs][key] & 0x80);

	return (cur_on) && (!old_on);
}

bool Input::get_mouse_down( char button )
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (mouse_state_[_cs].rgbButtons[(unsigned char)button] & 0x80);
	bool old_on = 0 != (mouse_state_[1^_cs].rgbButtons[(unsigned char)button] & 0x80);

	return (cur_on) && (!old_on);
}

bool Input::get_key_hold( GEKeyCode key )
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (keyboard_state_[_cs][key] & 0x80);
	bool old_on = 0 != (keyboard_state_[1^_cs][key] & 0x80);

	return (cur_on) && (old_on);
}

bool Input::get_mouse_hold( char button )
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (mouse_state_[_cs].rgbButtons[(unsigned char)button] & 0x80);
	bool old_on = 0 != (mouse_state_[1^_cs].rgbButtons[(unsigned char)button] & 0x80);

	return (cur_on) && (old_on);
}

bool Input::get_key_up( GEKeyCode key )
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (keyboard_state_[_cs][key] & 0x80);
	bool old_on = 0 != (keyboard_state_[1^_cs][key] & 0x80);

	return (!cur_on) && (old_on);
}

bool Input::get_mouse_up( char button )
{
	unsigned _cs = current_state_;
	bool cur_on = 0 != (mouse_state_[_cs].rgbButtons[(unsigned char)button] & 0x80);
	bool old_on = 0 != (mouse_state_[1^_cs].rgbButtons[(unsigned char)button] & 0x80);

	return (!cur_on) && (old_on);
}

bool Input::init()
{
	return get_instance()->init_input();
}

void Input::destory()
{
	get_instance()->destory_input();
}

void Input::update()
{
	get_instance()->update_input();
}

}


