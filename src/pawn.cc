#include "pawn.h"
#include "piece.h"
#include <iostream> 
#include <string>
#include <assert.h>
#include <vector>

using namespace std; 

Pawn::Pawn(char color) : Piece(color) {

}

std::vector<std::pair<int, int>> Pawn::getLegalMoves() {
    assert (this->board != NULL && "this.board is null"); 
    std::vector<std::pair<int, int>> legal_moves; 
    legal_moves.push_back(std::make_pair<int, int>(1, 1)); 
    return legal_moves; 
}

int Pawn::getNumMoves() {
    return 5; 
}

