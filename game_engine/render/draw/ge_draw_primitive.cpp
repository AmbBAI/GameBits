#include "ge_draw_primitive.h"
#include "../ge_render.h"
#include "ge_drawbuff.h"

namespace ge
{


void GEPrimitiveDrawTask::render()
{
	GEDrawPrimitive* ge_draw_primitive = GEDrawPrimitive::get_instance();
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
		//ge_draw_primitive->_draw_triangle_strip(this);
		break;
	}
}




DLL_MANAGE_CLASS_IMPLEMENT(GEDrawPrimitive);


const unsigned GEDrawPrimitive::DEFAULT_FVF_FORMAT = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);

GEDrawPrimitive::GEDrawPrimitive()
{

}

GEDrawPrimitive::~GEDrawPrimitive()
{
	_release_render();
}

GEDrawPrimitive* GEDrawPrimitive::get_instance()
{
	static GEDrawPrimitive _global_ge_draw_primitive;
	return &_global_ge_draw_primitive;
}

int GEDrawPrimitive::_get_cur_offset()
{
	return task_list_.size();
}

bool GEDrawPrimitive::_push_task( const GEPrimitiveDrawTask& task )
{
	task_list_.push_back(task);
	GERender::push_render(&(task_list_.back()));
	return true;
}

bool GEDrawPrimitive::_push_vertex( GE_VERTEX& vertex )
{
	vertex_list_.push_back(vertex);
	return true;
}

bool GEDrawPrimitive::_init_render()
{
	if (draw_buff_ == NULL)
		draw_buff_ = GEDrawBuff::create();
	if (draw_buff_ == NULL) return false;

	if (!draw_buff_->set_vertex_decl(vertex_decl_)) return false;
	if (!draw_buff_->init_vertex_buff(vertex_list_.size())) return false;

	if (!draw_buff_->set_verties(&vertex_list_[0], vertex_list_.size())) return false;
	return true;
}

void GEDrawPrimitive::_release_render()
{
	if (draw_buff_)
	{
		draw_buff_->destory_buff();
		GEDrawBuff::release(&draw_buff_);
	}
	draw_buff_ = NULL;
}

bool GEDrawPrimitive::draw_rect( GE_FRECT& rect, unsigned color )
{
	GEDrawPrimitive* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask task;
	task.offset = ge_draw_primitive->_get_cur_offset();
	task.count = 5;
	task.type = GEPrimitiveType_Rect;
	ge_draw_primitive->_push_task(task);

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

bool GEDrawPrimitive::_draw_line_strip( GEPrimitiveDrawTask* task )
{
	if (!_init_render()) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (draw_buff_ == NULL) return false;
	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->DrawIndexedPrimitive(D3DPT_LINESTRIP,
		0,						// BaseVertexIndex
		0,						// MinVertexIndex
		vertex_list_.size(),	// NumVertices
		task->offset,			// StartIndex
		task->count);			// PrimitiveCount
	assert(SUCCEEDED(h_res));
	return SUCCEEDED(h_res);
}



}