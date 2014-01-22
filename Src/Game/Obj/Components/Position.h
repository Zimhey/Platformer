/*
 * Position.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Component.h"

#ifndef POSITION_H_
#define POSITION_H_

class Position: public Component
{
public:
	Position();
	Position(int x, int y);
	virtual ~Position();
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

private:
	int x, y;
};

#endif /* POSITION_H_ */
