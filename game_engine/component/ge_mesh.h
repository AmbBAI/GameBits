#ifndef _GAME_ENGINE_MESH_H_
#define _GAME_ENGINE_MESH_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "component/ge_component.h"
#include "type/ge_vector3.h"
#include "type/ge_vector2.h"
#include "type/ge_color.h"

namespace ge
{

class GE_API Mesh : Component
{
	DLL_MANAGE_CLASS(Mesh);

protected:
	std::vector<Vector3> verties;
	std::vector<int> triangles;
	std::vector<Vector3> normals;
	std::vector<Color32> colors32;
	std::vector<Vector2> uv;
	std::vector<Vector2> uv2;
};

}

#endif //_GAME_ENGINE_MESH_H_