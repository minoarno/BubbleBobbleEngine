#include "MiniginPCH.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include "Utils.h"

namespace MidestinyEngine
{
#pragma region OpenGLDrawFunctionality
	void SetColor(const Color4f& color)
	{
		glColor4f(color.r, color.g, color.b, color.a);
	}

	void DrawPoint(float x, float y, float pointSize)
	{
		glPointSize(pointSize);
		glBegin(GL_POINTS);
		{
			glVertex2f(x, y);
		}
		glEnd();
	}

	void DrawRect(float left, float bottom, float width, float height, float lineWidth)
	{
		glLineWidth(lineWidth);
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(left, bottom);
			glVertex2f(left + width, bottom);
			glVertex2f(left + width, bottom + height);
			glVertex2f(left, bottom + height);
		}
		glEnd();
	}

	void DrawRect(const Rectf& rect, float lineWidth)
	{
		DrawRect(rect.x, rect.y, rect.w, rect.h, lineWidth);
	}

	void FillRect(float left, float bottom, float width, float height)
	{
		glBegin(GL_POLYGON);
		{
			glVertex2f(left, bottom);
			glVertex2f(left + width, bottom);
			glVertex2f(left + width, bottom + height);
			glVertex2f(left, bottom + height);
		}
		glEnd();
	}

	void FillRect(const Rectf& rect)
	{
		FillRect(rect.x, rect.y, rect.w, rect.h);
	}
#pragma endregion OpenGLDrawFunctionality

	bool IsPointInRect(float x,float y, const Rectf& r)
	{
		return ((x >= r.x) && (x <= r.x + r.w) && (y >= r.y) && (y <= r.y + r.h));
	}

	int Random(int min, int max)
	{
		return std::rand() % (max - min) + min;
	}

	///Checking if the stream is valid or not
	bool CheckStream(std::istream& inputStream)
	{
		if (!inputStream)
		{
			if (inputStream.eof()) ME_CORE_ERROR("End of file reached");
			if (inputStream.fail()) ME_CORE_ERROR("Stream is in a fail state");
			if (inputStream.bad()) ME_CORE_ERROR("Stream is in a bad state");
			inputStream.clear();
			return false;
		}
		return true;
	}

	float Round2Dec(float value)
	{
		return int(value * 100) / 100.f;
	}

	void Invoke(std::function<void()> func, int intervalInMilliseconds, bool isLooping)
	{
		std::thread([=]()
		{
			bool isGameStillGoing{ true };
			do
			{
				auto nextTimeFunctionCall = std::chrono::steady_clock::now() + std::chrono::milliseconds(intervalInMilliseconds);
				std::this_thread::sleep_until(nextTimeFunctionCall);
				func();
				isGameStillGoing = std::atomic<bool>(Core::g_DoContinue);
			} while (isLooping && isGameStillGoing);
		}).detach();
	}
}