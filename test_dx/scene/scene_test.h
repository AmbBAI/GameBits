#ifndef _SCENE_SCENE_TEST_H_
#define _SCENE_SCENE_TEST_H_

#include "game_engine.h"

class SceneTest : public ge::GEScene
{
public:
	SceneTest();

public:
	bool init_fps_text();
	bool init_gdi_text();
	bool init_bm_text();
	bool init_ft_text();

public:
	virtual bool show();
	virtual bool hide();

	virtual void update(time_t time_elapsed);
	virtual void render(time_t time_elapsed);

	virtual void update_camera();
	virtual void update_fps_text();

public:

	int					fps_font_id_;
	ge::GEOTextDX*		p_fps_text_;

	ge::GEOTextGDI*		p_gdi_text_;

	ge::GEOTextBM*		p_bm_text_;

	ge::GEOTextFT*		p_ft_text_;

	ge::GEOSpine*		p_spine_;

	ge::GEOArmature*	p_armature_;

	D3DXVECTOR3			position;
	D3DXVECTOR3			target;
	D3DXVECTOR3			up;

};

#endif //_SCENE_SCENE_TEST_H_