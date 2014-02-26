#ifndef _GAME_ENGINE_INCLUDE_H_
#define _GAME_ENGINE_INCLUDE_H_

#ifdef DLL_EXPORT
#define GE_API __declspec(dllexport)
#else
#define GE_API
#endif

#pragma warning (disable:4251) // ����dll����ģ�����warning

// c std include
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <assert.h>

// stl include
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <hash_map>

// win api include
#include <Windows.h>
#include <Gdiplus.h>

// d3d include
#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#define DEF_WND_STYLE ((WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX) | WS_CLIPCHILDREN | WS_VISIBLE)

#define D3D_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } } 

#define RGBA(r, g, b, a)   ((D3DCOLOR) (((a) << 24) | ((r) << 16) | ((g) << 8) | (b)))

#define FOR_EACH(type, obj, it) for (type::iterator it = obj.begin(); it != obj.end(); ++it)

#define DLL_MANAGE_CLASS(type) \
public:\
	static type* create();\
	static void release(type** ptr);\
private:

#define DLL_MANAGE_CLASS_IMPLEMENT(type) \
type* type::create()\
{\
	return new type();\
}\
\
void type::release(type** ptr)\
{\
	delete *ptr;\
	*ptr = NULL;\
}

#endif // _GAME_ENGINE_INCLUDE_H_