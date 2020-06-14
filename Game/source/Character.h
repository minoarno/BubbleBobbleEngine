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

	CharacterState GetCharacterState() const { return m_CharacterState; }
private:
	UnitTexture* m_pTexture = nullptr;
	CharacterState m_CharacterState;
};

