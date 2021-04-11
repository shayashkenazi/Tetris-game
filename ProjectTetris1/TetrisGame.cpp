#include "gotoxy.h"
#include "TetrisGame.h"





TetrisGame::TetrisGame()
{

    
}
TetrisGame::~TetrisGame()
{

}

void TetrisGame:: InitPlayersBoards()
{
	ThePlayers[Player1].getBoardGame().ResetBoard();
	ThePlayers[Player2].getBoardGame().ResetBoard();
}

void TetrisGame::InitColors()
{
    ThePlayers[Player1].getShapesarray().InitColorsShapesArray();
    ThePlayers[Player2].getShapesarray().InitColorsShapesArray();

}

void TetrisGame::DropShape(Shape& S, int player_num, char key)
{
	while (ThePlayers[player_num].IsPossible(S, key))
	{
		S.move(key);
		Sleep(10);
	}
}

void TetrisGame::run(Shape& S1 , Shape& S2)
{
    char key = 0;
    int randShape = rand() % RAND;
	
	if (S1.getPointByIdx(0).getCh() == ' ' && S2.getPointByIdx(0).getCh() == ' ') // Checks if the shapes are initiated or not
	{                                                                             // if initiated, we continue a paused game
		 S1 = ThePlayers[Player1].getShapesarray().getShape(randShape);
		 S2 = ThePlayers[Player2].getShapesarray().getShape(randShape);
	}
	//Prints boards
	ThePlayers[Player1].getBoardGame().PrintBoardGame(Player1);
	gotoxy(LeftBoardPlayer2, 0);
    ThePlayers[Player2].getBoardGame().PrintBoardGame(Player2);

    do {
	   //Checks if a shape reached the top of the board
	   if (!ThePlayers[Player1].CheckGameOver(S1) || !ThePlayers[Player2].CheckGameOver(S2))
	   {
		   printGameOver();

		  return;
	   }
	   S1.draw();
	   S2.draw();
	 
	//Clears the input buffer for more fluid gaming
	 HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	 FlushConsoleInputBuffer(hStdIn);
	   
	   for (int i = 0; i < CommandLoop; i++)
	   {
		  if (_kbhit())
		  {
			 hideCursor();
			 key = _getch();
			 if (key == ESC)
			 {
				clrscr();
				return;
			 }
			 if (IsKeyboard1(key))
			 {
				if (Drop1 == key || Drop1B == key)
				{
					DropShape(S1, Player1, key);//Drops shape while possible
				    i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player1].IsPossible(S1, key))//Checks if a given move input is possible (any move but down)
				    S1.move(key);//Moves shape according to given input
			 }
			 if (IsKeyboard2(key)) {
				if (Drop2 == key || Drop2B == key)
				{
					DropShape(S2, Player2, key);//Drops shape while possible
				    i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player2].IsPossible(S2, key))//Checks if a given move input is possible (any move but down)
				    S2.move(key);//Moves shape according to given input
			 }
		  }
		  Sleep(50);
	   }	   		
		  if (ThePlayers[Player1].IsPossible(S1, MoveDown))//Drops shape by one step
			 S1.move(MoveDown);
		  else //If shape reached bottom, update the shape in the board and randomly pick new shape
		  {
			 ThePlayers[Player1].UpdateBoard(S1);
			 randShape = rand() % RAND;
			 S1 = ThePlayers[Player1].getShapesarray().getShape(randShape);
			 ThePlayers[Player1].CheckRow(); //Checks if there is any rows that are full, if so deletes row
			 gotoxy(0, 0);
			 ThePlayers[Player1].getBoardGame().PrintBoardGame(Player1);//Prints updated board
		  }
		  if (ThePlayers[Player2].IsPossible(S2, MoveDown))//Drops shape by one step
			 S2.move(MoveDown);
		  else//If shape reached bottom, update the shape in the board and randomly pick new shape
		  {
			 ThePlayers[Player2].UpdateBoard(S2);
			 randShape = rand() % RAND;
			 S2 = ThePlayers[Player2].getShapesarray().getShape(randShape);
			 ThePlayers[Player2].CheckRow(); //Checks if there is any rows that are full, if so deletes row
			 gotoxy(LeftBoardPlayer2, 0);
			 ThePlayers[Player2].getBoardGame().PrintBoardGame(Player2);//Prints updated board
		  }
		  Sleep(200);
    } while (key != ESC);

}

void TetrisGame::PresentMenu(int pause)
	{
		Color c = LIGHTGREY;
		setTextColor(c);

		gotoxy(11, 7);
		cout << "TETRIS";
		gotoxy(5, 9);
	
		cout << "(1) Start a new game \n";

		int space_for_row = 0;
		if (pause)
		{
			space_for_row = 1;
			gotoxy(5, 10);
			cout << "(2) Continue the paused game\n ";
		}

		gotoxy(5, 10 + space_for_row);
		cout << "(8) Present instructions and keys\n";
		gotoxy(5, 11 + space_for_row);
		cout << "(9) EXIT " << endl;
	}

void TetrisGame::PresentInstructions()
	{
		gotoxy(5, 7);
		cout << "GAME INSTRUCTIONS\n";
		gotoxy(5, 8);
		cout << "In order to win you will need to keep your shapes from getting to the celling!\n";
		gotoxy(5, 9);
		cout << "You can do that by locating and turning the shapes to line them up as much as possible:\n ";
		gotoxy(5, 10);
		cout << "Every row that will be filled with shapes bricks will DISAPEAR!\n\n\n";

		gotoxy(30, 14);
		cout << "The controls are as below:\n";
		gotoxy(0, 18);
		cout << "Right:\n";
		cout << "Left:\n";
		cout << "Drop:\n";
		cout << "Rotate clockwise:\n";
		cout << "Rotate counter clockwise:\n";

		gotoxy(30, 16);
		cout << "PLAYER 1           PLAYER 2" << endl;
		gotoxy(31, 18);
		cout << "D or d             L or l" << endl;
		gotoxy(31, 19);
		cout << "A or a             J or j" << endl;
		gotoxy(31, 20);
		cout << "X or x             M or m" << endl;
		gotoxy(31, 21);
		cout << "S or s             K or k" << endl;
		gotoxy(31, 22);
		cout << "W or w             I or i" << endl;


		gotoxy(25, 30);

		cout << "Press any key to return to the menu!\n" << endl;
		hideCursor();
		char ch;
		_kbhit();
		ch = _getch();
		if (ch)
		{
			system("cls");
			return;
		}

	}

void TetrisGame::menu(int pause)
{ 
    int input = 0;
    char colorsInput;

    cout << "(1) For game with colors\n(2) For game without colors " << endl;
    _kbhit();
    colorsInput = _getch() - '0';
    
    Shape S1, S2;

	   while (input != EXIT)
	   {
		  clrscr();
		  PresentMenu(pause);
		  _kbhit();
		  input = _getch() - '0';
		  clrscr();
		  switch (input)
		  {
		  case Start:
		  {
			 InitPlayersBoards();
			 if (colorsInput == 1)
				InitColors();
			 S1.initShape();
			 S2.initShape();

			 run(S1, S2);
			 pause = 1;
			 break;
		  }
		  case Continue:
		  {
			 run(S1, S2);
			 break;
		  }
		  case PresentInstructionskeys:
		  {
			 PresentInstructions();
			 break;
		  }
		  }
	   }

	   if (input == EXIT)
	   {
		   gotoxy(20, 10);
		  cout << "THANK YOU FOR PLAYING, SEE YOU NEXT TIME!";
		  return;
	   }
    
}

bool TetrisGame::IsKeyboard1( char ch)
{
    for (int i = 0; i < 10; i++)
    {
	   if (keyboardString1[i] == ch)
		  return true;
    }
    return false;
}

bool TetrisGame::IsKeyboard2(char ch)
{
    for (int i = 0; i < 10; i++)
    {
	   if (keyboardString2[i] == ch)
		  return true;
    }
    return false;
}

void TetrisGame::pauseGame(Shape& S1, Shape& S2)
{
    menu(1);
}

void TetrisGame::printGameOver()
{
    gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2);
	if (!ThePlayers[Player1].getWinner())
	{
		cout << "PLAYER 2";
		gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2+1);
		cout << "   WON";
	}
	else
	{
		cout << "PLAYER 1";
		gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2 + 1);
		cout << "   WON";
	}

	gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2 +3);
	cout << "GAME OVER";
	Sleep(4000);
	system("cls");
	return;
}
