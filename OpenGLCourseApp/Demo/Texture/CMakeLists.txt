cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME Texture)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

#include_directories(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR})
if(OPENGL_FOUND)
	add_executable(${TARGET_NAME} main.cpp)
	target_link_libraries(${TARGET_NAME})
	set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Demo)
    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PRIVATE DEBUG=1)
    set(BIN_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
else()
    target_compile_definitions(${TARGET_NAME} PRIVATE DEBUG=0)
    set(BIN_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Release)
endif()

add_custom_command(
TARGET ${TARGET_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy 
		${GLEW_DLL} ${BIN_DIRECTORY}
)
