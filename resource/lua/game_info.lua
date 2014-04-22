
local function new_text()
	new_font = ge.GEFontManager:create_font(ge.FontType_BMFont)
	new_font = tolua.cast(new_font, "ge::GEFontBM")
	new_font:init("bmfont\\game_info.fnt");
	new_font:init_effect("bmfont\\font.fx");
	
	new_text = ge.GEOTextBM:create()
	new_text:set_font(new_font);
	new_text:set_text("hello lua!")
	return new_text
end

gi_text = new_text()
function gi_text:update()
	ge_app = ge.GEApp:get_instance()
	ge_input = ge_app:get_input()
	ge_render = ge.GERender:get_instance()

	fps = ge_app:get_fps()
	ret, mx, my = ge_input:get_mouse_pos(0, 0)
	dc, dv = ge_render:get_drawcall_cnt(), ge_render:get_drawvertex_cnt()

	fps_text = string.format("fps: %.2f\n", fps)
	fps_text = fps_text .. string.format("draw: %d, %d\n", dc, dv)
	fps_text = fps_text .. string.format("lua-mem: %d\n", collectgarbage("count"))
	fps_text = fps_text .. string.format("mouse: %d, %d\n", mx, my)

	self:set_text(fps_text)
end

return gi_text

