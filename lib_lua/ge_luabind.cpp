/*
** Lua binding: luabind
** Generated automatically by tolua++-1.0.92 on 03/18/14 13:46:56.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luabind_open (lua_State* tolua_S);

#include "ge_luabind.h"
ge::GEApp*		ptr_ge_app;
ge::GEEngine*	ptr_ge_engine;
ge::GEGame*	ptr_ge_game;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ge::GEApp");
 tolua_usertype(tolua_S,"ge::GEObject");
 tolua_usertype(tolua_S,"ge::GEInput");
 tolua_usertype(tolua_S,"ge::GEGame");
 tolua_usertype(tolua_S,"ge::GEScene");
}

/* method: get_instance of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_get_instance00
static int tolua_luabind_ge_GEApp_get_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEApp* tolua_ret = (ge::GEApp*)  ge::GEApp::get_instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEApp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_run00
static int tolua_luabind_ge_GEApp_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEApp* self = (ge::GEApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_input of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_get_input00
static int tolua_luabind_ge_GEApp_get_input00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEApp* self = (ge::GEApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_input'", NULL);
#endif
  {
   ge::GEInput* tolua_ret = (ge::GEInput*)  self->get_input();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEInput");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_input'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_fps of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_get_fps00
static int tolua_luabind_ge_GEApp_get_fps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEApp* self = (ge::GEApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_fps'", NULL);
#endif
  {
   float tolua_ret = (float)  self->get_fps();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_fps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show_console of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_show_console00
static int tolua_luabind_ge_GEApp_show_console00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEApp* self = (ge::GEApp*)  tolua_tousertype(tolua_S,1,0);
  bool is_show = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show_console'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show_console(is_show);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show_console'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_console_show of class  ge::GEApp */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEApp_get_console_show00
static int tolua_luabind_ge_GEApp_get_console_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEApp* self = (ge::GEApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_console_show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_console_show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_console_show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_instance of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_get_instance00
static int tolua_luabind_ge_GEGame_get_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEGame* tolua_ret = (ge::GEGame*)  ge::GEGame::get_instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEGame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_scene of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_add_scene00
static int tolua_luabind_ge_GEGame_add_scene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
  ge::GEScene* ge_scene = ((ge::GEScene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_scene'", NULL);
#endif
  {
   int tolua_ret = (int)  self->add_scene(ge_scene);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_scene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_valid_scene of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_is_valid_scene00
static int tolua_luabind_ge_GEGame_is_valid_scene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
  int scene_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_valid_scene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_valid_scene(scene_id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_valid_scene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_scene of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_get_scene00
static int tolua_luabind_ge_GEGame_get_scene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
  int scene_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_scene'", NULL);
#endif
  {
   ge::GEScene* tolua_ret = (ge::GEScene*)  self->get_scene(scene_id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_scene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: switch_scene of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_switch_scene00
static int tolua_luabind_ge_GEGame_switch_scene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
  int scene_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'switch_scene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->switch_scene(scene_id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'switch_scene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove_scene of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_remove_scene00
static int tolua_luabind_ge_GEGame_remove_scene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
  int scene_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove_scene'", NULL);
#endif
  {
   self->remove_scene(scene_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove_scene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove_all_scenes of class  ge::GEGame */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGame_remove_all_scenes00
static int tolua_luabind_ge_GEGame_remove_all_scenes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGame* self = (ge::GEGame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove_all_scenes'", NULL);
#endif
  {
   self->remove_all_scenes();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove_all_scenes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_mouse_move of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_mouse_move00
static int tolua_luabind_ge_GEInput_get_mouse_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  int delta_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int delta_y = ((int)  tolua_tonumber(tolua_S,3,0));
  int delta_z = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_mouse_move'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_mouse_move(delta_x,delta_y,delta_z);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)delta_x);
   tolua_pushnumber(tolua_S,(lua_Number)delta_y);
   tolua_pushnumber(tolua_S,(lua_Number)delta_z);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_mouse_move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_mouse_pos of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_mouse_pos00
static int tolua_luabind_ge_GEInput_get_mouse_pos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  int pos_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int pos_y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_mouse_pos'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_mouse_pos(pos_x,pos_y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)pos_x);
   tolua_pushnumber(tolua_S,(lua_Number)pos_y);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_mouse_pos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_key_down of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_key_down00
static int tolua_luabind_ge_GEInput_get_key_down00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char key = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_key_down'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_key_down(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_key_down'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_mouse_down of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_mouse_down00
static int tolua_luabind_ge_GEInput_get_mouse_down00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char button = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_mouse_down'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_mouse_down(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_mouse_down'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_key_hold of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_key_hold00
static int tolua_luabind_ge_GEInput_get_key_hold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char key = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_key_hold'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_key_hold(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_key_hold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_mouse_hold of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_mouse_hold00
static int tolua_luabind_ge_GEInput_get_mouse_hold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char button = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_mouse_hold'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_mouse_hold(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_mouse_hold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_key_up of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_key_up00
static int tolua_luabind_ge_GEInput_get_key_up00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char key = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_key_up'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_key_up(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_key_up'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_mouse_up of class  ge::GEInput */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEInput_get_mouse_up00
static int tolua_luabind_ge_GEInput_get_mouse_up00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEInput* self = (ge::GEInput*)  tolua_tousertype(tolua_S,1,0);
  char button = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_mouse_up'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get_mouse_up(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_mouse_up'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_object of class  ge::GEScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEScene_add_object00
static int tolua_luabind_ge_GEScene_add_object00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"ge::GEObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEScene* self = (ge::GEScene*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
  ge::GEObject* obj = ((ge::GEObject*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_object'", NULL);
#endif
  {
   self->add_object(key,obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_object'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove_object of class  ge::GEScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEScene_remove_object00
static int tolua_luabind_ge_GEScene_remove_object00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEScene* self = (ge::GEScene*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove_object'", NULL);
#endif
  {
   self->remove_object(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove_object'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  ge::GEObject */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEObject_init00
static int tolua_luabind_ge_GEObject_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEObject* self = (ge::GEObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory of class  ge::GEObject */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEObject_destory00
static int tolua_luabind_ge_GEObject_destory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEObject* self = (ge::GEObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory'", NULL);
#endif
  {
   self->destory();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_luabind_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"ge",0);
  tolua_beginmodule(tolua_S,"ge");
   tolua_cclass(tolua_S,"GEApp","ge::GEApp","",NULL);
   tolua_beginmodule(tolua_S,"GEApp");
    tolua_function(tolua_S,"get_instance",tolua_luabind_ge_GEApp_get_instance00);
    tolua_function(tolua_S,"run",tolua_luabind_ge_GEApp_run00);
    tolua_function(tolua_S,"get_input",tolua_luabind_ge_GEApp_get_input00);
    tolua_function(tolua_S,"get_fps",tolua_luabind_ge_GEApp_get_fps00);
    tolua_function(tolua_S,"show_console",tolua_luabind_ge_GEApp_show_console00);
    tolua_function(tolua_S,"get_console_show",tolua_luabind_ge_GEApp_get_console_show00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEGame","ge::GEGame","",NULL);
   tolua_beginmodule(tolua_S,"GEGame");
    tolua_function(tolua_S,"get_instance",tolua_luabind_ge_GEGame_get_instance00);
    tolua_function(tolua_S,"add_scene",tolua_luabind_ge_GEGame_add_scene00);
    tolua_function(tolua_S,"is_valid_scene",tolua_luabind_ge_GEGame_is_valid_scene00);
    tolua_function(tolua_S,"get_scene",tolua_luabind_ge_GEGame_get_scene00);
    tolua_function(tolua_S,"switch_scene",tolua_luabind_ge_GEGame_switch_scene00);
    tolua_function(tolua_S,"remove_scene",tolua_luabind_ge_GEGame_remove_scene00);
    tolua_function(tolua_S,"remove_all_scenes",tolua_luabind_ge_GEGame_remove_all_scenes00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEInput","ge::GEInput","",NULL);
   tolua_beginmodule(tolua_S,"GEInput");
    tolua_function(tolua_S,"get_mouse_move",tolua_luabind_ge_GEInput_get_mouse_move00);
    tolua_function(tolua_S,"get_mouse_pos",tolua_luabind_ge_GEInput_get_mouse_pos00);
    tolua_function(tolua_S,"get_key_down",tolua_luabind_ge_GEInput_get_key_down00);
    tolua_function(tolua_S,"get_mouse_down",tolua_luabind_ge_GEInput_get_mouse_down00);
    tolua_function(tolua_S,"get_key_hold",tolua_luabind_ge_GEInput_get_key_hold00);
    tolua_function(tolua_S,"get_mouse_hold",tolua_luabind_ge_GEInput_get_mouse_hold00);
    tolua_function(tolua_S,"get_key_up",tolua_luabind_ge_GEInput_get_key_up00);
    tolua_function(tolua_S,"get_mouse_up",tolua_luabind_ge_GEInput_get_mouse_up00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEScene","ge::GEScene","",NULL);
   tolua_beginmodule(tolua_S,"GEScene");
    tolua_function(tolua_S,"add_object",tolua_luabind_ge_GEScene_add_object00);
    tolua_function(tolua_S,"remove_object",tolua_luabind_ge_GEScene_remove_object00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEObject","ge::GEObject","",NULL);
   tolua_beginmodule(tolua_S,"GEObject");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEObject_init00);
    tolua_function(tolua_S,"destory",tolua_luabind_ge_GEObject_destory00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luabind (lua_State* tolua_S) {
 return tolua_luabind_open(tolua_S);
};
#endif

