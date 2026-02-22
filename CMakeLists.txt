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

find_package(raylib 5)
find_package(glm)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib glm::glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${fastnoise_SOURCE_DIR}/C/)
