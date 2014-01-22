/*
 * Game.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>
#include "../Datastructures/Node.h"
#include "Obj/Obj.h"
#include "Obj/GameObjects/Player.h"
#include "../Input/Keybinds.h"
#include "Level.h"
#include "Physics.h"
#include "Render.h"

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
	void calculateDeltaTime();
	void handleInput();

	Level *level;
	GLFWwindow* window;
	Keybinds* input;
	Node<Obj> *objects;

	Player *player;

	double deltaTime, lastTime;
};

#endif /* GAME_H_ */
