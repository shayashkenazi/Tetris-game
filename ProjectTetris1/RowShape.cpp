#include "RowShape.h"


 RowShape::RowShape(Point StartPoint, int direction)
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

     *this = RowShape(body[0], direction);
 }

 void RowShape::RotateCounterWise()
 {
     if (direction == 0) // TO DO : IF ROW == 1 ->> 0
         direction = 1;
     else
         direction--;
     *this = RowShape(body[0], direction);
     
 }
