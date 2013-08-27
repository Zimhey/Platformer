/*
 * PlayerController.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "EntityController.h"
#include "../Input/Keybinds.h"

class PlayerController: public EntityController
{
public:
	PlayerController(Level *level, Keybinds *input);
	virtual ~PlayerController();
	virtual void tick(double deltaTime);
private:
	Keybinds *input;
};

#endif /* PLAYERCONTROLLER_H_ */
