/*
 * PlayerController.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "PlayerController.h"

PlayerController::PlayerController(Level *level, Keybinds *input) :
		EntityController(level)
{
	this->input = input;
}

PlayerController::~PlayerController()
{

}

void PlayerController::tick(double deltaTime)
{
	int stopL, stopR, stopB;
	level->checkCollision(pawn->getX(), pawn->getY(), pawn->getWidth(),
			pawn->getHeight(), &stopL, &stopR, &stopB);

	double speed = 500 * deltaTime;
	if (input->moveUp())
		pawn->setY(pawn->getY() - speed * 2);
	if (input->moveLeft() && pawn->getX() > stopL)
		pawn->setX(pawn->getX() - speed);
	if (input->moveRight() && (pawn->getX() + pawn->getWidth() < stopR))
		pawn->setX(pawn->getX() + speed);

	if (input->moveDown())
		pawn->setHeight(64);
	else if (pawn->getHeight() == 64)
	{
		pawn->setHeight(128);
		pawn->setY(pawn->getY() - 64);
	}
	EntityController::tick(deltaTime);
}
