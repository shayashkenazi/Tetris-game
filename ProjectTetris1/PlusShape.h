#pragma once
#include "Shape.h"
class PlusShape : public Shape
{
public:
    PlusShape(Point StartPoint, int direction = Rotate0);
    
    void UpdatePlusShape(Point StartPoint, int direction = Rotate0);

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new PlusShape(*this);
    }
};

