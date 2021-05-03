#pragma once
#include"Player.h"
#include "HumanPlayer.h"
#include "Menu.h"

class TetrisGame
{
private:

    enum { NumOfPlayers =2};
    Player** ThePlayers = new Player*[NumOfPlayers];

    Menu GameMenu;
    int gameoverflag = startGame;

public:
    //TetrisGame() {};
    TetrisGame(int gameType = 0);
    ~TetrisGame();

    void createPlayers(int gameType);
    void run(Objects** S1, Objects** S2);

    void Start(); //Game menu
    bool IsKeyboard1(char ch); //check if the key is of player 1
    bool IsKeyboard2(char ch); //check if the key is of player 2

    void printGameOver();//Prints GAME OVER to the screen
    void InitPlayersBoards();//Resets players boards to default
    void InitColors();//Sets colors to all shapes
    void DropShape(Objects& S, int player_num, char key);//Drops shape as long as its possible

    void RandomShape(Objects** S,int player);

    char PlayerVsPlayer(Objects** S1, Objects** s2);

    char PlayerVsComputer(Objects** S1, Objects** S2);

};

