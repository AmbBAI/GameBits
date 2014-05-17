
local sound

local sid
local is_pause

local function scene_init_callback()

	game_info = require("game_info")
	scene_test:add_object(99999999, game_info)

	sound = ge.GEFMODSound:create()
	sound:init("media/wave.mp3")
	sid = sound:play(1)
	is_pause = false
end

local function scene_destory_callback()
	sound:release()
	sound = nil
end

local function scene_update_callback(delta)
	ge_app = ge.GEApp:get_instance()
	ge_input = ge.GEInput:get_instance()
	ge_render = ge.GERender:get_instance()

	game_info:update(delta)


	if ge_input:get_mouse_down(0) then
		sound:pause(not is_pause, sid)
		is_pause = not is_pause
	end
end

scene_test = ge.GELuaScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

