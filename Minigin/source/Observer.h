#pragma once

struct Event;
class GameObject;
class Observer
{
public:
	virtual ~Observer() = default;
	//virtual void Notify(GameObject* actor, Event event) = 0;
};

