
function new_spine_test()
	spine_test = ge.GEOSpine:create()
	spine_test:init("texture\\goblins.atlas", "texture\\goblins.json")
	spine_test:set_skin("goblingirl")
	spine_test:set_mix("walk", "jump", 0.3)
	spine_test:set_animation("walk")
	return spine_test
end

function new_fps_text()
	fps_font = ge.GEFontManager:create_font(ge.FontType_FTFont)
	fps_font = tolua.cast(fps_font, "ge::GEFontFT")
	fps_font:init("font\\simkai.ttf", 32);
	
	fps_text = ge.GEOTextFT:create()
	rect = ge.GE_IRECT:new(0, 0, 500, 400);
	fps_text:set_rect(rect);
	fps_text:set_font(fps_font);
	fps_text:set_text("hello lua!")

	return fps_text
end



