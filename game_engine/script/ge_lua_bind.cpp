/*
** Lua binding: luabind
** Generated automatically by tolua++-1.0.92 on 04/01/14 16:51:34.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua/tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luabind_open (lua_State* tolua_S);

#include "ge_lua_bind.h"
#include "../game_engine.h"
#include "lua_object/ge_lua_scene.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ge__GE_IPOINT (lua_State* tolua_S)
{
 ge::GE_IPOINT* self = (ge::GE_IPOINT*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_FSIZE (lua_State* tolua_S)
{
 ge::GE_FSIZE* self = (ge::GE_FSIZE*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_FRECT (lua_State* tolua_S)
{
 ge::GE_FRECT* self = (ge::GE_FRECT*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_FPOINT (lua_State* tolua_S)
{
 ge::GE_FPOINT* self = (ge::GE_FPOINT*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_ISIZE (lua_State* tolua_S)
{
 ge::GE_ISIZE* self = (ge::GE_ISIZE*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_IRECT (lua_State* tolua_S)
{
 ge::GE_IRECT* self = (ge::GE_IRECT*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ge__GE_VERTEX_DECL (lua_State* tolua_S)
{
 ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ge::GE_IPOINT");
 tolua_usertype(tolua_S,"ge::GETextureGroup");
 tolua_usertype(tolua_S,"ge::GEPrimitiveDraw");
 tolua_usertype(tolua_S,"ge::GETextureManager");
 tolua_usertype(tolua_S,"ge::GE_VERTEX_DECL");
 tolua_usertype(tolua_S,"ge::GE_FPOINT");
 tolua_usertype(tolua_S,"ge::GEDraw");
 tolua_usertype(tolua_S,"ge::GEOTextFT");
 tolua_usertype(tolua_S,"ge::GEDrawBuff");
 tolua_usertype(tolua_S,"ge::GEAtlasDraw");
 tolua_usertype(tolua_S,"UINT");
 tolua_usertype(tolua_S,"ge::GE_FSIZE");
 tolua_usertype(tolua_S,"ge::GEFontFT");
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"ge::GEVertexDecl");
 tolua_usertype(tolua_S,"ge::GE_IRECT");
 tolua_usertype(tolua_S,"ge::GEGDIFont");
 tolua_usertype(tolua_S,"ge::GEOSpine");
 tolua_usertype(tolua_S,"ge::GEGame");
 tolua_usertype(tolua_S,"ge::GEFont");
 tolua_usertype(tolua_S,"ge::GESurface");
 tolua_usertype(tolua_S,"DWORD");
 tolua_usertype(tolua_S,"ge::GE_QUAD_EX");
 tolua_usertype(tolua_S,"ge::GEInput");
 tolua_usertype(tolua_S,"ge::GEScene");
 tolua_usertype(tolua_S,"D3DCOLOR");
 tolua_usertype(tolua_S,"ge::GE_VERTEX");
 tolua_usertype(tolua_S,"ge::GE_FRECT");
 tolua_usertype(tolua_S,"ge::GEObject");
 tolua_usertype(tolua_S,"ge::GEFontBM");
 tolua_usertype(tolua_S,"ge::GEApp");
 tolua_usertype(tolua_S,"ge::GETexture");
 tolua_usertype(tolua_S,"ge::GE_ISIZE");
 tolua_usertype(tolua_S,"ge::GE_QUAD");
 tolua_usertype(tolua_S,"ge::GELuaScene");
 tolua_usertype(tolua_S,"ge::GEFontManager");
 tolua_usertype(tolua_S,"ge::GEOTextBM");
 tolua_usertype(tolua_S,"ge::GED3DXFont");
 tolua_usertype(tolua_S,"ge::GEOText");
 tolua_usertype(tolua_S,"ge::GEREffect");
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
  ge::GEInput::GEKeyCode key = ((ge::GEInput::GEKeyCode) (int)  tolua_tonumber(tolua_S,2,0));
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
  ge::GEInput::GEKeyCode key = ((ge::GEInput::GEKeyCode) (int)  tolua_tonumber(tolua_S,2,0));
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
  ge::GEInput::GEKeyCode key = ((ge::GEInput::GEKeyCode) (int)  tolua_tonumber(tolua_S,2,0));
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

/* method: create of class  ge::GEScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEScene_create00
static int tolua_luabind_ge_GEScene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEScene* tolua_ret = (ge::GEScene*)  ge::GEScene::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEScene_retain00
static int tolua_luabind_ge_GEScene_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEScene* self = (ge::GEScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEScene_release00
static int tolua_luabind_ge_GEScene_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEScene* self = (ge::GEScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
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

/* method: create of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_create00
static int tolua_luabind_ge_GELuaScene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GELuaScene* tolua_ret = (ge::GELuaScene*)  ge::GELuaScene::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GELuaScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_retain00
static int tolua_luabind_ge_GELuaScene_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_release00
static int tolua_luabind_ge_GELuaScene_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_init_func of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_set_init_func00
static int tolua_luabind_ge_GELuaScene_set_init_func00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION init_func = ((LUA_FUNCTION)  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_init_func'", NULL);
#endif
  {
   self->set_init_func(init_func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_init_func'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_destory_func of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_set_destory_func00
static int tolua_luabind_ge_GELuaScene_set_destory_func00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION destory_func = ((LUA_FUNCTION)  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_destory_func'", NULL);
#endif
  {
   self->set_destory_func(destory_func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_destory_func'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_show_func of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_set_show_func00
static int tolua_luabind_ge_GELuaScene_set_show_func00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION show_func = ((LUA_FUNCTION)  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_show_func'", NULL);
#endif
  {
   self->set_show_func(show_func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_show_func'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_hide_func of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_set_hide_func00
static int tolua_luabind_ge_GELuaScene_set_hide_func00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION hide_func = ((LUA_FUNCTION)  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_hide_func'", NULL);
#endif
  {
   self->set_hide_func(hide_func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_hide_func'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_update_func of class  ge::GELuaScene */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GELuaScene_set_update_func00
static int tolua_luabind_ge_GELuaScene_set_update_func00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GELuaScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GELuaScene* self = (ge::GELuaScene*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION update_func = ((LUA_FUNCTION)  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_update_func'", NULL);
#endif
  {
   self->set_update_func(update_func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_update_func'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GESurface */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GESurface_create00
static int tolua_luabind_ge_GESurface_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GESurface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GESurface* tolua_ret = (ge::GESurface*)  ge::GESurface::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GESurface");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GESurface */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GESurface_retain00
static int tolua_luabind_ge_GESurface_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GESurface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GESurface* self = (ge::GESurface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GESurface */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GESurface_release00
static int tolua_luabind_ge_GESurface_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GESurface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GESurface* self = (ge::GESurface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GETexture */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETexture_create00
static int tolua_luabind_ge_GETexture_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GETexture* tolua_ret = (ge::GETexture*)  ge::GETexture::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETexture");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GETexture */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETexture_retain00
static int tolua_luabind_ge_GETexture_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETexture* self = (ge::GETexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GETexture */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETexture_release00
static int tolua_luabind_ge_GETexture_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETexture* self = (ge::GETexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_create00
static int tolua_luabind_ge_GETextureGroup_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GETextureGroup* tolua_ret = (ge::GETextureGroup*)  ge::GETextureGroup::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETextureGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_retain00
static int tolua_luabind_ge_GETextureGroup_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_release00
static int tolua_luabind_ge_GETextureGroup_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_add_texture00
static int tolua_luabind_ge_GETextureGroup_add_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_texture'", NULL);
#endif
  {
   int tolua_ret = (int)  self->add_texture();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_add_texture01
static int tolua_luabind_ge_GETextureGroup_add_texture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
  ge::GETexture* texture = ((ge::GETexture*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_texture'", NULL);
#endif
  {
   int tolua_ret = (int)  self->add_texture(texture);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GETextureGroup_add_texture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_texture_from_file of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_add_texture_from_file00
static int tolua_luabind_ge_GETextureGroup_add_texture_from_file00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
  const char* texture_path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_texture_from_file'", NULL);
#endif
  {
   int tolua_ret = (int)  self->add_texture_from_file(texture_path);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_texture_from_file'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_get_texture00
static int tolua_luabind_ge_GETextureGroup_get_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
  int texture_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_texture'", NULL);
#endif
  {
   ge::GETexture* tolua_ret = (ge::GETexture*)  self->get_texture(texture_id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETexture");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replace_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_replace_texture00
static int tolua_luabind_ge_GETextureGroup_replace_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
  int texture_id = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* texture_path = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replace_texture'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->replace_texture(texture_id,texture_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replace_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_release_texture00
static int tolua_luabind_ge_GETextureGroup_release_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
  int texture_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release_texture'", NULL);
#endif
  {
   self->release_texture(texture_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_all_texture of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_release_all_texture00
static int tolua_luabind_ge_GETextureGroup_release_all_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release_all_texture'", NULL);
#endif
  {
   self->release_all_texture();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_all_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_texture_cnt of class  ge::GETextureGroup */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureGroup_get_texture_cnt00
static int tolua_luabind_ge_GETextureGroup_get_texture_cnt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* self = (ge::GETextureGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_texture_cnt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->get_texture_cnt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_texture_cnt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_texture of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_create_texture00
static int tolua_luabind_ge_GETextureManager_create_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GETexture* tolua_ret = (ge::GETexture*)  ge::GETextureManager::create_texture();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETexture");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_texture of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_create_texture01
static int tolua_luabind_ge_GETextureManager_create_texture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* texture_path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ge::GETexture* tolua_ret = (ge::GETexture*)  ge::GETextureManager::create_texture(texture_path);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETexture");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GETextureManager_create_texture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: refer_texture of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_refer_texture00
static int tolua_luabind_ge_GETextureManager_refer_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETexture* texture = ((ge::GETexture*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ge::GETextureManager::refer_texture(texture);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refer_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_texture of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_release_texture00
static int tolua_luabind_ge_GETextureManager_release_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETexture* texture = ((ge::GETexture*)  tolua_tousertype(tolua_S,2,0));
  {
   ge::GETextureManager::release_texture(texture);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_texture_group of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_create_texture_group00
static int tolua_luabind_ge_GETextureManager_create_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GETextureGroup* tolua_ret = (ge::GETextureGroup*)  ge::GETextureManager::create_texture_group();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETextureGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: refer_texture_group of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_refer_texture_group00
static int tolua_luabind_ge_GETextureManager_refer_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* texture_group = ((ge::GETextureGroup*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ge::GETextureManager::refer_texture_group(texture_group);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refer_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_texture_group of class  ge::GETextureManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GETextureManager_release_texture_group00
static int tolua_luabind_ge_GETextureManager_release_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GETextureManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GETextureGroup* texture_group = ((ge::GETextureGroup*)  tolua_tousertype(tolua_S,2,0));
  {
   ge::GETextureManager::release_texture_group(texture_group);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_font of class  ge::GEFontManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontManager_create_font00
static int tolua_luabind_ge_GEFontManager_create_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEFontManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontType font_type = ((ge::GEFontType) (int)  tolua_tonumber(tolua_S,2,0));
  {
   ge::GEFont* tolua_ret = (ge::GEFont*)  ge::GEFontManager::create_font(font_type);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_font of class  ge::GEFontManager */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontManager_release_font00
static int tolua_luabind_ge_GEFontManager_release_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEFontManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFont* ptr_font = ((ge::GEFont*)  tolua_tousertype(tolua_S,2,0));
  {
   ge::GEFontManager::release_font(ptr_font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  ge::GED3DXFont */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GED3DXFont_init00
static int tolua_luabind_ge_GED3DXFont_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GED3DXFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GED3DXFont* self = (ge::GED3DXFont*)  tolua_tousertype(tolua_S,1,0);
  const char* font = ((const char*)  tolua_tostring(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(font,size);
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

/* method: init of class  ge::GEGDIFont */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEGDIFont_init00
static int tolua_luabind_ge_GEGDIFont_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEGDIFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEGDIFont* self = (ge::GEGDIFont*)  tolua_tousertype(tolua_S,1,0);
  const char* font = ((const char*)  tolua_tostring(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(font,size);
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

/* method: init of class  ge::GEFontBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontBM_init00
static int tolua_luabind_ge_GEFontBM_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontBM",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontBM* self = (ge::GEFontBM*)  tolua_tousertype(tolua_S,1,0);
  const char* fnt_path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(fnt_path);
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

/* method: init_effect of class  ge::GEFontBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontBM_init_effect00
static int tolua_luabind_ge_GEFontBM_init_effect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontBM",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontBM* self = (ge::GEFontBM*)  tolua_tousertype(tolua_S,1,0);
  const char* fx_path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_effect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_effect(fx_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_effect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_effect of class  ge::GEFontBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontBM_destory_effect00
static int tolua_luabind_ge_GEFontBM_destory_effect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontBM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontBM* self = (ge::GEFontBM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_effect'", NULL);
#endif
  {
   self->destory_effect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_effect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  ge::GEFontFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontFT_init00
static int tolua_luabind_ge_GEFontFT_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontFT",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontFT* self = (ge::GEFontFT*)  tolua_tousertype(tolua_S,1,0);
  const char* face = ((const char*)  tolua_tostring(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(face,size);
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

/* method: init_texture_group of class  ge::GEFontFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontFT_init_texture_group00
static int tolua_luabind_ge_GEFontFT_init_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontFT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontFT* self = (ge::GEFontFT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_texture_group'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_texture_group();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_texture_group of class  ge::GEFontFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontFT_get_texture_group00
static int tolua_luabind_ge_GEFontFT_get_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontFT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontFT* self = (ge::GEFontFT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_texture_group'", NULL);
#endif
  {
   ge::GETextureGroup* tolua_ret = (ge::GETextureGroup*)  self->get_texture_group();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETextureGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_size of class  ge::GEFontFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEFontFT_set_size00
static int tolua_luabind_ge_GEFontFT_set_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEFontFT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEFontFT* self = (ge::GEFontFT*)  tolua_tousertype(tolua_S,1,0);
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_size'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_size(size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_create00
static int tolua_luabind_ge_GEDrawBuff_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEDrawBuff* tolua_ret = (ge::GEDrawBuff*)  ge::GEDrawBuff::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEDrawBuff");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_retain00
static int tolua_luabind_ge_GEDrawBuff_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_release00
static int tolua_luabind_ge_GEDrawBuff_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_vertex_decl of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_set_vertex_decl00
static int tolua_luabind_ge_GEDrawBuff_set_vertex_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_VERTEX_DECL* decl = ((ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_vertex_decl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_vertex_decl(decl);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_vertex_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_vertex_decl of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_get_vertex_decl00
static int tolua_luabind_ge_GEDrawBuff_get_vertex_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_vertex_decl'", NULL);
#endif
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  self->get_vertex_decl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_vertex_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init_vertex_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_init_vertex_buff00
static int tolua_luabind_ge_GEDrawBuff_init_vertex_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  int vertex_cnt = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_vertex_buff'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_vertex_buff(vertex_cnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_vertex_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init_index_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_init_index_buff00
static int tolua_luabind_ge_GEDrawBuff_init_index_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  int index_cnt = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_index_buff'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_index_buff(index_cnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_index_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init_quad_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_init_quad_buff00
static int tolua_luabind_ge_GEDrawBuff_init_quad_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  int quad_cnt = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_quad_buff'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_quad_buff(quad_cnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_quad_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_vertex_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_destory_vertex_buff00
static int tolua_luabind_ge_GEDrawBuff_destory_vertex_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_vertex_buff'", NULL);
#endif
  {
   self->destory_vertex_buff();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_vertex_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_index_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_destory_index_buff00
static int tolua_luabind_ge_GEDrawBuff_destory_index_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_index_buff'", NULL);
#endif
  {
   self->destory_index_buff();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_index_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_buff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_destory_buff00
static int tolua_luabind_ge_GEDrawBuff_destory_buff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_buff'", NULL);
#endif
  {
   self->destory_buff();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_buff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: prepare_drawbuff of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_prepare_drawbuff00
static int tolua_luabind_ge_GEDrawBuff_prepare_drawbuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'prepare_drawbuff'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->prepare_drawbuff();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'prepare_drawbuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_verties of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_set_verties00
static int tolua_luabind_ge_GEDrawBuff_set_verties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_VERTEX* verties = ((ge::GE_VERTEX*)  tolua_tousertype(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_verties'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_verties(verties,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_verties'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_indices of class  ge::GEDrawBuff */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDrawBuff_set_indices00
static int tolua_luabind_ge_GEDrawBuff_set_indices00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDrawBuff",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDrawBuff* self = (ge::GEDrawBuff*)  tolua_tousertype(tolua_S,1,0);
  unsigned short indices = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_indices'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_indices(&indices,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)indices);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_indices'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GEDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDraw_create00
static int tolua_luabind_ge_GEDraw_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEDraw* tolua_ret = (ge::GEDraw*)  ge::GEDraw::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEDraw");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDraw_retain00
static int tolua_luabind_ge_GEDraw_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDraw* self = (ge::GEDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDraw_release00
static int tolua_luabind_ge_GEDraw_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDraw* self = (ge::GEDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_effect of class  ge::GEDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDraw_set_effect00
static int tolua_luabind_ge_GEDraw_set_effect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEREffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDraw* self = (ge::GEDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GEREffect* effect = ((ge::GEREffect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_effect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_effect(effect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_effect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_effect of class  ge::GEDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEDraw_get_effect00
static int tolua_luabind_ge_GEDraw_get_effect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEDraw* self = (ge::GEDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_effect'", NULL);
#endif
  {
   ge::GEREffect* tolua_ret = (ge::GEREffect*)  self->get_effect();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEREffect");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_effect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: xys of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_get_luabind_ge_GE_QUAD_xys
static int tolua_get_luabind_ge_GE_QUAD_xys(lua_State* tolua_S)
{
 int tolua_index;
  ge::GE_QUAD* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ge::GE_QUAD*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=8)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->xys[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: xys of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_set_luabind_ge_GE_QUAD_xys
static int tolua_set_luabind_ge_GE_QUAD_xys(lua_State* tolua_S)
{
 int tolua_index;
  ge::GE_QUAD* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ge::GE_QUAD*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=8)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->xys[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rhw of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_rhw
static int tolua_get_ge__GE_QUAD_rhw(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rhw'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->rhw);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rhw of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_rhw
static int tolua_set_ge__GE_QUAD_rhw(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rhw'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rhw = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: color of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_color
static int tolua_get_ge__GE_QUAD_color(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->color);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: color of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_color
static int tolua_set_ge__GE_QUAD_color(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->color = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texid of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_texid
static int tolua_get_ge__GE_QUAD_texid(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->texid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texid of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_texid
static int tolua_set_ge__GE_QUAD_texid(lua_State* tolua_S)
{
  ge::GE_QUAD* self = (ge::GE_QUAD*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->texid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uvs of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_get_luabind_ge_GE_QUAD_uvs
static int tolua_get_luabind_ge_GE_QUAD_uvs(lua_State* tolua_S)
{
 int tolua_index;
  ge::GE_QUAD* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ge::GE_QUAD*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=8)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->uvs[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uvs of class  ge::GE_QUAD */
#ifndef TOLUA_DISABLE_tolua_set_luabind_ge_GE_QUAD_uvs
static int tolua_set_luabind_ge_GE_QUAD_uvs(lua_State* tolua_S)
{
 int tolua_index;
  ge::GE_QUAD* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ge::GE_QUAD*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=8)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->uvs[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_EX_tl
static int tolua_get_ge__GE_QUAD_EX_tl(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tl,"ge::GE_VERTEX");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_EX_tl
static int tolua_set_ge__GE_QUAD_EX_tl(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl = *((ge::GE_VERTEX*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_EX_tr
static int tolua_get_ge__GE_QUAD_EX_tr(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tr,"ge::GE_VERTEX");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_EX_tr
static int tolua_set_ge__GE_QUAD_EX_tr(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr = *((ge::GE_VERTEX*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_EX_bl
static int tolua_get_ge__GE_QUAD_EX_bl(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->bl,"ge::GE_VERTEX");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_EX_bl
static int tolua_set_ge__GE_QUAD_EX_bl(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl = *((ge::GE_VERTEX*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_EX_br
static int tolua_get_ge__GE_QUAD_EX_br(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->br,"ge::GE_VERTEX");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_EX_br
static int tolua_set_ge__GE_QUAD_EX_br(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br = *((ge::GE_VERTEX*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texid of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_QUAD_EX_texid
static int tolua_get_ge__GE_QUAD_EX_texid(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->texid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texid of class  ge::GE_QUAD_EX */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_QUAD_EX_texid
static int tolua_set_ge__GE_QUAD_EX_texid(lua_State* tolua_S)
{
  ge::GE_QUAD_EX* self = (ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->texid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_create00
static int tolua_luabind_ge_GEAtlasDraw_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEAtlasDraw* tolua_ret = (ge::GEAtlasDraw*)  ge::GEAtlasDraw::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEAtlasDraw");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_retain00
static int tolua_luabind_ge_GEAtlasDraw_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_release00
static int tolua_luabind_ge_GEAtlasDraw_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_vertex_fvf of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_set_vertex_fvf00
static int tolua_luabind_ge_GEAtlasDraw_set_vertex_fvf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"DWORD",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  DWORD fvf = *((DWORD*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_vertex_fvf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_vertex_fvf(fvf);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_vertex_fvf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_vertex_decl of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_set_vertex_decl00
static int tolua_luabind_ge_GEAtlasDraw_set_vertex_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_VERTEX_DECL* vertex_decl = ((ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_vertex_decl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_vertex_decl(vertex_decl);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_vertex_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_vertex_decl of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_get_vertex_decl00
static int tolua_luabind_ge_GEAtlasDraw_get_vertex_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_vertex_decl'", NULL);
#endif
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  self->get_vertex_decl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_vertex_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init_texture_group of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_init_texture_group00
static int tolua_luabind_ge_GEAtlasDraw_init_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_texture_group'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_texture_group();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_texture_group of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_set_texture_group00
static int tolua_luabind_ge_GEAtlasDraw_set_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GETextureGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GETextureGroup* texture_group = ((ge::GETextureGroup*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_texture_group'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_texture_group(texture_group);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_texture_group of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_get_texture_group00
static int tolua_luabind_ge_GEAtlasDraw_get_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_texture_group'", NULL);
#endif
  {
   ge::GETextureGroup* tolua_ret = (ge::GETextureGroup*)  self->get_texture_group();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GETextureGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_texture_group of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_release_texture_group00
static int tolua_luabind_ge_GEAtlasDraw_release_texture_group00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release_texture_group'", NULL);
#endif
  {
   self->release_texture_group();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_texture_group'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init_render of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_init_render00
static int tolua_luabind_ge_GEAtlasDraw_init_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_render'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init_render();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update_render of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_update_render00
static int tolua_luabind_ge_GEAtlasDraw_update_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update_render'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->update_render();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update_render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release_render of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_release_render00
static int tolua_luabind_ge_GEAtlasDraw_release_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release_render'", NULL);
#endif
  {
   self->release_render();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release_render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_quad of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_add_quad00
static int tolua_luabind_ge_GEAtlasDraw_add_quad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_QUAD",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_QUAD* quad = ((ge::GE_QUAD*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_quad'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->add_quad(*quad);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_quad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_quad of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_add_quad01
static int tolua_luabind_ge_GEAtlasDraw_add_quad01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_QUAD_EX",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_QUAD_EX* quad = ((ge::GE_QUAD_EX*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_quad'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->add_quad(*quad);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GEAtlasDraw_add_quad00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_quad of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_add_quad02
static int tolua_luabind_ge_GEAtlasDraw_add_quad02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  int texture_id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_quad'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->add_quad(texture_id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GEAtlasDraw_add_quad01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear_quads of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_clear_quads00
static int tolua_luabind_ge_GEAtlasDraw_clear_quads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear_quads'", NULL);
#endif
  {
   self->clear_quads();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear_quads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw_quads of class  ge::GEAtlasDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEAtlasDraw_draw_quads00
static int tolua_luabind_ge_GEAtlasDraw_draw_quads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEAtlasDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEREffect",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEAtlasDraw* self = (ge::GEAtlasDraw*)  tolua_tousertype(tolua_S,1,0);
  ge::GEREffect* effect = ((ge::GEREffect*)  tolua_tousertype(tolua_S,2,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_quads'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->draw_quads(effect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_quads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw_point of class  ge::GEPrimitiveDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEPrimitiveDraw_draw_point00
static int tolua_luabind_ge_GEPrimitiveDraw_draw_point00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEPrimitiveDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_FPOINT",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FPOINT* point = ((ge::GE_FPOINT*)  tolua_tousertype(tolua_S,2,0));
  unsigned color = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ge::GEPrimitiveDraw::draw_point(*point,color);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_point'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw_line of class  ge::GEPrimitiveDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEPrimitiveDraw_draw_line00
static int tolua_luabind_ge_GEPrimitiveDraw_draw_line00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEPrimitiveDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_FPOINT",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"ge::GE_FPOINT",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FPOINT* from = ((ge::GE_FPOINT*)  tolua_tousertype(tolua_S,2,0));
  ge::GE_FPOINT* to = ((ge::GE_FPOINT*)  tolua_tousertype(tolua_S,3,0));
  unsigned color = ((unsigned)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ge::GEPrimitiveDraw::draw_line(*from,*to,color);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_line'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw_rect of class  ge::GEPrimitiveDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEPrimitiveDraw_draw_rect00
static int tolua_luabind_ge_GEPrimitiveDraw_draw_rect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEPrimitiveDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_FRECT",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* rect = ((ge::GE_FRECT*)  tolua_tousertype(tolua_S,2,0));
  unsigned color = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ge::GEPrimitiveDraw::draw_rect(*rect,color);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_rect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw_solid_rect of class  ge::GEPrimitiveDraw */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEPrimitiveDraw_draw_solid_rect00
static int tolua_luabind_ge_GEPrimitiveDraw_draw_solid_rect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEPrimitiveDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_FRECT",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* rect = ((ge::GE_FRECT*)  tolua_tousertype(tolua_S,2,0));
  unsigned color = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ge::GEPrimitiveDraw::draw_solid_rect(*rect,color);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_solid_rect'.",&tolua_err);
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

/* method: create of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_create00
static int tolua_luabind_ge_GEOSpine_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEOSpine* tolua_ret = (ge::GEOSpine*)  ge::GEOSpine::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEOSpine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_retain00
static int tolua_luabind_ge_GEOSpine_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_release00
static int tolua_luabind_ge_GEOSpine_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_init00
static int tolua_luabind_ge_GEOSpine_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
  const char* atlas_file = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* skeleton_file = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(atlas_file,skeleton_file);
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

/* method: destory of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_destory00
static int tolua_luabind_ge_GEOSpine_destory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_skin of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_set_skin00
static int tolua_luabind_ge_GEOSpine_set_skin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
  const char* skin_name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_skin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_skin(skin_name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_skin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_mix of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_set_mix00
static int tolua_luabind_ge_GEOSpine_set_mix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
  const char* from_ani = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* to_ani = ((const char*)  tolua_tostring(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_mix'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_mix(from_ani,to_ani,duration);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_mix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_animation of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_set_animation00
static int tolua_luabind_ge_GEOSpine_set_animation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
  const char* ani_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_animation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_animation(ani_name,loop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_animation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_animation of class  ge::GEOSpine */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOSpine_add_animation00
static int tolua_luabind_ge_GEOSpine_add_animation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOSpine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOSpine* self = (ge::GEOSpine*)  tolua_tousertype(tolua_S,1,0);
  const char* ani_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,3,false));
  float delay = ((float)  tolua_tonumber(tolua_S,4,0.f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_animation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->add_animation(ani_name,loop,delay);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_animation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_font of class  ge::GEOText */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOText_set_font00
static int tolua_luabind_ge_GEOText_set_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOText",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOText* self = (ge::GEOText*)  tolua_tousertype(tolua_S,1,0);
  ge::GEFont* font = ((ge::GEFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_font'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_font(font);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_font of class  ge::GEOText */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOText_get_font00
static int tolua_luabind_ge_GEOText_get_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOText* self = (ge::GEOText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_font'", NULL);
#endif
  {
   ge::GEFont* tolua_ret = (ge::GEFont*)  self->get_font();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_text of class  ge::GEOText */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOText_set_text00
static int tolua_luabind_ge_GEOText_set_text00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOText",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOText* self = (ge::GEOText*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_text'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_text(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_text of class  ge::GEOText */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOText_get_text00
static int tolua_luabind_ge_GEOText_get_text00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOText* self = (ge::GEOText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_text'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->get_text();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_create00
static int tolua_luabind_ge_GEOTextFT_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEOTextFT* tolua_ret = (ge::GEOTextFT*)  ge::GEOTextFT::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEOTextFT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_retain00
static int tolua_luabind_ge_GEOTextFT_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextFT* self = (ge::GEOTextFT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_release00
static int tolua_luabind_ge_GEOTextFT_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextFT* self = (ge::GEOTextFT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_text of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_set_text00
static int tolua_luabind_ge_GEOTextFT_set_text00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextFT* self = (ge::GEOTextFT*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_text'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_text(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_font of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_set_font00
static int tolua_luabind_ge_GEOTextFT_set_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextFT* self = (ge::GEOTextFT*)  tolua_tousertype(tolua_S,1,0);
  ge::GEFont* font = ((ge::GEFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_font'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_font(font);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_rect of class  ge::GEOTextFT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextFT_set_rect00
static int tolua_luabind_ge_GEOTextFT_set_rect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextFT",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ge::GE_IRECT",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextFT* self = (ge::GEOTextFT*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_IRECT* rect = ((ge::GE_IRECT*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_rect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_rect(*rect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_rect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ge::GEOTextBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextBM_create00
static int tolua_luabind_ge_GEOTextBM_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEOTextBM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEOTextBM* tolua_ret = (ge::GEOTextBM*)  ge::GEOTextBM::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEOTextBM");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  ge::GEOTextBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextBM_retain00
static int tolua_luabind_ge_GEOTextBM_retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextBM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextBM* self = (ge::GEOTextBM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  ge::GEOTextBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextBM_release00
static int tolua_luabind_ge_GEOTextBM_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextBM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextBM* self = (ge::GEOTextBM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_font of class  ge::GEOTextBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextBM_set_font00
static int tolua_luabind_ge_GEOTextBM_set_font00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextBM",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GEFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextBM* self = (ge::GEOTextBM*)  tolua_tousertype(tolua_S,1,0);
  ge::GEFont* font = ((ge::GEFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_font'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_font(font);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_font'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_text of class  ge::GEOTextBM */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEOTextBM_set_text00
static int tolua_luabind_ge_GEOTextBM_set_text00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GEOTextBM",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GEOTextBM* self = (ge::GEOTextBM*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_text'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_text(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IPOINT_new00
static int tolua_luabind_ge_GE_IPOINT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_IPOINT* tolua_ret = (ge::GE_IPOINT*)  Mtolua_new((ge::GE_IPOINT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IPOINT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IPOINT_new00_local
static int tolua_luabind_ge_GE_IPOINT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_IPOINT* tolua_ret = (ge::GE_IPOINT*)  Mtolua_new((ge::GE_IPOINT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IPOINT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IPOINT_new01
static int tolua_luabind_ge_GE_IPOINT_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IPOINT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_IPOINT* tolua_ret = (ge::GE_IPOINT*)  Mtolua_new((ge::GE_IPOINT)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IPOINT");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_IPOINT_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IPOINT_new01_local
static int tolua_luabind_ge_GE_IPOINT_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IPOINT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_IPOINT* tolua_ret = (ge::GE_IPOINT*)  Mtolua_new((ge::GE_IPOINT)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IPOINT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_IPOINT_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IPOINT_delete00
static int tolua_luabind_ge_GE_IPOINT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IPOINT* self = (ge::GE_IPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IPOINT_x
static int tolua_get_ge__GE_IPOINT_x(lua_State* tolua_S)
{
  ge::GE_IPOINT* self = (ge::GE_IPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IPOINT_x
static int tolua_set_ge__GE_IPOINT_x(lua_State* tolua_S)
{
  ge::GE_IPOINT* self = (ge::GE_IPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IPOINT_y
static int tolua_get_ge__GE_IPOINT_y(lua_State* tolua_S)
{
  ge::GE_IPOINT* self = (ge::GE_IPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  ge::GE_IPOINT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IPOINT_y
static int tolua_set_ge__GE_IPOINT_y(lua_State* tolua_S)
{
  ge::GE_IPOINT* self = (ge::GE_IPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_ISIZE_new00
static int tolua_luabind_ge_GE_ISIZE_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_ISIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_ISIZE* tolua_ret = (ge::GE_ISIZE*)  Mtolua_new((ge::GE_ISIZE)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_ISIZE");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_ISIZE_new00_local
static int tolua_luabind_ge_GE_ISIZE_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_ISIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_ISIZE* tolua_ret = (ge::GE_ISIZE*)  Mtolua_new((ge::GE_ISIZE)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_ISIZE");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_ISIZE_new01
static int tolua_luabind_ge_GE_ISIZE_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_ISIZE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_ISIZE* tolua_ret = (ge::GE_ISIZE*)  Mtolua_new((ge::GE_ISIZE)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_ISIZE");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_ISIZE_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_ISIZE_new01_local
static int tolua_luabind_ge_GE_ISIZE_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_ISIZE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_ISIZE* tolua_ret = (ge::GE_ISIZE*)  Mtolua_new((ge::GE_ISIZE)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_ISIZE");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_ISIZE_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_ISIZE_delete00
static int tolua_luabind_ge_GE_ISIZE_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_ISIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_ISIZE* self = (ge::GE_ISIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_ISIZE_width
static int tolua_get_ge__GE_ISIZE_width(lua_State* tolua_S)
{
  ge::GE_ISIZE* self = (ge::GE_ISIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_ISIZE_width
static int tolua_set_ge__GE_ISIZE_width(lua_State* tolua_S)
{
  ge::GE_ISIZE* self = (ge::GE_ISIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_ISIZE_height
static int tolua_get_ge__GE_ISIZE_height(lua_State* tolua_S)
{
  ge::GE_ISIZE* self = (ge::GE_ISIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  ge::GE_ISIZE */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_ISIZE_height
static int tolua_set_ge__GE_ISIZE_height(lua_State* tolua_S)
{
  ge::GE_ISIZE* self = (ge::GE_ISIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IRECT_left
static int tolua_get_ge__GE_IRECT_left(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IRECT_left
static int tolua_set_ge__GE_IRECT_left(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IRECT_top
static int tolua_get_ge__GE_IRECT_top(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IRECT_top
static int tolua_set_ge__GE_IRECT_top(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IRECT_right
static int tolua_get_ge__GE_IRECT_right(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->right);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IRECT_right
static int tolua_set_ge__GE_IRECT_right(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bottom of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_IRECT_bottom
static int tolua_get_ge__GE_IRECT_bottom(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bottom);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bottom of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_IRECT_bottom
static int tolua_set_ge__GE_IRECT_bottom(lua_State* tolua_S)
{
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bottom = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_new00
static int tolua_luabind_ge_GE_IRECT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_IRECT* tolua_ret = (ge::GE_IRECT*)  Mtolua_new((ge::GE_IRECT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IRECT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_new00_local
static int tolua_luabind_ge_GE_IRECT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_IRECT* tolua_ret = (ge::GE_IRECT*)  Mtolua_new((ge::GE_IRECT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IRECT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_new01
static int tolua_luabind_ge_GE_IRECT_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int left_ = ((int)  tolua_tonumber(tolua_S,2,0));
  int top_ = ((int)  tolua_tonumber(tolua_S,3,0));
  int right_ = ((int)  tolua_tonumber(tolua_S,4,0));
  int bottom_ = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   ge::GE_IRECT* tolua_ret = (ge::GE_IRECT*)  Mtolua_new((ge::GE_IRECT)(left_,top_,right_,bottom_));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IRECT");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_IRECT_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_new01_local
static int tolua_luabind_ge_GE_IRECT_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int left_ = ((int)  tolua_tonumber(tolua_S,2,0));
  int top_ = ((int)  tolua_tonumber(tolua_S,3,0));
  int right_ = ((int)  tolua_tonumber(tolua_S,4,0));
  int bottom_ = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   ge::GE_IRECT* tolua_ret = (ge::GE_IRECT*)  Mtolua_new((ge::GE_IRECT)(left_,top_,right_,bottom_));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_IRECT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_IRECT_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_delete00
static int tolua_luabind_ge_GE_IRECT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_width00
static int tolua_luabind_ge_GE_IRECT_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   int tolua_ret = (int)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: height of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_height00
static int tolua_luabind_ge_GE_IRECT_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   int tolua_ret = (int)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_move00
static int tolua_luabind_ge_GE_IRECT_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
  int offset_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int offset_y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(offset_x,offset_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move_to of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_move_to00
static int tolua_luabind_ge_GE_IRECT_move_to00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
  int pos_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int pos_y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move_to'", NULL);
#endif
  {
   self->move_to(pos_x,pos_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move_to'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: include of class  ge::GE_IRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_IRECT_include00
static int tolua_luabind_ge_GE_IRECT_include00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_IRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_IRECT* self = (ge::GE_IRECT*)  tolua_tousertype(tolua_S,1,0);
  int pos_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int pos_y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'include'", NULL);
#endif
  {
   self->include(pos_x,pos_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'include'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FPOINT_new00
static int tolua_luabind_ge_GE_FPOINT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FPOINT* tolua_ret = (ge::GE_FPOINT*)  Mtolua_new((ge::GE_FPOINT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FPOINT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FPOINT_new00_local
static int tolua_luabind_ge_GE_FPOINT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FPOINT* tolua_ret = (ge::GE_FPOINT*)  Mtolua_new((ge::GE_FPOINT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FPOINT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FPOINT_new01
static int tolua_luabind_ge_GE_FPOINT_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FPOINT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_FPOINT* tolua_ret = (ge::GE_FPOINT*)  Mtolua_new((ge::GE_FPOINT)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FPOINT");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FPOINT_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FPOINT_new01_local
static int tolua_luabind_ge_GE_FPOINT_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FPOINT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_FPOINT* tolua_ret = (ge::GE_FPOINT*)  Mtolua_new((ge::GE_FPOINT)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FPOINT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FPOINT_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FPOINT_delete00
static int tolua_luabind_ge_GE_FPOINT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FPOINT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FPOINT* self = (ge::GE_FPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FPOINT_x
static int tolua_get_ge__GE_FPOINT_x(lua_State* tolua_S)
{
  ge::GE_FPOINT* self = (ge::GE_FPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FPOINT_x
static int tolua_set_ge__GE_FPOINT_x(lua_State* tolua_S)
{
  ge::GE_FPOINT* self = (ge::GE_FPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FPOINT_y
static int tolua_get_ge__GE_FPOINT_y(lua_State* tolua_S)
{
  ge::GE_FPOINT* self = (ge::GE_FPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  ge::GE_FPOINT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FPOINT_y
static int tolua_set_ge__GE_FPOINT_y(lua_State* tolua_S)
{
  ge::GE_FPOINT* self = (ge::GE_FPOINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FSIZE_new00
static int tolua_luabind_ge_GE_FSIZE_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FSIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FSIZE* tolua_ret = (ge::GE_FSIZE*)  Mtolua_new((ge::GE_FSIZE)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FSIZE");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FSIZE_new00_local
static int tolua_luabind_ge_GE_FSIZE_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FSIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FSIZE* tolua_ret = (ge::GE_FSIZE*)  Mtolua_new((ge::GE_FSIZE)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FSIZE");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FSIZE_new01
static int tolua_luabind_ge_GE_FSIZE_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FSIZE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_FSIZE* tolua_ret = (ge::GE_FSIZE*)  Mtolua_new((ge::GE_FSIZE)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FSIZE");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FSIZE_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FSIZE_new01_local
static int tolua_luabind_ge_GE_FSIZE_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FSIZE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ge::GE_FSIZE* tolua_ret = (ge::GE_FSIZE*)  Mtolua_new((ge::GE_FSIZE)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FSIZE");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FSIZE_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FSIZE_delete00
static int tolua_luabind_ge_GE_FSIZE_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FSIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FSIZE* self = (ge::GE_FSIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FSIZE_width
static int tolua_get_ge__GE_FSIZE_width(lua_State* tolua_S)
{
  ge::GE_FSIZE* self = (ge::GE_FSIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FSIZE_width
static int tolua_set_ge__GE_FSIZE_width(lua_State* tolua_S)
{
  ge::GE_FSIZE* self = (ge::GE_FSIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FSIZE_height
static int tolua_get_ge__GE_FSIZE_height(lua_State* tolua_S)
{
  ge::GE_FSIZE* self = (ge::GE_FSIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  ge::GE_FSIZE */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FSIZE_height
static int tolua_set_ge__GE_FSIZE_height(lua_State* tolua_S)
{
  ge::GE_FSIZE* self = (ge::GE_FSIZE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FRECT_left
static int tolua_get_ge__GE_FRECT_left(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FRECT_left
static int tolua_set_ge__GE_FRECT_left(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FRECT_top
static int tolua_get_ge__GE_FRECT_top(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FRECT_top
static int tolua_set_ge__GE_FRECT_top(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FRECT_right
static int tolua_get_ge__GE_FRECT_right(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->right);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FRECT_right
static int tolua_set_ge__GE_FRECT_right(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bottom of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_FRECT_bottom
static int tolua_get_ge__GE_FRECT_bottom(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bottom);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bottom of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_FRECT_bottom
static int tolua_set_ge__GE_FRECT_bottom(lua_State* tolua_S)
{
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bottom = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_new00
static int tolua_luabind_ge_GE_FRECT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FRECT* tolua_ret = (ge::GE_FRECT*)  Mtolua_new((ge::GE_FRECT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FRECT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_new00_local
static int tolua_luabind_ge_GE_FRECT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_FRECT* tolua_ret = (ge::GE_FRECT*)  Mtolua_new((ge::GE_FRECT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FRECT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_new01
static int tolua_luabind_ge_GE_FRECT_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float left_ = ((float)  tolua_tonumber(tolua_S,2,0));
  float top_ = ((float)  tolua_tonumber(tolua_S,3,0));
  float right_ = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom_ = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ge::GE_FRECT* tolua_ret = (ge::GE_FRECT*)  Mtolua_new((ge::GE_FRECT)(left_,top_,right_,bottom_));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FRECT");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FRECT_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_new01_local
static int tolua_luabind_ge_GE_FRECT_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float left_ = ((float)  tolua_tonumber(tolua_S,2,0));
  float top_ = ((float)  tolua_tonumber(tolua_S,3,0));
  float right_ = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom_ = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ge::GE_FRECT* tolua_ret = (ge::GE_FRECT*)  Mtolua_new((ge::GE_FRECT)(left_,top_,right_,bottom_));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_FRECT");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luabind_ge_GE_FRECT_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_delete00
static int tolua_luabind_ge_GE_FRECT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_width00
static int tolua_luabind_ge_GE_FRECT_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   float tolua_ret = (float)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: height of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_height00
static int tolua_luabind_ge_GE_FRECT_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   float tolua_ret = (float)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_move00
static int tolua_luabind_ge_GE_FRECT_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
  float offset_x = ((float)  tolua_tonumber(tolua_S,2,0));
  float offset_y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(offset_x,offset_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move_to of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_move_to00
static int tolua_luabind_ge_GE_FRECT_move_to00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
  float pos_x = ((float)  tolua_tonumber(tolua_S,2,0));
  float pos_y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move_to'", NULL);
#endif
  {
   self->move_to(pos_x,pos_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move_to'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: include of class  ge::GE_FRECT */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_FRECT_include00
static int tolua_luabind_ge_GE_FRECT_include00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_FRECT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_FRECT* self = (ge::GE_FRECT*)  tolua_tousertype(tolua_S,1,0);
  float pos_x = ((float)  tolua_tonumber(tolua_S,2,0));
  float pos_y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'include'", NULL);
#endif
  {
   self->include(pos_x,pos_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'include'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fvf of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_VERTEX_DECL_fvf
static int tolua_get_ge__GE_VERTEX_DECL_fvf(lua_State* tolua_S)
{
  ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fvf'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->fvf,"DWORD");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fvf of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_VERTEX_DECL_fvf
static int tolua_set_ge__GE_VERTEX_DECL_fvf(lua_State* tolua_S)
{
  ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fvf'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"DWORD",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->fvf = *((DWORD*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_get_ge__GE_VERTEX_DECL_size
static int tolua_get_ge__GE_VERTEX_DECL_size(lua_State* tolua_S)
{
  ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->size);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_set_ge__GE_VERTEX_DECL_size
static int tolua_set_ge__GE_VERTEX_DECL_size(lua_State* tolua_S)
{
  ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->size = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_DECL_new00
static int tolua_luabind_ge_GE_VERTEX_DECL_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  Mtolua_new((ge::GE_VERTEX_DECL)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_DECL_new00_local
static int tolua_luabind_ge_GE_VERTEX_DECL_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  Mtolua_new((ge::GE_VERTEX_DECL)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_valid of class  ge::GE_VERTEX_DECL */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_DECL_is_valid00
static int tolua_luabind_ge_GE_VERTEX_DECL_is_valid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX_DECL* self = (ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_valid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_valid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_valid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_instance of class  ge::GEVertexDecl */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEVertexDecl_get_instance00
static int tolua_luabind_ge_GEVertexDecl_get_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEVertexDecl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ge::GEVertexDecl* tolua_ret = (ge::GEVertexDecl*)  ge::GEVertexDecl::get_instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GEVertexDecl");
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

/* method: get_vertex_decl of class  ge::GEVertexDecl */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GEVertexDecl_get_vertex_decl00
static int tolua_luabind_ge_GEVertexDecl_get_vertex_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ge::GEVertexDecl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"DWORD",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DWORD fvf = *((DWORD*)  tolua_tousertype(tolua_S,2,0));
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  ge::GEVertexDecl::get_vertex_decl(fvf);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_vertex_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_fvf of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_fvf00
static int tolua_luabind_ge_GE_VERTEX_set_fvf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"DWORD",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  DWORD fvf = *((DWORD*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_fvf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_fvf(fvf);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_fvf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_decl of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_decl00
static int tolua_luabind_ge_GE_VERTEX_set_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ge::GE_VERTEX_DECL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  ge::GE_VERTEX_DECL* decl = ((ge::GE_VERTEX_DECL*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_decl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->set_decl(decl);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_decl of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_get_decl00
static int tolua_luabind_ge_GE_VERTEX_get_decl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_decl'", NULL);
#endif
  {
   ge::GE_VERTEX_DECL* tolua_ret = (ge::GE_VERTEX_DECL*)  self->get_decl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ge::GE_VERTEX_DECL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_decl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_position of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_position00
static int tolua_luabind_ge_GE_VERTEX_set_position00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_position'", NULL);
#endif
  {
   self->set_position(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_position'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_normal of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_normal00
static int tolua_luabind_ge_GE_VERTEX_set_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_normal'", NULL);
#endif
  {
   self->set_normal(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_texcoords of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_texcoords00
static int tolua_luabind_ge_GE_VERTEX_set_texcoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  float u = ((float)  tolua_tonumber(tolua_S,2,0));
  float v = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_texcoords'", NULL);
#endif
  {
   self->set_texcoords(u,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_texcoords'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_blend of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_blend00
static int tolua_luabind_ge_GE_VERTEX_set_blend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"UINT",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  UINT blend = *((UINT*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_blend'", NULL);
#endif
  {
   self->set_blend(blend);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_blend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_color of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_color00
static int tolua_luabind_ge_GE_VERTEX_set_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"D3DCOLOR",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  D3DCOLOR color = *((D3DCOLOR*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_color'", NULL);
#endif
  {
   self->set_color(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_rhw of class  ge::GE_VERTEX */
#ifndef TOLUA_DISABLE_tolua_luabind_ge_GE_VERTEX_set_rhw00
static int tolua_luabind_ge_GE_VERTEX_set_rhw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ge::GE_VERTEX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ge::GE_VERTEX* self = (ge::GE_VERTEX*)  tolua_tousertype(tolua_S,1,0);
  float rhw = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_rhw'", NULL);
#endif
  {
   self->set_rhw(rhw);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_rhw'.",&tolua_err);
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
    tolua_constant(tolua_S,"KC_ESCAPE",ge::GEInput::KC_ESCAPE);
    tolua_constant(tolua_S,"KC_1",ge::GEInput::KC_1);
    tolua_constant(tolua_S,"KC_2",ge::GEInput::KC_2);
    tolua_constant(tolua_S,"KC_3",ge::GEInput::KC_3);
    tolua_constant(tolua_S,"KC_4",ge::GEInput::KC_4);
    tolua_constant(tolua_S,"KC_5",ge::GEInput::KC_5);
    tolua_constant(tolua_S,"KC_6",ge::GEInput::KC_6);
    tolua_constant(tolua_S,"KC_7",ge::GEInput::KC_7);
    tolua_constant(tolua_S,"KC_8",ge::GEInput::KC_8);
    tolua_constant(tolua_S,"KC_9",ge::GEInput::KC_9);
    tolua_constant(tolua_S,"KC_0",ge::GEInput::KC_0);
    tolua_constant(tolua_S,"KC_MINUS",ge::GEInput::KC_MINUS);
    tolua_constant(tolua_S,"KC_EQUALS",ge::GEInput::KC_EQUALS);
    tolua_constant(tolua_S,"KC_BACK",ge::GEInput::KC_BACK);
    tolua_constant(tolua_S,"KC_TAB",ge::GEInput::KC_TAB);
    tolua_constant(tolua_S,"KC_Q",ge::GEInput::KC_Q);
    tolua_constant(tolua_S,"KC_W",ge::GEInput::KC_W);
    tolua_constant(tolua_S,"KC_E",ge::GEInput::KC_E);
    tolua_constant(tolua_S,"KC_R",ge::GEInput::KC_R);
    tolua_constant(tolua_S,"KC_T",ge::GEInput::KC_T);
    tolua_constant(tolua_S,"KC_Y",ge::GEInput::KC_Y);
    tolua_constant(tolua_S,"KC_U",ge::GEInput::KC_U);
    tolua_constant(tolua_S,"KC_I",ge::GEInput::KC_I);
    tolua_constant(tolua_S,"KC_O",ge::GEInput::KC_O);
    tolua_constant(tolua_S,"KC_P",ge::GEInput::KC_P);
    tolua_constant(tolua_S,"KC_LBRACKET",ge::GEInput::KC_LBRACKET);
    tolua_constant(tolua_S,"KC_RBRACKET",ge::GEInput::KC_RBRACKET);
    tolua_constant(tolua_S,"KC_RETURN",ge::GEInput::KC_RETURN);
    tolua_constant(tolua_S,"KC_LCONTROL",ge::GEInput::KC_LCONTROL);
    tolua_constant(tolua_S,"KC_A",ge::GEInput::KC_A);
    tolua_constant(tolua_S,"KC_S",ge::GEInput::KC_S);
    tolua_constant(tolua_S,"KC_D",ge::GEInput::KC_D);
    tolua_constant(tolua_S,"KC_F",ge::GEInput::KC_F);
    tolua_constant(tolua_S,"KC_G",ge::GEInput::KC_G);
    tolua_constant(tolua_S,"KC_H",ge::GEInput::KC_H);
    tolua_constant(tolua_S,"KC_J",ge::GEInput::KC_J);
    tolua_constant(tolua_S,"KC_K",ge::GEInput::KC_K);
    tolua_constant(tolua_S,"KC_L",ge::GEInput::KC_L);
    tolua_constant(tolua_S,"KC_SEMICOLON",ge::GEInput::KC_SEMICOLON);
    tolua_constant(tolua_S,"KC_APOSTROPHE",ge::GEInput::KC_APOSTROPHE);
    tolua_constant(tolua_S,"KC_GRAVE",ge::GEInput::KC_GRAVE);
    tolua_constant(tolua_S,"KC_LSHIFT",ge::GEInput::KC_LSHIFT);
    tolua_constant(tolua_S,"KC_BACKSLASH",ge::GEInput::KC_BACKSLASH);
    tolua_constant(tolua_S,"KC_Z",ge::GEInput::KC_Z);
    tolua_constant(tolua_S,"KC_X",ge::GEInput::KC_X);
    tolua_constant(tolua_S,"KC_C",ge::GEInput::KC_C);
    tolua_constant(tolua_S,"KC_V",ge::GEInput::KC_V);
    tolua_constant(tolua_S,"KC_B",ge::GEInput::KC_B);
    tolua_constant(tolua_S,"KC_N",ge::GEInput::KC_N);
    tolua_constant(tolua_S,"KC_M",ge::GEInput::KC_M);
    tolua_constant(tolua_S,"KC_COMMA",ge::GEInput::KC_COMMA);
    tolua_constant(tolua_S,"KC_PERIOD",ge::GEInput::KC_PERIOD);
    tolua_constant(tolua_S,"KC_SLASH",ge::GEInput::KC_SLASH);
    tolua_constant(tolua_S,"KC_RSHIFT",ge::GEInput::KC_RSHIFT);
    tolua_constant(tolua_S,"KC_MULTIPLY",ge::GEInput::KC_MULTIPLY);
    tolua_constant(tolua_S,"KC_LMENU",ge::GEInput::KC_LMENU);
    tolua_constant(tolua_S,"KC_SPACE",ge::GEInput::KC_SPACE);
    tolua_constant(tolua_S,"KC_CAPITAL",ge::GEInput::KC_CAPITAL);
    tolua_constant(tolua_S,"KC_F1",ge::GEInput::KC_F1);
    tolua_constant(tolua_S,"KC_F2",ge::GEInput::KC_F2);
    tolua_constant(tolua_S,"KC_F3",ge::GEInput::KC_F3);
    tolua_constant(tolua_S,"KC_F4",ge::GEInput::KC_F4);
    tolua_constant(tolua_S,"KC_F5",ge::GEInput::KC_F5);
    tolua_constant(tolua_S,"KC_F6",ge::GEInput::KC_F6);
    tolua_constant(tolua_S,"KC_F7",ge::GEInput::KC_F7);
    tolua_constant(tolua_S,"KC_F8",ge::GEInput::KC_F8);
    tolua_constant(tolua_S,"KC_F9",ge::GEInput::KC_F9);
    tolua_constant(tolua_S,"KC_F10",ge::GEInput::KC_F10);
    tolua_constant(tolua_S,"KC_NUMLOCK",ge::GEInput::KC_NUMLOCK);
    tolua_constant(tolua_S,"KC_SCROLL",ge::GEInput::KC_SCROLL);
    tolua_constant(tolua_S,"KC_NUMPAD7",ge::GEInput::KC_NUMPAD7);
    tolua_constant(tolua_S,"KC_NUMPAD8",ge::GEInput::KC_NUMPAD8);
    tolua_constant(tolua_S,"KC_NUMPAD9",ge::GEInput::KC_NUMPAD9);
    tolua_constant(tolua_S,"KC_SUBTRACT",ge::GEInput::KC_SUBTRACT);
    tolua_constant(tolua_S,"KC_NUMPAD4",ge::GEInput::KC_NUMPAD4);
    tolua_constant(tolua_S,"KC_NUMPAD5",ge::GEInput::KC_NUMPAD5);
    tolua_constant(tolua_S,"KC_NUMPAD6",ge::GEInput::KC_NUMPAD6);
    tolua_constant(tolua_S,"KC_ADD",ge::GEInput::KC_ADD);
    tolua_constant(tolua_S,"KC_NUMPAD1",ge::GEInput::KC_NUMPAD1);
    tolua_constant(tolua_S,"KC_NUMPAD2",ge::GEInput::KC_NUMPAD2);
    tolua_constant(tolua_S,"KC_NUMPAD3",ge::GEInput::KC_NUMPAD3);
    tolua_constant(tolua_S,"KC_NUMPAD0",ge::GEInput::KC_NUMPAD0);
    tolua_constant(tolua_S,"KC_DECIMAL",ge::GEInput::KC_DECIMAL);
    tolua_constant(tolua_S,"KC_OEM_102",ge::GEInput::KC_OEM_102);
    tolua_constant(tolua_S,"KC_F11",ge::GEInput::KC_F11);
    tolua_constant(tolua_S,"KC_F12",ge::GEInput::KC_F12);
    tolua_constant(tolua_S,"KC_F13",ge::GEInput::KC_F13);
    tolua_constant(tolua_S,"KC_F14",ge::GEInput::KC_F14);
    tolua_constant(tolua_S,"KC_F15",ge::GEInput::KC_F15);
    tolua_constant(tolua_S,"KC_KANA",ge::GEInput::KC_KANA);
    tolua_constant(tolua_S,"KC_ABNT_C1",ge::GEInput::KC_ABNT_C1);
    tolua_constant(tolua_S,"KC_CONVERT",ge::GEInput::KC_CONVERT);
    tolua_constant(tolua_S,"KC_NOCONVERT",ge::GEInput::KC_NOCONVERT);
    tolua_constant(tolua_S,"KC_YEN",ge::GEInput::KC_YEN);
    tolua_constant(tolua_S,"KC_ABNT_C2",ge::GEInput::KC_ABNT_C2);
    tolua_constant(tolua_S,"KC_NUMPADEQUALS",ge::GEInput::KC_NUMPADEQUALS);
    tolua_constant(tolua_S,"KC_PREVTRACK",ge::GEInput::KC_PREVTRACK);
    tolua_constant(tolua_S,"KC_AT",ge::GEInput::KC_AT);
    tolua_constant(tolua_S,"KC_COLON",ge::GEInput::KC_COLON);
    tolua_constant(tolua_S,"KC_UNDERLINE",ge::GEInput::KC_UNDERLINE);
    tolua_constant(tolua_S,"KC_KANJI",ge::GEInput::KC_KANJI);
    tolua_constant(tolua_S,"KC_STOP",ge::GEInput::KC_STOP);
    tolua_constant(tolua_S,"KC_AX",ge::GEInput::KC_AX);
    tolua_constant(tolua_S,"KC_UNLABELED",ge::GEInput::KC_UNLABELED);
    tolua_constant(tolua_S,"KC_NEXTTRACK",ge::GEInput::KC_NEXTTRACK);
    tolua_constant(tolua_S,"KC_NUMPADENTER",ge::GEInput::KC_NUMPADENTER);
    tolua_constant(tolua_S,"KC_RCONTROL",ge::GEInput::KC_RCONTROL);
    tolua_constant(tolua_S,"KC_MUTE",ge::GEInput::KC_MUTE);
    tolua_constant(tolua_S,"KC_CALCULATOR",ge::GEInput::KC_CALCULATOR);
    tolua_constant(tolua_S,"KC_PLAYPAUSE",ge::GEInput::KC_PLAYPAUSE);
    tolua_constant(tolua_S,"KC_MEDIASTOP",ge::GEInput::KC_MEDIASTOP);
    tolua_constant(tolua_S,"KC_VOLUMEDOWN",ge::GEInput::KC_VOLUMEDOWN);
    tolua_constant(tolua_S,"KC_VOLUMEUP",ge::GEInput::KC_VOLUMEUP);
    tolua_constant(tolua_S,"KC_WEBHOME",ge::GEInput::KC_WEBHOME);
    tolua_constant(tolua_S,"KC_NUMPADCOMMA",ge::GEInput::KC_NUMPADCOMMA);
    tolua_constant(tolua_S,"KC_DIVIDE",ge::GEInput::KC_DIVIDE);
    tolua_constant(tolua_S,"KC_SYSRQ",ge::GEInput::KC_SYSRQ);
    tolua_constant(tolua_S,"KC_RMENU",ge::GEInput::KC_RMENU);
    tolua_constant(tolua_S,"KC_PAUSE",ge::GEInput::KC_PAUSE);
    tolua_constant(tolua_S,"KC_HOME",ge::GEInput::KC_HOME);
    tolua_constant(tolua_S,"KC_UP",ge::GEInput::KC_UP);
    tolua_constant(tolua_S,"KC_PGUP",ge::GEInput::KC_PGUP);
    tolua_constant(tolua_S,"KC_LEFT",ge::GEInput::KC_LEFT);
    tolua_constant(tolua_S,"KC_RIGHT",ge::GEInput::KC_RIGHT);
    tolua_constant(tolua_S,"KC_END",ge::GEInput::KC_END);
    tolua_constant(tolua_S,"KC_DOWN",ge::GEInput::KC_DOWN);
    tolua_constant(tolua_S,"KC_PGDOWN",ge::GEInput::KC_PGDOWN);
    tolua_constant(tolua_S,"KC_INSERT",ge::GEInput::KC_INSERT);
    tolua_constant(tolua_S,"KC_DELETE",ge::GEInput::KC_DELETE);
    tolua_constant(tolua_S,"KC_LWIN",ge::GEInput::KC_LWIN);
    tolua_constant(tolua_S,"KC_RWIN",ge::GEInput::KC_RWIN);
    tolua_constant(tolua_S,"KC_APPS",ge::GEInput::KC_APPS);
    tolua_constant(tolua_S,"KC_POWER",ge::GEInput::KC_POWER);
    tolua_constant(tolua_S,"KC_SLEEP",ge::GEInput::KC_SLEEP);
    tolua_constant(tolua_S,"KC_WAKE",ge::GEInput::KC_WAKE);
    tolua_constant(tolua_S,"KC_WEBSEARCH",ge::GEInput::KC_WEBSEARCH);
    tolua_constant(tolua_S,"KC_WEBFAVORITES",ge::GEInput::KC_WEBFAVORITES);
    tolua_constant(tolua_S,"KC_WEBREFRESH",ge::GEInput::KC_WEBREFRESH);
    tolua_constant(tolua_S,"KC_WEBSTOP",ge::GEInput::KC_WEBSTOP);
    tolua_constant(tolua_S,"KC_WEBFORWARD",ge::GEInput::KC_WEBFORWARD);
    tolua_constant(tolua_S,"KC_WEBBACK",ge::GEInput::KC_WEBBACK);
    tolua_constant(tolua_S,"KC_MYCOMPUTER",ge::GEInput::KC_MYCOMPUTER);
    tolua_constant(tolua_S,"KC_MAIL",ge::GEInput::KC_MAIL);
    tolua_constant(tolua_S,"KC_MEDIASELECT",ge::GEInput::KC_MEDIASELECT);
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
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEScene_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEScene_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEScene_release00);
    tolua_function(tolua_S,"add_object",tolua_luabind_ge_GEScene_add_object00);
    tolua_function(tolua_S,"remove_object",tolua_luabind_ge_GEScene_remove_object00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GELuaScene","ge::GELuaScene","ge::GEScene",NULL);
   tolua_beginmodule(tolua_S,"GELuaScene");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GELuaScene_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GELuaScene_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GELuaScene_release00);
    tolua_function(tolua_S,"set_init_func",tolua_luabind_ge_GELuaScene_set_init_func00);
    tolua_function(tolua_S,"set_destory_func",tolua_luabind_ge_GELuaScene_set_destory_func00);
    tolua_function(tolua_S,"set_show_func",tolua_luabind_ge_GELuaScene_set_show_func00);
    tolua_function(tolua_S,"set_hide_func",tolua_luabind_ge_GELuaScene_set_hide_func00);
    tolua_function(tolua_S,"set_update_func",tolua_luabind_ge_GELuaScene_set_update_func00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GESurface","ge::GESurface","",NULL);
   tolua_beginmodule(tolua_S,"GESurface");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GESurface_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GESurface_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GESurface_release00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GETexture","ge::GETexture","ge::GESurface",NULL);
   tolua_beginmodule(tolua_S,"GETexture");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GETexture_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GETexture_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GETexture_release00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GETextureGroup","ge::GETextureGroup","",NULL);
   tolua_beginmodule(tolua_S,"GETextureGroup");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GETextureGroup_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GETextureGroup_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GETextureGroup_release00);
    tolua_function(tolua_S,"add_texture",tolua_luabind_ge_GETextureGroup_add_texture00);
    tolua_function(tolua_S,"add_texture",tolua_luabind_ge_GETextureGroup_add_texture01);
    tolua_function(tolua_S,"add_texture_from_file",tolua_luabind_ge_GETextureGroup_add_texture_from_file00);
    tolua_function(tolua_S,"get_texture",tolua_luabind_ge_GETextureGroup_get_texture00);
    tolua_function(tolua_S,"replace_texture",tolua_luabind_ge_GETextureGroup_replace_texture00);
    tolua_function(tolua_S,"release_texture",tolua_luabind_ge_GETextureGroup_release_texture00);
    tolua_function(tolua_S,"release_all_texture",tolua_luabind_ge_GETextureGroup_release_all_texture00);
    tolua_function(tolua_S,"get_texture_cnt",tolua_luabind_ge_GETextureGroup_get_texture_cnt00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GETextureManager","ge::GETextureManager","",NULL);
   tolua_beginmodule(tolua_S,"GETextureManager");
    tolua_function(tolua_S,"create_texture",tolua_luabind_ge_GETextureManager_create_texture00);
    tolua_function(tolua_S,"create_texture",tolua_luabind_ge_GETextureManager_create_texture01);
    tolua_function(tolua_S,"refer_texture",tolua_luabind_ge_GETextureManager_refer_texture00);
    tolua_function(tolua_S,"release_texture",tolua_luabind_ge_GETextureManager_release_texture00);
    tolua_function(tolua_S,"create_texture_group",tolua_luabind_ge_GETextureManager_create_texture_group00);
    tolua_function(tolua_S,"refer_texture_group",tolua_luabind_ge_GETextureManager_refer_texture_group00);
    tolua_function(tolua_S,"release_texture_group",tolua_luabind_ge_GETextureManager_release_texture_group00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"FontType_Default",ge::FontType_Default);
   tolua_constant(tolua_S,"FontType_D3DXFont",ge::FontType_D3DXFont);
   tolua_constant(tolua_S,"FontType_GDIFont",ge::FontType_GDIFont);
   tolua_constant(tolua_S,"FontType_BMFont",ge::FontType_BMFont);
   tolua_constant(tolua_S,"FontType_FTFont",ge::FontType_FTFont);
   tolua_cclass(tolua_S,"GEFontManager","ge::GEFontManager","",NULL);
   tolua_beginmodule(tolua_S,"GEFontManager");
    tolua_function(tolua_S,"create_font",tolua_luabind_ge_GEFontManager_create_font00);
    tolua_function(tolua_S,"release_font",tolua_luabind_ge_GEFontManager_release_font00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEFont","ge::GEFont","",NULL);
   tolua_beginmodule(tolua_S,"GEFont");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GED3DXFont","ge::GED3DXFont","ge::GEFont",NULL);
   tolua_beginmodule(tolua_S,"GED3DXFont");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GED3DXFont_init00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEGDIFont","ge::GEGDIFont","ge::GEFont",NULL);
   tolua_beginmodule(tolua_S,"GEGDIFont");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEGDIFont_init00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEFontBM","ge::GEFontBM","ge::GEFont",NULL);
   tolua_beginmodule(tolua_S,"GEFontBM");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEFontBM_init00);
    tolua_function(tolua_S,"init_effect",tolua_luabind_ge_GEFontBM_init_effect00);
    tolua_function(tolua_S,"destory_effect",tolua_luabind_ge_GEFontBM_destory_effect00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEFontFT","ge::GEFontFT","ge::GEFont",NULL);
   tolua_beginmodule(tolua_S,"GEFontFT");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEFontFT_init00);
    tolua_function(tolua_S,"init_texture_group",tolua_luabind_ge_GEFontFT_init_texture_group00);
    tolua_function(tolua_S,"get_texture_group",tolua_luabind_ge_GEFontFT_get_texture_group00);
    tolua_function(tolua_S,"set_size",tolua_luabind_ge_GEFontFT_set_size00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEDrawBuff","ge::GEDrawBuff","",NULL);
   tolua_beginmodule(tolua_S,"GEDrawBuff");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEDrawBuff_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEDrawBuff_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEDrawBuff_release00);
    tolua_function(tolua_S,"set_vertex_decl",tolua_luabind_ge_GEDrawBuff_set_vertex_decl00);
    tolua_function(tolua_S,"get_vertex_decl",tolua_luabind_ge_GEDrawBuff_get_vertex_decl00);
    tolua_function(tolua_S,"init_vertex_buff",tolua_luabind_ge_GEDrawBuff_init_vertex_buff00);
    tolua_function(tolua_S,"init_index_buff",tolua_luabind_ge_GEDrawBuff_init_index_buff00);
    tolua_function(tolua_S,"init_quad_buff",tolua_luabind_ge_GEDrawBuff_init_quad_buff00);
    tolua_function(tolua_S,"destory_vertex_buff",tolua_luabind_ge_GEDrawBuff_destory_vertex_buff00);
    tolua_function(tolua_S,"destory_index_buff",tolua_luabind_ge_GEDrawBuff_destory_index_buff00);
    tolua_function(tolua_S,"destory_buff",tolua_luabind_ge_GEDrawBuff_destory_buff00);
    tolua_function(tolua_S,"prepare_drawbuff",tolua_luabind_ge_GEDrawBuff_prepare_drawbuff00);
    tolua_function(tolua_S,"set_verties",tolua_luabind_ge_GEDrawBuff_set_verties00);
    tolua_function(tolua_S,"set_indices",tolua_luabind_ge_GEDrawBuff_set_indices00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEDraw","ge::GEDraw","",NULL);
   tolua_beginmodule(tolua_S,"GEDraw");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEDraw_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEDraw_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEDraw_release00);
    tolua_function(tolua_S,"set_effect",tolua_luabind_ge_GEDraw_set_effect00);
    tolua_function(tolua_S,"get_effect",tolua_luabind_ge_GEDraw_get_effect00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GE_QUAD","ge::GE_QUAD","",NULL);
   tolua_beginmodule(tolua_S,"GE_QUAD");
    tolua_array(tolua_S,"xys",tolua_get_luabind_ge_GE_QUAD_xys,tolua_set_luabind_ge_GE_QUAD_xys);
    tolua_variable(tolua_S,"rhw",tolua_get_ge__GE_QUAD_rhw,tolua_set_ge__GE_QUAD_rhw);
    tolua_variable(tolua_S,"color",tolua_get_ge__GE_QUAD_color,tolua_set_ge__GE_QUAD_color);
    tolua_variable(tolua_S,"texid",tolua_get_ge__GE_QUAD_texid,tolua_set_ge__GE_QUAD_texid);
    tolua_array(tolua_S,"uvs",tolua_get_luabind_ge_GE_QUAD_uvs,tolua_set_luabind_ge_GE_QUAD_uvs);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GE_QUAD_EX","ge::GE_QUAD_EX","",NULL);
   tolua_beginmodule(tolua_S,"GE_QUAD_EX");
    tolua_variable(tolua_S,"tl",tolua_get_ge__GE_QUAD_EX_tl,tolua_set_ge__GE_QUAD_EX_tl);
    tolua_variable(tolua_S,"tr",tolua_get_ge__GE_QUAD_EX_tr,tolua_set_ge__GE_QUAD_EX_tr);
    tolua_variable(tolua_S,"bl",tolua_get_ge__GE_QUAD_EX_bl,tolua_set_ge__GE_QUAD_EX_bl);
    tolua_variable(tolua_S,"br",tolua_get_ge__GE_QUAD_EX_br,tolua_set_ge__GE_QUAD_EX_br);
    tolua_variable(tolua_S,"texid",tolua_get_ge__GE_QUAD_EX_texid,tolua_set_ge__GE_QUAD_EX_texid);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEAtlasDraw","ge::GEAtlasDraw","ge::GEDraw",NULL);
   tolua_beginmodule(tolua_S,"GEAtlasDraw");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEAtlasDraw_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEAtlasDraw_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEAtlasDraw_release00);
    tolua_function(tolua_S,"set_vertex_fvf",tolua_luabind_ge_GEAtlasDraw_set_vertex_fvf00);
    tolua_function(tolua_S,"set_vertex_decl",tolua_luabind_ge_GEAtlasDraw_set_vertex_decl00);
    tolua_function(tolua_S,"get_vertex_decl",tolua_luabind_ge_GEAtlasDraw_get_vertex_decl00);
    tolua_function(tolua_S,"init_texture_group",tolua_luabind_ge_GEAtlasDraw_init_texture_group00);
    tolua_function(tolua_S,"set_texture_group",tolua_luabind_ge_GEAtlasDraw_set_texture_group00);
    tolua_function(tolua_S,"get_texture_group",tolua_luabind_ge_GEAtlasDraw_get_texture_group00);
    tolua_function(tolua_S,"release_texture_group",tolua_luabind_ge_GEAtlasDraw_release_texture_group00);
    tolua_function(tolua_S,"init_render",tolua_luabind_ge_GEAtlasDraw_init_render00);
    tolua_function(tolua_S,"update_render",tolua_luabind_ge_GEAtlasDraw_update_render00);
    tolua_function(tolua_S,"release_render",tolua_luabind_ge_GEAtlasDraw_release_render00);
    tolua_function(tolua_S,"add_quad",tolua_luabind_ge_GEAtlasDraw_add_quad00);
    tolua_function(tolua_S,"add_quad",tolua_luabind_ge_GEAtlasDraw_add_quad01);
    tolua_function(tolua_S,"add_quad",tolua_luabind_ge_GEAtlasDraw_add_quad02);
    tolua_function(tolua_S,"clear_quads",tolua_luabind_ge_GEAtlasDraw_clear_quads00);
    tolua_function(tolua_S,"draw_quads",tolua_luabind_ge_GEAtlasDraw_draw_quads00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEPrimitiveDraw","ge::GEPrimitiveDraw","",NULL);
   tolua_beginmodule(tolua_S,"GEPrimitiveDraw");
    tolua_function(tolua_S,"draw_point",tolua_luabind_ge_GEPrimitiveDraw_draw_point00);
    tolua_function(tolua_S,"draw_line",tolua_luabind_ge_GEPrimitiveDraw_draw_line00);
    tolua_function(tolua_S,"draw_rect",tolua_luabind_ge_GEPrimitiveDraw_draw_rect00);
    tolua_function(tolua_S,"draw_solid_rect",tolua_luabind_ge_GEPrimitiveDraw_draw_solid_rect00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEREffect","ge::GEREffect","",NULL);
   tolua_beginmodule(tolua_S,"GEREffect");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEObject","ge::GEObject","",NULL);
   tolua_beginmodule(tolua_S,"GEObject");
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEObject_init00);
    tolua_function(tolua_S,"destory",tolua_luabind_ge_GEObject_destory00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEOSpine","ge::GEOSpine","ge::GEObject",NULL);
   tolua_beginmodule(tolua_S,"GEOSpine");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEOSpine_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEOSpine_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEOSpine_release00);
    tolua_function(tolua_S,"init",tolua_luabind_ge_GEOSpine_init00);
    tolua_function(tolua_S,"destory",tolua_luabind_ge_GEOSpine_destory00);
    tolua_function(tolua_S,"set_skin",tolua_luabind_ge_GEOSpine_set_skin00);
    tolua_function(tolua_S,"set_mix",tolua_luabind_ge_GEOSpine_set_mix00);
    tolua_function(tolua_S,"set_animation",tolua_luabind_ge_GEOSpine_set_animation00);
    tolua_function(tolua_S,"add_animation",tolua_luabind_ge_GEOSpine_add_animation00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEOText","ge::GEOText","ge::GEObject",NULL);
   tolua_beginmodule(tolua_S,"GEOText");
    tolua_function(tolua_S,"set_font",tolua_luabind_ge_GEOText_set_font00);
    tolua_function(tolua_S,"get_font",tolua_luabind_ge_GEOText_get_font00);
    tolua_function(tolua_S,"set_text",tolua_luabind_ge_GEOText_set_text00);
    tolua_function(tolua_S,"get_text",tolua_luabind_ge_GEOText_get_text00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEOTextFT","ge::GEOTextFT","ge::GEOText",NULL);
   tolua_beginmodule(tolua_S,"GEOTextFT");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEOTextFT_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEOTextFT_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEOTextFT_release00);
    tolua_function(tolua_S,"set_text",tolua_luabind_ge_GEOTextFT_set_text00);
    tolua_function(tolua_S,"set_font",tolua_luabind_ge_GEOTextFT_set_font00);
    tolua_function(tolua_S,"set_rect",tolua_luabind_ge_GEOTextFT_set_rect00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEOTextBM","ge::GEOTextBM","ge::GEOText",NULL);
   tolua_beginmodule(tolua_S,"GEOTextBM");
    tolua_function(tolua_S,"create",tolua_luabind_ge_GEOTextBM_create00);
    tolua_function(tolua_S,"retain",tolua_luabind_ge_GEOTextBM_retain00);
    tolua_function(tolua_S,"release",tolua_luabind_ge_GEOTextBM_release00);
    tolua_function(tolua_S,"set_font",tolua_luabind_ge_GEOTextBM_set_font00);
    tolua_function(tolua_S,"set_text",tolua_luabind_ge_GEOTextBM_set_text00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_IPOINT","ge::GE_IPOINT","",tolua_collect_ge__GE_IPOINT);
   #else
   tolua_cclass(tolua_S,"GE_IPOINT","ge::GE_IPOINT","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_IPOINT");
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_IPOINT_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_IPOINT_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_IPOINT_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_IPOINT_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_IPOINT_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_IPOINT_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_IPOINT_delete00);
    tolua_variable(tolua_S,"x",tolua_get_ge__GE_IPOINT_x,tolua_set_ge__GE_IPOINT_x);
    tolua_variable(tolua_S,"y",tolua_get_ge__GE_IPOINT_y,tolua_set_ge__GE_IPOINT_y);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_ISIZE","ge::GE_ISIZE","",tolua_collect_ge__GE_ISIZE);
   #else
   tolua_cclass(tolua_S,"GE_ISIZE","ge::GE_ISIZE","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_ISIZE");
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_ISIZE_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_ISIZE_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_ISIZE_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_ISIZE_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_ISIZE_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_ISIZE_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_ISIZE_delete00);
    tolua_variable(tolua_S,"width",tolua_get_ge__GE_ISIZE_width,tolua_set_ge__GE_ISIZE_width);
    tolua_variable(tolua_S,"height",tolua_get_ge__GE_ISIZE_height,tolua_set_ge__GE_ISIZE_height);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_IRECT","ge::GE_IRECT","",tolua_collect_ge__GE_IRECT);
   #else
   tolua_cclass(tolua_S,"GE_IRECT","ge::GE_IRECT","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_IRECT");
    tolua_variable(tolua_S,"left",tolua_get_ge__GE_IRECT_left,tolua_set_ge__GE_IRECT_left);
    tolua_variable(tolua_S,"top",tolua_get_ge__GE_IRECT_top,tolua_set_ge__GE_IRECT_top);
    tolua_variable(tolua_S,"right",tolua_get_ge__GE_IRECT_right,tolua_set_ge__GE_IRECT_right);
    tolua_variable(tolua_S,"bottom",tolua_get_ge__GE_IRECT_bottom,tolua_set_ge__GE_IRECT_bottom);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_IRECT_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_IRECT_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_IRECT_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_IRECT_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_IRECT_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_IRECT_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_IRECT_delete00);
    tolua_function(tolua_S,"width",tolua_luabind_ge_GE_IRECT_width00);
    tolua_function(tolua_S,"height",tolua_luabind_ge_GE_IRECT_height00);
    tolua_function(tolua_S,"move",tolua_luabind_ge_GE_IRECT_move00);
    tolua_function(tolua_S,"move_to",tolua_luabind_ge_GE_IRECT_move_to00);
    tolua_function(tolua_S,"include",tolua_luabind_ge_GE_IRECT_include00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_FPOINT","ge::GE_FPOINT","",tolua_collect_ge__GE_FPOINT);
   #else
   tolua_cclass(tolua_S,"GE_FPOINT","ge::GE_FPOINT","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_FPOINT");
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FPOINT_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FPOINT_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FPOINT_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FPOINT_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FPOINT_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FPOINT_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_FPOINT_delete00);
    tolua_variable(tolua_S,"x",tolua_get_ge__GE_FPOINT_x,tolua_set_ge__GE_FPOINT_x);
    tolua_variable(tolua_S,"y",tolua_get_ge__GE_FPOINT_y,tolua_set_ge__GE_FPOINT_y);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_FSIZE","ge::GE_FSIZE","",tolua_collect_ge__GE_FSIZE);
   #else
   tolua_cclass(tolua_S,"GE_FSIZE","ge::GE_FSIZE","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_FSIZE");
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FSIZE_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FSIZE_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FSIZE_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FSIZE_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FSIZE_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FSIZE_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_FSIZE_delete00);
    tolua_variable(tolua_S,"width",tolua_get_ge__GE_FSIZE_width,tolua_set_ge__GE_FSIZE_width);
    tolua_variable(tolua_S,"height",tolua_get_ge__GE_FSIZE_height,tolua_set_ge__GE_FSIZE_height);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_FRECT","ge::GE_FRECT","",tolua_collect_ge__GE_FRECT);
   #else
   tolua_cclass(tolua_S,"GE_FRECT","ge::GE_FRECT","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_FRECT");
    tolua_variable(tolua_S,"left",tolua_get_ge__GE_FRECT_left,tolua_set_ge__GE_FRECT_left);
    tolua_variable(tolua_S,"top",tolua_get_ge__GE_FRECT_top,tolua_set_ge__GE_FRECT_top);
    tolua_variable(tolua_S,"right",tolua_get_ge__GE_FRECT_right,tolua_set_ge__GE_FRECT_right);
    tolua_variable(tolua_S,"bottom",tolua_get_ge__GE_FRECT_bottom,tolua_set_ge__GE_FRECT_bottom);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FRECT_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FRECT_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FRECT_new00_local);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_FRECT_new01);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_FRECT_new01_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_FRECT_new01_local);
    tolua_function(tolua_S,"delete",tolua_luabind_ge_GE_FRECT_delete00);
    tolua_function(tolua_S,"width",tolua_luabind_ge_GE_FRECT_width00);
    tolua_function(tolua_S,"height",tolua_luabind_ge_GE_FRECT_height00);
    tolua_function(tolua_S,"move",tolua_luabind_ge_GE_FRECT_move00);
    tolua_function(tolua_S,"move_to",tolua_luabind_ge_GE_FRECT_move_to00);
    tolua_function(tolua_S,"include",tolua_luabind_ge_GE_FRECT_include00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GE_VERTEX_DECL","ge::GE_VERTEX_DECL","",tolua_collect_ge__GE_VERTEX_DECL);
   #else
   tolua_cclass(tolua_S,"GE_VERTEX_DECL","ge::GE_VERTEX_DECL","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GE_VERTEX_DECL");
    tolua_variable(tolua_S,"fvf",tolua_get_ge__GE_VERTEX_DECL_fvf,tolua_set_ge__GE_VERTEX_DECL_fvf);
    tolua_variable(tolua_S,"size",tolua_get_ge__GE_VERTEX_DECL_size,tolua_set_ge__GE_VERTEX_DECL_size);
    tolua_function(tolua_S,"new",tolua_luabind_ge_GE_VERTEX_DECL_new00);
    tolua_function(tolua_S,"new_local",tolua_luabind_ge_GE_VERTEX_DECL_new00_local);
    tolua_function(tolua_S,".call",tolua_luabind_ge_GE_VERTEX_DECL_new00_local);
    tolua_function(tolua_S,"is_valid",tolua_luabind_ge_GE_VERTEX_DECL_is_valid00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GEVertexDecl","ge::GEVertexDecl","",NULL);
   tolua_beginmodule(tolua_S,"GEVertexDecl");
    tolua_function(tolua_S,"get_instance",tolua_luabind_ge_GEVertexDecl_get_instance00);
    tolua_function(tolua_S,"get_vertex_decl",tolua_luabind_ge_GEVertexDecl_get_vertex_decl00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GE_VERTEX","ge::GE_VERTEX","",NULL);
   tolua_beginmodule(tolua_S,"GE_VERTEX");
    tolua_function(tolua_S,"set_fvf",tolua_luabind_ge_GE_VERTEX_set_fvf00);
    tolua_function(tolua_S,"set_decl",tolua_luabind_ge_GE_VERTEX_set_decl00);
    tolua_function(tolua_S,"get_decl",tolua_luabind_ge_GE_VERTEX_get_decl00);
    tolua_function(tolua_S,"set_position",tolua_luabind_ge_GE_VERTEX_set_position00);
    tolua_function(tolua_S,"set_normal",tolua_luabind_ge_GE_VERTEX_set_normal00);
    tolua_function(tolua_S,"set_texcoords",tolua_luabind_ge_GE_VERTEX_set_texcoords00);
    tolua_function(tolua_S,"set_blend",tolua_luabind_ge_GE_VERTEX_set_blend00);
    tolua_function(tolua_S,"set_color",tolua_luabind_ge_GE_VERTEX_set_color00);
    tolua_function(tolua_S,"set_rhw",tolua_luabind_ge_GE_VERTEX_set_rhw00);
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

