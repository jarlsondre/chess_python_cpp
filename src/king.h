#include "piece.h"

#ifndef King_H
#define King_H

class King : public Piece {
    
    public: 
        King(char color); 
        int getNumMoves(); 
        std::vector<std::pair<int, int>> getLegalMoves(); 

}; 

#endif