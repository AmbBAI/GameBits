
local function new_spine_test()
	new_spine = ge.GEOSpine:create()
	new_spine:init("texture\\goblins.atlas", "texture\\goblins.json")
	new_spine:set_skin("goblingirl")
	new_spine:set_mix("walk", "jump", 0.3)
	new_spine:set_animation("walk")
	return new_spine
end

local spine_test = nil
local text_test = nil
local game_info = nil
local drag_rect = ge.GE_FRECT(0, 0, 0, 0)
local drag_line = ge.GEPrimitiveDrawUnit()
drag_line:set_type(ge.GEPrimitiveDrawUnit.DrawType_Line)
drag_line:set_color(ge.GE_COLOR( 0xff, 0xff, 0x88, 0x00))

local function scene_init_callback()
	--spine_test = new_spine_test()
	--scene_test:add_object(1, spine_test)

	game_info = require("game_info")
	scene_test:add_object(99999999, game_info)
end

local function scene_destory_callback()
end

local function scene_update_callback(delta)
	ge_app = ge.GEApp:get_instance()
	ge_input = ge.GEInput:get_instance()
	ge_render = ge.GERender:get_instance()

	game_info:update(delta)

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

