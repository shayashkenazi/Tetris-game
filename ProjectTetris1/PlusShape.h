#pragma once
#include "Shape.h"
class PlusShape : public Shape
{
public:
    PlusShape(Point StartPoint, int direction = Rotate0);
    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;


};

