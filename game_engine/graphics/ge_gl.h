#ifndef _GAME_ENGINE_GL_H_
#define _GAME_ENGINE_GL_H_

#include "common/ge_include.h"
#include "type/ge_rect.h"
#include "type/ge_color.h"
#include "component/ge_camera.h"

namespace ge
{

class GE_API GL
{
private:
	GL();
	virtual ~GL();

public:
	enum Mode
	{
		TRIANGLES,
		TRIANGLES_STRIP,
		QUADS,
		LINES
	};

public:
	static void begin(Mode mode);
	static void end();

	static void clear(bool clear_depth, bool clear_color, Color background_color, float depth = 1.0f);
	static void clear_with_skibox(bool clear_depth, Camera camera);

	static void viewport(Rect pixel_rect);
};

} // namespace ge

#endif // _GAME_ENGINE_GL_H_