#ifndef _GAME_ENGINE_GL_INTERFACE_H_
#define _GAME_ENGINE_GL_INTERFACE_H_

#include "common/ge_include.h"
#include "type/ge_rect.h"
#include "type/ge_color.h"
#include "component/ge_camera.h"
#include "ge_gl.h"

namespace ge
{
	
class GL_Interface
{
public:
	GL_Interface() : is_initialized(false) {}
	virtual ~GL_Interface() {}

public:
	virtual bool initialize_by_config() = 0;
	virtual bool initialize(
		int width,
		int height,
		bool is_windowed,
		bool vsync) = 0;
	virtual void finalize() = 0;

	virtual bool change_resolution(int width, int height) = 0;
	virtual bool change_windowed(bool is_windowed) = 0;

public:

	virtual void begin(GL::Mode mode) = 0;
	virtual void end() = 0;

	virtual void clear(bool clear_depth, bool clear_color, Color background_color, float depth = 1.0f) = 0;
	virtual void clear_with_skibox(bool clear_depth, Camera camera) = 0;

	virtual void viewport(Rect pixel_rect) = 0;

protected:
	bool is_initialized = false;
};

} // namespace ge

#endif // _GAME_ENGINE_GL_INTERFACE_H_