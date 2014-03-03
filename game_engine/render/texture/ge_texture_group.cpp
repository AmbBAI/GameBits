#include "ge_texture_group.h"
#include "ge_texture_manager.h"
#include "ge_texture.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GETextureGroup);

GETextureGroup::GETextureGroup()
: texture_list_()
{
}


GETextureGroup::~GETextureGroup()
{
	release_all_texture();
}

int GETextureGroup::add_texture()
{
	GETexture* texture = GETextureManager::create_texture();
	texture_list_.push_back(texture);
	return (int)texture_list_.size() - 1;
}

int GETextureGroup::add_texture( GETexture* texture )
{
	texture_list_.push_back(texture);
	return (int)texture_list_.size() - 1;
}

int GETextureGroup::add_texture_from_file( const char* texture_path )
{
	GETexture* texture = GETextureManager::create_texture(texture_path);
	texture_list_.push_back(texture);
	return (int)texture_list_.size() - 1;
}

GETexture* GETextureGroup::get_texture( int texture_id/* = 0*/ )
{
	if (texture_id < 0) return NULL;
	if ((int)texture_list_.size() <= texture_id) return NULL;
	return texture_list_[texture_id];
}

bool GETextureGroup::replace_texture( int texture_id, const char* texture_path )
{
	if (texture_id < 0) return false;
	if ((int)texture_list_.size() <= texture_id) return false;
	release_texture(texture_id);
	texture_list_[texture_id] = GETextureManager::create_texture(texture_path);
	return true;
}

void GETextureGroup::release_texture( int texture_id )
{
	if (texture_id < 0) return;
	if ((int)texture_list_.size() <= texture_id) return;
	GETexture* texture = texture_list_[texture_id];
	if (texture)
	{
		GETextureManager::release_texture(texture);
		texture_list_[texture_id] = NULL;
	}
}

void GETextureGroup::release_all_texture()
{
	for (int i=0; i<(int)texture_list_.size(); ++i)
	{
		release_texture(i);
	}
	texture_list_.clear();
}

int GETextureGroup::get_texture_cnt()
{
	return (int)texture_list_.size();
}

}