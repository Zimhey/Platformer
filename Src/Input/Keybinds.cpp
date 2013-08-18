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
	saveHeld = loadHeld = randHeld = delHeld = false;
}

Keybinds::~Keybinds()
{
	delete keyboard;
}

bool Keybinds::moveUp() const
{
	return keyboard->getKey(GLFW_KEY_W) | keyboard->getKey(GLFW_KEY_UP)
			| keyboard->getKey(GLFW_KEY_SPACE) | controller->getA()
			| controller->getDUp() | controller->getLeftStickUp();
}

bool Keybinds::moveDown() const
{
	return keyboard->getKey(GLFW_KEY_S) | keyboard->getKey(GLFW_KEY_DOWN)
			| controller->getDDown() | controller->getLeftStickDown();
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

bool Keybinds::deleteObjs()
{
	if (keyboard->getKey(GLFW_KEY_E))
	{
		if (delHeld == false)
		{
			delHeld = true;
			return true;
		}
	}
	else
		delHeld = false;

	return false;
}

bool Keybinds::randomObjs()
{
	if (keyboard->getKey(GLFW_KEY_R))
	{
		if (randHeld == false)
		{
			randHeld = true;
			return true;
		}
	}
	else
		randHeld = false;
	return false;
}

bool Keybinds::saveObjs()
{
	if (keyboard->getKey(GLFW_KEY_C))
	{
		if (saveHeld == false)
		{
			saveHeld = true;
			return true;
		}
	}
	else
		saveHeld = false;
	return false;
}

bool Keybinds::loadObjs()
{
	if (keyboard->getKey(GLFW_KEY_V))
	{
		if (loadHeld == false)
		{
			loadHeld = true;
			return true;
		}
	}
	else
		loadHeld = false;
	return false;
}

bool Keybinds::click() const
{
	return mouse->getButton(0);
}

bool Keybinds::rightClick() const
{
	return mouse->getButton(1);
}

int Keybinds::mouseX() const
{
	return mouse->getX();
}

int Keybinds::mouseY() const
{
	return mouse->getY();
}
