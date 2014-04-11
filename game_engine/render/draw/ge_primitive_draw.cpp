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
		ge_draw_primitive->_draw_point_list(this);
		break;
	case GEPrimitiveType_LineStrip:
	case GEPrimitiveType_Rect:
	case GEPrimitiveType_Polygon:
	case GEPrimitiveType_Circle:
		ge_draw_primitive->_draw_line_strip(this);
		break;
	case GEPrimitiveType_SolidRect:
	case GEPrimitiveType_SolidPolygon:
	case GEPrimitiveType_SolidCircle:
		ge_draw_primitive->_draw_triangle_fan(this);
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
	{
		draw_buff_ = GEDrawBuff::create();
		if (draw_buff_) draw_buff_->retain();
	}
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
		GE_RELEASE(draw_buff_);
	}
	draw_buff_ = NULL;
}

bool GEPrimitiveDraw::draw_point( GE_FPOINT& point, unsigned color )
{
	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = 1;
	task->type = GEPrimitiveType_Point;

	GE_VERTEX vertex;
	vertex.set_position(point.x, point.y, 0.f);
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);
	ge_draw_primitive->_push_vertex(vertex);

	return true;
}

bool GEPrimitiveDraw::draw_point( GE_FPOINT* list, int cnt, unsigned color )
{
	if (list == NULL) return false;
	if (cnt <= 0) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = cnt;
	task->type = GEPrimitiveType_Point;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	for (int i=0; i<cnt; ++i)
	{
		vertex.set_position(list[i].x, list[i].y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}

	return true;
}

bool GEPrimitiveDraw::draw_line( GE_FPOINT& from, GE_FPOINT& to, unsigned color )
{
	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = 1;
	task->type = GEPrimitiveType_LineStrip;

	GE_VERTEX verties[2];

	verties[0].set_position(from.x, from.y, 0.f);
	verties[1].set_position(to.x, to.y, 0.f);

	for (int i=0; i<2; ++i)
	{
		verties[i].set_fvf(DEFAULT_FVF_FORMAT);
		verties[i].set_rhw(1.f);
		verties[i].set_color(color);
		ge_draw_primitive->_push_vertex(verties[i]);
	}

	return true;
}

bool GEPrimitiveDraw::draw_line_strip( GE_FPOINT* list, int cnt, unsigned color )
{
	if (list == NULL) return false;
	if (cnt <= 1) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = cnt - 1;
	task->type = GEPrimitiveType_LineStrip;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	for (int i=0; i<cnt; ++i)
	{
		vertex.set_position(list[i].x, list[i].y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}

	return true;
}

bool GEPrimitiveDraw::draw_rect( GE_FRECT& rect, unsigned color )
{
	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = 4;
	task->type = GEPrimitiveType_Rect;

	GE_VERTEX verties[5];

	float minx = rect.left;
	float miny = rect.top;
	float maxx = rect.right;
	float maxy = rect.bottom;

	verties[0].set_position(minx, miny, 0.f);
	verties[1].set_position(minx, maxy, 0.f);
	verties[2].set_position(maxx, maxy, 0.f);
	verties[3].set_position(maxx, miny, 0.f);
	verties[4].set_position(minx, miny, 0.f);

	for (int i=0; i<5; ++i)
	{
		verties[i].set_fvf(DEFAULT_FVF_FORMAT);
		verties[i].set_rhw(1.f);
		verties[i].set_color(color);
		ge_draw_primitive->_push_vertex(verties[i]);
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

	GE_VERTEX verties[4];

	float minx = rect.left;
	float miny = rect.top;
	float maxx = rect.right;
	float maxy = rect.bottom;

	verties[0].set_position(minx, miny, 0.f);
	verties[1].set_position(minx, maxy, 0.f);
	verties[2].set_position(maxx, maxy, 0.f);
	verties[3].set_position(maxx, miny, 0.f);

	for (int i=0; i<4; ++i)
	{
		verties[i].set_fvf(DEFAULT_FVF_FORMAT);
		verties[i].set_rhw(1.f);
		verties[i].set_color(color);
		ge_draw_primitive->_push_vertex(verties[i]);
	}

	return true;
}

bool GEPrimitiveDraw::draw_polygon( GE_FPOINT* list, int cnt, unsigned color )
{
	if (list == NULL) return false;
	if (cnt <= 2) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = cnt;
	task->type = GEPrimitiveType_Polygon;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	for (int i=0; i<cnt+1; ++i)
	{
		if (i == cnt) vertex.set_position(list[0].x, list[0].y, 0.f);
		else vertex.set_position(list[i].x, list[i].y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}

	return true;
}

bool GEPrimitiveDraw::draw_solid_polygon( GE_FPOINT* list, int cnt, unsigned color )
{
	if (list == NULL) return false;
	if (cnt <= 2) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = cnt-2;
	task->type = GEPrimitiveType_Polygon;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	for (int i=0; i<cnt+1; ++i)
	{
		if (i == cnt) vertex.set_position(list[0].x, list[0].y, 0.f);
		else vertex.set_position(list[i].x, list[i].y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}

	return true;
}

bool GEPrimitiveDraw::draw_circle( GE_FPOINT& center, float radius, int segment, unsigned color )
{
	if (segment < 3) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = segment;
	task->type = GEPrimitiveType_Circle;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	const float coef = 2.0f * (float)M_PI / segment;
	for(int i = 0;i < segment + 1; i++)
	{
		float rads = i * coef;
		float x = radius * cosf(rads) + center.x;
		float y = radius * sinf(rads) + center.y;

		vertex.set_position(x, y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}
	return true;
}

bool GEPrimitiveDraw::draw_solid_circle( GE_FPOINT& center, float radius, int segment, unsigned color )
{
	if (segment < 3) return false;

	GEPrimitiveDraw* ge_draw_primitive = get_instance();

	GEPrimitiveDrawTask* task = ge_draw_primitive->_create_task();
	task->offset = ge_draw_primitive->_get_cur_offset();
	task->count = segment - 2;
	task->type = GEPrimitiveType_SolidCircle;

	GE_VERTEX vertex;
	vertex.set_fvf(DEFAULT_FVF_FORMAT);
	vertex.set_rhw(1.f);
	vertex.set_color(color);

	const float coef = 2.0f * (float)M_PI / segment;
	for(int i = 0;i < segment + 1; i++)
	{
		float rads = i * coef;
		float x = radius * cosf(rads) + center.x;
		float y = radius * sinf(rads) + center.y;

		vertex.set_position(x, y, 0.f);
		ge_draw_primitive->_push_vertex(vertex);
	}
	return true;
}

bool GEPrimitiveDraw::_draw_point_list( GEPrimitiveDrawTask* task )
{
	if (!_init_render()) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (draw_buff_ == NULL) return false;
	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->DrawPrimitive(D3DPT_POINTLIST,
		task->offset,			// StartVertex
		task->count);			// PrimitiveCount
	assert(SUCCEEDED(h_res));
	return SUCCEEDED(h_res);
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

bool GEPrimitiveDraw::_draw_triangle_fan( GEPrimitiveDrawTask* task )
{
	if (!_init_render()) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (draw_buff_ == NULL) return false;
	if (!draw_buff_->prepare_drawbuff()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->DrawPrimitive(D3DPT_TRIANGLEFAN,
		task->offset,			// StartVertex
		task->count);			// PrimitiveCount
	assert(SUCCEEDED(h_res));
	return SUCCEEDED(h_res);
}



bool GEPrimitiveDraw::draw_point( GE_FPOINT& point, GE_COLOR& color )
{
	return draw_point( point, color.argb );
}

bool GEPrimitiveDraw::draw_line( GE_FPOINT& from, GE_FPOINT& to, GE_COLOR& color )
{
	return draw_line( from, to, color.argb );
}

bool GEPrimitiveDraw::draw_rect( GE_FRECT& rect, GE_COLOR& color )
{
	return draw_rect( rect, color.argb );
}

bool GEPrimitiveDraw::draw_solid_rect( GE_FRECT& rect, GE_COLOR& color )
{
	return draw_solid_rect( rect, color.argb );
}

bool GEPrimitiveDraw::draw_circle( GE_FPOINT& center, float radius, int segment, GE_COLOR& color )
{
	return draw_circle(center, radius, segment, color.argb);
}

bool GEPrimitiveDraw::draw_solid_circle( GE_FPOINT& center, float radius, int segment, GE_COLOR& color )
{
	return draw_solid_circle(center, radius, segment, color.argb);
}

bool GEPrimitiveDraw::draw_unit( GEPrimitiveDrawUnit* unit )
{
	if (unit == NULL) return false;

	GE_FPOINT* list = &(unit->draw_point_list_[0]);
	int cnt = (int)unit->draw_point_list_.size();

	switch (unit->draw_type_)
	{
	case GEPrimitiveDrawUnit::DrawType_Point:
		return draw_point(list, cnt, unit->draw_color_);
	case GEPrimitiveDrawUnit::DrawType_Line:
		return draw_line_strip(list, cnt, unit->draw_color_);
	case GEPrimitiveDrawUnit::DrawType_Polygon:
		return draw_polygon(list, cnt, unit->draw_color_);
	case GEPrimitiveDrawUnit::DrawType_SolidPolygon:
		return draw_solid_polygon(list, cnt, unit->draw_color_);
	}
	return false;
}



GEPrimitiveDrawUnit::GEPrimitiveDrawUnit()
: draw_type_(DrawType_Point)
, draw_color_(0xffffffff)
, draw_point_list_()
{
}

GEPrimitiveDrawUnit::~GEPrimitiveDrawUnit()
{
	clear_points();
}

void GEPrimitiveDrawUnit::set_type( DrawType type )
{
	draw_type_ = type;
}

void GEPrimitiveDrawUnit::set_color( GE_COLOR& color )
{
	draw_color_ = color.argb;
}

void GEPrimitiveDrawUnit::add_point( GE_FPOINT& point )
{
	if (draw_point_list_.size() > 0
		&& draw_point_list_.back().x == point.x
		&& draw_point_list_.back().y == point.y) return;
	draw_point_list_.push_back(point);
}

void GEPrimitiveDrawUnit::clear_points()
{
	draw_point_list_.clear();
}




}