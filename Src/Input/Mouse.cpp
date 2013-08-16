/*
 * Mouse.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "Mouse.h"

Mouse::Mouse(GLFWwindow* window)
{
	this->window = window;
	x = 0;
	y = 0;
}

Mouse::~Mouse()
{
}

double Mouse::getX() const
{
	return x;
}

double Mouse::getY() const
{
	return y;
}

bool Mouse::getButton(int button) const
{
	return glfwGetMouseButton(window, button);
}

void Mouse::setWindow(GLFWwindow* window)
{
	this->window = window;
}
