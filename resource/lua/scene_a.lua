
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
	new_font:init("font\\simsun.ttc", 18)
	new_font:set_outline_weight(1.0)
	
	new_text = ge.GEOTextFT:create()
	local rect = ge.GE_IRECT:new_local(0, 0, 0, 0);
	new_text:set_rect(rect);
	new_text:set_font(new_font);
	new_text:set_text("hello lua!")
	return new_text
end

local function new_fps_text2()
	new_font = ge.GEFontManager:create_font(ge.FontType_BMFont)
	new_font = tolua.cast(new_font, "ge::GEFontBM")
	new_font:init("bmfont\\arial24.fnt");
	new_font:init_effect("bmfont\\font.fx");
	
	new_text = ge.GEOTextBM:create()
	new_text:set_font(new_font);
	new_text:set_text("hello lua!")
	return new_text
end

local spine_test = nil
local text_test = nil
local text_test2 = nil
local drag_rect = ge.GE_FRECT(0, 0, 0, 0)
local drag_line = ge.GEPrimitiveDrawUnit()
drag_line:set_type(ge.GEPrimitiveDrawUnit.DrawType_Line)
drag_line:set_color(ge.GE_COLOR( 0xff, 0xff, 0x88, 0x00))

local function scene_init_callback()
	--spine_test = new_spine_test()
	--scene_test:add_object(1, spine_test)

	text_test = new_fps_text()
	scene_test:add_object(3, text_test)

	--text_test2 = new_fps_text2()
	--scene_test:add_object(2, text_test2)
end

local function scene_destory_callback()
end

local function scene_update_callback(delta)
	ge_app = ge.GEApp:get_instance()
	ge_input = ge_app:get_input()
	ge_render = ge.GERender:get_instance()

	fps = ge_app:get_fps()
	ret, mx, my = ge_input:get_mouse_pos(0, 0)
	dc, dv = ge_render:get_drawcall_cnt(), ge_render:get_drawvertex_cnt()
	fps_text = string.format("fps: %.2f\n", fps)
	fps_text = fps_text .. string.format("mouse: %d, %d\n", mx, my)
	fps_text = fps_text .. string.format("draw: %d, %d\n", dc, dv)
	fps_text = fps_text .. string.format("lua-mem: %d\n", collectgarbage("count"))

	font_obj = text_test:get_font()
	font_obj = tolua.cast(font_obj, "ge::GEFontFT")
	if fps < 1000 then
		font_obj:set_outline_weight(2.0)
	else
		font_obj:set_outline_weight(1.0)
	end

	-- if ge_input:get_key_hold(ge.GEInput.KC_UP) then
	-- 	fps_text = fps_text .. "¡ü"
	-- end

	-- if ge_input:get_key_hold(ge.GEInput.KC_LEFT) then
	-- 	fps_text = fps_text .. "¡û"
	-- end

	-- if ge_input:get_key_hold(ge.GEInput.KC_RIGHT) then
	-- 	fps_text = fps_text .. "¡ú"
	-- end

	-- if ge_input:get_key_hold(ge.GEInput.KC_DOWN) then
	-- 	fps_text = fps_text .. "¡ý"
	-- end

	text_test:set_text(fps_text)
	--text_test2:set_text(fps_text)

	local rect = ge.GE_FRECT(10, 10, 100, 100)
	ge.GEPrimitiveDraw:draw_rect(rect, ge.GE_COLOR( 0xff, 0x00, 0xff, 0xff))
	ge.GEPrimitiveDraw:draw_solid_rect(rect, ge.GE_COLOR( 0x88, 0x00, 0xff, 0xff))


	if ge_input:get_mouse_down(0) then
		p = ge.GE_FPOINT(0, 0)
		ret, p.x, p.y = ge_input:get_mouse_pos(0, 0)
		
		drag_rect.left, drag_rect.top = p.x, p.y

		drag_line:clear_points()
		drag_line:add_point(p)

	elseif ge_input:get_mouse_hold(0) then
		p = ge.GE_FPOINT(0, 0)

		ret, p.x, p.y = ge_input:get_mouse_pos(0, 0)
		drag_rect.right, drag_rect.bottom = p.x, p.y
		ge.GEPrimitiveDraw:draw_rect(drag_rect, ge.GE_COLOR( 0xff, 0xff, 0x88, 0x00))
		ge.GEPrimitiveDraw:draw_solid_rect(drag_rect, ge.GE_COLOR( 0x88, 0xff, 0x88, 0x00))

		drag_line:add_point(p)

		ge.GEPrimitiveDraw:draw_unit(drag_line)

		local from = ge.GE_FPOINT(drag_rect.left, drag_rect.top)
		local to = ge.GE_FPOINT(drag_rect.right, drag_rect.bottom)
		ge.GEPrimitiveDraw:draw_line(from, to, ge.GE_COLOR( 0xff, 0xff, 0x88, 0x00))

		local dis = from:distance(to)
		local seg = math.min(200, math.max(dis * 6.28 / 10, 16))
		ge.GEPrimitiveDraw:draw_circle(from, dis, seg, ge.GE_COLOR( 0xff, 0x00, 0x88, 0x77))
		ge.GEPrimitiveDraw:draw_solid_circle(from, dis, seg, ge.GE_COLOR( 0x88, 0x00, 0x88, 0x77))
	end
end

scene_test = ge.GELuaScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

