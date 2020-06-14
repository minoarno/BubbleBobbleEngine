#pragma once
class WalkRightCommand
{
public:
	virtual ~WalkRightCommand() = default;
	virtual void Execute()const;
};

