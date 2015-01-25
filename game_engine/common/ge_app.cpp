#include "ge_app.h"
#include "ge_game.h"
#include "audio/ge_audio.h"
#include "utility/ge_time.h"

namespace ge
{

Application::Application()
	:is_app_created_(false)
{
	p_ge_game_ = GEGame::get_instance();
	//p_ge_engine_ = GEEngine::get_instance();
}

Application::~Application()
{
}

Application* Application::get_instance()
{
	static Application _global_ge_app;
	return &_global_ge_app;
}

LRESULT CALLBACK Application::WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	ge::Application* _g_p_ge_app = ge::Application::get_instance();
	if(_g_p_ge_app)
	{
		BOOL use_def_win_proc = TRUE;
		LRESULT ge_win_proc_ret = 0;
		ge_win_proc_ret = _g_p_ge_app->MsgProc( uMsg, wParam, lParam, use_def_win_proc );
		if (!use_def_win_proc) return ge_win_proc_ret;
	}

	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

LRESULT Application::MsgProc( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bUseDefWindowsProc )
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		if( wParam == SIZE_RESTORED || wParam == SIZE_MAXIMIZED )
		{
			on_resize();
		}
		else if( wParam == SIZE_MAXHIDE || wParam == SIZE_MINIMIZED )
		{
			// The deactivate message will pause the app
		}
		return 0;
	}

	return 0;
}

LRESULT Application::MainLoop()
{
	MSG  msg;
	PeekMessage( &msg, NULL, 0U, 0U, PM_NOREMOVE );
	HACCEL h_accel = LoadAccelerators( NULL, MAKEINTRESOURCE(0) );

	while( WM_QUIT != msg.message  )
	{
		BOOL has_msg = PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE );

		if (has_msg)
		{
			if( 0 == TranslateAccelerator( h_app_wnd_, h_accel, &msg ) )
			{
				if (PreTranslateMessage(&msg))
				{
					TranslateMessage( &msg );
					DispatchMessage( &msg );
				}
			}
		}
		else
		{
			this->_process();
		}
	}
	return 0;
}

bool Application::create_app( HINSTANCE h_app_inst, const char* title, int width, int height )
{
	h_app_inst_ = h_app_inst;

	WNDCLASS wnd_class;
	ZeroMemory(&wnd_class, sizeof(wnd_class));
	wnd_class.lpszClassName	= "DxApp Window";
	wnd_class.lpfnWndProc	= (WNDPROC) Application::WndProc;
	wnd_class.style			= CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;
	wnd_class.hInstance		= h_app_inst;
	wnd_class.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wnd_class.hbrBackground	= (HBRUSH) (COLOR_WINDOW + 1);
	wnd_class.lpszMenuName	= NULL;
	wnd_class.cbClsExtra	= 0;
	wnd_class.cbWndExtra	= 0;

	BOOL ret = TRUE;

	ret = RegisterClass( &wnd_class );
	if(!ret) return false;

	RECT wnd_rect;
	wnd_rect.top = 0;
	wnd_rect.left = 0;
	wnd_rect.bottom = height;
	wnd_rect.right = width;

	ret = AdjustWindowRect(&wnd_rect, DEF_WND_STYLE, FALSE);
	if(!ret) return false;

	RECT work_area_rect;
	if(!SystemParametersInfo(SPI_GETWORKAREA, 0, &work_area_rect, 0))
		return false;

	int wnd_width = wnd_rect.right - wnd_rect.left;
	int wnd_height = wnd_rect.bottom - wnd_rect.top;
	int work_area_width = work_area_rect.right - work_area_rect.left;
	int work_area_height = work_area_rect.bottom - work_area_rect.top;

	int pos_x = (work_area_width - wnd_width) / 2;
	int pos_y = (work_area_height - wnd_height) / 2;

	h_app_wnd_ = CreateWindow("DxApp Window", title, DEF_WND_STYLE,
		pos_x,
		pos_y,
		wnd_width,
		wnd_height,
		0L, 0L, h_app_inst, 0L);
	if (h_app_wnd_ == NULL) return false;

	//GetClientRect(h_app_wnd_, &game_rect_);
	UpdateWindow(h_app_wnd_);
	ShowWindow(h_app_wnd_, SW_NORMAL);

	Time::init();

	is_app_created_ = true;
	return true;
}

void Application::_process()
{
	Time::update();
	_update_fps();
	Input::update();
	Audio::update();

	if (p_ge_game_ != NULL)
	{
		p_ge_game_->process();

		//p_ge_engine_ = GEEngine::get_instance();
		//if (p_ge_engine_ != NULL)
		//{
		//	p_ge_engine_->process();
		//}
	}
	::Sleep(0);
}

void Application::_update_fps()
{
	++ frame_cnt_;
	float delta = Time::get_real_delta_time();
	fps_elapsed_ += delta;

	if (fps_elapsed_ >= 1.0f)
	{
		fps_ = float(frame_cnt_) / fps_elapsed_;
		fps_elapsed_ = 0.f;
		frame_cnt_ = 0;
	}
}

bool Application::on_resize()
{
	//GetClientRect(h_app_wnd_, &game_rect_);

	//int width = game_rect_.right - game_rect_.left;
	//int height = game_rect_.bottom - game_rect_.top;

	//if (p_ge_engine_)
	//{
	//	p_ge_engine_->set_resolution(width, height);
	//}

	InvalidateRect(h_app_wnd_, 0, false);

	return true;
}

bool Application::init()
{
	Input::init();
	Audio::init();
	return true;
}

void Application::destory()
{
	Input::destory();
	Audio::destory();
}



}
