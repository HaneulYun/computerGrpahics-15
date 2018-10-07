#include <iostream>
#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

float Vector3::distance() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	return Vector3{ x + rhs.x, y + rhs.y, z + rhs.z };
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	return Vector3{ x - rhs.x, y - rhs.y, z - rhs.z };
}

Vector3 Vector3::operator*(const float& rhs)
{
	return Vector3{ x * rhs, y * rhs, z * rhs };
}

Vector3 Vector3::operator/(const Vector3& rhs)
{
	return Vector3{ x / rhs.x, y / rhs.y, z / rhs.z };
}

Vector3 Vector3::operator/(const float& rhs)
{
	return Vector3{ x / rhs, y / rhs, z / rhs };
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	*this = *this - rhs;
	return *this;
}