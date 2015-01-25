#ifndef _GAME_ENGINE_GL_DIRECTX9_H_
#define _GAME_ENGINE_GL_DIRECTX9_H_

#include "common/ge_include.h"
#include "type/ge_rect.h"
#include "type/ge_color.h"
#include "component/ge_camera.h"
#include "ge_gl.h"
#include "ge_gl_interface.h"

// d3d include
#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>

namespace ge
{
	
class GL_DX9 : public GL_Interface
{
public:
	virtual bool initialize_by_config();
	virtual bool initialize(
		int width,
		int height,
		bool is_windowed,
		bool vsync);
	virtual void finalize();

	virtual bool change_resolution(int width, int height);
	virtual bool change_windowed(bool is_windowed);

protected:
	bool _d3d_begin_scene();
	bool _d3d_end_scene();
	bool _d3d_clear(bool clear_depth, bool clear_color, Color background_color, float depth = 1.0f);
	bool _d3d_present();
	bool _d3d_reset();
	bool _d3d_check();
	bool _on_lost_device();
	bool _on_reset_device();

public:

	virtual void begin(GL::Mode mode);
	virtual void end();

	virtual void clear(bool clear_depth, bool clear_color, Color background_color, float depth = 1.0f);
	virtual void clear_with_skibox(bool clear_depth, Camera camera);

	virtual void viewport(Rect pixel_rect);

public:
	typedef void(*void_callback)();
	void register_d3d_device_object(void* obj, void_callback lost_device_func, void_callback reset_device_func);
	void unregister_d3d_device_object(void* obj);

private:
	LPDIRECT3DDEVICE9 d3d_device_;
	D3DPRESENT_PARAMETERS d3d_present_param_;

	std::hash_map<void*, void_callback> lost_device_functions;
	std::hash_map<void*, void_callback> reset_device_functions;
};

} // namespace ge

#endif // _GAME_ENGINE_GL_DIRECTX9_H_