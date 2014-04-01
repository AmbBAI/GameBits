#ifndef _GAME_ENGINE_ENGINE_H_
#define _GAME_ENGINE_ENGINE_H_

#include "ge_include.h"

namespace ge
{

class GE_API GED3DDeviceObject
{
public:
	virtual void on_lost_device() = 0;
	virtual void on_reset_device() = 0;
};

class GERender;
class GEFontManager;

class GE_API GEEngine
{
protected:
	GEEngine();
	virtual ~GEEngine();

public:
	static LPDIRECT3DDEVICE9	get_device();
	static GEEngine*			get_instance();

public:
	bool init_engine();
	void close_engine();

	void process(time_t delta);

	void register_device_object(GED3DDeviceObject*);
	void unregister_device_object(GED3DDeviceObject*);

	bool set_resolution(int width, int height);
	bool set_windowed(bool is_windowed);
	bool get_windowed();

protected:
	bool _init_render();
	bool _init_font();

	bool _dx_begin_scene();
	bool _dx_end_scene();
	bool _dx_clear();
	bool _dx_present();
	
	bool _dx_check();
	bool _dx_reset();
	void _on_lost_device();
	void _on_reset_device();
	bool _on_dx_reset();

private:
	LPDIRECT3DDEVICE9		p_d3d_device_;
	D3DPRESENT_PARAMETERS	d3d_present_param_;

	GERender*				p_ge_render_;

	typedef std::set<GED3DDeviceObject*> DEVICE_OBJECT_SET;
	DEVICE_OBJECT_SET		device_object_set_;

	bool					is_windowed_;
};

} // namespace ge

#endif // _GAME_ENGINE_ENGINE_H_