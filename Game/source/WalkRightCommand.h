#pragma once
#include "Command.h"
class Character;
class WalkRightCommand : public Command
{
public:
	virtual ~WalkRightCommand() = default;
	virtual void Execute()const;
private:
	Character* receiver;
};

