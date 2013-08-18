/*
 * Entity.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include <fstream>
#include <iostream>

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Obj.h"

class Entity: public Obj
{
public:
	Entity();
	Entity(float x, float y);
	Entity(float x, float y, float z);
	Entity(float x, float y, float width, float height);
	Entity(float x, float y, float z, float width, float height);
	Entity(float x, float y, float z, float width, float height, int health);
	virtual ~Entity();
	int getHealth() const;
	void setHealth(int health);

	virtual void tick(double deltaTime);

	// Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Entity& obj)
		{
			// write out individual members of obj with an end of line between each one
			os << obj.x << '\n';
			os << obj.y << '\n';
			os << obj.z << '\n';
			os << obj.width << '\n';
			os << obj.height << '\n';
			os << obj.type << '\n';
			os << obj.health << '\n';
			os << obj.alive << '\n';
			return os;
		}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Entity& obj)
	{
		// read in individual members of s
		is >> obj.x >> obj.y >> obj.z >> obj.width >> obj.height >> obj.type >> obj.health >> obj.alive;
		return is;
	}
protected:
	int health;
	bool alive;
};

#endif /* ENTITY_H_ */
