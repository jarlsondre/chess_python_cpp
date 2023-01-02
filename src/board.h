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

   

}; 


#endif