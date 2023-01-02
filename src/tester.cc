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
    Piece *temp, *p1, *p2, *p3;


    string init_state = board->getBoardString(); 
    board->movePiece(0, 0, 4, 4); 

    string new_state = board->getBoardString(); 

    cout << init_state << endl; 
    cout << new_state << endl; 


    return 0; 
}