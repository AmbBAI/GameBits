#ifndef _GAME_ENGINE_OBJECT_TEXTURE_MANAGER_H_
#define _GAME_ENGINE_OBJECT_TEXTURE_MANAGER_H_

#include "../../common/ge_include.h"
#include "ge_texture_group.h"
#include "ge_texture.h"

namespace ge
{

class GE_API GETextureManager
{
public:
	static GETexture* create_texture(const char* texture_path);
	//static GETexture* bind_texture(const char* texture_key, GETexture* texture);
	static void release_texture(const char* texture_key);

protected:
	GETextureManager();
	virtual ~GETextureManager();

	static GETextureManager* get_instance();

private:
	typedef std::map<std::string, GETexture*> TEXTURE_KEY_MAP;
	TEXTURE_KEY_MAP		texture_key_map_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXTURE_MANAGER_H_