#ifndef VEC3_H
#define VEC3_H
class Vec3
{
public:
	float x;
	float y;
	float z;

	Vec3();
	Vec3(float x_, float y_, float z_);
	void SetZero();
};
#endif
