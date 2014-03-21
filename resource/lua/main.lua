
print("hello lua!")

ge_app = ge.GEApp:get_instance()
ge_game = ge.GEGame:get_instance()

scene_test = require "lua/scene_a"
ge_game:add_scene(scene_test)

ge_app:run()

ge_game:remove_all_scenes()
ge.GEScene:release(scene_test)

print("exit!")