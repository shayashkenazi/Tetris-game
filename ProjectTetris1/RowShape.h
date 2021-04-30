#pragma once
#include "Shape.h"

class RowShape : public Shape
{
public:
    RowShape(Point StartPoint, int direction = Rotate0);
    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

};

