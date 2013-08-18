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
