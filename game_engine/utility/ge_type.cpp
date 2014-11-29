#include "ge_type.h"

namespace ge
{

GE_IRECT::GE_IRECT()
{
	top		= 0;
	bottom	= 0;
	left	= 0;
	right	= 0;
}

GE_IRECT::GE_IRECT( int left_, int top_, int right_, int bottom_ )
{
	top		= top_;
	bottom	= bottom_;
	left	= left_;
	right	= right_;
}

void GE_IRECT::move( int offset_x, int offset_y )
{
	top		+= offset_y;
	bottom	+= offset_y;
	left	+= offset_x;
	right	+= offset_x;
}

void GE_IRECT::move_to( int pos_x, int pos_y )
{
	right	+= pos_x - left;
	left	= pos_x;
	bottom	+= pos_y - top;
	top		= pos_y;
}

void GE_IRECT::expand( int pos_x, int pos_y )
{
	if (left > pos_x)	left = pos_x;
	if (right < pos_x)	right = pos_x;
	if (top > pos_y)	top = pos_y;
	if (bottom < pos_y)	bottom = pos_y;
}

}


