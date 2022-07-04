cmake_minimum_required(VERSION 3.22)
project(DataGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataGenerator main.cpp Class/Celula.cpp Class/Celula.h Utils/index.h Utils/Utils.cpp)
