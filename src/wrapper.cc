#include <iostream>
#include <typeinfo> 
#include <string>
#include <vector>
#include <utility>

#include "pawn.h"
#include "piece.h"
#include "board.h"

using namespace std; 

// Code used to bind the C++ code to Python

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
namespace py = pybind11; 
PYBIND11_MODULE(chess_module, handle) {
    handle.doc() = "This is the module docs. Teehee"; 

    py::class_<Pawn>(handle, "PyPawn")
        .def(py::init<char>())
        .def("getNumMoves", &Pawn::getNumMoves)
        .def("getColor", &Piece::getColor)
        .def("getLegalMoves", &Piece::getLegalMoves); 

    py::class_<Piece>(handle, "PyPiece")
        .def("getColor", &Piece::getColor) 
        .def("getNumMoves", &Piece::getNumMoves); 

    py::class_<Board>(handle, "PyBoard")
        .def(py::init<>())
        .def("getPiece", &Board::getPiece) 
        .def("movePiece", &Board::movePiece) 
        .def("getBoardString", &Board::getBoardString); 

}