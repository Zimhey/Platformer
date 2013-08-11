/*
 * Game.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Game.h"

Game::Game()
{
	// TODO Auto-generated constructor stub
	objects = 0;
	player.setX(640);
	player.setY(360);
	player.setWidth(64);
	player.setHeight(128);
}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

void Game::loop()
{
	if(player.getY() + player.getHeight() < 620)
		player.setY(player.getY() + 1);
	player.draw();
}
