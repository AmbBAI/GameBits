
print("hello lua!")

ge_app = ge.GEApp:get_instance()
ge_game = ge.GEGame:get_instance()

scene_test = ge.GEScene:create()
ge_game:add_scene(scene_test)

spine_test = ge.GEOSpine:create()
scene_test:add_object(1, spine_test)

spine_test:init("texture\\goblins.atlas", "texture\\goblins.json");
spine_test:set_skin("goblingirl");
spine_test:set_mix("walk", "jump", 0.3);
spine_test:set_animation("walk");

ge_app:run()

ge_game:remove_all_scenes()
ge.GEScene:remove(scene_test)
ge.GEOSpine:remove(spine_test)

print("exit!")