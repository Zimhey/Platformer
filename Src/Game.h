/*
 * Game.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>
#include "Datastructures/Node.h"
#include "Obj.h"
#include "Entity.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
	Game();
	Game(GLFWwindow* window);
	virtual ~Game();
	void loop();

	const GLFWwindow* getWindow() const
	{
		return window;
	}

	void setWindow(GLFWwindow* window)
	{
		this->window = window;
	}

private:
	void addObj(Obj *obj);
	GLFWwindow* window;
	// TODO add multiple data structures for collision types, e.g. environment, player, enemy
	Node<Obj> *objects;
	// TEMP Player
	Entity *player;
};

#endif /* GAME_H_ */
