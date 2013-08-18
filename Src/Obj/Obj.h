/*
 * Obj.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include <fstream>
#include <iostream>

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
	virtual void tick(double deltaTime);
	void draw();
	void drawDebug();

	// Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Obj& obj)
		{
			// write out individual members of obj with an end of line between each one
			os << obj.x << '\n';
			os << obj.y << '\n';
			os << obj.z << '\n';
			os << obj.width << '\n';
			os << obj.height << '\n';
			os << obj.type << '\n';
			return os;
		}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Obj& obj)
	{
		// read in individual members of s
		is >> obj.x >> obj.y >> obj.z >> obj.width >> obj.height >> obj.type;
		return is;
	}

	int getType() const;
	void setType(int type);

protected:
	float x, y, z, width, height;
	int type;
};

#endif /* OBJ_H_ */
