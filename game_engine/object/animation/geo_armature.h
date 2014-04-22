#ifndef _GAME_ENGINE_OBJECT_ANIMATION_ARMATURE_H_
#define _GAME_ENGINE_OBJECT_ANIMATION_ARMATURE_H_

#include "common/ge_include.h"
#include "object/ge_object.h"
#include "object/ge_object_def.h"

#include "CCInclude.h"


namespace ge
{

class GE_API GEOArmature : public GEObject
{
	DLL_MANAGE_CLASS(GEOArmature);

	GEOArmature();
	virtual ~GEOArmature();

public:
	virtual void destory();

	virtual void update(time_t delta);
	virtual void render(time_t delta);

public:
	virtual bool init(const char* data_file);



private:
	CC::CCArmature* cc_armature_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_ANIMATION_ARMATURE_H_