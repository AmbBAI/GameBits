#include "ge_draw.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEDraw);

GEDraw::GEDraw()
: effect_(NULL)
{

}

GEDraw::~GEDraw()
{

}

void GEDraw::render( time_t delta )
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