cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME RedWindowApp)
project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

#include_directories(${TARGET_NAME} PUBLIC ${GLEW_LIB_DIR} ${GLFW_LIB_DIR})
if(OPENGL_FOUND)
	add_executable(${TARGET_NAME} main.cpp)
	set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Demo)
	target_link_libraries(${TARGET_NAME} PUBLIC BootsTrap)
endif()

target_compile_definitions(${TARGET_NAME} PUBLIC -D_UNICODE -DUNICODE -DNOMINMAX)


