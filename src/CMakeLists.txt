cmake_minimum_required(VERSION 3.10)

project(persona_x CXX)

# Add project-specific CMake configs
set(CMAKE_MODULE_PATH
    "${PROJECT_SOURCE_DIR}/cmake"
)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(SFML COMPONENTS graphics system)
find_package(OpenGL REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
)

link_directories(
    ${SFML_LIBRARY_DIRS}
    ${OPENGL_LIBRARY_DIRS}
)
add_definitions(
    ${OPENGL_CFLAGS_OTHER}
)

find_package(pybind11 REQUIRED)

add_library(${PROJECT_NAME} MODULE
    pywrap.cpp
    game.cpp
    scenes.cpp
    graphics/cache.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pybind11::module
    sfml-graphics
    ${OPENGL_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
)
