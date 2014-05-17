
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

local function get_base_info()
	ge_app = ge.GEApp:get_instance()
	ge_input = ge.GEInput:get_instance()
	ge_render = ge.GERender:get_instance()

	fps = ge_app:get_fps()
	ret, mx, my = ge_input:get_mouse_pos(0, 0)
	dc, dv = ge_render:get_drawcall_cnt(), ge_render:get_drawvertex_cnt()

	base_text = 
	string.format("%s\n%s\n%s\n%s\n",
	string.format("fps: %.2f", fps),
	string.format("draw: %d, %d", dc, dv),
	string.format("lua-mem: %d", collectgarbage("count")),
	string.format("mouse: %d, %d", mx, my))
	return base_text
end

gameinfo_label = new_text()

local info_data = {}

function gameinfo_label:update()
	gameinfo_text = ""
	gameinfo_text = get_base_info()
	for key, info in pairs(info_data) do
		gameinfo_text = gameinfo_text .. info
	end

	self:set_text(gameinfo_text)
end

function gameinfo_label:add_info(info)
	table.insert(info_data, info)
end

function gameinfo_label:clear_info(info)
	info_data = {}
end

return gameinfo_label
