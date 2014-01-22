/*
 * Render.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>

#include "../DataStructures/Node.h"
#include "Level.h"
#include "Obj/ComponentManager.h"
#include "Obj/Obj.h"
#include "Obj/Components/Position.h"
#include "Obj/Components/Sprite.h"

#ifndef RENDER_H_
#define RENDER_H_

class Render
{
public:
	Render();
	virtual ~Render();
	void draw(Level *level, Node<Obj> *objects);
private:
	void drawBackdrop();
	void drawLevel(Level *level);
	void drawObjects(Node<Obj> *objects);
};

#endif /* RENDER_H_ */
