/*
 * Position.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Position.h"

Position::Position()
{
	x = y = 0;

}

Position::Position(int x, int y) :
		x(x), y(y)
{
}

Position::~Position()
{
}

int Position::getX() const
{
	return x;
}

void Position::setX(int x)
{
	this->x = x;
}

int Position::getY() const
{
	return y;
}

void Position::setY(int y)
{
	this->y = y;
}
