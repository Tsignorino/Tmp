cmake_minimum_required(VERSION 3.28)
project(Cpp_pros)

set(CMAKE_CXX_STANDARD 26)

add_executable(Cpp_pros main.cpp
        src/func1_lambda.cpp
        src/test.cpp
)
