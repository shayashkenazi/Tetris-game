#pragma once
#include "Board.h"
#include"ShapesArray.h"
class Player
{
private:
    Board boardGameForPlayer;
    ShapesArray shapesarray;
    int playerNumber;
    int winner = 1;
    
public:

    Player(int player);
    ~Player();
    
    int getWinner();

    Board& getBoardGame() { return boardGameForPlayer; } //Returns Board
    ShapesArray& getShapesarray() { return shapesarray ;} //Returns shapes array
    void printboard(); //Prints board to screen
    void UpdateBoard( Shape& shape);// Updates a shape to be permanent in the board

    void CheckRow();//Checks if there is any rows that are full, if so deletes row
    bool IsPossible(Shape& shape, char direction);//Checks if a given move input is possible
    bool CheckGameOver(Shape& shape);//Checks if a shape reached the top of the board

};

