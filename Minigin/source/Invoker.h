#pragma once
//https://refactoring.guru/design-patterns/command/cpp/example
class Command;
class Invoker
{
public:
	void SetOnStart(Command* command) 
	{
		this->on_start_ = command;
	}
	void SetOnFinish(Command* command) 
	{
		this->on_finish_ = command;
	}
private:
	Command* on_start_;
	Command* on_finish_;
};

