#pragma once
#include "GameObject.h"
#include "Enums.h"
#include "Structs.h"

class UnitTexture;
class Character final : public  MidestinyEngine::GameObject
{
public:
	Character();
	~Character();

	void Start() override;
	void Update() override;
	void LateUpdate() override;
	void FixedUpdate() override;
	void Render() const override;

	void SetTexture(const std::string& filename) override;

	void SetInput();
	void SetSize(float width, float height);
	Rectf GetBoundaries() const { return Rectf{m_Transform->GetPosition().x, m_Transform->GetPosition().y,m_DestinationRectangle.w,m_DestinationRectangle.h}; }
	CharacterState GetCharacterState() const { return m_CharacterState; }
private:
	Rectf m_DestinationRectangle;
	UnitTexture* m_pTexture = nullptr;
	CharacterState m_CharacterState;
};

