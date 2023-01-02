#include "pawn.h"
#include "piece.h"
#include "board.h"
#include <string>
#include <stdexcept>
#include <assert.h>

Board::Board() {
    // Filling up the first side with pawns 
    for (int i = 0; i < 64; i++) {
        // Have to use new since we're using pointers
        // because when we don't use new, the object goes to 
        // stack, meaning that the pointer will point to the stack
        // instead of referencing the object. The "new" keyword, however
        // does require you to delete your object when you don't want to use it anymore
        Pawn* pawn; 
        if (i < 16) {
            // Top squares are black 
            pawn = new Pawn('b'); 
            pawn->board = this; 
        }
        else if (i < 48) {
            // Middle squares are empty
            pawn = NULL; 
        }
        else {
            // Bottom squares are black 
            pawn = new Pawn('w'); 
            pawn->board = this; 
        }
        pieces.push_back(pawn); 
    }
}

Piece* Board::getPiece(u_int8_t x, u_int8_t y) {
    assert (x >= 0 && x <= 7 && "x is out of bounds"); 
    assert (y >= 0 && y <= 7 && "y is out of bounds");
    return pieces[x + 8*y]; 
}

// This function will remove whatever piece is in the landing spot 
void Board::movePiece(u_int8_t from_x, u_int8_t from_y, u_int8_t to_x, u_int8_t to_y) {

    assert (from_x < 8 && from_x >= 0 && "from_x is out of bounds"); 
    assert (from_y < 8 && from_y >= 0 && "from_y is out of bounds"); 
    assert (to_x < 8 && to_x >= 0 && "to_x is out of bounds"); 
    assert (to_y < 8 && to_y >= 0 && "to_y is out of bounds"); 
    assert (to_y != from_y || to_x != from_x && "trying to move a piece onto itself"); 

    Piece* from_piece = pieces[from_x + 8*from_y]; 
    Piece* to_piece = pieces[to_x + 8*to_y]; 

    assert (from_piece != NULL && "Trying to move a NULL piece"); 
    if (to_piece != NULL)
        assert (from_piece->getColor() != to_piece->getColor() && 
        "Trying to move a piece to another piece with the same color "); 

    // Move the piece 
    pieces[to_x + 8*to_y] = pieces[from_x + 8*from_y];
    pieces[from_x + 8*from_y] = NULL;
}

std::string Board::getBoardString() {
    std::string result = "\n----------------------------------------"; 
    for (int y = 0; y < 8; y++) {
        result += "\n"; 
        for (int x = 0; x < 8; x++) {
            result += "|"; 
            if (this->getPiece(x, y) == NULL) {
                result += "    "; 
                continue; 
            }
            // not NULL 
            if (this->getPiece(x, y)->getColor() == 'w') {
                result += " wP ";
            }
            else {
                result += " bP ";
            }
        }
        result += "|\n----------------------------------------"; 
    }

    return result; 

}