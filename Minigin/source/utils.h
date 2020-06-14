#pragma once
#include "Structs.h"

namespace MidestinyEngine
{
	const float g_Pi{ 3.1415926535f };

	#pragma region OpenGLDrawFunctionality

	void SetColor( const Color4f& color );
	
	void DrawPoint( float x, float y, float pointSize = 1.0f );
	void DrawRect(float left, float bottom, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float bottom, float width, float height);
	
	void FillRect(const Rectf& rect);

	#pragma endregion OpenGLDrawFunctionality
	
	bool IsPointInRect(float x, float y, const Rectf& r);
	
	int Random(int min, int max);

	bool CheckStream(std::istream& inputStream);

	float Round2Dec(float value);

	glm::vec3 MakeVec3(const b2Vec2& pos);
}