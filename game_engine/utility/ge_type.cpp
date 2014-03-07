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
	top		+= offset_x;
	bottom	+= offset_x;
	left	+= offset_y;
	right	+= offset_y;
}

void GE_IRECT::move_to( int pos_x, int pos_y )
{
	right	+= pos_x - left;
	left	= pos_x;
	bottom	+= pos_y - top;
	top		= pos_y;
}

void GE_IRECT::include( int pos_x, int pos_y )
{
	if (left > pos_x)	left = pos_x;
	if (right < pos_x)	right = pos_x;
	if (top > pos_y)	top = pos_y;
	if (bottom < pos_y)	bottom = pos_y;
}


GE_FRECT::GE_FRECT()
: left(0.f)
, top(0.f)
, right(0.f)
, bottom(0.f)
{
}

GE_FRECT::GE_FRECT( float left_, float top_, float right_, float bottom_ )
: left(left_)
, top(top_)
, right(right_)
, bottom(bottom_)
{
}

void GE_FRECT::move( float offset_x, float offset_y )
{
	top		+= offset_x;
	bottom	+= offset_x;
	left	+= offset_y;
	right	+= offset_y;
}

void GE_FRECT::move_to( float pos_x, float pos_y )
{
	right	+= pos_x - left;
	left	= pos_x;
	bottom	+= pos_y - top;
	top		= pos_y;
}

void GE_FRECT::include( float pos_x, float pos_y )
{
	if (left > pos_x)	left = pos_x;
	if (right < pos_x)	right = pos_x;
	if (top > pos_y)	top = pos_y;
	if (bottom < pos_y)	bottom = pos_y;
}

}


