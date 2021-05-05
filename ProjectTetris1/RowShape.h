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
    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual char* FindBestSpot(Board& playerBoard);

    bool FindPath(char** path, int rox, int col, Board& playerBoard,int rotate);
};

