cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME OpenGLCourseApp)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

find_package(OpenGL REQUIRED)

set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/include/)
set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/include/)
set(GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/lib/Release/Win32/glew32.lib)
set(GLFW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/lib-vc2022/glfw3.lib)

set(GLEW_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/bin/Release/Win32/glew32.dll)


#include_directories(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR})
if(OPENGL_FOUND)
	include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
endif()


add_subdirectory(red_window)
add_subdirectory(triangle_vertex)

