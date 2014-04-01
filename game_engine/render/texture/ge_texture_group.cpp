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
	destory();
}

void GETextureGroup::destory()
{
	release_all_texture();
}

int GETextureGroup::add_texture()
{
	GETexture* texture = GETexture::create();
	texture->retain();
	texture_list_.push_back(texture);
	return (int)texture_list_.size() - 1;
}

int GETextureGroup::add_texture( GETexture* texture )
{
	if (texture) texture->retain();
	texture_list_.push_back(texture);
	return (int)texture_list_.size() - 1;
}

int GETextureGroup::add_texture_from_file( const char* texture_path )
{
	GETexture* texture = GETextureManager::create_texture(texture_path);
	return add_texture(texture);
}

GETexture* GETextureGroup::get_texture( int texture_id/* = 0*/ )
{
	if (texture_id < 0) return NULL;
	if ((int)texture_list_.size() <= texture_id) return NULL;
	return texture_list_[texture_id];
}

void GETextureGroup::release_texture( int texture_id )
{
	if (texture_id < 0) return;
	if ((int)texture_list_.size() <= texture_id) return;
	GE_RELEASE(texture_list_[texture_id]);
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