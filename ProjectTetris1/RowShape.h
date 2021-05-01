#pragma once
#include "Shape.h"

class RowShape : public Shape
{
public:
    RowShape(Point StartPoint, int direction = Rotate0);
    
    void UpdateRowShape(Point StartPoint, int direction = Rotate0);

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new RowShape(*this);
    }
};

