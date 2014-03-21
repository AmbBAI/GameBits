#include "game_engine.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	static ge::GEApp* g_p_ge_app = NULL;
	static ge::GEEngine* g_p_ge_engine = NULL;
	static ge::GEGame* g_p_ge_game = NULL;
	static ge::GELuaEngine* g_p_ge_lua_engine = NULL;
	g_p_ge_app = ge::GEApp::get_instance();
	g_p_ge_engine = ge::GEEngine::get_instance();
	g_p_ge_game = ge::GEGame::get_instance();
	g_p_ge_lua_engine = ge::GELuaEngine::get_instance();

	bool init_ok = true;
	init_ok = init_ok && g_p_ge_app->create_app(hInstance, "Hello World!", 800, 600);
	init_ok = init_ok && g_p_ge_engine->init_engine();

	if (init_ok)
	{
		g_p_ge_app->show_console(true);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		g_p_ge_lua_engine->open();
		g_p_ge_lua_engine->run_script("lua\\main.lua");
		g_p_ge_lua_engine->report_error();
		g_p_ge_lua_engine->close();
	}

	g_p_ge_engine->close_engine();
	return 0;
}