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

//-----------------------------------------------------------------
// Point2f Constructors
//-----------------------------------------------------------------
Point2f::Point2f()
	:Point2f{ 0.0f, 0.0f }
{
}
Point2f::Point2f(float x, float y)
	: x{ x }, y{ y }
{
}

//-----------------------------------------------------------------
// Circlef Constructors
//-----------------------------------------------------------------
Circlef::Circlef()
	:Circlef{ 0.0f, 0.0f, 0.0f }
{
}

Circlef::Circlef(float centerX, float centerY, float radius)
	: Circlef{ Point2f{ centerX, centerY }, radius }
{
}

Circlef::Circlef(const Point2f& center, float radius)
	: center{ center }
	, radius{ radius }
{
}

//-----------------------------------------------------------------
// Ellipsef Constructors
//-----------------------------------------------------------------
Ellipsef::Ellipsef()
	:Ellipsef{ 0.0f, 0.0f, 0.0f, 0.0f }
{
}


Ellipsef::Ellipsef(const Point2f& center, float radiusX, float radiusY)
	: center{ center }
	, radiusX{ radiusX }
	, radiusY{ radiusY }
{
}

Ellipsef::Ellipsef(float centerX, float centerY, float radiusX, float radiusY)
	: Ellipsef{ Point2f{ centerX, centerY }, radiusX, radiusY }
{
}
