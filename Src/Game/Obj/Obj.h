/*
 * Obj.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "ComponentManager.h"

#ifndef OBJ_H_
#define OBJ_H_

class Obj
{
public:
	Obj();
	virtual ~Obj();
	ComponentManager* getAttributes();

protected:
	ComponentManager attributes;
};

#endif /* OBJ_H_ */
