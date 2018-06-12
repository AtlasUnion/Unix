cmake_minimum_required(VERSION 3.10)
project(Unix C)

set(CMAKE_C_STANDARD 99)

add_executable(Unix main.c "User, Files/who/who1.c" "User, Files/who/who2.c" "User, Files/cp/cp1.c" "User, Files/who/utmplib.c" "User, Files/who/who3.c")