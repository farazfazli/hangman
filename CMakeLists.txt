cmake_minimum_required(VERSION 3.13)
project(PointerPractice C)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Weverything -Werror -fsanitize=undefined,integer,implicit-conversion,nullability,address,leak,cfi -flto -fvisibility=default")

add_executable(${CMAKE_PROJECT_NAME} main.c rng.h rng.c utils.c utils.h)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CURSES_LIBRARIES})