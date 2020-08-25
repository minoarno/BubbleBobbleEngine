#pragma once
#include "SceneObject.h"
#include "Transform.h"
#include "Structs.h"

namespace MidestinyEngine
{
	class Font;
	class Texture2D;
	class TextObject final : public SceneObject
	{
	public:
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void FixedUpdate() override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);

		TextObject(const std::string& text, const std::shared_ptr<Font>& font);
		TextObject(const std::string& text, const std::shared_ptr<Font>& font, const SDL_Color& color);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		Transform m_Transform;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_Texture;
		const SDL_Color m_Color = { 255,255,255 };
	};
}
