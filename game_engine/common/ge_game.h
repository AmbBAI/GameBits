#ifndef _GAME_ENGINE_GAME_H_
#define _GAME_ENGINE_GAME_H_

#include "ge_include.h"

namespace ge
{

class Scene;

class GE_API GEGame
{
protected:
	GEGame();
	virtual ~GEGame();


public:
	static GEGame* get_instance();

public:
	void		process();

	int			add_scene(Scene* ge_scene);
	bool		is_valid_scene(int scene_id);
	Scene*	get_scene(int scene_id);
	bool		switch_scene(int scene_id);
	void		remove_scene(int scene_id);
	void		remove_all_scenes();

private:
	typedef std::vector<Scene*> GE_SCENE_VEC;
	GE_SCENE_VEC	scene_vec_;
	int				cur_scene_id_;
};

} // namespace ge

#endif // _GAME_ENGINE_GAME_H_