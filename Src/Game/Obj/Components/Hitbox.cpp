/*
 * Hitbox.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Hitbox.h"

Hitbox::Hitbox(int width, int height) :
		width(width), height(height)
{

}

Hitbox::~Hitbox()
{
}

int Hitbox::getHeight() const
{
	return height;
}

void Hitbox::setHeight(int height)
{
	this->height = height;
}

int Hitbox::getWidth() const
{
	return width;
}

void Hitbox::setWidth(int width)
{
	this->width = width;
}
