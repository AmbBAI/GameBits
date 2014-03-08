#include "geo_spine.h"
#include "../../common/ge_app.h"
#include "../../common/ge_input.h"
#include "../../utility/ge_type.h"
#include "../../utility/ge_vertex.h"
#include "../../render/texture/ge_texture_manager.h"
#include "../../render/ge_atlas_render.h"

void _spAtlasPage_createTexture (spAtlasPage* self, const char* path) {
	if (self == NULL) return;
	ge::GETexture* render_object = ge::GETextureManager::create_texture(path);
	if (render_object == NULL) return;
	render_object->get_size(self->width, self->height);
	self->rendererObject = (void*)render_object;
}

void _spAtlasPage_disposeTexture (spAtlasPage* self) {
	ge::GETexture* render_object = (ge::GETexture*)(self->rendererObject);
	if (render_object == NULL) return;
	ge::GETextureManager::release_texture(render_object);
	render_object = NULL;
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
, draw_bone_mesh_(true)
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
	spSkeleton_setSkinByName(p_skeleton_, "goblingirl");
	spSkeleton_setToSetupPose(p_skeleton_);

	p_animation_state_data_ = spAnimationStateData_create(p_skeleton_data_);
	spAnimationStateData_setMixByName(p_animation_state_data_, "walk", "jump", 0.3f);
	spAnimationStateData_setMixByName(p_animation_state_data_, "jump", "walk", 0.3f);
	spAnimationStateData_setMixByName(p_animation_state_data_, "jump", "jump", 0.3f);

	p_animation_state_ = spAnimationState_create(p_animation_state_data_);
	spAnimationState_setAnimationByName(p_animation_state_, 0, "walk", true);

	return init_render();
}

void GEOSpine::destory()
{
	if(p_animation_state_)		spAnimationState_dispose(p_animation_state_);
	if(p_animation_state_data_)	spAnimationStateData_dispose(p_animation_state_data_);
	if(p_skeleton_)				spSkeleton_dispose(p_skeleton_);
	if(p_skeleton_data_)		spSkeletonData_dispose(p_skeleton_data_);
	if(p_skeleton_json_)		spSkeletonJson_dispose(p_skeleton_json_);
	if(p_atlas_)				spAtlas_dispose(p_atlas_);
}

void GEOSpine::update( time_t delta )
{
	GEInput* p_input = GEApp::get_instance()->get_input();
	if (p_input)
	{
		if (p_input->get_key_down(DIK_J))
		{		
			spAnimationState_addAnimationByName(p_animation_state_, 0, "jump", false, 0);
			spAnimationState_addAnimationByName(p_animation_state_, 0, "walk", true, 0);
		}
		if (p_input->get_key_down(DIK_D))
			draw_bone_mesh_ = !draw_bone_mesh_;
	}

	if (p_skeleton_ == NULL) return;
	spSkeleton_update(p_skeleton_, delta / 1000.f);
	spAnimationState_update(p_animation_state_, delta / 1000.f);
	spAnimationState_apply(p_animation_state_, p_skeleton_);
}

void GEOSpine::render( time_t delta )
{
	if (p_skeleton_ == NULL) return;
	spSkeleton_updateWorldTransform(p_skeleton_);

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return;
	p_d3d_device->SetTransform(D3DTS_WORLD, &get_world_transform());

	_do_render();
	if (draw_bone_mesh_)
		_do_bone_render();
}

bool GEOSpine::init_render()
{
	if (render_object_ == NULL) render_object_ = GEAtlasRender::create();
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

	render_object_->prepare_render();
	render_object_->draw_quads();
}

void GEOSpine::_do_bone_render()
{
	//if (p_skeleton_ == NULL) return;

	//int slot_cnt = p_skeleton_->slotCount;

	//std::vector<GE_VERTEX> vertex_buff;
	//vertex_buff.resize(slot_cnt * 3);

	//int render_bone_cnt = 0;
	//for (int i=0; i<slot_cnt; ++i)
	//{
	//	spSlot* slot = p_skeleton_->slots[i];
	//	if (slot == NULL) continue;

	//	const spBone* bone = slot->bone;
	//	if (bone == NULL) continue;

	//	const spBoneData* bone_data = bone->data;
	//	if (bone_data == NULL) continue;

	//	if (bone_data->length - FLT_EPSILON < 0.f) continue;

	//	float plx = 0.f, ply = -5.f;
	//	float prx = 0.f, pry = 5.f;
	//	float ptx = bone->data->length, pty = 0.f;

	//	float fangle = bone->worldRotation / 180.f * 3.141592654f;
	//	float fsin = sin(fangle);
	//	float fcos = cos(fangle);

	//	float vlx = plx * fcos - ply * fsin + bone->worldX;
	//	float vly = plx * fsin + ply * fcos + bone->worldY;
	//	float vrx = prx * fcos - pry * fsin + bone->worldX;
	//	float vry = prx * fsin + pry * fcos + bone->worldY;
	//	float vtx = ptx * fcos - pty * fsin + bone->worldX;
	//	float vty = ptx * fsin + pty * fcos + bone->worldY;

	//	int vertex_offset = render_bone_cnt * 3;
	//	GE_VERTEX vertex;
	//	vertex.set_decl(bone_vertex_decl_);
	//	vertex.set_color(0xffffffff);

	//	vertex.set_position(vlx, vly, 0.f);
	//	vertex_buff[vertex_offset + 0] = vertex;

	//	vertex.set_position(vrx, vry, 0.f);
	//	vertex_buff[vertex_offset + 1] = vertex;

	//	vertex.set_position(vtx, vty, 0.f);
	//	vertex_buff[vertex_offset + 2] = vertex;

	//	++ render_bone_cnt;
	//}

	//if (bone_mesh_.get_vertex_buff_size() <= 0)
	//{
	//	bone_mesh_.set_vertex_decl(bone_vertex_decl_);
	//	bone_mesh_.create_vetrix_buff(slot_cnt * 3);
	//}

	//bone_mesh_.set_vertices(&vertex_buff[0], 0, render_bone_cnt * 3);
	//bone_mesh_.set_primitive_draw(0, render_bone_cnt);
	//bone_mesh_.render(0);
}
}
