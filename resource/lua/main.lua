print("hello lua!")

collectgarbage("setpause", 100)
collectgarbage("setstepmul", 5000)

ge_app = ge.GEApp:get_instance()
ge_game = ge.GEGame:get_instance()

scene_test = require "lua/scene_c"
ge_game:add_scene(scene_test)

ge_app:run()

ge_game:remove_all_scenes()

print("exit!")