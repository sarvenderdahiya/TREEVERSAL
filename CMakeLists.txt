cmake_minimum_required(VERSION 3.6)
project(LearningTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lopengl32 -lfreeglut")

find_package(GLUT)
find_package(OpenGL)

set(SOURCE_FILES main.cpp)
add_executable(LearningTree ${SOURCE_FILES})

target_link_libraries(
        LearningTree
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES})


