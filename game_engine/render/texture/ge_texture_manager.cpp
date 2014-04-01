#include "ge_texture_manager.h"
#include "ge_texture.h"

namespace ge
{

GETextureManager::GETextureManager()
: texture_key_map_()
{
}

GETextureManager::~GETextureManager()
{
}

GETextureManager* GETextureManager::get_instance()
{
	static GETextureManager _global_ge_texture_manager;
	return &_global_ge_texture_manager;
}

GETexture* GETextureManager::create_texture( const char* texture_path )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return NULL;
	TEXTURE_KEY_MAP& texture_key_map = texture_manager->texture_key_map_;
	TEXTURE_KEY_MAP::iterator itor_texture = texture_key_map.find(texture_path);
	if (itor_texture != texture_key_map.end()) return itor_texture->second;
	GETexture* texture = GETexture::create();
	if (texture)
	{
		texture->init(texture_path);
		texture->retain();
	}
	return texture;
}

void GETextureManager::release_texture(const char* texture_key)
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return ;
	TEXTURE_KEY_MAP& texture_key_map = texture_manager->texture_key_map_;
	TEXTURE_KEY_MAP::iterator itor_texture = texture_key_map.find(texture_key);
	if (itor_texture != texture_key_map.end())
	{
		GE_RELEASE((GETexture*)itor_texture->second);
		texture_key_map.erase(itor_texture);
	}
}
}