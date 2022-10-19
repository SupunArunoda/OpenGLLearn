cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME OpenGLEnvSetup)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

find_package(OpenGL REQUIRED)

set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/include/)
set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/include/)
set(GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/lib/Release/Win32/glew32.lib)
set(GLFW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLFW/lib-vc2022/glfw3.lib)

set(GLEW_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../ExternalLibs/GLEW/bin/Release/Win32/glew32.dll)


#include_directories(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR})
if(OPENGL_FOUND)
	add_executable(${TARGET_NAME} main.cpp)
	target_include_directories(${TARGET_NAME} PUBLIC ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
	target_link_libraries(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR} ${OPENGL_LIBRARIES})
endif()

message(${GLEW_DLL})
set(BIN_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(BIN_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Release)
endif()

add_custom_command(
TARGET ${TARGET_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy 
		${GLEW_DLL} ${BIN_DIRECTORY}
)
