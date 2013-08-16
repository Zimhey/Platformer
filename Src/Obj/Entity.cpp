/*
 * Entity.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Entity.h"

Entity::Entity()
{
	x = y = z = width = height = 0;
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y)
{
	this->x = x;
	this->y = y;
	z = width = height = 0;
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	width = height = 0;
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	z = 0;
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z, float width, float height)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z, float width, float height, int health)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	this->health = health;
	type = 1;
	alive = true;
}

Entity::~Entity()
{

}

int Entity::getHealth() const
{
	return health;
}

void Entity::setHealth(int health)
{
	this->health = health;
}

void Entity::tick()
{
	if (health < 1)
		alive = false;
	// TEMP gravity
	if (y + height < 620)
		y += 5;
	if (y + height > 620)
		y = 620 - height;
}
