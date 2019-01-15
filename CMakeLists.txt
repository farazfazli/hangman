cmake_minimum_required(VERSION 3.13)
project(PointerPractice C)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Weverything -Werror -fsanitize=undefined,integer,implicit-conversion,nullability,address,leak,cfi -flto -fvisibility=default")

FILE(GLOB Sources *.c)
add_executable(${CMAKE_PROJECT_NAME} ${Sources})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CURSES_LIBRARIES})