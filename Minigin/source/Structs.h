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

struct Point2f
{
	Point2f();
	explicit Point2f(float x, float y);

	float x;
	float y;
};

struct Circlef
{
	Circlef();
	explicit Circlef(const Point2f& center, float radius);
	explicit Circlef(float centerX, float centerY, float radius);

	Point2f center;
	float radius;
};


struct Ellipsef
{
	Ellipsef();
	explicit Ellipsef(const Point2f& center, float radiusX, float radiusY);
	explicit Ellipsef(float centerX, float centerY, float radiusX, float radiusY);

	Point2f center;
	float radiusX;
	float radiusY;
};
