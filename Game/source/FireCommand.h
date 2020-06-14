#pragma once
#include "Command.h"

class FireCommand : public Command
{
public:
	virtual ~FireCommand() = default;
	virtual void Execute()const;
};