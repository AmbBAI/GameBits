#ifndef _GAME_ENGINE_LUA_BIND_H_
#define _GAME_ENGINE_LUA_BIND_H_

extern "C"
{
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"

#include "tolua/tolua++.h"
#include "tolua/tolua_fix.h"

};

typedef int LUA_FUNCTION;
typedef int LUA_TABLE;

#include "../game_engine.h"

TOLUA_API int  tolua_luabind_open (lua_State* tolua_S);

#endif // _GAME_ENGINE_LUA_BIND_H_