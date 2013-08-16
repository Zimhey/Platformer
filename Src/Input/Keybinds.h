/*
 * Keybinds.h
 *
 *  Created on: Aug 15, 2013
 *      Author: Corey Dixon
 */
#include "Keyboard.h"
#include "Mouse.h"
#include "Controller.h"

#ifndef KEYBINDS_H_
#define KEYBINDS_H_

class Keybinds
{
public:
	Keybinds(GLFWwindow* window);
	virtual ~Keybinds();
	bool moveUp() const;
	bool moveDown() const;
	bool moveLeft() const;
	bool moveRight() const;
	bool deleteObjs();
	bool randomObjs();
	bool saveObjs();
	bool loadObjs();
private:	// add custom control support
	Keyboard* keyboard;
	Mouse* mouse;
	Controller* controller;
	bool saveHeld;
	bool loadHeld;
	bool randHeld;
	bool delHeld;
};

#endif /* KEYBINDS_H_ */
