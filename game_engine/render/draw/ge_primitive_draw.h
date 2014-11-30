#ifndef _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_
#define _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_

#include "common/ge_include.h"
#include "utility/ge_vertex.h"
#include "utility/ge_type.h"
#include "ge_draw.h"

namespace ge
{
//
//enum GEPrimitiveType
//{
//	GEPrimitiveType_Null = 0,
//	GEPrimitiveType_Point,
//	GEPrimitiveType_LineStrip,
//	GEPrimitiveType_Rect,
//	GEPrimitiveType_SolidRect,
//	GEPrimitiveType_Polygon,
//	GEPrimitiveType_SolidPolygon,
//	GEPrimitiveType_Circle,
//	GEPrimitiveType_SolidCircle,
//};
//
//class GE_API GEPrimitiveDrawTask : public GEDraw
//{
//	DLL_MANAGE_CLASS(GEPrimitiveDrawTask);
//
//public:
//	int				offset;
//	int				count;
//	GEPrimitiveType type;
//
//	virtual void render();
//};
//
//class GEDrawBuff;
//class GEPrimitiveDrawUnit;
//class GE_API GEPrimitiveDraw
//{
//	friend GEPrimitiveDrawTask;
//
//protected:
//	GEPrimitiveDraw();
//	virtual ~GEPrimitiveDraw();
//
//public:
//	static const unsigned DEFAULT_FVF_FORMAT;
//	static const unsigned DEFAULT_VERTEX_BLOCK_SIZE;
//	static GEPrimitiveDraw* get_instance();
//
//	static bool draw_point(Vector2& point, unsigned color);
//	static bool draw_point(Vector2* list, int cnt, unsigned color);
//	static bool draw_line(Vector2& from, Vector2& to, unsigned color);
//	static bool draw_line_strip(Vector2* list, int cnt, unsigned color);
//	static bool draw_rect(Rect& rect, unsigned color);
//	static bool draw_solid_rect(Rect& rect, unsigned color);
//	static bool draw_polygon(Vector2* list, int cnt, unsigned color);
//	static bool draw_solid_polygon(Vector2* list, int cnt, unsigned color);
//	static bool draw_circle(Vector2& center, float radius, int segment, unsigned color);
//	static bool draw_solid_circle(Vector2& center, float radius, int segment, unsigned color);
//
//	static bool draw_point(Vector2& point, Color& color);
//	static bool draw_line(Vector2& from, Vector2& to, Color& color);
//	static bool draw_rect(Rect& rect, Color& color);
//	static bool draw_solid_rect(Rect& rect, Color& color);
//	static bool draw_circle(Vector2& center, float radius, int segment, Color& color);
//	static bool draw_solid_circle(Vector2& center, float radius, int segment, Color& color);
//	static bool draw_unit(GEPrimitiveDrawUnit* draw_obj);
//
//protected:
//	int _get_cur_offset();
//	bool _push_vertex(GE_VERTEX& vertex);
//
//	bool _init_render();
//	void _release_render();
//
//	GEPrimitiveDrawTask* _create_task();
//	void _release_task(GEPrimitiveDrawTask* task);
//
//	bool _draw_point_list(GEPrimitiveDrawTask* task);
//	bool _draw_line_strip(GEPrimitiveDrawTask* task);
//	bool _draw_triangle_strip(GEPrimitiveDrawTask* task);
//	bool _draw_triangle_fan(GEPrimitiveDrawTask* task);
//
//private:
//	std::vector<GE_VERTEX> vertex_list_;
//	std::queue<GEPrimitiveDrawTask*> task_pool_;
//	int						task_cnt_;
//
//	GE_VERTEX_DECL*			vertex_decl_;
//	GEDrawBuff*				draw_buff_;
//};
//
//class GE_API GEPrimitiveDrawUnit
//{
//	friend GEPrimitiveDraw;
//
//public:
//	GEPrimitiveDrawUnit();
//	virtual ~GEPrimitiveDrawUnit();
//
//public:
//	enum DrawType
//	{
//		DrawType_Point = 0,
//		DrawType_Line,
//		DrawType_Polygon,
//		DrawType_SolidPolygon,
//	};
//
//	void set_type(DrawType type);
//	void set_color(Color& color);
//	void add_point(Vector2& point);
//	void clear_points();
//
//protected:
//	DrawType				draw_type_;
//	U32						draw_color_;
//	std::vector<Vector2>	draw_point_list_;
//};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_PRIMITIVE_DRAW_H_