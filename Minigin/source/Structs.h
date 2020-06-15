#pragma once

enum class DataType
{
	s = 0,
	f = 1,
	i = 2
};

struct Rectf
{
	Rectf();
	explicit Rectf(float left, float bottom, float width, float height);
	float x, y, w, h;
};

struct Color4f
{
	float r, g, b, a;
};