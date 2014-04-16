#include "ge_draw.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEDraw);

GEDraw::GEDraw()
: effect_(NULL)
, drawcall_cnt_(0)
, drawvertex_cnt_(0)
{

}

GEDraw::~GEDraw()
{

}

void GEDraw::render()
{

}

bool GEDraw::set_effect( GEREffect* effect )
{
	effect_ = effect;
	return true;
}

GEREffect* GEDraw::get_effect()
{
	return effect_;
}



}