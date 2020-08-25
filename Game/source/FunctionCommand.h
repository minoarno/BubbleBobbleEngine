#pragma once
#include <Command.h>
#include <functional>

class FunctionCommand : public Command
{
public:
	FunctionCommand(std::function<void()> func)
		:m_Function{func}
	{
	}
	virtual void Execute()const override
	{
		m_Function();
	}
protected:
	std::function<void()> m_Function;
};
