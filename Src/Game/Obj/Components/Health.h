/*
 * Health.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Component.h"

#ifndef HEALTH_H_
#define HEALTH_H_

class Health: public Component
{
public:
	Health(int hp, int max);
	virtual ~Health();
	bool isAlive() const;
	void setAlive(bool alive);
	int getHp() const;
	void setHp(int hp);
	int getMax() const;
	void setMax(int max);

private:
	int hp, max;	// TODO abstract base component class
	bool alive;
};

#endif /* HEALTH_H_ */
