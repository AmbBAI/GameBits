#ifndef _GAME_ENGINE_RENDER_DRAW_PRIMITIVE_H_
#define _GAME_ENGINE_RENDER_DRAW_PRIMITIVE_H_

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
	GEPrimitiveType_LineList,
	GEPrimitiveType_Rect,
	GEPrimitiveType_SolidRect,
	GEPrimitiveType_Polygon,
	GEPrimitiveType_SolidPolygon,
	//GEPrimitiveType_Circle,
	//GEPrimitiveType_SolidCircle,
};

class GE_API GEPrimitiveDrawTask : public GEDraw
{
public:
	int				offset;
	int				count;
	GEPrimitiveType type;

	virtual void render();
};

class GEDrawBuff;
class GE_API GEDrawPrimitive
{
	DLL_MANAGE_CLASS(GEDrawPrimitive);

	friend GEPrimitiveDrawTask;

protected:
	GEDrawPrimitive();
	virtual ~GEDrawPrimitive();

public:
	static const unsigned DEFAULT_FVF_FORMAT;
	static GEDrawPrimitive* get_instance();

	//static bool draw_point(GE_FPOINT& point, unsigned color);
	//static bool draw_line(GE_FPOINT& from, GE_FPOINT& to, unsigned color);
	//static bool draw_line_list(GE_FPOINT* list, int cnt, unsigned color);
	static bool draw_rect(GE_FRECT& rect, unsigned color);
	//static bool draw_solid_rect(GE_FRECT& rect, unsigned color);

protected:
	int _get_cur_offset();
	bool _push_vertex(GE_VERTEX& vertex);

	bool _init_render();
	void _release_render();
	bool _push_task(const GEPrimitiveDrawTask& task);

	bool _draw_line_strip(GEPrimitiveDrawTask* task);
	//bool _draw_triangle_strip(GEPrimitiveDrawTask* task);

private:
	std::vector<GE_VERTEX> vertex_list_;
	std::vector<GEPrimitiveDrawTask> task_list_;

	GE_VERTEX_DECL*			vertex_decl_;
	GEDrawBuff*				draw_buff_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_DRAW_PRIMITIVE_H_