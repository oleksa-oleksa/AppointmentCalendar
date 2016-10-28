cmake_minimum_required(VERSION 3.6)
project(ueb1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c datastructure.h datetime.c tools.h datetime.h calendar.c calendar.h menu.c menu.h)
add_executable(ueb1 ${SOURCE_FILES})