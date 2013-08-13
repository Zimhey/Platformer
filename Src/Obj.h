/*
 * Obj.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#ifndef OBJ_H_
#define OBJ_H_

class Obj
{
public:
	Obj();
	Obj(float x, float y);
	Obj(float x, float y, float z);
	Obj(float x, float y, float width, float height);
	Obj(float x, float y, float z, float width, float height);
	virtual ~Obj();
	float getHeight() const;
	void setHeight(float height);
	float getWidth() const;
	void setWidth(float width);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	float getZ() const;
	void setZ(float z);
	virtual void tick();
	void draw();
	void drawDebug();
protected:
	float x, y, z, width, height;
};

#endif /* OBJ_H_ */
