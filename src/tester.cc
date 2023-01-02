#include <iostream>
#include <typeinfo> 
#include <string>
#include <vector>
#include <utility>

#include "pawn.h"
#include "piece.h"
#include "board.h"

using namespace std; 


// In order to cast to subclass: 
// dynamic_cast<Pawn*>(board.getPiece(1, 1))
// This gives you a pointer, but will return 0 if 
// it is not of the same type as the subclass you're trying 
// to convert it to. 


// In order to see the type name of a piece: 
// typeid(p1).name(), given that p1 is a piece

int main() {
    Board* board = new Board(); 

    Piece* p1 = (board->getPiece(0, 1)); 
    board->movePiece(0, 1, 0, 3); 

    vector<pair<int, int>> legal_moves = p1->getLegalMoves(); 
    for (pair<int, int> move : legal_moves) {
        cout << "(" << get<0>(move) << ", " << get<1>(move) << ") "; 
    }
    cout << endl; 

    return 0; 
}