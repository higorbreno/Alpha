#include <cmath>

#ifndef VECTOR2_H
#define VECTOR2_H

enum TypeVector {
	POLAR, CARTESIAN
};

class Vector2 {
private:
	float x, y, magnitude, angle;

public:
	Vector2();
	Vector2(float, float, TypeVector);
	~Vector2();
	void SetPolar(float, float);
	void SetCartesian(float, float);
	float X();
	float Y();
	float Magnitude();
	float Angle();
};

inline float Vector2::X()
{ return x; }

inline float Vector2::Y()
{ return y; }

inline float Vector2::Magnitude()
{ return magnitude; }

inline float Vector2::Angle()
{ return angle; }

#endif // !VECTOR2_H
