#include "HUD.h"

void HUD::LoseALive()
{
	m_CurrentLives--;
}

void HUD::Restart()
{
	m_CurrentLives = m_MaxLives;
}
