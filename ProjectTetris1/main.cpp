#include <iostream>
using namespace std;

#include <windows.h>
#include <process.h>
#include "TetrisGame.h"
#include "gotoxy.h"
#include"ShapesArray.h"



void gotoxy(int, int); // prototype
void clrscr(); // prototype

void main()
{
    Color c = LIGHTGREY;
    setTextColor(c);
    

    TetrisGame g(1);
    hideCursor();
    g.Start();

    gotoxy(20, 20);
}

