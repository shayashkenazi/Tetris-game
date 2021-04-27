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
    
    const int getWinner() const;

    Board& getBoardGame() { return boardGameForPlayer; } //Returns Board
    ShapesArray& getShapesarray(){ return shapesarray ;} //Returns shapes array
    const void printboard() const; //Prints board to screen
    void UpdateBoard(const Shape& shape);// Updates a shape to be permanent in the board

    void CheckRow();//Checks if there is any rows that are full, if so deletes row
    bool IsPossible(const Shape& shape, char direction);//Checks if a given move input is possible
    bool CheckGameOver(Shape& shape);//Checks if a shape reached the top of the board

};

