/*
 * EntityController.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "EntityController.h"

EntityController::EntityController(Level *level)
{
	this->level = level;
	pawn = new Entity(640, 360, 64, 128);
}

EntityController::~EntityController()
{

}

void EntityController::tick(double deltaTime)
{
	int stopL, stopR, stopB;
	level->checkCollision(pawn->getX(), pawn->getY(), pawn->getWidth(),
			pawn->getHeight(), &stopL, &stopR, &stopB);
	// TEMP gravity
	double gravity = 400 * deltaTime;
	if (pawn->getY() + pawn->getHeight() < stopB + gravity)
		pawn->setY(pawn->getY() + gravity);
	if (pawn->getY() + pawn->getHeight() > stopB)
		pawn->setY(stopB - pawn->getHeight());
/*	if (pawn->getX() + pawn->getWidth() > stopR)
			pawn->setX(stopR - pawn->getWidth());*/
	pawn->tick(deltaTime);
	pawn->draw();
}
