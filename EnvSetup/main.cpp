#include <stdlib.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

const GLint WIDTH = 800, HEIGHT = 600;

int main() 
{
	if (!glfwInit()) 
	{
		std::cerr << "GLFW Initialization Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Setup GLFW window properties
	//OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//create window
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow) 
	{
		std::cerr << "GLFW Window creation Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Get Buffer Size Information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) 
	{
		std::cerr << "GLEW Initialisation Failed" << std::endl;
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return -1;
	}

	//Setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		glfwPollEvents();

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}
	return 0;
}