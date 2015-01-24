#ifndef _GAME_ENGINE_GL_DIRECTX9_H_
#define _GAME_ENGINE_GL_DIRECTX9_H_

#include "common/ge_include.h"
#include "type/ge_rect.h"
#include "type/ge_color.h"
#include "component/ge_camera.h"
#include "ge_gl.h"

// d3d include
#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>

namespace ge
{
	
class GL_DX9
{

public:
	static void begin(GL::Mode mode);
	static void end();

	static void clear(bool clear_depth, bool clear_color, Color background_color, float depth = 1.0f);
	static void clear_with_skibox(bool clear_depth, Camera camera);

	static void viewport(Rect pixel_rect);
};

} // namespace ge

#endif // _GAME_ENGINE_GL_DIRECTX9_H_