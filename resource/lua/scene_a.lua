
local function new_spine_test()
	new_spine = ge.GEOSpine:create()
	new_spine:init("texture\\goblins.atlas", "texture\\goblins.json")
	new_spine:set_skin("goblingirl")
	new_spine:set_mix("walk", "jump", 0.3)
	new_spine:set_animation("walk")
	return new_spine
end

local function new_fps_text()
	new_font = ge.GEFontManager:create_font(ge.FontType_FTFont)
	new_font = tolua.cast(new_font, "ge::GEFontFT")
	new_font:init("font\\simsun.ttc", 32);
	
	new_text = ge.GEOTextFT:create()
	rect = ge.GE_IRECT:new(0, 0, 500, 400);
	new_text:set_rect(rect);
	new_text:set_font(new_font);
	new_text:set_text("hello lua!")
	return new_text
end

local spine_test = nil
local text_test = nil

local function scene_init_callback()
	spine_test = new_spine_test()
	scene_test:add_object(1, spine_test)

	text_test = new_fps_text()
	scene_test:add_object(2, text_test)
end

local function scene_destory_callback()
	ge.GEOSpine:release(spine_test)
	ge.GEOTextFT:release(text_test)
	spine_test = nil
	text_test = nil
end

local function scene_update_callback()
	ge_app = ge.GEApp:get_instance()
	fps = ge_app:get_fps()

	text_test:set_text(string.format("fps: %.2f", fps))
end

scene_test = ge.GEScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

