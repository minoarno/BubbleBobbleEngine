#pragma once
#include "Singleton.h"
namespace MidestinyEngine
{
	class GameTime : public Singleton<GameTime>
	{
	public:
		~GameTime() = default;
		inline float GetTimeScale() { return m_TimeScale; }
		inline float GetElapsedSeconds() { return m_ElapsedSeconds * m_TimeScale; }
		inline float GetFixedElapsedSeconds() { return m_FixedElapsedSeconds * m_TimeScale; }

		inline void SetTimeScale(float value) { m_TimeScale = value; }
		inline void SetElapsedSeconds(float value) { m_ElapsedSeconds = value; }
		inline void SetFixedElapsedSeconds(float value) { m_FixedElapsedSeconds = value; }
	private:
		friend class Singleton<GameTime>;
		GameTime();
		float m_TimeScale = 1.f;
		float m_ElapsedSeconds = 0.f;
		float m_FixedElapsedSeconds = 1.f;
	};
}