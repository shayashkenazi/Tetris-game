#include "Square.h"

Square::Square(Point StartPoint, int direction) : Shape() {

    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _Square; // update the serial number of the shape
}