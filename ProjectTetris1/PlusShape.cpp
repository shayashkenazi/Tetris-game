#include "PlusShape.h"


PlusShape::PlusShape(Point StartPoint, int direction)
{
    StartPoint = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
    serialNumber = _PlusShape; // update the serial number of the shape
    this->direction = direction;
}

void PlusShape :: UpdatePlusShape(Point& StartPoint, int direction, int CheckRotate )
{

    switch (direction)
    {
    case Rotate0:
    {

        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    case Rotate2:
    {
        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate3:
    {
        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    }
}

void PlusShape::RotateClockWise()
{
    if (direction == 3) // TO DO : IF ROW == 1 ->> 0
        direction = 0;
    else
        direction++;

    this-> UpdatePlusShape(body[0], direction);
}

void PlusShape::RotateCounterWise()
{
    if (direction == 0) // TO DO : IF ROW == 1 ->> 0
        direction = 3;
    else
        direction--;
    switch (direction)
    {
    case Rotate0: //from 1 -> 0
    {
        this->UpdatePlusShape(body[0], direction);
        break;
    }
    case Rotate1://from 2 -> 1

    {
        //body[0] = Point(body[0].getx()+ 1, body[0].gety() - 1, body[0].getCh());
        this->UpdatePlusShape(body[0], direction);

        break;
    }
    case Rotate2://from 3 -> 2
    {
        //  body[0] = Point(body[0].getx() , body[0].gety() + 1, body[0].getCh());
        this->UpdatePlusShape(body[0], direction);

        break;

    }
    case Rotate3://from 0 -> 3
    {
        //body[0] = Point(body[0].getx() - 1, body[0].gety(), body[0].getCh());
        this->UpdatePlusShape(body[0], direction);
        break;
    }
    }
    
}


bool PlusShape::CheckRotate(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 1
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

        break;

    }
    case Rotate1: // from 1 -> 2
    {

        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;


    }
    case Rotate2: // from 2 -> 3
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    case Rotate3: // from 3 -> 0
    {
        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }

        break;
    }
    }
    return true;
}

bool PlusShape::CheckCounterRotate(int playerNumber, Board& boardGameForPlayer) const
{

    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {

        for (int i = 0; i < 3; i++)
        {

            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;

        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    }

    return true;

}

char* PlusShape::FindBestSpot(Board& playerBoard, int level, int playerNumber)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0, curr_holes = 0,min_holes=-1;
    Point StartPoint(1 + playerNumber*LeftBoardPlayer2, 2);
    PlusShape* temp = new PlusShape(StartPoint);

    for (int i = 0; i <= Rotate3; i++) {
        temp->UpdatePlusShape(StartPoint, i, _CheckRotate);
        for (int j = 1; j < rightBoardPlayer1; j++)
        {
            temp->CreateDropShape(playerBoard);
            UpdateBestCurPosition(*temp, &x, &y);
            if (temp->CheckRow(playerBoard, y, &curr_holes))
                return  FindPath(y, x, playerBoard, i,playerNumber);

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
            temp->UpdatePlusShape(StartPoint, i, _CheckRotate);
        }
        StartPoint.setX(1 + playerNumber*LeftBoardPlayer2);
        StartPoint.setY(1);

    }
    delete temp;
    return  FindPath(max_depth, best_col, playerBoard, Best_Rotate, playerNumber);
}

void PlusShape::UpdateBestCurPosition(Objects& obj, int* x, int* y)
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
    case Rotate2:
    {
        *x = obj.getPointByIdx(3).getx();
        if (*x > rightBoardPlayer1 + 5)
            *x = *x - LeftBoardPlayer2;
        *y = obj.getPointByIdx(3).gety();
        break;
    }
    case Rotate3:
    {
        *x = obj.getPointByIdx(2).getx();
        if (*x > rightBoardPlayer1 + 5)
            *x = *x - LeftBoardPlayer2;
        *y = obj.getPointByIdx(2).gety();
        break;
    }
    }

}

char* PlusShape::FindPath(int row, int col, Board& playerBoard, int rotate,int playerNumber )
{
    char* commands = new char[10];
    int x = body[0].getx() - (playerNumber *LeftBoardPlayer2);
    int y = body[0].gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter, CounterRotate = rotate;
    if (rotate == Rotate1 || rotate == Rotate3 )
        x = body[1].getx() - playerNumber*LeftBoardPlayer2;
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
