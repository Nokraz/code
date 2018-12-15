#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Body.h"
#include "Assignment.h"
class Assignment
{
public:
	// Member variables
	// Scott prefers we leave std::vector for later
	// std::vector<Body*> bodies // A vector list of Body pointers
	// Use an array of 2 bodies instead
	Body* bodies[2];
	float elapsedTime;
	Vec3 gravitationalAcceleration;

	// Constructors
	Assignment();
	// Sets the elapsed time to zero and gravity as given
	Assignment(Vec3 gravitationalAcceleration_);

	//Methods
	// Add two bodies to the array of bodies
	void AddTwoBodies(Body* body1, Body* body2);

	// Update all the bodies using wind, gravity, and the equations of motion
	void Update(float timeStep);

	// Destructor
	~Assignment();
};
#endif 