#include "ge_texture_manager.h"
#include "ge_texture.h"

namespace ge
{

GETextureManager::GETextureManager()
: texture_key_map_()
, texture_ref_map_()
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

GETexture* GETextureManager::create_texture()
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return NULL;
	return texture_manager->_create_texture();
}

GETexture* GETextureManager::create_texture( const char* texture_path )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return NULL;
	GETexture* texture = texture_manager->_create_texture();
	if (texture) texture->init(texture_path);
	return texture;
}

bool GETextureManager::refer_texture( GETexture* texture )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return false;
	return texture_manager->_refer_texture(texture);
}

void GETextureManager::release_texture( GETexture* texture )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return;
	texture_manager->_release_texture(texture);
}

GETexture* GETextureManager::_create_texture()
{
	GETexture* texture = GETexture::create();
	texture_ref_map_[texture] = 1;
	return texture;
}

bool GETextureManager::_refer_texture( GETexture* texture )
{
	TEXTURE_REF_MAP::iterator itor_ref = texture_ref_map_.find(texture);
	if (itor_ref == texture_ref_map_.end()) return false;
	++ itor_ref->second;
	return true;
}

void GETextureManager::_release_texture( GETexture* texture )
{
	TEXTURE_REF_MAP::iterator itor_ref = texture_ref_map_.find(texture);
	if (itor_ref == texture_ref_map_.end()) return;
	int ref_cnt = -- itor_ref->second;
	if (ref_cnt == 0) {
		std::string texture_key = texture->get_key();
		texture_key_map_.erase(texture_key);

		texture->destory();
		GETexture::release(&texture);
	}
}

GETextureGroup* GETextureManager::_create_texture_group()
{
	GETextureGroup* texture_group = GETextureGroup::create();
	texture_group_ref_map_[texture_group] = 1;
	return texture_group;
}

bool GETextureManager::_refer_texture_group( GETextureGroup* texture_group )
{
	TEXTURE_GROUP_REF_MAP::iterator itor_ref = texture_group_ref_map_.find(texture_group);
	if (itor_ref == texture_group_ref_map_.end()) return false;
	++ itor_ref->second;
	return true;
}

void GETextureManager::_release_texture_group( GETextureGroup* texture_group )
{
	TEXTURE_GROUP_REF_MAP::iterator itor_ref = texture_group_ref_map_.find(texture_group);
	if (itor_ref == texture_group_ref_map_.end()) return;
	int ref_cnt = -- itor_ref->second;
	if (ref_cnt == 0) GETextureGroup::release(&texture_group);
}

GETextureGroup* GETextureManager::create_texture_group()
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return NULL;
	return texture_manager->_create_texture_group();
}

bool GETextureManager::refer_texture_group( GETextureGroup* texture_group )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return false;
	return texture_manager->_refer_texture_group(texture_group);
}

void GETextureManager::release_texture_group( GETextureGroup* texture_group )
{
	GETextureManager* texture_manager = get_instance();
	if (texture_manager == NULL) return;
	texture_manager->_release_texture_group(texture_group);
}



}