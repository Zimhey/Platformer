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
	player = new Player();
	objects = NULL;
	deltaTime = 0;
	lastTime = glfwGetTime();
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
	handleInput();
	Physics physics;
	physics.run(level, objects, deltaTime);

/*	Node<Obj> *traverseP = objects;
	while (traverseP != NULL)
	{
		traverseP = traverseP->next;
	} */


	Render render;
	render.draw(level, objects);
}

void Game::save()
{
	level->save(); // TEMP
}

void Game::load()
{
	level->load();	// TEMP
}

void Game::addRandom()
{
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

void Game::handleInput()
{
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
}
