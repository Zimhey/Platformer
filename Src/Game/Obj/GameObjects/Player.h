/*
 * Player.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "../Components/Position.h"
#include "../Components/Sprite.h"
#include "../Components/Hitbox.h"
#include "../Components/Velocity.h"

#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Obj.h"

class Player: public Obj
{
public:
	Player();
	virtual ~Player();
};

#endif /* PLAYER_H_ */
