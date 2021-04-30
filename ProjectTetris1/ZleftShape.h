#pragma once
#include "Shape.h"

class ZleftShape : public Shape
{
public:
    ZleftShape(Point StartPoint, int direction = Rotate0);//Creates Z left by direction

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

};

