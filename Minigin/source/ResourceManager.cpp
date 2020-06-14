#include "MiniginPCH.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Texture2D.h"
#include "Font.h"

void MidestinyEngine::ResourceManager::Init(const std::string& dataPath)
{
	m_DataPath = dataPath;

	// load support for png and jpg, this takes a while!

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		ME_ERROR("Failed to load support for png's: {0}", SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		ME_ERROR("Failed to load support for jpg's: {0}", SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		ME_ERROR("Failed to load support for fonts: {0}", SDL_GetError());
	}
}

std::shared_ptr<MidestinyEngine::Texture2D> MidestinyEngine::ResourceManager::LoadTexture(const std::string& file) const
{
	const auto fullPath = m_DataPath + file;
	auto texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (texture == nullptr) 
	{
		ME_ERROR("Failed to load texture: {0}",SDL_GetError());
	}
	return std::make_shared<Texture2D>(texture);
}

std::shared_ptr<MidestinyEngine::Font> MidestinyEngine::ResourceManager::LoadFont(const std::string& file, unsigned int size) const
{
	return std::make_shared<Font>(m_DataPath + file, size);
}
