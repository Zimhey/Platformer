/*
 * Entity.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Entity.h"

Entity::Entity() :
		Obj()
{
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y) :
		Obj(x, y)
{
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z) :
		Obj(x, y, z)
{
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float width, float height) :
		Obj(x, y, width, height)
{
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z, float width, float height) :
		Obj(x, y, z, width, height)
{
	health = type = 1;
	alive = true;
}

Entity::Entity(float x, float y, float z, float width, float height, int health) :
		Obj(x, y, z, width, height)
{
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
		y += 8;
	if (y + height > 620)
		y = 620 - height;
}
