cmake_minimum_required(VERSION 3.0.0)
project(gkLab VERSION 0.1.0)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_BUILD_TYPE "Debug")
add_executable(main ${SRC_FILES})
target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )