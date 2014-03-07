#ifndef _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_
#define _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_

#include "spine/spine.h"
#include "spine/extension.h"

#include "../../common/ge_include.h"
#include "../ge_object.h"
#include "../ge_object_def.h"

namespace ge
{

struct GE_VERTEX_DECL;
class GEAtlasRender;
class GETexture;

class GE_API GEOSpine : public GEObject
{
	DLL_MANAGE_CLASS(GEOSpine);

public:
	GEOSpine();
	virtual ~GEOSpine();

protected:
	void _do_render();
	void _do_bone_render();

public:
	virtual bool init(const char* atlas_file, const char* skeleton_file);
	virtual void destory();

	virtual void update(time_t delta);
	virtual void render(time_t delta);

	bool init_render();

private:
	spAtlas*				p_atlas_;
	spSkeleton*				p_skeleton_;
	spSkeletonJson*			p_skeleton_json_;
	spSkeletonData*			p_skeleton_data_;
	spAnimation*			p_animation_;
	spAnimationState*		p_animation_state_;
	spAnimationStateData*	p_animation_state_data_;

	GEAtlasRender*			render_object_;
	typedef std::map<GETexture*, int> PAGE_ID_MAP;
	PAGE_ID_MAP				page_id_map_;

	bool					draw_bone_mesh_;
	GEAtlasRender*			bone_mesh_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_