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
    legal_moves.push_back(std::make_pair<int, int>(-1, -1)); 

    // Finding current position on board
    std::pair<int, int> cur_pos = std::make_pair<int, int>(-1, -1); 
    int found = 0; 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (this->board->getPiece(i, j) == this) {
                cur_pos.first = i;
                cur_pos.second = j;
                found = 1; 
                break; 
            }
        }
        if (found) break; 
    }
    assert (found && cur_pos.first != -1 && cur_pos.second != -1 && 
            "Unable to find position on board"); 
        
    // Pawn cannot move forwards. Note that the pawn starts on the 
    // 2nd or 7th rank, so it can only reach the edges if it has crossed
    // all the way. 
    if (cur_pos.second == 7 || cur_pos.second == 0) return legal_moves; 
    
    // Finding the direction of the pawn 
    int direction; 
    if (this->getColor() == 'w') direction = -1; 
    else direction = 1; 

    // Checking if there are any pieces directly in front 
    if (this->board->getPiece(cur_pos.first, cur_pos.second + direction) == NULL) {
        legal_moves.push_back(std::make_pair<int, int>((int) cur_pos.first, (int) cur_pos.second + direction)); 
    }

    // Checking if a double move can be made
    if (((cur_pos.second == 6 && direction == -1) || (cur_pos.second == 1 && direction == 1)) && 
        (this->board->getPiece(cur_pos.first, cur_pos.second + 2*direction) == NULL)) 
        {
            // idk how to format this in a nice way, hehe
            legal_moves
            .push_back(std::make_pair<int, int>(
                (int) cur_pos.first, (int) cur_pos.second + 2*direction)
                ); 
        }
    

    // Checking if a piece can be captured 
    Piece* left_diag = NULL; 
    Piece* right_diag = NULL; 
    if (cur_pos.first - 1 >= 0)
        Piece* left_diag = this->board->getPiece(cur_pos.first - 1, cur_pos.second + direction); 
    if (cur_pos.first + 1 <= 7)
        Piece* right_diag = this->board->getPiece(cur_pos.first + 1, cur_pos.second + direction); 
    if (left_diag != NULL && left_diag->getColor() != this->getColor()) {
        legal_moves.push_back(
            std::make_pair<int, int>(
                (int) cur_pos.first - 1, (int) cur_pos.second + direction
            )
        ); 
    }
    if (right_diag != NULL and right_diag->getColor() != this->getColor()) {
        legal_moves.push_back(
            std::make_pair<int, int>(
                (int) cur_pos.first + 1, (int) cur_pos.second + direction
            )
        ); 
    }


    // TODO: Check if you set your own king in check 
    // maybe check all the legal moves up until now to see if any of them 
    // put the king in check? Could potentially have a check at every place 
    // moves are added to legal_moves 


    // TODO: Check en passant 



    return legal_moves; 
}

int Pawn::getNumMoves() {
    return 5; 
}

