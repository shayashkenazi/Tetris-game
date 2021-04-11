#include "Board.h"
 #include "gotoxy.h"


Board::Board()
{
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {
		  if(j == LeftBoardPlayer1 && i == TopBoard)
			  boardGame[i][j] = 220;
		  else if (j == rightBoardPlayer1 && i == TopBoard)
			  boardGame[i][j] = 220;
		  else if (j == LeftBoardPlayer1 || j == rightBoardPlayer1)
			 boardGame[i][j] = 219;
		  else if (i == TopBoard || i == Bottom)
			 boardGame[i][j] = 220;
		  else
			 boardGame[i][j] = ' ';
	   }
    }
    
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {
		  //if (i == TopBoard || j == LeftBoardPlayer1 || i == Bottom || j == rightBoardPlayer1)
		  //{
			 BoardColors[i][j] = LIGHTGREY;
		//  }
		
	   }
	   

    }
}

void Board::setPointAtBoard(Point point,Color c)
{
    int x, y;
    x = point.getx();
    y = point.gety();
    if (x > 13)
	   x = x - LeftBoardPlayer2;
    boardGame[y][x] = point.getCh();
    BoardColors[y][x] = c;
}

void Board::UpdateBoardByRow(int row)
{
    for (int i = 1; i < Cols-1; i++)
    {
	   boardGame[row][i] = ' ';
	   
    }

    for (int i = row; i > 2 ; i--)
    {
	   for (int j = 1; j < Cols - 1; j++)
	   {
		  boardGame[i][j] = boardGame[i-1][j];
		  BoardColors[i][j] = BoardColors[i - 1][j];
	   }	 
    }

}

void Board::ResetBoard()
{
	*this = Board();
}

void Board::PrintBoardGame(int player)
{
     
    
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {			
		  if(player == Player2)
			  gotoxy(j + LeftBoardPlayer2, i);
		  Color c = BoardColors[i][j];
		  setTextColor(c);
		  cout << boardGame[i][j];
	   }
	   cout << endl;
    }
}