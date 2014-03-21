#ifndef _GAME_ENGINE_LUA_ENGINE_H_
#define _GAME_ENGINE_LUA_ENGINE_H_

#include "../common/ge_include.h"
#include "ge_lua_bind.h"

namespace ge
{

class GE_API GELuaEngine
{

protected:
	GELuaEngine();
	virtual ~GELuaEngine();

public:
	static GELuaEngine* get_instance();

	bool open();
	void close();

	bool run_script(const char* path);
	int run_function(LUA_FUNCTION func_id, int args_cnt);

	void report_error();

protected:
	int _execute_function(int args_cnt);

private:
	lua_State*	lua_state_;

};

} // namespace ge

#endif // _GAME_ENGINE_LUA_ENGINE_H_