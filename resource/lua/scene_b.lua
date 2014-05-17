
local function new_text_label_ft()
	new_font = ge.GEFontManager:create_font(ge.FontType_FTFont)
	new_font = tolua.cast(new_font, "ge::GEFontFT")
	new_font:init("font\\SIMLI.TTF", 22)
	new_font:set_outline_weight(2.0)
	
	new_text = ge.GEOTextFT:create()
	new_text:set_font(new_font)
	return new_text
end

local function new_text_label_bm()
	new_font = ge.GEFontManager:create_font(ge.FontType_BMFont)
	new_font = tolua.cast(new_font, "ge::GEFontBM")
	new_font:init("bmfont\\qsmy.fnt");
	new_font:init_effect("bmfont\\font.fx");
	
	new_text = ge.GEOTextBM:create()
	new_text:set_font(new_font)
	return new_text
end

local text_test = nil
local game_info = nil
local draw_rect = ge.GE_IRECT(0, 0, 0, 0)
local temp_pos = ge.GE_FPOINT(0, 0)

local function scene_init_callback()

	game_info = require("game_info")
	scene_test:add_object(99999999, game_info)

	text_test = new_text_label_ft()
	text_test:set_text(require("qsmy"))
	text_test:set_rect(draw_rect)
	scene_test:add_object(3, text_test)
end

local function scene_destory_callback()
end

local function scene_update_callback(delta)
	ge_app = ge.GEApp:get_instance()
	ge_input = ge.GEInput:get_instance()
	ge_render = ge.GERender:get_instance()

	game_info:update(delta)


	if ge_input:get_mouse_down(0) then
		ret, temp_pos.x, temp_pos.y = ge_input:get_mouse_pos(0, 0)
	elseif ge_input:get_mouse_hold(0) then
		local p = ge.GE_FPOINT(0, 0)
		ret, p.x, p.y = ge_input:get_mouse_pos(0, 0)

		draw_rect:move(p.x - temp_pos.x, p.y - temp_pos.y)
		text_test:set_rect(draw_rect)

		temp_pos = p
	end
end

scene_test = ge.GELuaScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

