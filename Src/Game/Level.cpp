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
	tileSize = 16;
	width = 160;
	height = 80;
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
	clear();
}

int Level::getHeight() const
{
	return height;
}

void Level::setHeight(int height)	// TEMP	level editor only
{
	this->height = height;
}

int Level::getWidth() const
{
	return width;
}

void Level::setWidth(int width)		// TEMP level editor only
{
	this->width = width;
}

int** Level::getTiles() const
{
	return tiles;
}


int Level::getTileSize() const
{
	return tileSize;
}

void Level::setTile(int x, int y, int click, int radius)// TODO implement radius
{
	int tile = click * -1;
	tiles[x / tileSize][y / tileSize] = tile;
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
		int* stopR, int *stopB)		// TODO change
{
	int xx = x / tileSize;
	int yy = y / tileSize;
	int xw = (x + width) / tileSize;
	int yh = ((y + height) / tileSize) - 1;

	/*tiles[xx][yy] = 1;
	 tiles[xx][yh] = 1;*/
	for (int i = xw; i < this->width; i++)	// right
	{
		// head
		if (tiles[i][yy] != -1)
		{
			tiles[i][yy] = 2;
			*stopR = i * tileSize;
			break;
		}
		// feet
		if (tiles[i][yh] != -1)
		{
			tiles[i][yh] = 2;
			*stopR = i * tileSize;
			break;
		}
	}

	for (int i = xx; i >= 0; i--)	// left
	{
		// head
		if (tiles[i][yy] != -1)
		{
			tiles[i][yy] = 2;
			*stopL = (i + 1) * tileSize;
			break;
		}
		// feet
		if (tiles[i][yh] != -1)
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

void Level::clear()
{
	for (int i = 0; i < width; i++)
		delete tiles[i];
	delete tiles;
}
