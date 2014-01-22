/*
 * PhysicsSystem.h
 *
 *  Created on: Aug 31, 2013
 *      Author: Corey Dixon
 */

#include "../Components/Position.h"
#include "../Components/Hitbox.h"
#include "../Components/Velocity.h"

#ifndef PHYSICSSYSTEM_H_
#define PHYSICSSYSTEM_H_

class PhysicsSystem
{
public:
	PhysicsSystem();
	virtual ~PhysicsSystem();
	Position *pos;
	Hitbox *hitbox;
	Velocity *vel;
};

#endif /* PHYSICSSYSTEM_H_ */
