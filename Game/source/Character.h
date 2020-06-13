#pragma once
#include "GameObject.h"

class Character final : public  dae::GameObject
{
public:
	enum class CharacterState
	{
		idle = 0,
		walking = 1,
	};

	Character();
	~Character();

	void Start() override;
	void Update() override;
	void LateUpdate() override;
	void FixedUpdate() override;
	void Render() const override;

	void SetInput();
private:

};

