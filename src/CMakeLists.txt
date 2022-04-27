cmake_minimum_required(VERSION 3.16)

project(sudoku_solver)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(sudoku_solver main.c Pixels.c sudoku.c construct.c)

target_link_libraries(sudoku_solver ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})