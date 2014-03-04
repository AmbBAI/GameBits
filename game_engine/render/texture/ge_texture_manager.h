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
	static GETexture* create_texture();
	static GETexture* create_texture(const char* texture_path);
	static bool refer_texture(GETexture* texture);
	static void release_texture(GETexture* texture);

	static GETextureGroup* create_texture_group();
	static bool refer_texture_group(GETextureGroup* texture_group);
	static void release_texture_group(GETextureGroup* texture_group);

protected:
	GETextureManager();
	virtual ~GETextureManager();

	static GETextureManager* get_instance();

protected:
	virtual GETexture* _create_texture();
	virtual bool _refer_texture(GETexture* texture);
	virtual void _release_texture(GETexture* texture);

	virtual GETextureGroup* _create_texture_group();
	virtual bool _refer_texture_group(GETextureGroup* texture_group);
	virtual void _release_texture_group(GETextureGroup* texture_group);

private:
	typedef std::map<std::string, GETexture*> TEXTURE_KEY_MAP;
	typedef std::map<GETexture*, int> TEXTURE_REF_MAP;
	TEXTURE_KEY_MAP		texture_key_map_;
	TEXTURE_REF_MAP		texture_ref_map_;

	typedef std::map<GETextureGroup*, int> TEXTURE_GROUP_REF_MAP;
	TEXTURE_GROUP_REF_MAP		texture_group_ref_map_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXTURE_MANAGER_H_