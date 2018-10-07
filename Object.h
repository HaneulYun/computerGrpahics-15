#pragma once
#include <vector>
#include "Vector3.h"
#include "Matrix3d.h"

class Object
{
	union {
		struct {
			float positionX;
			float positionY;
			float positionZ;
		};
		Vector3	position;
	};
	union {
		struct {
			float rotationX;
			float rotationY;
			float rotationZ;
		};
		Vector3	rotation;
	}; // degree
	union {
		struct {
			float axisX;
			float axisY;
			float axisZ;
			float rotationAxis;
		};
		Vector3	axis;
	};
	union {
		struct {
			float scaleX;
			float scaleY;
			float scaleZ;
		};
		Vector3	scale;
	};
	union {
		struct {
			float colorR;
			float colorG;
			float colorB;
		};
		Vector3	color;
	};
	Matrix3d matrix;

	std::vector<Object*> child;
	int hierarchyLevel;

protected:
	bool bVisible;

public:
	Object();
	virtual ~Object();

	virtual void initialize();
	virtual void update();
	void preRender();
	void postRender();
	virtual void render();
	virtual void release();

	void addChild(Object* _child);

	void setVisible(const bool _b);
	void setRotationAxis(const float _r);
	void addRotationAxis(const float _r);
	void subRotationAxis(const float _r);

	void setPosition(float _x, float _y, float _z);
	void setRotation(float _x, float _y, float _z);
	void setAxis(float _x, float _y, float _z);
	void setScale(float _x, float _y, float _z);
	void setColor(float _r, float _g, float _b);
	void setPosition(const Vector3 _position);
	void setRotation(const Vector3 _rotation);
	void setAxis(const Vector3 _axis);
	void setScale(const Vector3 _scale);
	void setColor(const Vector3 _color);

	Vector3 getPosition() const;
	Vector3 getRotation() const;
	Vector3 getScale() const;
	Vector3 getColor() const;

	void addPosition(float _x, float _y, float _z);
	void addRotation(float _x, float _y, float _z);
	void addScale(float _x, float _y, float _z);
	void addColor(float _r, float _g, float _b);
	void addPosition(const Vector3 _position);
	void addRotation(const Vector3 _rotation);
	void addScale(const Vector3 _scale);
	void addColor(const Vector3 _color);

	void subPosition(float _x, float _y, float _z);
	void subRotation(float _x, float _y, float _z);
	void subScale(float _x, float _y, float _z);
	void subColor(float _r, float _g, float _b);
	void subPosition(const Vector3 _position);
	void subRotation(const Vector3 _rotation);
	void subScale(const Vector3 _scale);
	void subColor(const Vector3 _color);
};

