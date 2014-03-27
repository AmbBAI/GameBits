#include "ge_draw_atlas.h"
#include "../../common/ge_engine.h"
#include "../../render/texture/ge_texture_manager.h"
#include "../../render/ger_effect.h"
#include "ge_drawbuff.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEDrawAtlas);

const DWORD GEDrawAtlas::DEFAULT_FVF_FORMAT = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

GEDrawAtlas::GEDrawAtlas()
: draw_buff_(NULL)
, vertex_list_()
, vertex_decl_(NULL)
, texture_group_(NULL)
, need_render_update_(true)
{
	set_vertex_fvf(DEFAULT_FVF_FORMAT);
}

GEDrawAtlas::~GEDrawAtlas()
{
	destory();
}

bool GEDrawAtlas::init()
{
	return true;
}

void GEDrawAtlas::destory()
{
	release_render();
	release_texture_group();

	vertex_decl_ = NULL;
}

bool GEDrawAtlas::init_texture_group()
{
	if (texture_group_ == NULL)
		texture_group_ = GETextureGroup::create();

	if (texture_group_ == NULL) return false;
	return true;
}

bool GEDrawAtlas::set_texture_group( GETextureGroup* texture_group )
{
	release_texture_group();
	texture_group_ = texture_group;
	if (texture_group_) GETextureManager::refer_texture_group(texture_group_);
	return true;
}

GETextureGroup* GEDrawAtlas::get_texture_group()
{
	return texture_group_;
}

void GEDrawAtlas::release_texture_group()
{
	if (texture_group_)
	{
		GETextureManager::release_texture_group(texture_group_);
		texture_group_ = NULL;
	}
}

bool GEDrawAtlas::set_vertex_fvf( DWORD fvf )
{
	return set_vertex_decl(GEVertexDecl::get_vertex_decl(fvf));
}

bool GEDrawAtlas::set_vertex_decl( GE_VERTEX_DECL* vertex_decl )
{
	if (vertex_decl == NULL) return false;
	if (!vertex_decl->is_valid()) return false;

	vertex_decl_ = vertex_decl;

	release_render();
	return true;
}

GE_VERTEX_DECL* GEDrawAtlas::get_vertex_decl()
{
	return vertex_decl_;
}

bool GEDrawAtlas::init_render()
{
	if (draw_buff_ == NULL)
		draw_buff_ = GEDrawBuff::create();
	if (draw_buff_ == NULL) return false;

	draw_buff_->set_vertex_decl(vertex_decl_);
	return draw_buff_->init_quad_buff(vertex_list_.size() / 4);
}

bool GEDrawAtlas::update_render()
{
	if (draw_buff_ == NULL) return false;
	return draw_buff_->set_verties(&vertex_list_[0], vertex_list_.size());
}

bool GEDrawAtlas::_update_render_task( int quad_index, int texture_id )
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

void GEDrawAtlas::release_render()
{
	if (draw_buff_)
	{
		draw_buff_->destory_buff();
		GEDrawBuff::release(&draw_buff_);
	}
	draw_buff_ = NULL;
}

bool GEDrawAtlas::add_quad( GE_QUAD_EX& quad )
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

bool GEDrawAtlas::add_quad( GE_QUAD& quad )
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

bool GEDrawAtlas::add_quad( int texture_id /*= 0*/ )
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

void GEDrawAtlas::clear_quads()
{
	vertex_list_.clear();
	render_task_list_.clear();
	need_render_update_ = true;
}

bool GEDrawAtlas::draw_quads( GEREffect* effect/* = NULL*/ )
{
	if (need_render_update_)
	{
		if (!init_render()) return false;
		if (!update_render()) return false;
		need_render_update_ = false;
	}

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
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
					vertex_list_.size(),		// NumVertices
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
				vertex_list_.size(),		// NumVertices
				task->offset * 6,		// StartIndex
				task->count * 2);		// PrimitiveCount
			assert(SUCCEEDED(h_res));
		}
	}
	if (effect) effect->set_texture("TEXTURE0", NULL);
	else GETexture::use_null_texture();
	return true;
}

void GEDrawAtlas::render()
{
	draw_quads(effect_);
}

}