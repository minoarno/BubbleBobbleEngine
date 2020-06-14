#pragma once
#include "Structs.h"

class Character;
class GameObject;
class Texture2D;
class UnitTexture
{
public:
	UnitTexture() = default;
	UnitTexture(MidestinyEngine::GameObject* gameObject, const std::string& filepath, int amountOfFrames);
	UnitTexture(const UnitTexture& other) = delete;
	UnitTexture& operator=(const UnitTexture& other) = delete;
	UnitTexture(UnitTexture&& other) = delete;
	UnitTexture& operator=(UnitTexture&& other) = delete;
	~UnitTexture() = default;

	void Start();
	void Update();
	void IncrementAnimationCounter();
	void Render()const;

	void ResetAnimationCounter();

	int GetFramesPerSec() const { return m_FramesPerSec; }
	int GetAmountOfFrames() const { return m_AmountOfFrames; }
	int GetAmountOfWalkingFrames() const { return m_AmountOfWalkingFrames; }
	int GetAmountOfDyingFrames() const { return m_AmountOfDyingFrames; }
	int GetAmountOfAttackingFrames() const { return m_AmountOfAttackingFrames; }

	void SetFramesPerSec(int value) { m_FramesPerSec = value; }
	void SetAmountOfFrames(int value) { m_AmountOfFrames = value; }
	void SetAmountOfWalkingFrames(int value) { m_AmountOfWalkingFrames = value; }
	void SetAmountOfDyingFrames(int value) { m_AmountOfDyingFrames = value; }
	void SetAmountOfAttackingFrames(int value) { m_AmountOfAttackingFrames = value; }
	void SetGameObject(MidestinyEngine::GameObject* gameObject) { m_pGameObject = gameObject; }

	void SetTexture(const std::string& filepath);
	void SetCharacter(Character* character) { m_pCharacter = character; }

private:
	Character* m_pCharacter = nullptr;

	MidestinyEngine::GameObject* m_pGameObject = nullptr;

	float m_ImageWidth = 0.f, m_ImageHeight = 0.f;

	std::shared_ptr<MidestinyEngine::Texture2D> m_pTexture;

	int m_FramesPerSec = 4, m_AmountOfFrames = 4, m_AmountOfWalkingFrames = 0, m_AmountOfDyingFrames = 0, m_AmountOfAttackingFrames = 0;

	float m_AnimationTimer = 0;
	int m_AnimationCounter = 0;
};

