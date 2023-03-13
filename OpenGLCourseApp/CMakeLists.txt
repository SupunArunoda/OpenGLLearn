cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0079 NEW)

set(TARGET_NAME OpenGLCourseApp)
project(${TARGET_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(OpenGL REQUIRED)

set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/include/)
set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/include/)
set(GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/lib/Release/Win32/glew32.lib)
set(GLFW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/lib-vc2022/glfw3.lib)

##Make sure to add glew32.dll folder path to PATH variable

if(OPENGL_FOUND)
	include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
endif()


add_subdirectory(Library)
add_subdirectory(Demo)

