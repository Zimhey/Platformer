/*
 * Game.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Game.h"

Game::Game()
{
	window = NULL;
	objects = NULL;
	Obj *floor = new Obj(0, 620, 1280, 720);
	player = new Entity(640, 360, 64, 128);
	addObj(floor);
	addObj(player);
}

Game::Game(GLFWwindow* window)
{
	this->window = window;
	objects = NULL;
	Obj *floor = new Obj(0, 620, 1280, 720);
	player = new Entity(640, 360, 64, 128);
	addObj(floor);
	addObj(player);
}

Game::~Game()
{
	while(objects != NULL)
	{
		Node<Obj> *del = objects;
		delete del->obj;
		objects = objects->next;
		delete del;
	}
}

void Game::loop()
{
	// TEMP input stuff
	if(glfwGetKey(window, 87))	// W
		player->setY(player->getY() - 5);
	if(glfwGetKey(window, 65))	// A
			player->setX(player->getX() - 5);
	if(glfwGetKey(window, 68))	// D
				player->setX(player->getX() + 5);




	Node<Obj> *traverseP = objects;
	while(traverseP != NULL)
	{
		traverseP->obj->tick();
		//traverseP->obj->draw();
		traverseP->obj->drawDebug();
		traverseP = traverseP->next;
	}
}

void Game::addObj(Obj *obj)
{
	if(objects == NULL)
	{
		objects = new Node<Obj>(obj);
		return;
	}
	objects->prev = new Node<Obj>(obj);
	objects->prev->next = objects;
	objects = objects->prev;

}