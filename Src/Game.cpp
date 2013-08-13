/*
 * Game.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Game.h"

Game::Game()
{
	objects = NULL;
	Obj *floor = new Obj(0, 620, 1280, 720);
	Entity *player = new Entity(640, 360, 64, 128);
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

	Node<Obj> *traverseP = objects;
	while(traverseP != NULL)
	{
		traverseP->obj->tick();
		traverseP->obj->draw();
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
