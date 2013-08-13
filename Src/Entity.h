/*
 * Entity.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Obj.h"

class Entity: public Obj
{
public:
	Entity();
	Entity(float x, float y);
	Entity(float x, float y, float z);
	Entity(float x, float y, float width, float height);
	Entity(float x, float y, float z, float width, float height);
	Entity(float x, float y, float z, float width, float height, int health);
	virtual ~Entity();
	int getHealth() const;
	void setHealth(int health);

	virtual void tick();

protected:
	int health;
	bool alive;
};

#endif /* ENTITY_H_ */
