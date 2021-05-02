#pragma once
#include "Shape.h"
class ZrightShape : public Shape
{
public :
    ZrightShape(Point StartPoint, int direction = Rotate0);

    void UpdateZrightShape(Point StartPoint, int direction = Rotate0);

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new ZrightShape(*this);
    }

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;
};

