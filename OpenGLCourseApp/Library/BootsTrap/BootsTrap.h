#ifndef OPENGL_LIBRARY_BOOTSTRAP
#define OPENGL_LIBRARY_BOOTSTRAP

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
constexpr char* WINDOW_NAME = "My Window";

namespace GL 
{
	enum BOOTSTRAPRESULT
	{
		SUCCESS,
		GLFW_INITIALIZE_FAILED,
		GLFW_WINDOW_INITIALIZE_FAILED,
		GLEW_INITIALIZE_FAILED,
		OTHER
	};

	class BootsTrap 
	{
	private:
		char* window_name_;
		int window_width_;
		int window_height_;
		GLFWwindow* main_window_;

		void processInput();


	public:
		BootsTrap();
		BootsTrap(int window_width, int window_height, char* window_name);
		BOOTSTRAPRESULT init();
		void play();
		GLFWwindow* getMainWindow();
		BOOTSTRAPRESULT clear();
		


	};
}

#endif // OPENGL_LIBRARY_BOOTSTRAP