/*
 * Keyboard.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "Keyboard.h"

Keyboard::Keyboard(GLFWwindow* window)
{
	this->window = window;
}

Keyboard::~Keyboard()
{

}

void Keyboard::setWindow(GLFWwindow* window)
{
	this->window = window;
}

bool Keyboard::getKey(int key) const
{
	return glfwGetKey(window, key);
}
