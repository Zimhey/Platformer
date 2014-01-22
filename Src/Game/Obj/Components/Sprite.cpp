/*
 * Sprite.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Sprite.h"

Sprite::Sprite(float width, float height) :
		width(width), height(height)
{
	z = tex = 0;
}

Sprite::Sprite(float width, float height, int z) :
		width(width), height(height), z(z)
{
	tex = 0;
}

Sprite::Sprite(float width, float height, int z, int tex) :
		width(width), height(height), z(z), tex(tex)
{
}

Sprite::~Sprite()
{
}

float Sprite::getHeight() const
{
	return height;
}

void Sprite::setHeight(float height)
{
	this->height = height;
}

int Sprite::getTex() const
{
	return tex;
}

void Sprite::setTex(int tex)
{
	this->tex = tex;
}

float Sprite::getWidth() const
{
	return width;
}

void Sprite::setWidth(float width)
{
	this->width = width;
}

int Sprite::getZ() const
{
	return z;
}

void Sprite::setZ(int z)
{
	this->z = z;
}
