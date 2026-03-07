cmake_minimum_required(VERSION 3.31)
project(bg-raymarcher)

include(FetchContent)

FetchContent_Declare(
    fastnoise
    GIT_REPOSITORY https://github.com/Auburn/FastNoiseLite.git
    GIT_TAG master
)

FetchContent_MakeAvailable(fastnoise)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(raylib 5)
find_package(glm)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(bg_raymarcher ${SOURCES} bins/bg_raymarcher.cpp)
target_link_libraries(bg_raymarcher PRIVATE raylib glm::glm)
target_include_directories(bg_raymarcher PRIVATE ${fastnoise_SOURCE_DIR}/C/ src/)

add_executable(vector_visuals ${SOURCES} bins/vector_visuals.cpp)
target_link_libraries(vector_visuals PRIVATE raylib glm::glm)
target_include_directories(vector_visuals PRIVATE ${fastnoise_SOURCE_DIR}/C/ src/)
# TODO: Make this a for loop


