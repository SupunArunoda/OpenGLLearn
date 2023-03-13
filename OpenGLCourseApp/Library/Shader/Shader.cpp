#include "Shader.h"


namespace GL 
{
	/*
	//One color
	const char* vertex_shader_source_ = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragment_shader_source_ = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"	//FragColor = vec4(1.0f, 0.5f, 0.9f, 1.0f);\n"
		"	FragColor = ourColor; \n"
		"}\n\0";
	*/
	const char* vertex_shader_source_ = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos, 1.0);\n"
		"	ourColor = aColor;\n"
		"}\0";

	const char* fragment_shader_source_ = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(ourColor, 1.0f);\n"
		"}\n\0";
	
	int sucess;
	char info_log_[INFO_MESSAGE_SIZE];

	ShaderResult createFragmentShader(unsigned int& fragment_shader)
	{
		
		fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source_, NULL);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &sucess);
		if (!sucess)
		{
			glGetShaderInfoLog(fragment_shader, INFO_MESSAGE_SIZE, NULL, info_log_);
			return ShaderResult::FragmentShaderFailed;
		}
		return ShaderResult::Success;
	}

	ShaderResult createVertexShader(unsigned int& vertex_shader)
	{
		vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source_, NULL);
		glCompileShader(vertex_shader);
		
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &sucess);

		if (!sucess)
		{
			glGetShaderInfoLog(vertex_shader, INFO_MESSAGE_SIZE, NULL, info_log_);
			return ShaderResult::VertexShaderFailed;
		}
		return ShaderResult::Success;
	}

	ShaderResult linkShaderList(unsigned int& shader_program, std::vector<unsigned int>& shader_list)
	{
		shader_program = glCreateProgram();
		for (unsigned int shader : shader_list) 
		{
			glAttachShader(shader_program, shader);
		}
		glLinkProgram(shader_program);
		//check linking status
		glGetProgramiv(shader_program, GL_LINK_STATUS, &sucess);
		if (!sucess) 
		{
			glGetProgramInfoLog(shader_program, INFO_MESSAGE_SIZE, NULL, info_log_);
			return ShaderResult::LinkingFailed;
		}
		//Delete shader
		for (unsigned int shader : shader_list)
		{
			glDeleteShader(shader);
		}
	}
}

