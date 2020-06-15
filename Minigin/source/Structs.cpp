#include "MiniginPCH.h"
#include "Structs.h"

Rectf::Rectf()
	:Rectf{ 0.0f, 0.0f, 0.0f, 0.0f }
{
}

Rectf::Rectf(float left, float bottom, float width, float height)
	: x{ left }
	, y{ bottom }
	, w{ width }
	, h{ height }
{
}