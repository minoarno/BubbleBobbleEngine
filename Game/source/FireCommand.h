#pragma once
#include "Command.h"
class Character;
class FireCommand : public Command
{
public:
	virtual ~FireCommand() = default;
	virtual void Execute()const;
private:
	Character* receiver;
};