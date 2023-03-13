#ifndef OPENGL_LIBRARY_SHADER_H
#define OPENGL_LIBRARY_SHADER_H

#include "BootsTrap.h"
#include <vector>

namespace GL 
{

	constexpr int INFO_MESSAGE_SIZE = 512;

	enum ShaderResult 
	{
		Success,
		FragmentShaderFailed,
		VertexShaderFailed,
		LinkingFailed,
		Other
	};
	
	

	ShaderResult createFragmentShader(unsigned int& fragment_shader);
	ShaderResult createVertexShader(unsigned int& vertex_shader);
	ShaderResult linkShaderList(unsigned int& shader_program, std::vector<unsigned int>& shader_list);
	

}



#endif //OPENGL_LIBRARY_SHADER_H
