
print("hello lua!")

ge_app = ge.GEApp:get_instance()
ge_game = ge.GEGame:get_instance()

require "lua/scene_a"
scene_test = ge.GEScene:create()
ge_game:add_scene(scene_test)

spine_test = new_spine_test()
scene_test:add_object(1, spine_test)

text_test = new_fps_text()
scene_test:add_object(2, text_test)

ge_app:run()

ge_game:remove_all_scenes()
ge.GEScene:remove(scene_test)
ge.GEOSpine:remove(spine_test)
ge.GEOTextFT:remove(text_test)

print("exit!")