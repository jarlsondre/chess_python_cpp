cmake_minimum_required(VERSION 3.4)
project(chess_cpp)
add_subdirectory(pybind11)
pybind11_add_module(chess_module src/pawn.cc src/board.cc src/wrapper.cc)