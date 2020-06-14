#pragma once
#include "Command.h"
class WalkLeftCommand : public Command
{
public:
	virtual ~WalkLeftCommand() = default;
	virtual void Execute()const;
};

