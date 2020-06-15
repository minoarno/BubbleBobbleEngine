#pragma once
#include "Command.h"
class Character;
class JumpCommand : public Command
{
public:
	virtual ~JumpCommand() = default;
	virtual void Execute()const;
private:
	Character* receiver;
};

