#ifndef _GAME_ENGINE_GRAPHICS_H_
#define _GAME_ENGINE_GRAPHICS_H_

#include "common/ge_include.h"
#include "type/ge_vector3.h"
#include "type/ge_quaternion.h"
#include "type/ge_matrix4x4.h"

namespace ge
{

class Mesh;
class Camera;
class Material;
class GE_API Graphics
{
protected:
	Graphics() {}
	virtual ~Graphics() {}

public:
	static void draw_mesh(
		Mesh* mesh,
		Vector3 position,
		Quaternion rotation,
		Material* material,
		int layer,
		Camera* camera = NULL,
		int submesh_index = 0);
	
	static void draw_mesh(
		Mesh* mesh,
		Matrix4x4 matrix,
		Material* material,
		int layer,
		Camera* camera = NULL,
		int submesh_index = 0);

};

} // namespace ge

#endif // _GAME_ENGINE_GRAPHICS_H_