#include "ge_primitive_draw.h"
#include "../ge_render.h"
#include "ge_drawbuff.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEPrimitiveDrawTask);

void GEPrimitiveDrawTask::render()
{
	GEPrimitiveDraw* ge_draw_primitive = GEPrimitiveDraw::get_instance();
	switch (type)
	{
	case GEPrimitiveType_Point:
		break;
	case GEPrimitiveType_LineList:
	case GEPrimitiveType_Rect:
	case GEPrimitiveType_Polygon:
		ge_draw_primitive->_draw_line_strip(this);
		break;
	case GEPrimitiveType_SolidRect:
	case GEPrimitiveType_SolidPolygon:
		ge_draw_primitive->_draw_triangle_strip(this);
		break;
	}
	ge_draw_primitive->_release_task(this);
}



const unsigned GEPrimitiveDraw::DEFAULT_FVF_FORMAT = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);

GEPrimitiveDraw::GEPrimitiveDraw()
: task_cnt_(0)
, task_pool_()
, vertex_list_()
, vertex_decl_(NULL)
, draw_buff_(NULL)
{

}

GEPrimitiveDraw::~GEPrimitiveDraw()
{
	_release_render();
}

GEPrimitiveDraw* GEPrimitiveDraw::get_instance()
{
	static GEPrimitiveDraw _global_ge_draw_primitive;
	return &_global_ge_draw_primitive;
}

int GEPrimitiveDraw::_get_cur_offset()
{
	return vertex_list_.size();
}

GEPrimitiveDrawTask* GEPrimitiveDraw::_create_task()
{
	GEPrimitiveDrawTask* task = NULL;
	if (task_pool_.empty())
	{
		task = GEPrimitiveDrawTask::create();
	}
	else
	{
		task = task_pool_.front();
		task_pool_.pop();
	}

	GERender::push_render(task);
	++ task_cnt_;
	return task;
}

void GEPrimitiveDraw::_release_task( GEPrimitiveDrawTask* task )
{
	task_pool_.push(task);
	-- task_cnt_;
	if (task_cnt_ <= 0)
	{
		task_cnt_ = 0;
		vertex_list_.clear();
	}
}

bool GEPrimitiveDraw::_push_vertex( GE_VERTEX& vertex )
{
	vertex_list_.push_back(vertex);
	return true;
}

bool GEPrimitiveDraw::_init_render()
{
	if (draw_buff_ == NULL)
		draw_buff_ = GEDrawBuff::create();
	if (draw_buff_ == NULL) return false;

	vertex_decl_ = GEVertexDecl::get_vertex_decl(DEFAULT_FVF_FORMAT);
	if (!draw_buff_->set_vertex_decl(vertex_decl_)) return false;
	if (!draw_buff_->init_vertex_buff(vertex_list_.size())) return false;

	if (!draw_buff_->set_verties(&vertex_list_[0], vertex_list_.size())) return false;
	return true;
}

void GEPrimitiveDraw::_release_render()
{
	if (draw_buff_)
	{
		draw_buff_->destory_buff();
		GEDrawBuff::release(&draw_buff_);
	}
	draw_buff_ = NULL;
}

bool GEPrimitiveDraw::draw_rect( GE_FRECT& rect, unsigned color )
{
	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = 4;
	task->type = GEPrimitiveType_Rect;

	GE_VERTEX vertex[5];

	float minx = rect.left;
	float miny = rect.top;
	float maxx = rect.right;
	float maxy = rect.bottom;

	vertex[0].set_position(minx, miny, 0.f);
	vertex[1].set_position(minx, maxy, 0.f);
	vertex[2].set_position(maxx, maxy, 0.f);
	vertex[3].set_position(maxx, miny, 0.f);
	vertex[4].set_position(minx, miny, 0.f);

	for (int i=0; i<5; ++i)
	{
		vertex[i].set_fvf(DEFAULT_FVF_FORMAT);
		vertex[i].set_rhw(1.f);
		vertex[i].set_color(color);
		ge_draw_primitive->_push_vertex(vertex[i]);
	}

	return true;
}

bool GEPrimitiveDraw::draw_solid_rect( GE_FRECT& rect, unsigned color )
{
	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = 2;
	task->type = GEPrimitiveType_SolidRect;

	GE_VERTEX vertex[4];

	float minx = rect.left;
	float miny = rect.top;
	float maxx = rect.right;
	float maxy = rect.bottom;

	vertex[0].set_position(minx, miny, 0.f);
	vertex[1].set_position(minx, maxy, 0.f);
	vertex[2].set_position(maxx, miny, 0.f);
	vertex[3].set_position(maxx, maxy, 0.f);

	for (int i=0; i<4; ++i)
	{
		vertex[i].set_fvf(DEFAULT_FVF_FORMAT);
		vertex[i].set_rhw(1.f);
		vertex[i].set_color(color);
		ge_draw_primitive->_push_vertex(vertex[i]);
	}

	return true;
}

bool GEPrimitiveDraw::_draw_line_strip( GEPrimitiveDrawTask* task )
{
	if (!_init_render()) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (draw_buff_ == NULL) return false;
	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->DrawPrimitive(D3DPT_LINESTRIP,
		task->offset,			// StartVertex
		task->count);			// PrimitiveCount
	assert(SUCCEEDED(h_res));
	return SUCCEEDED(h_res);
}

bool GEPrimitiveDraw::_draw_triangle_strip( GEPrimitiveDrawTask* task )
{
	if (!_init_render()) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (draw_buff_ == NULL) return false;
	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		task->offset,			// StartVertex
		task->count);			// PrimitiveCount
	assert(SUCCEEDED(h_res));
	return SUCCEEDED(h_res);
}



}