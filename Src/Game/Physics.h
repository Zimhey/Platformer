/*
 * Physics.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "../DataStructures/Node.h"
#include "Level.h"
#include "Obj/ComponentManager.h"
#include "Obj/Obj.h"
#include "Obj/Components/Position.h"
#include "Obj/Components/Hitbox.h"
#include "Obj/Components/Velocity.h"
#include "Obj/ComponentsSystems/PhysicsSystem.h"


#ifndef PHYSICS_H_
#define PHYSICS_H_

class Physics
{
public:
	Physics();
	virtual ~Physics();	// TODO Finds collisions between Obj and level, then between Objs, then moves each
	void run(Level *level, Node<Obj> *objects, double deltaTime);
private:
	void levelCollision(Level *level, PhysicsSystem &ps);
	void ObjCollision();
	void AABB();
	void update(PhysicsSystem &ps);
	double deltaTime;
};

#endif /* PHYSICS_H_ */
