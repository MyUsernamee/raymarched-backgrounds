cmake_minimum_required(VERSION 3.31)
project(bg-raymarcher)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 5)
find_package(glm)

file(GLOB_RECURSE SOURCES src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib glm::glm)
