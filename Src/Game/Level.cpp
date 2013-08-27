/*
 * Level.cpp
 *
 *  Created on: Aug 17, 2013
 *      Author: Corey Dixon
 */

#include "Level.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

Level::Level()
{
	tileSize = 64;
	width = 1280 / tileSize;
	height = 720 / tileSize;
	tiles = new int *[width];
	//srand(2);
	for (int i = 0; i < width; i++)
	{
		tiles[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			tiles[i][j] = rand() % 2 - 1;	// -1-0
		}
	}
	load();
}

Level::~Level()
{
	// TODO delete tiles
}

int Level::getHeight() const
{
	return height;
}

void Level::setHeight(int height)
{
	this->height = height;
}

int Level::getWidth() const
{
	return width;
}

void Level::setWidth(int width)
{
	this->width = width;
}

int** Level::getTiles() const
{
	return tiles;
}

void Level::setTile(int x, int y, int click, int radius)// TODO implement radius
{
	int tile = click * -1;
	tiles[x / tileSize][y / tileSize] = tile;
}

void Level::draw()
{
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

void Level::save()
{
	std::ofstream ofs("level.dat");
	ofs << width << '\n' << height << '\n' << tileSize << '\n';

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			ofs << tiles[i][j] << '\n';
	ofs.close();
}

void Level::load()
{
	// delete tiles first
	std::ifstream ifs("level.dat");
	ifs >> width;
	ifs >> height;
	ifs >> tileSize;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			ifs >> tiles[i][j];
	ifs.close();
}
// separate the fall check from left and right check
void Level::checkCollision(int x, int y, int width, int height, int* stopL,
		int* stopR, int *stopB)
{
	int xx = x / tileSize;
	int yy = y / tileSize;
	int xw = (x + width) / tileSize;
	int yh = ((y + height) / tileSize) - 1;

	/*tiles[xx][yy] = 1;
	 tiles[xx][yh] = 1;*/
	for(int i = xw; i < this->width; i++)	// right
	{
		// head
		if(tiles[i][yy] != -1)
		{
			tiles[i][yy] = 2;
			*stopR = i * tileSize;
			break;
		}
		// feet
		if(tiles[i][yh] != -1)
		{
			tiles[i][yh] = 2;
			*stopR = i * tileSize;
			break;
		}
	}

	for(int i = xx; i >= 0; i--)	// left
	{
		// head
		if(tiles[i][yy] != -1)
		{
			tiles[i][yy] = 2;
			*stopL = (i + 1) * tileSize;
			break;
		}
		// feet
		if(tiles[i][yh] != -1)
		{
			tiles[i][yh] = 2;
			*stopL = (i + 1) * tileSize;
			break;
		}
	}

	for (int i = yh + 1; i < this->height; i++)	// bottom
	{
		if (tiles[xx][i] != -1)
		{
			tiles[xx][i] = 1;
			*stopB = i * tileSize;
			break;
		}
		if (tiles[xw][i] != -1)	//
		{
			tiles[xw][i] = 1;
			*stopB = i * tileSize;
			break;
		}
	}

}
