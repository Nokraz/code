#include "Assignment.h"

Assignment::Assignment()
{
}


Assignment::~Assignment()
{
	// Delete the Body pointers 
	delete bodies[0];
	delete bodies[1];
}

Assignment::Assignment(Vec3 gravitationalAcceleration_)
{
	// Set the member variable to the one given
	gravitationalAcceleration = gravitationalAcceleration_;
	
	// Set the elapsedTime to zero
	elapsedTime = 0;
}

void Assignment::AddTwoBodies(Body* body1, Body* body2)
{
	// Put body1 and body2 into the array
	// First element of the array is [0]
	bodies[0] = body1;
	
	// Second element of the array is [1]
	bodies[1] = body2;
}

// Update all the bodies using wind, gravity, and the equations of motion
void Assignment::Update(float timeStep)
{
	// Make sure you are applying gravitational acceleration through
	// Vec3 gravitationalAcceleration
	bodies[0]->acceleration.y += gravitationalAcceleration.y;

	bodies[1]->acceleration.y += gravitationalAcceleration.y;

	// Use the Body's update method
	bodies[0]->Update(timeStep);
	bodies[1]->Update(timeStep);

	
	

}