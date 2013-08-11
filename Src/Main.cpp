/*
 * Main.cpp
 *
 *  Created on: Aug 8, 2013
 *      Author: Corey Dixon
 */

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "Obj.h"

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action,
		int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	GLFWwindow* window;
	Obj floor(0, 620, 1280, 720);
	Game game;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(1280, 720, "plzkthx studios: platformer", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window))
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, -100, 100);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		/* do things here */
		floor.draw();
		floor.drawDebug();
		game.loop();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

