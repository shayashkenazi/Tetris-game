#pragma once
#include "Shape.h"
class ZrightShape : public Shape
{
public :
    ZrightShape(Point StartPoint, int direction = Rotate0);
    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;


};

