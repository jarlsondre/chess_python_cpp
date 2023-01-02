#include <string>
#include <vector>
#include "piece.h"

#ifndef Pawn_H
#define Pawn_H

class Pawn : public Piece {
    private: 
        int has_moved; // Is this strictly necessary from a functional POV? 
    public:
        Pawn(char color); 
        int getNumMoves(); 
        std::vector<std::pair<int, int>> getLegalMoves(); 

};

#endif