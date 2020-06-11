#pragma once

struct Event;
class GameObject;
class Observer
{
	virtual ~Observer() = default;
	virtual void Notify(GameObject* actor, Event event) = 0;
};

