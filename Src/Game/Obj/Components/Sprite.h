/*
 * Sprite.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Corey Dixon
 */

#include "Component.h"

#ifndef SPRITE_H_
#define SPRITE_H_

class Sprite: public Component
{
public:
	Sprite(float width, float height);
	Sprite(float width, float height, int z);
	Sprite(float width, float height, int z, int tex);
	virtual ~Sprite();
	float getHeight() const;
	void setHeight(float height);
	int getTex() const;
	void setTex(int tex);
	float getWidth() const;
	void setWidth(float width);
	int getZ() const;
	void setZ(int z);

private:
	float width, height;
	int z, tex;
};

#endif /* SPRITE_H_ */
