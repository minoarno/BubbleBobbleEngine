#pragma once
#include "GameObject.h"
#include "Enums.h"
#include "Structs.h"

class UnitTexture;
class Character : public  MidestinyEngine::GameObject
{
public:
	Character();
	~Character();

	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void FixedUpdate() override;
	virtual void Render() const override;

	void Move(bool isToTheRight);
	void Jump();
	void Fire();

	void SetTexture(const std::string& filename) override;
	void SetInput();

	CharacterState GetCharacterState() const { return m_CharacterState; }
private:
	UnitTexture* m_pTexture = nullptr;
	CharacterState m_CharacterState;
	bool m_IsToTheRight = true;
	float m_Speed = 30.f;
};

