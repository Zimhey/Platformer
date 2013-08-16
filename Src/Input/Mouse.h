/*
 * Mouse.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>

#ifndef MOUSE_H_
#define MOUSE_H_

class Mouse
{
public:
	Mouse(GLFWwindow* window);
	virtual ~Mouse();
	double getX() const;
	double getY() const;
	bool getButton(int button) const;
	void setWindow(GLFWwindow* window);

private:
	GLFWwindow* window;
	double x, y;
};

#endif /* MOUSE_H_ */
