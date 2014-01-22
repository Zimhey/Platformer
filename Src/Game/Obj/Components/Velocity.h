/*
 * Velocity.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Component.h"

#ifndef VELOCITY_H_
#define VELOCITY_H_

class Velocity: public Component
{
public:
	Velocity();
	Velocity(float x, float y);
	virtual ~Velocity();
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

private:
	float x, y;
};

#endif /* VELOCITY_H_ */
