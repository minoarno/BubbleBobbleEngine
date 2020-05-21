#pragma once
class RigidBody2D
{
public:
	RigidBody2D();
	RigidBody2D(const RigidBody2D& other);
	RigidBody2D& operator=(const RigidBody2D& other);
	RigidBody2D(RigidBody2D&& other);
	RigidBody2D& operator=(RigidBody2D&& other);
private:

};

