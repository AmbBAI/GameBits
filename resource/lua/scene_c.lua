
local sound

local sid
local is_pause

local function scene_init_callback()

	game_info = require("game_info")
	scene_test:add_object(99999999, game_info)

	sound = ge.GEFMODSound:create()
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

	ge_fmod = ge.GEFMOD:get_instance()
	c_cnt = ge_fmod:get_channels_playing()
	mem_use = ge_fmod:get_memory_use()
	wave = ge_fmod:get_current_wave()

	info = string.format([[
		channels: %d / %d
		fmod-mem: %d
		]], c_cnt, 32, mem_use)
	game_info:clear_info()
	game_info:add_info(info)
	game_info:update(delta)

	dis = wave * 100
	local seg = math.min(200, math.max(dis * 6.28 / 6, 16))
	ge.GEPrimitiveDraw:draw_circle(ge.GE_FPOINT(200, 200), dis, seg, ge.GE_COLOR( 0xff, 0x00, 0x88, 0x77))

	if ge_input:get_key_down(ge.GEInput.KC_L) then
		sound:init("media/wave.mp3")
	elseif ge_input:get_key_down(ge.GEInput.KC_K) then
		sound:destory()
	end

	if ge_input:get_mouse_down(0) then
		sid = sound:play(false)
	end
end

scene_test = ge.GELuaScene:create()
print(scene_test, tolua.type(scene_test))
scene_test:set_init_func(scene_init_callback)
scene_test:set_destory_func(scene_destory_callback)
scene_test:set_update_func(scene_update_callback)

return scene_test

