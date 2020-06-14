#pragma once
#include "BaseComponent.h"

struct SDL_Texture;
namespace MidestinyEngine
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D
	{
	public:
		explicit Texture2D(SDL_Texture* texture);
		~Texture2D();

		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;

		SDL_Texture* GetSDLTexture() const { return  m_Texture; }
		int GetWidth()const { return m_Width; }
		int GetHeight()const { return m_Height; }
	private:
		SDL_Texture* m_Texture = nullptr;
		int m_Width = 0;
		int m_Height = 0;
		Uint32 m_Format = NULL;
	};
}
