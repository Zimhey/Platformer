/*
 * Keybinds.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "Keybinds.h"

Keybinds::Keybinds(GLFWwindow* window)
{
	keyboard = new Keyboard(window);
	mouse = new Mouse(window);
	controller = new Controller(window);
}

Keybinds::~Keybinds()
{
	delete keyboard;
}

bool Keybinds::moveUp() const
{
	return keyboard->getKey(GLFW_KEY_W) | keyboard->getKey(GLFW_KEY_UP) | keyboard->getKey(GLFW_KEY_SPACE) | controller->getA() |
			controller->getDUp() | controller->getLeftStickUp();
}

bool Keybinds::moveDown() const
{
	return false;
}

bool Keybinds::moveLeft() const
{
	return keyboard->getKey(GLFW_KEY_A) | keyboard->getKey(GLFW_KEY_LEFT)
			| controller->getDLeft() | controller->getLeftStickLeft();
}

bool Keybinds::moveRight() const
{
	return keyboard->getKey(GLFW_KEY_D) | keyboard->getKey(GLFW_KEY_RIGHT)
			| controller->getDRight() | controller->getLeftStickRight();
}
