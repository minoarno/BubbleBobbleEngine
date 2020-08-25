#pragma once

enum class TypeOfDrop
{
	banana = 0,
	melon = 1,
	peach = 2,
	grapes = 3,
	strawberry = 4,
	diamond = 5,
	Manadarin = 6,
	ruby = 7,
};

enum class CharacterState
{
	walking = 0,
	dying = 1,
	attack = 2
};

enum class EnemyState
{
	walking = 0,
	trapped = 1,
	dying = 2,
};

enum class Cooldown
{
	Reloading = 0,
	Activated = 1,
	Ready = 2
};