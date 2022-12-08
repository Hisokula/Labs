cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME test)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" 6lab.cpp
								inc/Func.hpp
								src/CountMatrix.cpp
								src/Input.cpp
								src/Outputing.cpp
								src/Process.cpp
								src/ReadMatrix.cpp
								src/Squares.cpp
								src/Test.cpp
								src/Minim.cpp)

file(COPY input.txt DESTINATION "/")