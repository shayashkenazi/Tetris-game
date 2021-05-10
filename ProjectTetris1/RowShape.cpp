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

void RowShape::UpdateRowShape(Point& StartPoint, int direction, int CheckRotate)
{
    //send body[1]
    switch (direction)
    {
    case Rotate0:
    {

        if (body[0].getx() != 0 && CheckRotate == RegularRoatate)//if it is not the start row
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
        if (CheckRotate == RegularRoatate)
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

 char* RowShape::FindBestSpot(Board& playerBoard,int level, int playerNumber)
 {
   
     // int point_rating = 0, depth_rating = 0, row_rating = 0;

     int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0;
     Point StartPoint(1 + playerNumber * LeftBoardPlayer2, 1);
     RowShape* temp = new RowShape(StartPoint);

     for (int i = 0; i <= Rotate1; i++) {
         temp->UpdateRowShape(StartPoint, i, _CheckRotate);
        
         for (int j = 1; j < rightBoardPlayer1 ; j++)
         {
             temp->CreateDropShape(playerBoard);
             UpdateBestCurPosition(*temp, &x, &y);
             if (temp->CheckRow(playerBoard, y))
                 return  FindPath(y, x, playerBoard, i, playerNumber);

             if (max_depth < y)
             {
                 max_depth = y;
                 best_col = x;
                 Best_Rotate = i;
             }

             StartPoint.setX(StartPoint.getx() + 1);
             temp->UpdateRowShape(StartPoint, i, _CheckRotate);
         }
         
         StartPoint.setX(playerNumber * LeftBoardPlayer2 + 1);
         StartPoint.setY(1);
        
         
        
     }
     delete temp;
     return  FindPath(max_depth, best_col, playerBoard, Best_Rotate, playerNumber);
 }

 void RowShape::UpdateBestCurPosition(Objects& obj, int* x, int* y)
 {
     switch (obj.getDirection())
     {
     case Rotate0:
     {
         *x = obj.getPointByIdx(0).getx();
         if (*x > rightBoardPlayer1 + 5)
             *x = *x - LeftBoardPlayer2;
         *y = obj.getPointByIdx(0).gety();
         break;
     }
     case Rotate1:
     {   
         *x = obj.getPointByIdx(3).getx();
         if (*x > rightBoardPlayer1 + 5)
             *x = *x - LeftBoardPlayer2;
         *y = obj.getPointByIdx(3).gety();
        break;
     }
     }
     

 }

 
 char* RowShape::FindPath(int row, int col, Board& playerBoard, int rotate,int playerNumber )
 {
     char* commands = new char[10];
     int x = body[0].getx() - playerNumber * LeftBoardPlayer2;
     int y = body[0].gety();
     int i = 0;
     int counterRight = 0, counterLeft = 0, Counter, CounterRotate = rotate;
     if (rotate != Rotate0)
         x = body[2].getx() - playerNumber * LeftBoardPlayer2;
 
     Counter = col - x;
     if (Counter < 0)
         counterLeft = Counter * (-1);
     else if (Counter > 0)
         counterRight = Counter;
    
     if (rotate != 0 && !this->CheckRotate(playerNumber, playerBoard))
     {
         CounterRotate = CounterRotate + 2;
     }
     while (CounterRotate)
     {
         if (playerNumber == Computer_Player2)
             commands[i] = RotateClockWise2;
         else
             commands[i] = RotateClockWise1;
         CounterRotate--;
         i++;
     }
     while (counterLeft)
     {
         if (playerNumber == Computer_Player2)
             commands[i] = Left2;
         else
             commands[i] = Left1;
         counterLeft--;
         i++;
     }
     while (counterRight)
     {
         if (playerNumber == Computer_Player2)
             commands[i] = Right2;
         else
             commands[i] = Right1;
         
         counterRight--;
         i++;
     }


     commands[i] = '\0';
     return commands;
 }