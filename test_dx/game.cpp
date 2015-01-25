#include "game_engine.h"
#include "script/ge_lua_engine.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	static ge::Application* g_p_ge_app = NULL;
	//static ge::GEGame* g_p_ge_game = NULL;
	//static ge::GELuaEngine* g_p_ge_lua_engine = NULL;
	g_p_ge_app = ge::Application::get_instance();
	////g_p_ge_game = ge::GEGame::get_instance();
	//g_p_ge_lua_engine = ge::GELuaEngine::get_instance();

	bool init_ok = true;
	init_ok = init_ok && g_p_ge_app->create_app(hInstance, "Hello World!", 800, 600);
	init_ok = init_ok && g_p_ge_app->init();

	if (init_ok)
	{
		g_p_ge_app->show_console(true);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		ge::GameObject* obj = ge::GameObject::create();
		ge::Mesh* mesh = (ge::Mesh*)obj->add_component("Mesh");

		g_p_ge_app->run();
		/*g_p_ge_lua_engine->open();
		bool ret = g_p_ge_lua_engine->run_script("lua\\main.lua");
		assert(ret);
		g_p_ge_lua_engine->close();*/
	}

	g_p_ge_app->destory();
	return 0;
}