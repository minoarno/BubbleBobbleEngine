#include "MiniginPCH.h"
#include "GameTime.h"
namespace MidestinyEngine
{
	GameTime::GameTime()
	{
		m_TimeScale = 1.f;
		m_ElapsedSeconds = 0.f;
		m_FixedElapsedSeconds = 1.f;
	}
}