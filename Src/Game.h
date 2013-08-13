/*
 * Game.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Datastructures/Node.h"
#include "Obj.h"
#include "Entity.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
	Game();
	virtual ~Game();
	void loop();

private:
	void addObj(Obj *obj);
	// TODO add multiple data structures for collision types, e.g. environment, player, enemy
	Node<Obj> *objects;
};

#endif /* GAME_H_ */
