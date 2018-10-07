#pragma once

struct Vector3
{
	float x;
	float y;
	float z;

public:
	Vector3(float x = 0, float y = 0, float z = 0);
	~Vector3();

	float distance() const;

	Vector3 operator+(const Vector3& rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator*(const float& rhs);
	Vector3 operator/(const Vector3& rhs);
	Vector3 operator/(const float& rhs);

	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
};