cmake_minimum_required(VERSION 3.0)

project(persona-x CXX)

set(CMAKE_MODULE_PATH
    "${PROJECT_SOURCE_DIR}/cmake"
)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(SFML 2 COMPONENTS window system REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
)

link_directories(
    ${SFML_LIBRARY_DIRS}
    ${OPENGL_LIBRARY_DIRS}
)
add_definitions(
    ${OPENGL_CFLAGS_OTHER}
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})
