#pragma once
#include "Command.h"
class Character;
class WalkLeftCommand : public Command
{
public:
	virtual ~WalkLeftCommand() = default;
	virtual void Execute()const;
private:
	Character* receiver;
};

