#include <gl/freeglut.h>
#include "Object.h"

Object::Object() : position{}, rotation{}, axis{}, scale({ 1, 1, 1 }), color{ 1, 1, 1 },
	bVisible{ true }, matrix{}, hierarchyLevel{ 0 }
{
	rotationAxis = 0.f;
}

Object::~Object()
{
}

void Object::initialize()
{
}

void Object::update()
{
	for (auto& v : child)
		if (v) v->update();
}

void Object::preRender()
{
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	if (!hierarchyLevel)
	{
		glLoadIdentity();
		glOrtho(0.f, 800.f, 0.f, 600.f, -400.f, 400.f);
	}
	glTranslatef(positionX, positionY, positionZ);
	glRotatef(rotationZ, 0, 0, 1);
	glRotatef(rotationY, 0, 1, 0);
	glRotatef(rotationX, 1, 0, 0);
	if (axisX != 0 && axisY != 0 && axisZ != 0)
		glRotatef(rotationAxis, axisX, axisY, axisZ);
	glScalef(scaleX, scaleY, scaleZ);

	glColor3f(colorR, colorG, colorB);
}

void Object::postRender()
{
	for (auto& v : child)
		if (v) v->render();
	glPopMatrix();
}

void Object::render()
{
	preRender();
	postRender();
}

void Object::release()
{
}

void Object::addChild(Object* _child)
{
	_child->hierarchyLevel = hierarchyLevel + 1;
	child.push_back(_child);
}

void Object::setVisible(const bool _b)
{
	bVisible = _b;
}

void Object::setRotationAxis(const float _r)
{
	rotationAxis = _r;
}

void Object::addRotationAxis(const float _r)
{
	rotationAxis += _r;
}

void Object::subRotationAxis(const float _r)
{
	rotationAxis -= _r;
}

void Object::setPosition(float _x, float _y, float _z)
{
	position = Vector3{ _x, _y, _z };
}

void Object::setRotation(float _x, float _y, float _z)
{
	rotation = Vector3{ _x, _y, _z };
}

void Object::setAxis(float _x, float _y, float _z)
{
	axis = Vector3{ _x, _y, _z };
}

void Object::setScale(float _x, float _y, float _z)
{
	scale = Vector3{ _x, _y, _z };
}

void Object::setColor(float _r, float _g, float _b)
{
	if (_r > 1.f) _r = 1.f; else if (_r < 0.f) _r = 0.f;
	if (_g > 1.f) _g = 1.f; else if (_g < 0.f) _g = 0.f;
	if (_b > 1.f) _b = 1.f; else if (_b < 0.f) _b = 0.f;
	color = Vector3{ _r, _g, _b };
}

void Object::setPosition(const Vector3 _position)
{
	position = _position;
}

void Object::setRotation(const Vector3 _rotation)
{
	rotation = _rotation;
}

void Object::setAxis(const Vector3 _axis)
{
	axis = _axis;
}

void Object::setScale(const Vector3 _scale)
{
	scale = _scale;
}

void Object::setColor(const Vector3 _color)
{
	color = _color;
}

Vector3 Object::getPosition() const
{
	return position;
}

Vector3 Object::getRotation() const
{
	return rotation;
}

Vector3 Object::getScale() const
{
	return scale;
}

Vector3 Object::getColor() const
{
	return color;
}

void Object::addPosition(float _x, float _y, float _z)
{
	position += Vector3{ _x, _y, _z };
}

void Object::addRotation(float _x, float _y, float _z)
{
	rotation += Vector3{ _x, _y, _z };
}

void Object::addScale(float _x, float _y, float _z)
{
	scale += Vector3{ _x, _y, _z };
}

void Object::addColor(float _r, float _g, float _b)
{
	if (colorR += _r; colorR > 1.f) colorR = 1.f;
	if (colorG += _g; colorG > 1.f) colorG = 1.f;
	if (colorB += _b; colorB > 1.f) colorB = 1.f;
}

void Object::addPosition(const Vector3 _position)
{
	position += _position;
}

void Object::addRotation(const Vector3 _rotation)
{
	rotation += _rotation;
}

void Object::addScale(const Vector3 _scale)
{
	scale += _scale;
}

void Object::addColor(const Vector3 _color)
{
	color += _color;
}

void Object::subPosition(float _x, float _y, float _z)
{
	position -= Vector3{ _x, _y, _z };
}

void Object::subRotation(float _x, float _y, float _z)
{
	rotation -= Vector3{ _x, _y, _z };
}

void Object::subScale(float _x, float _y, float _z)
{
	scale -= Vector3{ _x, _y, _z };
}

void Object::subColor(float _r, float _g, float _b)
{
	if (colorR -= _r; colorR < 0.f) colorR = 0.f;
	if (colorG -= _g; colorG < 0.f) colorG = 0.f;
	if (colorB -= _b; colorB < 0.f) colorB = 0.f;
}

void Object::subPosition(const Vector3 _position)
{
	position -= _position;
}

void Object::subRotation(const Vector3 _rotation)
{
	rotation -= _rotation;
}

void Object::subScale(const Vector3 _scale)
{
	scale -= _scale;
}

void Object::subColor(const Vector3 _color)
{
	color -= _color;
}