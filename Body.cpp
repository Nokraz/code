#include "Body.h"


// Sets the mass to mass_ and everything else to zero
Body::Body(float mass_)
{
	mass = mass_;
	angle = 0.0f;
	position = 0.0f;
	position.y = 1.4;
	velocity = 0.0f;
	acceleration = 0.0f;
}

Body::Body(float mass_, float angle_, Vec3 position_, Vec3 velocity, Vec3 acceleration_)
{

}

void Body::Update(float timeStep)
{
	// Code up the equations of motion
	// s = vi * t + 0.5 * a * t * t
	// vf = vi + a * t

	position.x += velocity.x * timeStep + 0.5 * acceleration.x * timeStep * timeStep;
	velocity.x += acceleration.x * timeStep;

}

void Body::ApplyForce(Vec3 force)
{
	// Code up Newton's second law F = ma to update acceleration
	// a = F / m

	acceleration.x = force.x / mass; 
}

