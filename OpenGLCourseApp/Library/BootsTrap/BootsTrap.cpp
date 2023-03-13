#include "BootsTrap.h"

namespace GL 
{
	BootsTrap::BootsTrap() 
	{
		window_width_ = WINDOW_WIDTH;
		window_height_ = WINDOW_HEIGHT;
		window_name_ = WINDOW_NAME;
	}

	BootsTrap::BootsTrap(int window_width, int window_height, char* window_name)
	{
		window_width_ = window_width;
		window_height_ = window_height;
		window_name_ = window_name;
	}

	BOOTSTRAPRESULT BootsTrap::init()
	{
		// Initialise GLFW
		if (!glfwInit())
		{
			std::cerr << "GLFW initialisation failed!" << std::endl;
			//printf("GLFW initialisation failed!");
			glfwTerminate();
			return BOOTSTRAPRESULT::GLFW_INITIALIZE_FAILED;
		}

		// Setup GLFW window properties
		// OpenGL version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Core Profile = No Backwards Compatibility
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// Allow Forward Compatbility
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		// Create the window
		main_window_ = glfwCreateWindow(window_width_, window_height_, window_name_, NULL, NULL);
		if (!main_window_)
		{
			std::cerr << "GLFW window creation failed!" << std::endl;
			//printf("GLFW window creation failed!");
			glfwTerminate();
			return BOOTSTRAPRESULT::GLFW_WINDOW_INITIALIZE_FAILED;
		}

		// Get Buffer Size information
		int buffer_width, buffer_height;
		glfwGetFramebufferSize(main_window_, &buffer_width, &buffer_height);

		// Set context for GLEW to use
		glfwMakeContextCurrent(main_window_);

		// Allow modern extension features
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			std::cerr << "GLEW initialisation failed!" << std::endl;
			//printf("GLEW initialisation failed!");
			glfwDestroyWindow(main_window_);
			glfwTerminate();
			return BOOTSTRAPRESULT::GLEW_INITIALIZE_FAILED;
		}

		// Setup Viewport size
		glViewport(0, 0, buffer_width, buffer_height);
		return BOOTSTRAPRESULT::SUCCESS;
	}

	BOOTSTRAPRESULT BootsTrap::clear() 
	{
		glfwTerminate();
		return BOOTSTRAPRESULT::SUCCESS;
	}

	void BootsTrap::play() 
	{
		// Loop until window closed
		while (!glfwWindowShouldClose(main_window_))
		{
			// Get + Handle user input events
			glfwPollEvents();
			processInput();

			// Clear window
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(main_window_);
		}
	}

	GLFWwindow* BootsTrap::getMainWindow() 
	{
		return main_window_;
	}

	void BootsTrap::processInput()
	{
		if (glfwGetKey(main_window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(main_window_, true);
		}
	}
}