/*
 * Physics.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Physics.h"

Physics::Physics()
{
	deltaTime = 0;
}

Physics::~Physics()
{
}

void Physics::run(Level* level, Node<Obj>* objects, double deltaTime)
{
	this->deltaTime = deltaTime;

	Node<Obj> *traverseP = objects;
	while (traverseP != 0)	// NULL
	{
		Component** attributes =
				traverseP->obj->getAttributes()->getContainer();
		int stored = traverseP->obj->getAttributes()->getStored();

		PhysicsSystem ps;
		for (int i = 0; i < stored; i++)
		{
			ps.pos = dynamic_cast<Position*>(attributes[i]);
			if (ps.pos != 0)	// found Position
			{
				for (int j = 0; j < stored; j++)
				{
					ps.hitbox = dynamic_cast<Hitbox*>(attributes[j]);
					if (ps.hitbox != 0)	// found Hitbox
					{
						for (int k = 0; k < stored; k++)
						{
							ps.vel = dynamic_cast<Velocity*>(attributes[k]);
							if (ps.vel != 0)	// found Velocity
								break;
						}
						break;
					}
				}
				break;
			}
		}

		if (ps.pos != 0 && ps.hitbox != 0 && ps.vel != 0)
		{
			levelCollision(level, ps);
			update(ps);
		}
		traverseP = traverseP->next;
	}

}

void Physics::levelCollision(Level* level, PhysicsSystem& ps)
{
	ps.vel->setY(ps.vel->getY() + (1500 * deltaTime));	// DEBUG gravity
	int stopL = 0;
	int stopR = 0;
	int stopB = 0;
	level->checkCollision(ps.pos->getX(), ps.pos->getY(), ps.hitbox->getWidth(),
			ps.hitbox->getHeight(), &stopL, &stopR, &stopB);

	if (ps.pos->getY() + ps.hitbox->getHeight() + (ps.vel->getY() * deltaTime)
			> stopB)
		ps.vel->setY(0);
}

void Physics::update(PhysicsSystem& ps)
{

	ps.pos->setX(ps.pos->getX() + ps.vel->getX() * deltaTime);
	ps.pos->setY(ps.pos->getY() + ps.vel->getY() * deltaTime);
}
