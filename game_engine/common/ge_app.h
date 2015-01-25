#ifndef _GAME_ENGINE_APP_H_
#define _GAME_ENGINE_APP_H_

#include "ge_include.h"
#include "ge_input.h"
#include "utility/ge_type.h"


namespace ge
{

class GEGame;
class GE_API Application
{
	friend Input;

protected:
	Application();
	virtual ~Application();

public:
	static Application* get_instance();

	bool create_app(HINSTANCE h_instance, const char* wnd_title, int wnd_width, int wnd_height);
	void run() { MainLoop(); }

	bool init();
	void destory();

	bool		is_app_created()	{ return is_app_created_; }
	GE_IRECT&	get_game_rect()		{ return game_rect_; }	
	float		get_fps()			{ return fps_; }

	bool		show_console(bool is_show);
	bool		get_console_show()	{ return is_console_show_; }
	
	bool		on_resize();

protected:
	void		_update_fps();
	void		_process();

	HINSTANCE	get_app_inst()		{ return h_app_inst_; }	
	HWND		get_app_wnd()		{ return h_app_wnd_; }

	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	LRESULT	MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bUseDefWindowsProc);
	BOOL	PreTranslateMessage(MSG* uMsg) {return TRUE;}
	LRESULT	MainLoop();

private:
	HWND		h_app_wnd_;
	HINSTANCE	h_app_inst_;

	GE_IRECT	game_rect_;
	bool		is_app_created_;

	bool		is_console_show_;

	float		fps_;
	float		fps_elapsed_;
	int			frame_cnt_;

	GEGame*		p_ge_game_;

	int			mouse_x_;
	int			mouse_y_;
};

} // namespace ge

#endif // _GAME_ENGINE_APP_H_