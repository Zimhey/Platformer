/*
 * Entity.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Obj.h"

class Entity: private Obj
{
public:
	Entity();
	virtual ~Entity();
};

#endif /* ENTITY_H_ */
