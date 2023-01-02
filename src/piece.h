#include <string>
#include <vector>
#include "board.h"

#ifndef Piece_H
#define Piece_H

class Piece {
    private: 
        char color_; 

    public: 
        Board* board; 
        Piece(char color) {
            color_ = color; 
            board = NULL; 
        }; 

        void setBoard(Board* board) {
            board = board; 
        }

        char getColor() {
            return color_; 
        }; 

        virtual int getNumMoves(){
            // Dummy function body, how can I remove this? 
            return 0; 
        }; 

        virtual std::vector<std::pair<int, int>> getLegalMoves(){
            // Dummy function body, how can I remove this? 
            return *(new std::vector<std::pair<int, int>>); 
        }; 
}; 

#endif