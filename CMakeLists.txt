cmake_minimum_required(VERSION 3.17)
project(AIChat)

set(CMAKE_CXX_STANDARD 20)

add_executable(AIChat src/main.cpp src/ShowDesktop/Book.cpp src/ShowDesktop/Book.h)
