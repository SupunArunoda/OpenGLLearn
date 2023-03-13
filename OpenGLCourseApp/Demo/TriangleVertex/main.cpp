#include <stdio.h>
#include <iostream>

#include "Shader.h"
// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

std::shared_ptr<GL::BootsTrap> bootstrap;

void processInput(GLFWwindow* window) 
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void generateRectangle(GLFWwindow* mainWindow, unsigned int& shader_program)
{
	float vertices[] = {
		0.5f,0.5f,0.0f,		//top right
		0.5f,-0.5f,0.0f,		//bootom right
		-0.5f,-0.5f,0.0f,	//bottom left
		-0.5f,0.5f,0.0f,	//top left
		
	};

	unsigned int indices[] = {
		0,1,3,
		1,2,3
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	///Enable polygon mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();
		processInput(mainWindow);

		// Clear window
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw triangle
		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

		glfwSwapBuffers(mainWindow);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);


}

void generateTwoTriangle(GLFWwindow* mainWindow, unsigned int& shader_program)
{
	//create vertex data and buffers
	float vertices[] = {
		//first triangle
		-0.5f,-0.25f,0.0f,
		0.0f,-0.25f,0.0f,
		-0.25f,0.25f,0.0f,
		

		//second triangle
		0.0f,-0.25f,0.0f,
		0.5f,-0.25f,0.0f,
		0.25f,0.25f,0.0f,
		
	};


	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	//bind the buffer after enable the vertex attribute
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//bind the vertex array
	glBindVertexArray(0);

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();
		processInput(mainWindow);

		// Clear window
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw triangle
		glUseProgram(shader_program);

		//Use uniform
		double time_value = glfwGetTime();
		float green_value = static_cast<float>(sin(time_value) / 2.0 + 0.5);
		int vertex_color_location = glGetUniformLocation(shader_program, "ourColor");
		glUniform4f(vertex_color_location, 0.0f, green_value, 0.0f, 1.0f);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(mainWindow);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	
}

void generateTriangle(GLFWwindow* mainWindow, unsigned int& shader_program)
{
	//create vertex data and buffers
	float vertices[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	//bind the buffer after enable the vertex attribute
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//bind the vertex array
	glBindVertexArray(0);

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();
		processInput(mainWindow);

		// Clear window
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw triangle
		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(mainWindow);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void generateMultiColorTriangle(GLFWwindow* mainWindow, unsigned int& shader_program) 
{
	float vertices[] = {
		//vertices				//colors
		-0.5f,	-0.5f,	0.0f,	1.0f,	0.0f,	0.0f,
		0.5f,	-0.5f,	0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.5f,	0.0f,	0.0f,	0.0f,	1.0f
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	

	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();
		processInput(mainWindow);

		// Clear window
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader_program);

		// render the triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(mainWindow);
	}
}

int main()
{
	bootstrap = std::make_shared<GL::BootsTrap>();
	bootstrap->init();
	
	//Shader program
	//vertex Shader
	unsigned int vertex_shader;
	GL::ShaderResult res = GL::createVertexShader(vertex_shader);
	if (res == GL::ShaderResult::VertexShaderFailed) 
	{
		return -1;
	}

	//Fragment Shader
	unsigned int fragment_shader;
	res = GL::createFragmentShader(fragment_shader);
	if (res == GL::ShaderResult::FragmentShaderFailed)
	{
		return -1;
	}

	//link shaders
	unsigned int shader_program;
	std::vector<unsigned int> shader_list;
	shader_list.push_back(vertex_shader);
	shader_list.push_back(fragment_shader);
	res = GL::linkShaderList(shader_program, shader_list);
	if (res == GL::LinkingFailed) 
	{
		return -1;
	}

	//generateTwoTriangle(mainWindow, shader_program);
	//generateTriangle(mainWindow,shader_program);
	//generateRectangle(mainWindow, shader_program);
	generateMultiColorTriangle(bootstrap->getMainWindow(), shader_program);

	glDeleteProgram(shader_program);

	bootstrap->clear();

	return 0;
}