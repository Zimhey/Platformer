/*
 * EntityController.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "../Obj/Entity.h"
#include "Level.h"

#ifndef ENTITYCONTROLLER_H_
#define ENTITYCONTROLLER_H_

class EntityController
{
public:
	EntityController(Level *level);
	virtual ~EntityController();
	virtual void tick(double deltaTime);
protected:
	Level *level;
	Entity *pawn;
	bool pawnFalling;
	int stopL, stopR;
};

#endif /* ENTITYCONTROLLER_H_ */
