#include "RowShape.h"


RowShape::RowShape(Point StartPoint, int direction)
{
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 3, StartPoint.gety(), StartPoint.getCh());
    serialNumber = _RowShape; // update the serial number of the shape
    this->direction = direction;
}

void RowShape::UpdateRowShape(Point StartPoint, int direction)
{
    //send body[1]
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 2, StartPoint.gety() + 2, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 3, StartPoint.gety(), StartPoint.getCh());
        serialNumber = _RowShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 2, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx(), StartPoint.gety() + 3, StartPoint.getCh());
        serialNumber = _RowShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }

    }
}

 void RowShape::RotateClockWise()
 {
     if (direction == 1) // TO DO : IF ROW == 1 ->> 0
         direction = 0;
     else
         direction++;

     this->UpdateRowShape(body[0], direction);
 }

 void RowShape::RotateCounterWise()
 {
     if (direction == 0) // TO DO : IF ROW == 1 ->> 0
         direction = 1;
     else
         direction--;
    this->UpdateRowShape(body[0], direction);
     
 }


 bool RowShape::CheckRotate(int playerNumber, Board& boardGameForPlayer)const
 {
     int x, y;
     switch (direction)
     {
     case Rotate0:
     {
         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety() - 1;
             x = getPointByIdx(2).getx();
         }
         else
         {
             y = getPointByIdx(2).gety() - 1;
             x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
         }

         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;
         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety() - 2;
             x = getPointByIdx(2).getx();
         }
         else
         {
             y = getPointByIdx(2).gety() - 2;
             x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
         }
         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;
         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety() + 1;
             x = getPointByIdx(2).getx();
         }
         else
         {
             y = getPointByIdx(2).gety() + 1;
             x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
         }
         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;

         break;

     }
     case Rotate1:
     {

         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() - 1;
         }
         else
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() - 1 - LeftBoardPlayer2;;
         }

         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;
         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() + 1;
         }
         else
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() + 1 - LeftBoardPlayer2;;
         }
         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;
         if (playerNumber == Player1)
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() - 2;
         }
         else
         {
             y = getPointByIdx(2).gety();
             x = getPointByIdx(2).getx() - 2 - LeftBoardPlayer2;;
         }
         if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
             return false;

         break;
     }
     }
     return true;


 }

 bool RowShape::CheckCounterRotate(int playerNumber, Board& boardGameForPlayer) const
 {
     return CheckRotate(playerNumber, boardGameForPlayer); 
 }

 char* RowShape::FindBestSpot(Board& playerBoard)
 {
     char* path = nullptr;
     int point_rating = 0, depth_rating = 0, row_rating = 0;


     for (int i = Bottom - 1; i > 1; i--)
     {
         for (int j = 1; j < rightBoardPlayer1; j++)
         {
             if (playerBoard.getCharAtBoard(i, j) == space && playerBoard.getCharAtBoard(i, j + 1) == space && playerBoard.getCharAtBoard(i, j + 2) == space && playerBoard.getCharAtBoard(i, j + 3) == space)
             {
                if (FindPath(&path, i, j, playerBoard, Rotate0))
                  return path;
             }
         }
         for (int j = 1; j < rightBoardPlayer1; j++)
         {
             if (playerBoard.getCharAtBoard(i, j) == space && playerBoard.getCharAtBoard(i -1, j) == space && playerBoard.getCharAtBoard(i -2, j) == space && playerBoard.getCharAtBoard(i-3, j) == space)
             {
                 if (FindPath(&path, i, j, playerBoard, Rotate1))
                       return path;
             }
         }
     }
 }

 
 bool RowShape::FindPath(char** path, int row, int col, Board& playerBoard, int rotate)
 {
     //this->UpdateRowShape(rotate);
     char*  commands = new char[10];
     int x = body[0].getx() - LeftBoardPlayer2;
     int y = body[0].gety();
     int i = 0;

     while (x != col && y != row)
     {
         if (rotate == Rotate0) {
             if (col < x && playerBoard.getCharAtBoard(x - 1, y) == space)
             {
                 commands[i]= Left1;
                 x--;
             }
             else if (col > x && playerBoard.getCharAtBoard(x + 1, y) == space)
             {
                 commands[i] = Right1;
                 x++;
             }
         }
         else if (rotate == Rotate1) {
             if (this->CheckRotate(Computer_Player, playerBoard))
             {
                 commands[i] = RotateClockWise2;
                 rotate--;
                 x = x + 2;
                 y = y - 2;
             }
             else {
                 commands[i] = MoveDown;
               
             }

         }
         y++;
         i++;
     }
     commands[i] = '\0';
     *path = commands;
     if (*path) 
         return true;
   
     else
         return false;
 }