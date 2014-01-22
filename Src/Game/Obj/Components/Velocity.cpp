/*
 * Velocity.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Velocity.h"

Velocity::Velocity()
{
	x = y = 0;
}

Velocity::Velocity(float x, float y) :
		x(x), y(y)
{
}

Velocity::~Velocity()
{
}

float Velocity::getX() const
{
	return x;
}

void Velocity::setX(float x)
{
	this->x = x;
}

float Velocity::getY() const
{
	return y;
}

void Velocity::setY(float y)
{
	this->y = y;
}
