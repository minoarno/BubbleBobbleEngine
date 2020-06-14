#pragma once
#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

MidestinyEngine::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

MidestinyEngine::Texture2D::Texture2D(SDL_Texture* texture)
	: m_Format{NULL}
	, m_Width{0}
	, m_Height{0}
{
	m_Texture = texture;
	SDL_QueryTexture(texture, &m_Format, NULL, &m_Width, &m_Height);
}
