/*
 * Controller.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include "Controller.h"

Controller::Controller(GLFWwindow* window)
{
	this->window = window;
}

Controller::~Controller()
{

}

bool Controller::getA()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[0];
}

bool Controller::getB()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	/*for(int i = 0; i < count; i++)
	 if(buttons[i] > 0)
	 return true;*/
	return buttons[1];
}

bool Controller::getX()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[2];
}

bool Controller::getY()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[3];
}

bool Controller::getLB()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[4];
}

bool Controller::getRB()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[5];
}

bool Controller::getBack()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[6];
}

bool Controller::getStart()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[7];
}

bool Controller::getLeftJoyStickPressed()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[8];
}

bool Controller::getRightJoyStickPressed()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[9];
}

bool Controller::getDUp()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[10];
}

bool Controller::getDDown()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[12];
}

bool Controller::getDLeft()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[13];
}

bool Controller::getDRight()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(0, &count);
	return buttons[11];
}

bool Controller::getLeftStickUp()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[1] > 0.25;
}

bool Controller::getLeftStickDown()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[1] < -0.25;
}

bool Controller::getLeftStickRight()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[0] > 0.25;
}

bool Controller::getLeftStickLeft()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[0] < -0.25;
}

bool Controller::getRightStickUp()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[3] < -0.25;
}

bool Controller::getRightStickDown()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[3] > 0.25;
}

bool Controller::getRightStickRight()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[4] > 0.25;
}

bool Controller::getRightStickLeft()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[4] < -0.25;
}

bool Controller::getLeftTrigger()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[2] > 0.25;
}

bool Controller::getRightTrigger()
{
	if (!controllerPresent())
		return false;
	int count = 0;
	const float* axes = glfwGetJoystickAxes(0, &count);
	return axes[2] < -0.25;
}

/* private function to make sure there is a controller and prevent accessing NULL */
bool Controller::controllerPresent()
{
	return glfwJoystickPresent(0);
}
