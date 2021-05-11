#include "ZrightShape.h"

ZrightShape::ZrightShape(Point StartPoint, int direction)
{
    StartPoint = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
    serialNumber = _ZrightShape; // update the serial number of the shape
    this->direction = direction;
}

void ZrightShape :: UpdateZrightShape(Point& StartPoint, int direction,int CheckRotate)
{

    switch (direction)
    {
    case Rotate0:
    {

        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 2, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        serialNumber = _ZrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 2, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _ZrightShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    }
}

void ZrightShape::RotateClockWise()
{
    if (direction == 1) // TO DO : IF ROW == 1 ->> 0
        direction = 0;
    else
        direction++;

    this->UpdateZrightShape(body[0], direction);
}

void ZrightShape::RotateCounterWise()
{
    if (direction == 0) // TO DO : IF ROW == 1 ->> 0
        direction = 1;
    else
        direction--;
    this->  UpdateZrightShape(body[0], direction);
}


bool ZrightShape::CheckRotate(int playerNumber, Board& boardGameForPlayer)const
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
            y = getPointByIdx(3).gety() + 1;
            x = getPointByIdx(3).getx();
        }
        else
        {
            y = getPointByIdx(3).gety() + 1;
            x = getPointByIdx(3).getx() - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate1:
    {

        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;


        break;
    }
    }
    return true;


}

bool ZrightShape::CheckCounterRotate(int playerNumber, Board& boardGameForPlayer) const
{
    return CheckRotate(playerNumber, boardGameForPlayer);
}


char* ZrightShape::FindBestSpot(Board& playerBoard, int level, int playerNumber)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0, min_holes = -1, curr_holes=0;
    Point StartPoint(1 + playerNumber*LeftBoardPlayer2, 2);
    ZrightShape* temp = new ZrightShape(StartPoint);

    for (int i = 0; i <= Rotate1; i++) {
        temp->UpdateZrightShape(StartPoint, i, _CheckRotate);

        for (int j = 1; j < rightBoardPlayer1; j++)
        {
            temp->CreateDropShape(playerBoard);
            UpdateBestCurPosition(*temp, &x, &y);
            if (temp->CheckRow(playerBoard, y, &curr_holes))
                return  FindPath(y, x, playerBoard, i, playerNumber);
            
            if (min_holes == -1)
                min_holes = curr_holes;
            if (curr_holes < min_holes)
            {
                min_holes = curr_holes;
                max_depth = y;
                best_col = x;
                Best_Rotate = i;
            }           
            else if (curr_holes == min_holes)
            {
                if (max_depth < y)
                {
                    min_holes = curr_holes;
                    max_depth = y;
                    best_col = x;
                    Best_Rotate = i;
                }
            }
            
            StartPoint.setX(StartPoint.getx() + 1);
            temp->UpdateZrightShape(StartPoint, i, _CheckRotate);
        }

        StartPoint.setX(playerNumber *LeftBoardPlayer2 + 1);
        StartPoint.setY(1);

    }
    delete temp;
    return  FindPath(max_depth, best_col, playerBoard, Best_Rotate, playerNumber);
}

void ZrightShape::UpdateBestCurPosition(Objects& obj, int* x, int* y)
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

char* ZrightShape::FindPath(int row, int col, Board& playerBoard, int rotate,int playerNumber )
{
    char* commands = new char[10];
    int x = body[0].getx() - playerNumber * LeftBoardPlayer2;
    int y = body[0].gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter, CounterRotate = rotate;

    if (rotate == Rotate1)
        x = body[3].getx() - playerNumber * LeftBoardPlayer2;

    Counter = col - x;
    if (Counter < 0)
        counterLeft = Counter * (-1);
    else if (Counter > 0)
        counterRight = Counter;

    if (rotate != 0 && !this->CheckRotate(playerNumber, playerBoard))
    {
        CounterRotate++;
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

  





