/*
 * Controller.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

class Controller
{
public:
	Controller(GLFWwindow* window);
	virtual ~Controller();
	// buttons
	bool getA();
	bool getB();
	bool getX();
	bool getY();
	bool getLB();
	bool getRB();
	bool getBack();
	bool getStart();
	bool getLeftJoyStickPressed();
	bool getRightJoyStickPressed();
	bool getDUp();
	bool getDDown();
	bool getDLeft();
	bool getDRight();
	// axes
	bool getLeftStickUp();
	bool getLeftStickDown();
	bool getLeftStickRight();
	bool getLeftStickLeft();
	bool getRightStickUp();
	bool getRightStickDown();
	bool getRightStickRight();
	bool getRightStickLeft();
	bool getLeftTrigger();
	bool getRightTrigger();
private:
	GLFWwindow* window;
	bool controllerPresent();	// COOP add multiple controllers
};

#endif /* CONTROLLER_H_ */
