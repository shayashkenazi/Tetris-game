#pragma once
#include "Shape.h"
class LrightShape : public Shape
{
public:
    LrightShape(Point StartPoint, int direction = Rotate0);
    virtual void RotateClockWise() override;

    virtual void RotateCounterWise() override;

};

