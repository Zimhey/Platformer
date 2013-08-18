/*
 * Game.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Game::Game(GLFWwindow* window)
{
	this->window = window;
	input = new Keybinds(window);
	level = new Level();
	objects = NULL;
	deltaTime = 0;
	lastTime = glfwGetTime();
	//Obj *floor = new Obj(0, 620, 1281, 720);
	player = new Entity(640, 360, 64, 128);
	player->setType(2);
	//addObj(floor);
	addObj(player);
}

Game::~Game()
{
	while (objects != NULL)
	{
		Node<Obj> *del = objects;
		delete del->obj;
		objects = objects->next;
		delete del;
	}
}

void Game::loop()
{
	calculateDeltaTime();
	level->draw();

	// TEMP input stuff
	if (input->deleteObjs())
		deleteObjs();
	if (input->randomObjs())
		addRandom();
	if (input->saveObjs())
		save();
	if (input->loadObjs())
		load();
	if (input->click())
		level->setTile(input->mouseX(), input->mouseY(), 0, 2);
	if (input->rightClick())
		level->setTile(input->mouseX(), input->mouseY(), 1, 2);

	if (player != NULL)
	{
		double speed = 700 * deltaTime;
		if (input->moveUp())
			player->setY(player->getY() - speed * 2);
		if (input->moveLeft())
			player->setX(player->getX() - speed);
		if (input->moveRight())
			player->setX(player->getX() + speed);

		if (input->moveDown())
			player->setHeight(64);
		else
			player->setHeight(128);
	}
	else
	{
		player = new Entity(640, 360, 64, 128);
		player->setType(2);
		addObj(player);
	}

	Node<Obj> *traverseP = objects;
	while (traverseP != NULL)
	{
		traverseP->obj->tick(deltaTime);
		traverseP->obj->draw();
		//traverseP->obj->drawDebug();
		traverseP = traverseP->next;
	}
}

void Game::save()
{
	level->save(); // TEMP
	int totalObjects = 0;
	std::ofstream ofs("save.sav");
	Node<Obj> *traverseP = objects;
	while (traverseP != NULL)
	{
		totalObjects++;
		traverseP = traverseP->next;
	}

	// write total objects
	ofs << totalObjects << "\n\n";

	traverseP = objects;
	while (traverseP != NULL)
	{
		ofs << traverseP->obj->getType() << '\n';
		ofs << traverseP->obj[0] << '\n';
		traverseP = traverseP->next;
	}
	ofs.close();
}

void Game::load()
{
	level->load();	// TEMP
	deleteObjs();
	std::ifstream ifs("save.sav");
	int read = 0;
	ifs >> read;
	for (int i = 0; i < read; i++)
	{
		int type = -1;
		ifs >> type;
		Obj *obj;
		if (type == 0)
		{
			obj = new Obj();
			ifs >> *obj;
			addObj(obj);
		}
		else if (type == 1)
		{
			obj = new Entity();
			ifs >> *obj;
			addObj(obj);
		}
		else if (type == 2)
		{
			obj = new Entity();
			ifs >> *obj;
			player = dynamic_cast<Entity*>(obj);
			addObj(obj);
		}
		else
		{
			std::cout << "ERROR: Invalid Object type: Object #" << i;
			break;
		}

	}

	ifs.close();
}

void Game::addRandom()
{
	srand(int(glfwGetTime() * glfwGetTime()) % 256);
	int newObjs = rand() % 4 + 1; // 1-5
	for (int i = 0; i < newObjs; i++)
	{
		Obj *obj;
		int type = rand() % 2;
		if (type == 0)
			obj = new Obj(rand() % 1280, rand() % 640, rand() % 32 + 32,
					rand() % 64 + 64);
		if (type == 1)
			obj = new Entity(rand() % 1280, rand() % 640, rand() % 32 + 32,
					rand() % 64 + 64);
		addObj(obj);
	}
}

void Game::addObj(Obj *obj)
{
	if (objects == NULL)
	{
		objects = new Node<Obj>(obj);
		return;
	}
	objects->prev = new Node<Obj>(obj);
	objects->prev->next = objects;
	objects = objects->prev;

}

void Game::deleteObjs()
{
	while (objects != NULL)
	{
		Node<Obj> *last = objects;
		if (objects->obj == player)
			player = NULL;
		delete objects->obj;
		objects = objects->next;
		delete last;
	}
}

void Game::calculateDeltaTime()
{
	deltaTime = (glfwGetTime() - lastTime);
	lastTime = glfwGetTime();
}
