#ifndef _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_
#define _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_

#include "../../common/ge_include.h"
#include "../../utility/ge_vertex.h"
#include "../../utility/ge_type.h"
#include "ge_draw.h"

namespace ge
{

enum GEPrimitiveType
{
	GEPrimitiveType_Null = 0,
	GEPrimitiveType_Point,
	GEPrimitiveType_LineStrip,
	GEPrimitiveType_Rect,
	GEPrimitiveType_SolidRect,
	GEPrimitiveType_Polygon,
	GEPrimitiveType_SolidPolygon,
	GEPrimitiveType_Circle,
	GEPrimitiveType_SolidCircle,
};

class GE_API GEPrimitiveDrawTask : public GEDraw
{
	DLL_MANAGE_CLASS(GEPrimitiveDrawTask);

public:
	int				offset;
	int				count;
	GEPrimitiveType type;

	virtual void render();
};

class GEDrawBuff;
class GEPrimitiveDrawUnit;
class GE_API GEPrimitiveDraw
{
	friend GEPrimitiveDrawTask;

protected:
	GEPrimitiveDraw();
	virtual ~GEPrimitiveDraw();

public:
	static const unsigned DEFAULT_FVF_FORMAT;
	static const unsigned DEFAULT_VERTEX_BLOCK_SIZE;
	static GEPrimitiveDraw* get_instance();

	static bool draw_point(GE_FPOINT& point, unsigned color);
	static bool draw_point(GE_FPOINT* list, int cnt, unsigned color);
	static bool draw_line(GE_FPOINT& from, GE_FPOINT& to, unsigned color);
	static bool draw_line_strip(GE_FPOINT* list, int cnt, unsigned color);
	static bool draw_rect(GE_FRECT& rect, unsigned color);
	static bool draw_solid_rect(GE_FRECT& rect, unsigned color);
	static bool draw_polygon(GE_FPOINT* list, int cnt, unsigned color);
	static bool draw_solid_polygon(GE_FPOINT* list, int cnt, unsigned color);
	static bool draw_circle(GE_FPOINT& center, float radius, int segment, unsigned color);
	static bool draw_solid_circle(GE_FPOINT& center, float radius, int segment, unsigned color);

	static bool draw_point(GE_FPOINT& point, GE_COLOR& color);
	static bool draw_line(GE_FPOINT& from, GE_FPOINT& to, GE_COLOR& color);
	static bool draw_rect(GE_FRECT& rect, GE_COLOR& color);
	static bool draw_solid_rect(GE_FRECT& rect, GE_COLOR& color);
	static bool draw_circle(GE_FPOINT& center, float radius, int segment, GE_COLOR& color);
	static bool draw_solid_circle(GE_FPOINT& center, float radius, int segment, GE_COLOR& color);
	static bool draw_unit(GEPrimitiveDrawUnit* draw_obj);

protected:
	int _get_cur_offset();
	bool _push_vertex(GE_VERTEX& vertex);

	bool _init_render();
	void _release_render();

	GEPrimitiveDrawTask* _create_task();
	void _release_task(GEPrimitiveDrawTask* task);

	bool _draw_point_list(GEPrimitiveDrawTask* task);
	bool _draw_line_strip(GEPrimitiveDrawTask* task);
	bool _draw_triangle_strip(GEPrimitiveDrawTask* task);
	bool _draw_triangle_fan(GEPrimitiveDrawTask* task);

private:
	std::vector<GE_VERTEX> vertex_list_;
	std::queue<GEPrimitiveDrawTask*> task_pool_;
	int						task_cnt_;

	GE_VERTEX_DECL*			vertex_decl_;
	GEDrawBuff*				draw_buff_;
};

class GE_API GEPrimitiveDrawUnit
{
	friend GEPrimitiveDraw;

public:
	GEPrimitiveDrawUnit();
	virtual ~GEPrimitiveDrawUnit();

public:
	enum DrawType
	{
		DrawType_Point = 0,
		DrawType_Line,
		DrawType_Polygon,
		DrawType_SolidPolygon,
	};

	void set_type(DrawType type);
	void set_color(GE_COLOR& color);
	void add_point(GE_FPOINT& point);
	void clear_points();

protected:
	DrawType				draw_type_;
	U32						draw_color_;
	std::vector<GE_FPOINT>	draw_point_list_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_