#include "geo_spine.h"
#include "common/ge_app.h"
#include "common/ge_input.h"
#include "utility/ge_type.h"
#include "utility/ge_vertex.h"
#include "render/texture/ge_texture_manager.h"
#include "render/ge_render.h"
#include "render/draw/ge_draw.h"
#include "render/draw/ge_atlas_draw.h"

void _spAtlasPage_createTexture (spAtlasPage* self, const char* path) {
	if (self == NULL) return;
	ge::GETexture* render_object = ge::GETextureManager::create_texture(path);
	if (render_object == NULL) return;
	render_object->get_size(self->width, self->height);
	self->rendererObject = (void*)render_object;
}

void _spAtlasPage_disposeTexture (spAtlasPage* self) {
	ge::GETexture* render_object = (ge::GETexture*)(self->rendererObject);
	GE_RELEASE(render_object);
}

char* _spUtil_readFile (const char* path, int* length) {
	return _readFile(path, length);
}

namespace ge {

DLL_MANAGE_CLASS_IMPLEMENT(GEOSpine);

GEOSpine::GEOSpine()
: p_atlas_(NULL)
, p_skeleton_json_(NULL)
, p_skeleton_data_(NULL)
, p_skeleton_(NULL)
, p_animation_(NULL)
, p_animation_state_(NULL)
, p_animation_state_data_(NULL)

, render_object_(NULL)
{

}

GEOSpine::~GEOSpine()
{
	destory();
}

bool GEOSpine::init(const char* atlas_file, const char* skeleton_file)
{
	p_atlas_ = spAtlas_readAtlasFile(atlas_file);
	p_skeleton_json_ = spSkeletonJson_create(p_atlas_);
	p_skeleton_data_ = spSkeletonJson_readSkeletonDataFile(p_skeleton_json_, skeleton_file);
	if (!p_skeleton_data_) return false;

	p_skeleton_ = spSkeleton_create(p_skeleton_data_);
	spSkeleton_setToSetupPose(p_skeleton_);

	p_animation_state_data_ = spAnimationStateData_create(p_skeleton_data_);

	p_animation_state_ = spAnimationState_create(p_animation_state_data_);

	return _init_render();
}

void GEOSpine::destory()
{
	if(p_animation_state_)		spAnimationState_dispose(p_animation_state_);
	if(p_animation_state_data_)	spAnimationStateData_dispose(p_animation_state_data_);
	if(p_skeleton_)				spSkeleton_dispose(p_skeleton_);
	if(p_skeleton_data_)		spSkeletonData_dispose(p_skeleton_data_);
	if(p_skeleton_json_)		spSkeletonJson_dispose(p_skeleton_json_);
	if(p_atlas_)				spAtlas_dispose(p_atlas_);
	p_animation_state_			= NULL;
	p_animation_state_data_		= NULL;
	p_skeleton_					= NULL;
	p_skeleton_data_			= NULL;
	p_skeleton_json_			= NULL;
	p_atlas_					= NULL;

	GE_RELEASE(render_object_);
	page_id_map_.clear();
}

void GEOSpine::update( time_t delta )
{
	if (p_skeleton_ == NULL) return;
	spSkeleton_update(p_skeleton_, delta / 1000.f);
	spAnimationState_update(p_animation_state_, delta / 1000.f);
	spAnimationState_apply(p_animation_state_, p_skeleton_);

	if (p_skeleton_ == NULL) return;
	spSkeleton_updateWorldTransform(p_skeleton_);

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return;
	p_d3d_device->SetTransform(D3DTS_WORLD, &get_world_transform());

	_do_render();
}

bool GEOSpine::set_skin( const char* skin_name )
{
	if (p_skeleton_ == NULL) return false;
	int ret = spSkeleton_setSkinByName(p_skeleton_, skin_name);
	spSkeleton_setToSetupPose(p_skeleton_);
	return ret != 0;
}


bool GEOSpine::set_mix( const char* from_ani, const char* to_ani, float duration )
{
	if (p_animation_state_data_ == NULL) return false;
	spAnimationStateData_setMixByName(p_animation_state_data_, from_ani, to_ani, duration);
	return true;
}

bool GEOSpine::set_animation( const char* ani_name, bool loop /*= true*/ )
{
	if (p_animation_state_ == NULL) return false;
	spAnimationState_setAnimationByName(p_animation_state_, 0, "walk", loop);
	return true;
}

bool GEOSpine::add_animation( const char* ani_name, bool loop /*= false*/, float delay /*= 0.f*/ )
{
	if (p_animation_state_ == NULL) return false;
	spAnimationState_addAnimationByName(p_animation_state_, 0, ani_name, loop, delay);
	return true;
}


bool GEOSpine::_init_render()
{
	if (render_object_ == NULL) render_object_ = GEAtlasDraw::create();
	if (render_object_ == NULL) return false;

	render_object_->set_vertex_fvf(D3DFVF_XYZ | D3DFVF_TEX1);
	render_object_->init_texture_group();

	GETextureGroup* texture_group = render_object_->get_texture_group();
	if (texture_group == NULL) return false;
	texture_group->release_all_texture();

	spAtlasPage* page = p_atlas_->pages;
	while (page != NULL)
	{
		GETexture* texture = (GETexture*)page->rendererObject;
		if (texture)
		{
			page_id_map_[texture] = texture_group->get_texture_cnt();
			texture_group->add_texture(texture);
		}
		page = page->next;
	}
	return true;
}

void GEOSpine::_do_render()
{
	if (p_atlas_ == NULL) return;
	if (p_skeleton_ == NULL) return;
	if (render_object_ == NULL) return;

	int slot_cnt = p_skeleton_->slotCount;

	render_object_->clear_quads();

	int region_offset = 0;
	for (int i=0; i<slot_cnt; ++i)
	{
		spSlot* slot = p_skeleton_->slots[i];
		spAttachment* attachment = slot->attachment;
		if (attachment && attachment->type ==  ATTACHMENT_REGION)
		{
			spRegionAttachment* region_attachment = (spRegionAttachment*)attachment;
			if (region_attachment == NULL) continue;

			GETexture* render_object = (GETexture*)region_attachment->rendererObject;
			if (render_object == NULL) continue;

			float xys[8], *uvs;
			spRegionAttachment_computeWorldVertices(region_attachment, 0.f, 0.f, slot->bone, xys);
			uvs = region_attachment->uvs;

			GE_QUAD quad;
			quad.texid = page_id_map_[render_object];

			for (int ii=0; ii<8; ++ii)
			{
				quad.xys[ii] = xys[ii];
				quad.uvs[ii] = uvs[ii];
			}

			render_object_->add_quad(quad);
		}
	}

	GERender::push_render(render_object_);
}

}
