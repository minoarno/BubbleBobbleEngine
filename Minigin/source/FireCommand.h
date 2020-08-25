#pragma once
#include <iostream>
#include "Log.h"
#include "Command.h"
class FireCommand : public Command
{
	virtual void Execute()const
	{
		ME_INFO("FIRE");
	}
};

