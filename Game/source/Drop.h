#pragma once
#include "GameObject.h"
#include "Enums.h"

class Drop : public MidestinyEngine::GameObject
{
public:
	Drop() = default;
	~Drop() = default;

	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void FixedUpdate() override;
	virtual void Render() const override;

	void SetTypeOfDrop(TypeOfDrop type) { m_TypeOfDrop = type; }
	TypeOfDrop GetTypeOfDrop()const { return m_TypeOfDrop; }
private:
	TypeOfDrop m_TypeOfDrop;
};

