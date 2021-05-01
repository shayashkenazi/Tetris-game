#pragma once
#include"Player.h"
#include "Menu.h"

class TetrisGame
{
private:

    enum { NumOfPlayers =2};
    Player ThePlayers[NumOfPlayers] = { Player(Player1),Player(Player2) };

    char keyboardString1[10] = { Drop1,Drop1B,Right1 ,Right1B,Left1 ,Left1B,RotateClockWise1,RotateClockWise1B,
        RotateCounterClockWise1 ,RotateCounterClockWise1B };
    char keyboardString2[10] = { Drop2,Drop2B,Right2 ,Right2B,Left2 ,Left2B,RotateClockWise2,RotateClockWise2B,
        RotateCounterClockWise2 ,RotateCounterClockWise2B };

    Menu GameMenu;
    int gameoverflag = startGame;

public:

    TetrisGame();
    ~TetrisGame();

    void run(Shape** S1, Shape** S2);

    void Start(); //Game menu
    bool IsKeyboard1(char ch) const; //check if the key is of player 1
    bool IsKeyboard2(char ch) const; //check if the key is of player 2

    void printGameOver();//Prints GAME OVER to the screen
    void InitPlayersBoards();//Resets players boards to default
    void InitColors();//Sets colors to all shapes
    void DropShape(Shape& S, int player_num, char key);//Drops shape as long as its possible

    void RandomShape(Shape** S,int player);

};

