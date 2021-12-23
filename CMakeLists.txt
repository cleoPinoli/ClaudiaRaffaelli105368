cmake_minimum_required(VERSION 3.21)

project(ClaudiaRaffaelli105368 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(extractlcs extractlcs.c extractlcs.h main.c)     #here will go all the source files im guessing
