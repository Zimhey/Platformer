/*
 * ComponentManager.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: Corey Dixon
 */

#include "ComponentManager.h"

ComponentManager::ComponentManager()
{
	stored = 0;
	container = 0;	// NULL
}

ComponentManager::~ComponentManager()
{
	for (int i = 0; i < stored; i++)
		delete container[i];
	delete container;
	container = 0;	// NULL
}

void ComponentManager::add(Component* attribute)
{
	stored++;
	Component **temp = container;
	container = new Component *[stored];
	if (temp != 0)
	{
		for (int i = 0; i < stored - 1; i++)
			container[i] = temp[i];
		delete temp;
	}
	container[stored - 1] = attribute;

}

Component** ComponentManager::getContainer() const
{
	return container;
}

int ComponentManager::getStored() const
{
	return stored;
}
