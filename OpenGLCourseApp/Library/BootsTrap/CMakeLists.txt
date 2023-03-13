cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME BootsTrap)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

if(OPENGL_FOUND)
	add_library(${TARGET_NAME} BootsTrap.h BootsTrap.cpp)
	set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Library)
	target_link_libraries(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR} ${OPENGL_LIBRARIES})
	target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()


