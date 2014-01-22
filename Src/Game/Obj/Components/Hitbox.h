/*
 * Hitbox.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Component.h"

#ifndef HITBOX_H_
#define HITBOX_H_

class Hitbox: public Component
{
public:
	Hitbox(int width, int height);
	virtual ~Hitbox();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);

private:
	int width, height;
};

#endif /* HITBOX_H_ */
