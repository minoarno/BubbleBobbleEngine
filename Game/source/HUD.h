#pragma once
class HUD
{
public:
	HUD() = default;

	void LoseALive();
	void Restart();
private:
	unsigned int m_Score = 0;
	unsigned int m_MaxLives = 4;
	unsigned int m_CurrentLives = 4;
};

