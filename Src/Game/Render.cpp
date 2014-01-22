/*
 * Render.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Render.h"

Render::Render()
{
}

Render::~Render()
{
}

void Render::draw(Level* level, Node<Obj> *objects)
{
	// TODO Render Backdrop
	drawBackdrop();

	drawLevel(level);

	drawObjects(objects);
}

void Render::drawBackdrop()
{
}

void Render::drawLevel(Level* level)
{
	int width = level->getWidth();
	int height = level->getHeight();
	int tileSize = level->getTileSize();
	int **tiles = level->getTiles();

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			if (tiles[i][j] != -1)
			{
				glPushMatrix();
				glTranslated(i * tileSize, j * tileSize, 0);
				glBegin(GL_QUADS);
				if (tiles[i][j] == 1)
					glColor3f(0.f, 0.f, 1.f);
				else if (tiles[i][j] == 2)
					glColor3f(1.f, 0.f, 1.f);
				else
					glColor3f(1.f, 1.f, 1.f);
				glVertex3f(0, 0, 0);
				glVertex3f(tileSize, 0, 0);
				glVertex3f(tileSize, tileSize, 0);
				glVertex3f(0, tileSize, 0);
				glEnd();
				glPopMatrix();

			}
		}
}

void Render::drawObjects(Node<Obj>* objects)
{
	Node<Obj> *traverseP = objects;
	while (traverseP != 0)	// NULL check
	{
		ComponentManager* obj = traverseP->obj->getAttributes();
		// USE dynamic cast to find position and sprite attributes then render

		int stored = obj->getStored();
		Component** attributes = obj->getContainer();
		Position *pos = 0;
		Sprite *sprite = 0;

		for (int i = 0; i < stored; i++)
		{
			pos = dynamic_cast<Position*>(attributes[i]);
			if (pos != 0)	// found Position
			{
				for (int j = 0; j < stored; j++)
				{
					sprite = dynamic_cast<Sprite*>(attributes[j]);
					if (sprite != 0)	// found Sprite
						break;
				}
				break;
			}
		}

		if (pos != 0 && sprite != 0)
		{
			glPushMatrix();
			glTranslated(pos->getX(), pos->getY(), sprite->getZ());
			glBegin(GL_QUADS);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3d(0, 0, sprite->getZ());
			glVertex3d(sprite->getWidth(), 0, sprite->getZ());
			glVertex3d(sprite->getWidth(), sprite->getHeight(), sprite->getZ());
			glVertex3d(0, sprite->getHeight(), sprite->getZ());
			glEnd();
			glPopMatrix();
		}
		traverseP = traverseP->next;
	}
}
