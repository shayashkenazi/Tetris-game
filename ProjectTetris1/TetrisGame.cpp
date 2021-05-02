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

void TetrisGame::DropShape(Objects& S, int player_num, char key)
{
	while (ThePlayers[player_num].IsPossible(S, key))
	{
		S.move(key);
		Sleep(10);
	}
}

void TetrisGame::RandomShape(Objects** S,int player)
{
    int randShape;
    randShape = rand() % RAND;
    Objects* TempPointerShape;
    TempPointerShape = *S;
   if(player == Player1)
	  *S =  ThePlayers[Player1].getShapesarray().getShape(randShape)->Clone();
   else
	*S = ThePlayers[Player2].getShapesarray().getShape(randShape)->Clone();
 
   delete TempPointerShape;
}

void TetrisGame::run(Objects** S1 , Objects** S2)
{
    char key = 0;
    int randShape = rand() % RAND;
	
   

	/*if (S1.getPointByIdx(0).getCh() == ' ' && S2.getPointByIdx(0).getCh() == ' ') // Checks if the shapes are initiated or not
	{                                                                             // if initiated, we continue a paused game
		 S1 = ThePlayers[Player1].getShapesarray().getShape(randShape);
		 S2 = ThePlayers[Player2].getShapesarray().getShape(randShape);
	}*/
    if (*S1 == nullptr && *S2 == nullptr) {
	   
	   RandomShape(S1,Player1);
	   RandomShape(S2, Player2);
    }
    //Prints boards
	ThePlayers[Player1].getBoardGame().PrintBoardGame(Player1);
	gotoxy(LeftBoardPlayer2, 0);
    ThePlayers[Player2].getBoardGame().PrintBoardGame(Player2);

    do {
	   //Checks if a shape reached the top of the board
	   if (!ThePlayers[Player1].CheckGameOver(**S1) || !ThePlayers[Player2].CheckGameOver(**S2))
	   {
		  printGameOver();
		  return;
	   }
	   (*S1)->draw();
	   (*S2)->draw();
	 
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
					DropShape(**S1, Player1, key);//Drops shape while possible
				    i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player1].IsPossible(**S1, key))//Checks if a given move input is possible (any move but down)
				    (*S1)->move(key);//Moves shape according to given input
			 }
			 if (IsKeyboard2(key)) {
				if (Drop2 == key || Drop2B == key)
				{
					DropShape(**S2, Player2, key);//Drops shape while possible
				    i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player2].IsPossible(**S2, key))//Checks if a given move input is possible (any move but down)
				    (*S2)->move(key);//Moves shape according to given input
			 }
		  }
		  Sleep(50);
	   }	   		
		  if (ThePlayers[Player1].IsPossible(**S1, MoveDown))//Drops shape by one step
			 (*S1)->move(MoveDown);
		  else //If shape reached bottom, update the shape in the board and randomly pick new shape
		  {

			 ThePlayers[Player1].UpdateBoard(**S1);
			 RandomShape(S1, Player1);
			 ThePlayers[Player1].CheckRow(); //Checks if there is any rows that are full, if so deletes row
			 gotoxy(0, 0);
			 ThePlayers[Player1].getBoardGame().PrintBoardGame(Player1);//Prints updated board
		  }
		  if (ThePlayers[Player2].IsPossible(**S2, MoveDown))//Drops shape by one step
			 
			 (*S2)->move(MoveDown);
		  else//If shape reached bottom, update the shape in the board and randomly pick new shape
		  {
			 ThePlayers[Player2].UpdateBoard(**S2);
			 RandomShape(S2, Player2);
			 ThePlayers[Player2].CheckRow(); //Checks if there is any rows that are full, if so deletes row
			 gotoxy(LeftBoardPlayer2, 0);
			 ThePlayers[Player2].getBoardGame().PrintBoardGame(Player2);//Prints updated board
		  }
		  Sleep(200);
    } while (key != ESC);

}

void TetrisGame::Start()
{ 
    int input = 0;
    char colorsInput;

	GameMenu.PresentColorOptions();
    _kbhit();
    colorsInput = _getch() - '0';
    
    Objects *S1 = nullptr, *S2=nullptr;

	   while (input != EXIT)
	   {
		  clrscr();
		  GameMenu.PresentMenu(gameoverflag);
		  _kbhit();
		  input = _getch() - '0';
		  clrscr();
		  switch (input)
		  {
		  case start:
		  {
			 InitPlayersBoards();
			 if (colorsInput == 1)
				InitColors();			 			 
			 S1 = nullptr;
			 S2 = nullptr;
			 
			 run(&S1, &S2);
			 gameoverflag = conGame;
			 break;
		  }
		  case Continue:
		  {
			 run(&S1,&S2);
			 break;
		  }
		  case PresentInstructionskeys:
		  {
			 GameMenu.PresentInstructions();
			 break;
		  }
		  }
	   }

	   if (input == EXIT)
	   {
		   GameMenu.PresentEnd();
	   }
}

bool TetrisGame::IsKeyboard1(char ch)const
{
    for (int i = 0; i < CommandLoop; i++)
    {
	   if (keyboardString1[i] == ch)
		  return true;
    }
    return false;
}

bool TetrisGame::IsKeyboard2(char ch)const
{
    for (int i = 0; i < CommandLoop; i++)
    {
	   if (keyboardString2[i] == ch)
		  return true;
    }
    return false;
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
	gameoverflag = startGame;

	return;
}
