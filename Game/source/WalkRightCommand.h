#pragma once
#include "Command.h"
class WalkRightCommand : public Command
{
public:
	virtual ~WalkRightCommand() = default;
	virtual void Execute()const;
};

