
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
	new_font:init("font\\simsun.ttc", 18);
	
	new_text = ge.GEOTextFT:create()
	rect = ge.GE_IRECT:new(0, 0, 0, 0);
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
	ge_input = ge_app:get_input()

	fps = ge_app:get_fps()
	ret, mx, my = ge_input:get_mouse_pos(0, 0)
	fps_text = string.format("fps: %.2f\n", fps)
	fps_text = fps_text .. string.format("mouse: %d, %d\n", mx, my)

	if ge_input:get_key_hold(ge.GEInput.KC_UP) then
		fps_text = fps_text .. "U"
	end

	if ge_input:get_key_hold(ge.GEInput.KC_LEFT) then
		fps_text = fps_text .. "L"
	end

	if ge_input:get_key_hold(ge.GEInput.KC_RIGHT) then
		fps_text = fps_text .. "R"
	end

	if ge_input:get_key_hold(ge.GEInput.KC_DOWN) then
		fps_text = fps_text .. "D"
	end

	text_test:set_text(fps_text)
end

scene_test = ge.GEScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

