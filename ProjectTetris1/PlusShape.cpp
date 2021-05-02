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

void PlusShape :: UpdatePlusShape(Point StartPoint, int direction)
{

    switch (direction)
    {
    case Rotate0:
    {


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
