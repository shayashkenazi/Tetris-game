#pragma once
#include "Shape.h"

class ZleftShape : public Shape
{
public:
    ZleftShape(Point StartPoint, int direction = Rotate0);//Creates Z left by direction
    void UpdateZleftShape(Point StartPoint, int direction = Rotate0);//Creates Z left by direction



    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new ZleftShape(*this);
    }
};

