#ifndef _GAME_ENGINE_COMMON_INPUT_H_
#define _GAME_ENGINE_COMMON_INPUT_H_

#include "../common/ge_include.h"

namespace ge
{

#define DEFINE_INPUT_DISL ( DISCL_NONEXCLUSIVE | DISCL_FOREGROUND )

class GEApp;

class GE_API GEInput
{
	friend GEApp;

protected:
	GEInput();
	virtual ~GEInput();

public:
	bool init();
	void destory();

	void update();

public:
	bool get_mouse_move(int& delta_x, int& delta_y, int& delta_z);
	bool get_mouse_pos(int& pos_x, int& pos_y);

	bool get_key_down(char key);
	bool get_mouse_down(char button);

	bool get_key_hold(char key);
	bool get_mouse_hold(char button);

	bool get_key_up(char key);
	bool get_mouse_up(char button);

private:
	LPDIRECTINPUT			p_input_;
	LPDIRECTINPUTDEVICE		p_keyboard_device_;
	char					keyboard_state_[2][256];

	LPDIRECTINPUTDEVICE		p_mouse_device_;
	DIMOUSESTATE2			mouse_state_[2];

	unsigned				current_state_;
};

}

#endif // _GAME_ENGINE_COMMON_INPUT_H_