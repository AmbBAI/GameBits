#ifndef _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_
#define _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_

#include "common/ge_include.h"
#include "object/ge_object.h"
#include "object/ge_object_def.h"

#include "spine/spine.h"
#include "spine/extension.h"

//struct spAtlas;
//struct spSkeleton;
//struct spSkeletonJson;
//struct spSkeletonData;
//struct spAnimation;
//struct spAnimationState;
//struct spAnimationStateData;

namespace ge
{

struct GE_VERTEX_DECL;
class GEAtlasDraw;
class GETexture;

class GE_API GEOSpine : public Object
{
	DLL_MANAGE_CLASS(GEOSpine);

	GEOSpine();
	virtual ~GEOSpine();

public:
	virtual bool init(const char* atlas_file, const char* skeleton_file);
	virtual void destory();

	virtual void update(time_t delta);

	bool set_skin(const char* skin_name);
	bool set_mix(const char* from_ani, const char* to_ani, float duration);
	bool set_animation(const char* ani_name, bool loop = true);
	bool add_animation(const char* ani_name, bool loop = false, float delay = 0.f);

protected:
	bool _init_render();
	void _do_render();

private:
	spAtlas*				p_atlas_;
	spSkeleton*				p_skeleton_;
	spSkeletonJson*			p_skeleton_json_;
	spSkeletonData*			p_skeleton_data_;
	spAnimation*			p_animation_;
	spAnimationState*		p_animation_state_;
	spAnimationStateData*	p_animation_state_data_;

	GEAtlasDraw*			render_object_;
	typedef std::map<GETexture*, int> PAGE_ID_MAP;
	PAGE_ID_MAP				page_id_map_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_ANIMATION_SPINE_H_