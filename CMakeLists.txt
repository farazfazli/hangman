# Improved version adapted from https://codereview.stackexchange.com/a/210770/78786
cmake_minimum_required(VERSION 3.13)
project(Hangman C)

add_executable(${CMAKE_PROJECT_NAME} main.c utils.c utils.h rng.c rng.h config.h dictionary.c dictionary.h)

set(CMAKE_C_COMPILER clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For YouCompleteMe
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE c_std_99)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        $<$<C_COMPILER_ID:Clang>:
        -Weverything
        -fsanitize=undefined,integer,implicit-conversion,nullability,address,leak,cfi
        -flto
        -fvisibility=default>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
        $<$<C_COMPILER_ID:Clang>:
        -fsanitize=undefined,integer,implicit-conversion,nullability,address,leak,cfi
        -flto>)
