/*
 * Keyboard.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard
{
public:
	Keyboard(GLFWwindow* window);
	virtual ~Keyboard();
	void setWindow(GLFWwindow* window);
	bool getKey(int key) const;
private:
	GLFWwindow* window;
};

#endif /* KEYBOARD_H_ */
