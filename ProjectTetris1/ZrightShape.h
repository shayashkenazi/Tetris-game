#pragma once
#include "Shape.h"
class ZrightShape : public Shape
{
public :
    ZrightShape(Point StartPoint, int direction = Rotate0);

    void UpdateZrightShape(Point& StartPoint, int direction = Rotate0,int CheckRotate = RegularRoatate);

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new ZrightShape(*this);
    }

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual char* FindBestSpot(Board& playerBoard, int level);
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y);
    char* FindPath(int row, int col, Board& playerBoard, int rotate);

};

