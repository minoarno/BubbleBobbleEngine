#pragma once
class GameObject;
class Texture2D;
class UnitTexture
{
public:
	UnitTexture();
	UnitTexture(MidestinyEngine::GameObject* gameObject, const std::string& filepath, int amountOfFrames);
	UnitTexture(const UnitTexture& other) = delete;
	UnitTexture& operator=(const UnitTexture& other) = delete;
	UnitTexture(UnitTexture&& other) = delete;
	UnitTexture& operator=(UnitTexture&& other) = delete;
	~UnitTexture();

	void Update();
	void Render()const;

	void ResetAnimationCounter();

	void SetDestRect(const Rectf& rect) { m_DestinationRectangle = rect; }
	void SetFramesPerSec(int value) { m_FramesPerSec = value; }
	void SetAmountOfFrames(int value) { m_AmountOfFrames = value; }
	void SetGameObject(MidestinyEngine::GameObject* gameObject) { m_pGameObject = gameObject; }
	void SetTexture(const std::string& filepath);
private:
	Rectf m_DestinationRectangle;

	MidestinyEngine::GameObject* m_pGameObject = nullptr;

	float m_ImageWidth, m_ImageHeight;

	std::shared_ptr<MidestinyEngine::Texture2D> m_pTexture;

	int m_FramesPerSec = 4, m_AmountOfFrames;

	float m_AnimationTimer;
	int m_AnimationCounter;
};

