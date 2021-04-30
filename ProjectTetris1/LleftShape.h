#pragma once
#include "Shape.h"
class LleftShape : public Shape
{
public:
    LleftShape(Point StartPoint, int direction = Rotate0);//Creates L left by direction

    virtual void RotateClockWise() override ;
    virtual void RotateCounterWise() override ;

};

