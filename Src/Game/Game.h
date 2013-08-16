/*
 * Game.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>
#include "../Datastructures/Node.h"
#include "../Obj/Obj.h"
#include "../Obj/Entity.h"
#include "../Input/Keybinds.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
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
	void save();
	void load();
	void addRandom();
	void addObj(Obj *obj);
	void deleteObjs();
	GLFWwindow* window;
	Keybinds* input;
	// TODO add multiple data structures for different collision types, e.g. player, enemy, neutral
	Node<Obj> *objects;
	// TEMP Player
	Entity *player;
};

#endif /* GAME_H_ */
