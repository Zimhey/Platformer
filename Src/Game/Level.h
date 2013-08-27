/*
 * Level.h
 *
 *  Created on: Aug 17, 2013
 *      Author: Corey Dixon
 */



#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
public:
	Level();
	virtual ~Level();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int** getTiles() const;
	void setTile(int x, int y, int click, int radius);

	void draw();
	void save();
	void load();

	void checkCollision(int x, int y, int width, int height, int *stopL, int *stopR, int *stopB);
private:
	int width, height;
	int tileSize;
	int **tiles;
};

#endif /* LEVEL_H_ */
