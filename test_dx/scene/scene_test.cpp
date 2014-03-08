#include "scene_test.h"

SceneTest::SceneTest()
: p_fps_text_(NULL)
, p_gdi_text_(NULL)
, p_bm_text_(NULL)
, p_ft_text_(NULL)
, p_armature_(NULL)
, fps_font_id_(-1)
{
	position = D3DXVECTOR3(0.0f, 0.0f, -256.f);
	target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}

bool SceneTest::init_fps_text()
{
	p_fps_text_ = ge::GEOTextDX::create();
	if (p_fps_text_ == NULL) return false;

	ge::GEFont* ge_font = ge::GEFontManager::create_font(ge::FontType_D3DXFont);
	if (ge_font == NULL) return false;
	ge_font->init("consolas", 32);

	ge::GE_TEXT_STYLE style = {
		fps_font_id_,
		DT_LEFT | DT_TOP,
		RGBA(0xff, 0xff, 0xff, 0xff),
		false, 0, RGBA(0xff, 0xff, 0xff, 0xff),
		false, 0, RGBA(0xff, 0xff, 0xff, 0xff)
	};
	p_fps_text_->set_text_style(style);

	ge::GE_IRECT rect(0, 0, 400, 500);
	p_fps_text_->set_rect(rect);

	p_fps_text_->set_font(ge_font);

	add_object(10086, p_fps_text_);
	return true;
}

bool SceneTest::init_gdi_text()
{
	p_gdi_text_ = ge::GEOTextGDI::create();
	if (p_gdi_text_ == NULL) return false;

	ge::GEFont* ge_font = ge::GEFontManager::create_font(ge::FontType_GDIFont);
	if (ge_font == NULL) return false;
	ge_font->init("consolas", 32);

	ge::GE_TEXT_STYLE style = {
		fps_font_id_,
		DT_LEFT | DT_TOP,
		RGBA(0xff, 0xff, 0xff, 0xff),
		false, 0, RGBA(0xff, 0xff, 0xff, 0xff),
		false, 0, RGBA(0xff, 0xff, 0xff, 0xff)
	};
	p_gdi_text_->set_text_style(style);

	ge::GE_IRECT rect(400, 0, 800, 500);
	p_gdi_text_->set_rect(rect);

	p_gdi_text_->set_font(ge_font);

	//add_object(-10000, p_gdi_text_);
	return true;
}

bool SceneTest::init_bm_text()
{
	ge::GEFont* p_font = NULL;
	p_font = ge::GEFontManager::create_font(ge::FontType_BMFont);
	ge::GEFontBM* p_bm_font = (ge::GEFontBM*)p_font;
	p_bm_font->init("bmfont\\arial24.fnt");
	p_bm_font->init_effect("bmfont\\font.fx");

	p_bm_text_ = ge::GEOTextBM::create();
	p_bm_text_->set_font(p_bm_font);

	//add_object(0, p_bm_text_);
	return true;
}

bool SceneTest::init_ft_text()
{
	ge::GEFont* p_font = NULL;
	p_font = ge::GEFontManager::create_font(ge::FontType_FTFont);
	//p_font->init("font\\consola.ttf", 32);
	//p_font->init("font\\simsun.ttc", 32);
	//p_font->init("font\\simkai.ttf", 32);
	//p_font->init("font\\msyh.ttf", 32);
	//p_font->init("font\\PRISTINA.TTF", 32);

	p_ft_text_ = ge::GEOTextFT::create();
	if (!p_ft_text_) return false;

	ge::GE_ISIZE size;
	size.width = 1024;
	size.height = 1024;
	p_ft_text_->set_size(size);
	p_ft_text_->set_font(p_font);

	add_object(1234, p_ft_text_);
	return true;
}

bool SceneTest::show()
{
	ge::GEScene::show();

	//ge::GEApp* p_app = ge::GEApp::get_instance();
	//p_app->show_console(true);

	init_fps_text();
	init_gdi_text();
	init_bm_text();
	init_ft_text();

	//p_panel_2d_ = new Panel2D();
	//p_panel_2d_->init();
	//add_object(1, p_panel_2d_);

	p_spine_ = ge::GEOSpine::create();
	p_spine_->init("texture\\goblins.atlas", "texture\\goblins.json");
	add_object(2, p_spine_);

	p_armature_ = ge::GEOArmature::create();
	p_armature_->init("cocos/HeroAnimation.ExportJson");
	add_object(3, p_armature_);

	return true;
}


bool SceneTest::hide()
{
	//remove_object(2);
	//ge::GEOSpine::release(&p_spine_);

	//remove_object(3);
	//ge::GEOArmature::release(&p_armature_);

	//remove_object(0);
	//ge::GEOTextDX::release(&p_fps_text_);

	return true;
}

void SceneTest::update( time_t time_elapsed )
{
	update_fps_text();
	update_camera();

	ge::GEApp* p_app = ge::GEApp::get_instance();
	ge::GEInput* input = p_app->get_input();
	if (input)
	{
		if (input->get_key_down(DIK_GRAVE))
		{
			p_app->show_console(!p_app->get_console_show());
		}
	}

	ge::GEScene::update(time_elapsed);
}

void SceneTest::render(time_t time_elapsed)
{
	ge::GEScene::render(time_elapsed);
}

void SceneTest::update_camera()
{
	ge::GEApp* p_app = ge::GEApp::get_instance();

	ge::GERender* p_render = ge::GERender::get_instance();
	if (p_render == NULL) return;
	ge::GEInput* input = p_app->get_input();
	if (input == NULL) return;
	int delta_x = 0;
	int delta_y = 0;
	int delta_z = 0;
	input->get_mouse_move(delta_x, delta_y, delta_z);
	
	position.z += delta_z / 10;

	if (delta_z != 0 || input->get_mouse_hold(0))
	{
		position.x -= delta_x;
		position.y += delta_y;

		target.x -= delta_x;
		target.y += delta_y;

		p_render->do_view_trans(position, target, up);
	}

}

void SceneTest::update_fps_text()
{
	if(NULL != p_fps_text_)
	{
		ge::GEApp* p_app = ge::GEApp::get_instance();
		float fps = p_app->get_fps();

		int mouse_x, mouse_y;
		p_app->get_input()->get_mouse_pos(mouse_x, mouse_y);

		char buff[10240];
		sprintf_s(buff, "fps: %.2f\nmouse: %d, %d\n", fps, mouse_x, mouse_y);
		char rand_str[128];
		for (int i=0; i<100; ++i)
		{
			if (i%10 == 0) rand_str[i] = '\n';
			else rand_str[i] = char(rand() % (128 - 32) + 32);
		}
		rand_str[100] = 0;
		strcat(buff, "\n������Ⱦ");
		strcat(buff, rand_str);
		int len = strlen(buff);
		buff[len+1] = 0;
		buff[len] = 'A';
		if (p_fps_text_) p_fps_text_->set_text(buff);
		buff[len] = 'B';
		if (p_gdi_text_) p_gdi_text_->set_text(buff);
		buff[len] = 'C';
		if (p_bm_text_) p_bm_text_->set_text(buff);
		buff[len] = 'D';
		if (p_ft_text_) p_ft_text_->set_text(buff);
	}
}
