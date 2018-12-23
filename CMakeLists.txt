cmake_minimum_required(VERSION 3.13)
project(my_projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_projects
        README.md "Kurdyumov Dima/h_stek.cpp")



add_executable(h_stek "Kurdyumov Dima/h_stek.cpp")
add_executable(lifo "Kurdyumov Dima/lifo.cpp")
add_executable(fifo "Kurdyumov Dima/fifo.cpp")