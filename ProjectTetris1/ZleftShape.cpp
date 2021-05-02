#include "ZleftShape.h"


ZleftShape::ZleftShape(Point StartPoint, int direction)
{
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _ZleftShape; // update the serial number of the shape     
    this->direction = direction;
}

void ZleftShape :: UpdateZleftShape(Point StartPoint, int direction)
{
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 2, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape     
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    }

}

void ZleftShape::RotateClockWise()
{
    if (direction == 1) // TO DO : IF ROW == 1 ->> 0
        direction = 0;
    else
        direction++;

    this-> UpdateZleftShape(body[0], direction);
}

void ZleftShape::RotateCounterWise()
{
    if (direction == 0) // TO DO : IF ROW == 1 ->> 0
        direction = 1;
    else
        direction--;
    this -> UpdateZleftShape(body[0], direction);
}


bool ZleftShape::CheckRotate(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
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
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1;
        }
        else
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;


        break;
    }
    }
    return true;
}

bool ZleftShape::CheckCounterRotate(int playerNumber, Board& boardGameForPlayer) const
{
    return CheckRotate(playerNumber, boardGameForPlayer);
}



