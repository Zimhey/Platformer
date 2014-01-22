/*
 * ComponentManager.h
 *
 *  Created on: Aug 31, 2013
 *      Author: Corey Dixon
 */

#include "Components/Component.h"

#ifndef COMPONENTMANAGER_H_
#define COMPONENTMANAGER_H_

class ComponentManager
{
public:
	ComponentManager();
	virtual ~ComponentManager();
	void add(Component *attribute);
	Component** getContainer() const;
	int getStored() const;
	// TODO create a function that takes a Component, finds a Component of the same type and returns it
private:
	Component **container;	// TODO simplify *remove pointer*
	int stored;
};

#endif /* COMPONENTMANAGER_H_ */
