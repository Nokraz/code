#ifndef BODY_H
#define BODY_H
#include <SDL_image.h>
#include "VMath.h"

using namespace MATH;

class Body
{
public:
	// Member variables
	float mass;
	float angle;
	
	Vec3 position;
	Vec3 velocity;
	Vec3 acceleration;
	
	SDL_Surface * image;

	// Constructors
	// Sets mass to the given value and everything else to zero or [0, 0, 0]
	Body(float mass_);

	// Overloaded constructor that sets all member variables to given values
	Body(float mass_, float angle_, Vec3 position_, Vec3 velocity, Vec3 acceleration_);

	// Methods
	// Updates position and velocity using equations of motion
	void Update(float timeStep);

	// Updates acceleration using the equation a = F/m
	void ApplyForce(Vec3 force);


};
#endif
