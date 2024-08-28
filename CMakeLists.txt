cmake_minimum_required(VERSION 3.5)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
include(FetchContent)

project(cross_stitch)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(SOURCES
  pattern.cpp

  colors.txt

  pattern.hpp
  gl_includes.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

#target_sources(${PROJECT_NAME} PRIVATE dep/glad/src/glad.c)
#target_include_directories(${PROJECT_NAME} PRIVATE dep/glad/include/)
#target_sources(${RENDER_VIDEO_NAME} PRIVATE dep/glad/src/glad.c)
#target_include_directories(${RENDER_VIDEO_NAME} PRIVATE dep/glad/include/)

#target_sources(${RENDER_VIDEO_NAME} PRIVATE dep/glad/src/glad.c)
#target_include_directories(${RENDER_VIDEO_NAME} PRIVATE dep/glad/include/)

#add_subdirectory(dep/glfw)
#include_directories(dep/glfw/include/)
add_subdirectory(dep/glm)
include_directories(dep/glm)
#add_subdirectory(dep/imgui)
#include_directories(dep/imgui/)
#add_subdirectory(dep/implot)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} glm raylib) #Ai retiré glfw et IMGUI IMPLOT
#target_link_libraries(${RENDER_VIDEO_NAME} ${CMAKE_DL_LIBS} glfw glm IMGUI IMPLOT)