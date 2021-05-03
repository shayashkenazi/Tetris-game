#pragma once
#include "Board.h"
#include"ShapesArray.h"

class Player
{
protected:
    Board boardGameForPlayer;
    ShapesArray shapesarray;
    int playerNumber;
    char KeyboardKeys[10];
    int winner = 1;
    
public:

    Player(int player);
    ~Player();
    
    const int getWinner() const;
    char* getKeys() { return KeyboardKeys; }
    
    Board& getBoardGame() { return boardGameForPlayer; } //Returns Board
    ShapesArray& getShapesarray(){ return shapesarray ;} //Returns shapes array
    const void printboard() const; //Prints board to screen
    void UpdateBoard(const Objects& shape);// Updates a shape to be permanent in the board
    void UpdateBoardExplosion(const Point& point);

    void CheckRow();//Checks if there is any rows that are full, if so deletes row
    bool IsPossible(const Objects& shape, char direction);//Checks if a given move input is possible
    bool CheckGameOver(Objects& shape);//Checks if a shape reached the top of the board
};

