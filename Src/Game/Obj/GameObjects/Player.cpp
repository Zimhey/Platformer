/*
 * Player.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Player.h"

Player::Player()
{
	attributes.add(new Position(1280 / 2, 720 / 2));
	attributes.add(new Sprite(32, 64));
	attributes.add(new Hitbox(32, 64));
	attributes.add(new Velocity());
}

Player::~Player()
{
}

