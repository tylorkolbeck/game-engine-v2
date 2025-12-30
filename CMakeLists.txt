cmake_minimum_required(VERSION 3.23)

project(
  tk-engine
  VERSION 0.1.0
  LANGUAGES C CXX
)

# GLFW options
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)


add_subdirectory(external/glfw)

# Language settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
find_package(SDL3 CONFIG REQUIRED)


file(GLOB_RECURSE TK_ENGINE_SOURCES CONFIGURE_DEPENDS
  src/*.cpp
)

add_executable(tk-engine ${TK_ENGINE_SOURCES})


target_link_libraries(tk-engine
  PRIVATE SDL3::SDL3
)
target_link_libraries(tk-engine PRIVATE glfw)

target_compile_definitions(tk-engine
  PRIVATE SDL_MAIN_HANDLED
)


