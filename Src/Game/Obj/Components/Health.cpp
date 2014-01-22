/*
 * Health.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Health.h"

Health::Health(int hp, int max) :
		hp(hp), max(max)
{
	alive = true;
}

Health::~Health()
{
}

bool Health::isAlive() const
{
	return alive;
}

void Health::setAlive(bool alive)
{
	this->alive = alive;
}

int Health::getHp() const
{
	return hp;
}

void Health::setHp(int hp)
{
	this->hp = hp;
}

int Health::getMax() const
{
	return max;
}

void Health::setMax(int max)
{
	this->max = max;
}
