#include "ge_atlas_render.h"
#include "../common/ge_engine.h"
#include "../render/texture/ge_texture_manager.h"
#include "../render/ger_effect.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEAtlasRender);

const DWORD GEAtlasRender::DEFAULT_FVF_FORMAT = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

GEAtlasRender::GEAtlasRender()
: dx_vertex_buff_(NULL)
, dx_index_buff_(NULL)
, dx_quads_cnt_(0)
, vertex_list_()
, vertex_decl_(NULL)
, texture_group_(NULL)
, need_render_update_(true)
{
	set_vertex_fvf(DEFAULT_FVF_FORMAT);
}

GEAtlasRender::~GEAtlasRender()
{
	destory();
}

bool GEAtlasRender::init()
{
	return true;
}

void GEAtlasRender::destory()
{
	release_render();
	release_texture_group();

	vertex_decl_ = NULL;
}

bool GEAtlasRender::init_texture_group()
{
	if (texture_group_ == NULL)
		texture_group_ = GETextureGroup::create();

	if (texture_group_ == NULL) return false;
	return true;
}

bool GEAtlasRender::set_texture_group( GETextureGroup* texture_group )
{
	release_texture_group();
	texture_group_ = texture_group;
	if (texture_group_) GETextureManager::refer_texture_group(texture_group_);
	return true;
}

GETextureGroup* GEAtlasRender::get_texture_group()
{
	return texture_group_;
}

void GEAtlasRender::release_texture_group()
{
	if (texture_group_)
	{
		GETextureManager::release_texture_group(texture_group_);
		texture_group_ = NULL;
	}
}

bool GEAtlasRender::set_vertex_fvf( DWORD fvf )
{
	return set_vertex_decl(GEVertexDecl::get_vertex_decl(fvf));
}

bool GEAtlasRender::set_vertex_decl( GE_VERTEX_DECL* vertex_decl )
{
	if (vertex_decl == NULL) return false;
	if (!vertex_decl->is_valid()) return false;

	vertex_decl_ = vertex_decl;

	release_render();
	return true;
}

GE_VERTEX_DECL* GEAtlasRender::get_vertex_decl()
{
	return vertex_decl_;
}

bool GEAtlasRender::init_render()
{
	if (dx_quads_cnt_ * 4 < (int)vertex_list_.size())
	{
		release_render();

		LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
		if (p_d3d_device == NULL) return false;

		if (vertex_decl_ == NULL) return false;
		if (!vertex_decl_->is_valid()) return false;

		int quads_cnt = vertex_list_.size() / 4;
		
		HRESULT h_res = S_OK;
		std::vector<WORD> indices;
		indices.resize(quads_cnt * 6);

		h_res = p_d3d_device->CreateVertexBuffer(
			quads_cnt * 4 * vertex_decl_->size,
			D3DUSAGE_WRITEONLY,
			NULL,
			D3DPOOL_MANAGED,
			&dx_vertex_buff_,
			NULL);
		if (FAILED(h_res)) goto init_faild;

		h_res = p_d3d_device->CreateIndexBuffer(
			quads_cnt * 6 * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&dx_index_buff_,
			NULL);		
		if (FAILED(h_res)) goto init_faild;
		dx_quads_cnt_ = quads_cnt;

		for (int i=0; i<quads_cnt; ++i)
		{
			int i6 = i * 6;
			int i4 = i * 4;
			indices[i6 + 0] = i4 + 0;
			indices[i6 + 1] = i4 + 1;
			indices[i6 + 2] = i4 + 3;
			indices[i6 + 3] = i4 + 1;
			indices[i6 + 4] = i4 + 2;
			indices[i6 + 5] = i4 + 3;
		}
		if(!_set_indices(indices)) goto init_faild;
		
		return true;

init_faild:
		release_render();
		return false;

	} else return true;
}

bool GEAtlasRender::update_render()
{
	return _set_verties(vertex_list_);
}

bool GEAtlasRender::_update_render_task( int quad_index, int texture_id )
{
	int current_task = render_task_list_.size() - 1;

	if (quad_index == 0)
	{
		assert (current_task == -1);
		if (current_task != -1) return false;
	}
	else
	{
		assert (current_task != -1);
		if (current_task == -1) return false;
	}

	if (current_task == -1
		|| texture_id != render_task_list_[current_task].texture)
	{
		QUAD_RENDER_TASK render_task;
		render_task.offset = quad_index;
		render_task.count = 1;
		render_task.texture = texture_id;
		render_task_list_.push_back(render_task);
	}
	else
	{
		++ render_task_list_[current_task].count;
	}
	return true;
}

bool GEAtlasRender::_set_verties( std::vector<GE_VERTEX>& vertex_array )
{
	if (dx_vertex_buff_ == NULL) return false;

	if (vertex_decl_ == NULL) return false;
	if (!vertex_decl_->is_valid()) return false;

	int vertex_cnt = (int)vertex_array.size();
	if ( vertex_cnt > dx_quads_cnt_ * 4) return false;

	char* vertex_buff = NULL;
	HRESULT h_res = dx_vertex_buff_->Lock(
		0, vertex_cnt * vertex_decl_->size,
		(void**)&vertex_buff, 0);

	for (int i=0; i < vertex_cnt; ++i)
	{
		bool b_ret = true;
		b_ret = vertex_array[i].pack(vertex_buff, vertex_decl_->size);
		if (!b_ret)
		{
			b_ret = false;
			break;
		}

		vertex_buff += vertex_decl_->size;
	}

	dx_vertex_buff_->Unlock();
	return true;
}

bool GEAtlasRender::_set_indices( std::vector<WORD>& index_array )
{
	int index_cnt = (int)index_array.size();
	if ( index_cnt > dx_quads_cnt_ * 6) return false;

	WORD* index_buff = NULL;
	dx_index_buff_->Lock(
		0, index_cnt * sizeof(WORD),
		(void**)&index_buff, 0);
	for (int i=0; i < index_cnt; ++i)
	{
		index_buff[i] = index_array[i];
	}
	dx_index_buff_->Unlock();
	return true;
}

void GEAtlasRender::release_render()
{
	D3D_RELEASE(dx_vertex_buff_);
	D3D_RELEASE(dx_index_buff_);
	dx_quads_cnt_ = 0;
}

bool GEAtlasRender::add_quad( GE_QUAD_EX& quad )
{
	if (vertex_decl_ != quad.tl.get_decl()) return false;
	if (vertex_decl_ != quad.tr.get_decl()) return false;
	if (vertex_decl_ != quad.bl.get_decl()) return false;
	if (vertex_decl_ != quad.br.get_decl()) return false;

	int quad_index = vertex_list_.size() / 4;
	int texture_id = quad.texid;

	vertex_list_.push_back(quad.tl);
	vertex_list_.push_back(quad.tr);
	vertex_list_.push_back(quad.br);
	vertex_list_.push_back(quad.bl);
	
	_update_render_task(quad_index, texture_id);

	need_render_update_ = true;
	return true;
}

bool GEAtlasRender::add_quad( GE_QUAD& quad )
{
	int quad_index = vertex_list_.size() / 4;
	int texture_id = quad.texid;
	for (int i=0; i<4; ++i)
	{
		GE_VERTEX vertex;
		vertex.set_decl(vertex_decl_);
		vertex.set_rhw(quad.rhw);
		vertex.set_color(quad.color);
		vertex.set_position(quad.xys[i<<1], quad.xys[i<<1|1], 0.f);
		vertex.set_texcoords(quad.uvs[i<<1], quad.uvs[i<<1|1]);
		vertex_list_.push_back(vertex);
	}
	_update_render_task(quad_index, texture_id);

	need_render_update_ = true;
	return true;
}

bool GEAtlasRender::add_quad( int texture_id /*= 0*/ )
{
	if (texture_group_ == NULL) return false;

	GETexture* texture = texture_group_->get_texture(texture_id);
	if (texture == NULL) return false;

	GE_QUAD_EX out_quad;

	GE_VERTEX* vertex_ptr[4];
	vertex_ptr[0] = &(out_quad.tl);
	vertex_ptr[1] = &(out_quad.tr);
	vertex_ptr[2] = &(out_quad.br);
	vertex_ptr[3] = &(out_quad.bl);

	for (int i=0; i<4; ++i)
	{
		vertex_ptr[i]->set_decl(vertex_decl_);
		vertex_ptr[i]->set_color(0xffffffff);
	}

	int width = 0;
	int height = 0;
	texture->get_size(width, height);

	float min_x = 0.f;
	float min_y = 0.f;
	float max_x = (float)width;
	float max_y = (float)height;

	out_quad.tl.set_position(min_x, -min_y, 0.f);
	out_quad.tr.set_position(max_x, -min_y, 0.f);
	out_quad.br.set_position(max_x, -max_y, 0.f);
	out_quad.bl.set_position(min_x, -max_y, 0.f);

	out_quad.tl.set_texcoords(0.f, 0.f);
	out_quad.tr.set_texcoords(1.f, 0.f);
	out_quad.br.set_texcoords(1.f, 1.f);
	out_quad.bl.set_texcoords(0.f, 1.f);

	out_quad.texid = texture_id;

	return add_quad(out_quad);
}

void GEAtlasRender::clear_quads()
{
	vertex_list_.clear();
	render_task_list_.clear();
	need_render_update_ = true;
}

bool GEAtlasRender::draw_quads( GEREffect* effect/* = NULL*/ )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (vertex_decl_ == NULL) return false;
	if (!vertex_decl_->is_valid()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->SetStreamSource(0, dx_vertex_buff_, 0, vertex_decl_->size);
	assert(SUCCEEDED(h_res));
	h_res = p_d3d_device->SetIndices(dx_index_buff_);
	assert(SUCCEEDED(h_res));
	h_res = p_d3d_device->SetVertexDeclaration(vertex_decl_->decl);
	assert(SUCCEEDED(h_res));

	FOR_EACH (QUAD_RENDER_TASK_LIST, render_task_list_, task)
	{
		GETexture* texture = NULL;
		if (texture_group_)
			texture = texture_group_->get_texture(task->texture);
		if (effect)
		{
			effect->set_texture("TEXTURE0", texture);

			int pass_cnt = effect->begin_effect();
			for (int i=0; i<pass_cnt; ++i)
			{
				effect->begin_pass(i);
				h_res = p_d3d_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
					0,						// BaseVertexIndex
					0,						// MinVertexIndex
					dx_quads_cnt_ * 4,		// NumVertices
					task->offset * 6,		// StartIndex
					task->count * 2);		// PrimitiveCount
				assert(SUCCEEDED(h_res));
				effect->end_pass();
			}
			effect->end_effect();
		}
		else
		{
			if(texture) texture->use_texture();
			else GETexture::use_null_texture();

			h_res = p_d3d_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
				0,						// BaseVertexIndex
				0,						// MinVertexIndex
				dx_quads_cnt_ * 4,		// NumVertices
				task->offset * 6,		// StartIndex
				task->count * 2);		// PrimitiveCount
			assert(SUCCEEDED(h_res));
		}
	}
	if (effect) effect->set_texture("TEXTURE0", NULL);
	else GETexture::use_null_texture();
	return true;
}

bool GEAtlasRender::prepare_render()
{
	if (need_render_update_)
	{
		if (!init_render()) return false;
		if (!update_render()) return false;
		need_render_update_ = false;
	}
	return true;
}


}