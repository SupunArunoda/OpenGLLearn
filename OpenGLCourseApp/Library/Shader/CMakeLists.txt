cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME Shader)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

if(OPENGL_FOUND)
	add_library(${TARGET_NAME} Shader.h Shader.cpp ShaderN.h ShaderN.cpp)
	set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Library)
	target_link_libraries(${TARGET_NAME} PUBLIC BootsTrap)
	target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()


