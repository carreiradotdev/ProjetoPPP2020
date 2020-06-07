cmake_minimum_required(VERSION 3.15)
project(PPPCarreira)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra")

add_executable(teste1 "teste1.c")
add_executable(lista "lista.c")
add_executable(main "main.c")