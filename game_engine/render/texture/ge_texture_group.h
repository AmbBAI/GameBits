#ifndef _GAME_ENGINE_OBJECT_TEXTURE_GROUP_H_
#define _GAME_ENGINE_OBJECT_TEXTURE_GROUP_H_

#include "../../common/ge_include.h"
#include "ge_texture.h"

namespace ge
{

class GE_API GETextureGroup
{
	DLL_MANAGE_CLASS(GETextureGroup);

protected:
	GETextureGroup();
	virtual ~GETextureGroup();

public:
	virtual int add_texture();
	virtual int add_texture(GETexture* texture);
	virtual int add_texture_from_file(const char* texture_path);
	virtual GETexture* get_texture(int texture_id = 0);
	virtual bool replace_texture(int texture_id, const char* texture_path);
	virtual void release_texture(int texture_id);
	virtual void release_all_texture();
	virtual void destory();

	int get_texture_cnt();

protected:
	typedef std::vector<GETexture*> TEXTURE_LIST;
	TEXTURE_LIST			texture_list_;
};

} // namespace ge

#endif // _GAME_ENGINE_OBJECT_TEXTURE_GROUP_H_