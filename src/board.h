#include <vector>
#include <string>

#ifndef Board_H
#define Board_H

class Piece; 
class Pawn; 
class Board {
    /*
    Class for containing the entire board. This should contain pieces and 
    Make it possible to move them and interact in any way wanted 
    */ 
   private: 
    // Creating a list of pointers to the different pieces 
    Piece* pieces[64]; 

   public: 
    Board(); 
    Piece* getPiece(u_int8_t x, u_int8_t y); 
    void movePiece(u_int8_t from_x, u_int8_t from_y, u_int8_t to_x, u_int8_t to_y); 


    // Idea: 
    // Store the moves that have been made in a stack and have a 
    // function called "reverse" or something, that would remove 
    // the last move from the stack and allow you to continue from 
    // the previous position. This could be particularly useful 
    // when simulating moves in e.g. minimax 
    // This would probably need to store which piece was removed from 
    // which position, e.g. store a pointer to that piece so it is never 
    // actually deleted, but stored in that stack? 

    // Maybe a stack of structs? 

   

}; 


#endif