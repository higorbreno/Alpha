#include "Vector2.h"

const float pi = 3.14159f;

Vector2::Vector2() : x(0), y(0), magnitude(0), angle(0)
{
}

Vector2::Vector2(float n1, float n2, TypeVector type = TypeVector::CARTESIAN)
{
	if (type == TypeVector::CARTESIAN) {
		x = n1;
		y = n2;
		magnitude = sqrt((x * x) + y * y);
		angle = atan2(y, x) * 180 / pi;
	}
	else {
		magnitude = n1;
		angle = n2;
		x = magnitude * cos(angle * pi / 180.0f);
		y = magnitude * sin(angle * pi / 180.0f);
	}
}

Vector2::~Vector2()
{
}

void Vector2::SetPolar(float magnitude, float angle)
{
	this->magnitude = magnitude;
	this->angle = angle;
	x = magnitude * cos(angle * pi / 180.0f);
	y = magnitude * sin(angle * pi / 180.0f);
}

void Vector2::SetCartesian(float x, float y)
{
	this->x = x;
	this->y = y;
	magnitude = sqrt((x * x) + y * y);
	angle = atan2(y, x) * 180 / pi;
}
