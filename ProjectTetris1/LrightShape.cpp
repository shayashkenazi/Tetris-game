#include "LrightShape.h"
LrightShape::LrightShape(Point StartPoint, int direction) {
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate2:
    {
        StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety(), StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate3:
    {

        StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;    
    }
    }
}

void LrightShape::RotateClockWise()
{
    if (direction == 3) // TO DO : IF ROW == 1 ->> 0
        direction = 0;
    else
        direction++;

    *this = LrightShape(body[0], direction);
}

void LrightShape::RotateCounterWise()
{
    if (direction == 0) // TO DO : IF ROW == 1 ->> 0
        direction = 3;
    else
        direction--;
    switch (direction)
    {
    case Rotate0: //from 1 -> 0
    {
        body[0] = Point(body[1].getx(), body[1].gety() - 1, body[1].getCh());
        *this = LrightShape(body[0], direction);

        break;
    }
    case Rotate1: //from 2 -> 1
    {
        *this = LrightShape(body[1], direction);

        break;
    }
    case Rotate2: //from 3 -> 2
    {
        body[0] = Point(body[1].getx() - 1, body[1].gety(), body[1].getCh());
        *this = LrightShape(body[0], direction);

        break;

    }
    case Rotate3: //from 0 -> 3
    {
        body[0] = Point(body[0].getx() - 1, body[0].gety(), body[0].getCh());
        *this = LrightShape(body[0], direction);
        break;
    }
    }

}
