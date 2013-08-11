/*
 * Game.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Node.h"
#include "Obj.h"


#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
	Game();
	virtual ~Game();
	void loop();
private:
	Node<Obj> *objects;
	Obj player;
};

#endif /* GAME_H_ */
