/*
 * Obj.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Obj.h"
#include <GLFW/glfw3.h>

Obj::Obj()
{
	x = y = z = width = height = type = 0;
}

Obj::Obj(float x, float y) :
		x(x), y(y)
{
	z = width = height = type = 0;
}

Obj::Obj(float x, float y, float z) :
		x(x), y(y), z(z)
{
	width = height = type = 0;
}

Obj::Obj(float x, float y, float width, float height) :
		x(x), y(y), width(width), height(height)
{
	z = type = 0;
}

Obj::Obj(float x, float y, float z, float width, float height) :
		x(x), y(y), z(z), width(width), height(height)
{
	type = 0;
}

Obj::~Obj()
{
}

float Obj::getHeight() const
{
	return height;
}

void Obj::setHeight(float height)
{
	this->height = height;
}

float Obj::getWidth() const
{
	return width;
}

void Obj::setWidth(float width)
{
	this->width = width;
}

float Obj::getX() const
{
	return x;
}

void Obj::setX(float x)
{
	this->x = x;
}

float Obj::getY() const
{
	return y;
}

void Obj::setY(float y)
{
	this->y = y;
}

float Obj::getZ() const
{
	return z;
}

void Obj::setZ(float z)
{
	this->z = z;
}

int Obj::getType() const
{
	return type;
}

void Obj::setType(int type)
{
	this->type = type;
}

void Obj::draw()
{
	glPushMatrix();

	glTranslated(x, y, z);
	glBegin(GL_QUADS);

	if (type == 0)
		glColor3f(0.f, 0.5f, 1.f);
	else if (type == 1)
		glColor3f(0.f, 1.f, 0.f);
	else if (type == 2)
		glColor3f(1.f, 0.f, 0.f);

	glVertex3d(0, 0, z);
	glVertex3d(width, 0, z);
	glVertex3d(width, height, z);
	glVertex3d(0, height, z);

	glEnd();
	glPopMatrix();
}

void Obj::drawDebug()
{
	glPushMatrix();
	glBegin(GL_LINES);

	//verticle
	glVertex3d(x, y, 50);
	glVertex3d(x, y + height, 50);
	glVertex3d(x + width, y, 50);
	glVertex3d(x + width, y + height, 50);
	//horizontal
	glVertex3d(x, y, 50);
	glVertex3d(x + width, y, 50);
	glVertex3d(x, y + height, 50);
	glVertex3d(x + width, y + height, 50);

	glEnd();
	glPopMatrix();
}

void Obj::tick()
{

}

