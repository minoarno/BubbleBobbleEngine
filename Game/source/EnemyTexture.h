#pragma once
class BaseEnemy;
class EnemyTexture
{
public:
	EnemyTexture() = default;
	EnemyTexture(MidestinyEngine::GameObject * gameObject, const std::string & filepath, int amountOfFrames);
	EnemyTexture(const EnemyTexture& other) = delete;
	EnemyTexture& operator=(const EnemyTexture& other) = delete;
	EnemyTexture(EnemyTexture&& other) = delete;
	EnemyTexture& operator=(EnemyTexture&& other) = delete;
	~EnemyTexture() = default;

	void Start();
	void Update();
	void IncrementAnimationCounter();
	void Render()const;

	void ResetAnimationCounter();

	int GetFramesPerSec()const { return m_FramesPerSec; }
	int GetAmountOfFrames()const { return m_AmountOfFrames; }
	int GetAmountOfWalkingFrames()const { return m_AmountOfWalkingFrames; }
	int GetAmountOfDyingFrames()const { return m_AmountOfDyingFrames; }
	int GetAmountOfBeingTrappedFrames()const { return m_AmountOfBeingTrappedFrames; }

	void SetFramesPerSec(int value) { m_FramesPerSec = value; }
	void SetAmountOfFrames(int value) { m_AmountOfFrames = value; }
	void SetAmountOfWalkingFrames(int value) { m_AmountOfWalkingFrames = value; }
	void SetAmountOfDyingFrames(int value) { m_AmountOfDyingFrames = value; }
	void SetAmountOfBeingTrappedFrames(int value) { m_AmountOfBeingTrappedFrames = value; }
	void SetGameObject(MidestinyEngine::GameObject * gameObject) { m_pGameObject = gameObject; }

	void SetTexture(const std::string & filepath);
	void SetBaseEnemy(BaseEnemy * enemy) { m_pBaseEnemy = enemy; }
private:
	BaseEnemy* m_pBaseEnemy = nullptr;

	MidestinyEngine::GameObject* m_pGameObject = nullptr;

	float m_ImageWidth = 0.f, m_ImageHeight = 0.f;

	std::shared_ptr<MidestinyEngine::Texture2D> m_pTexture;

	int m_FramesPerSec = 4, m_AmountOfFrames = 12, m_AmountOfWalkingFrames = 4, m_AmountOfDyingFrames = 4, m_AmountOfBeingTrappedFrames = 4;

	float m_AnimationTimer = 0;
	int m_AnimationCounter = 0;
};

