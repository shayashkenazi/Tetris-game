#pragma once
#include "Shape.h"
class LleftShape : public Shape
{
public:
    LleftShape(Point StartPoint, int direction = Rotate0);//Creates L left by direction
    
    void UpdateLleftShape(Point StartPoint, int direction = Rotate0, int CheckRotate = RegularRoatate);//Creates L left by direction

    virtual void RotateClockWise() override ;
    virtual void RotateCounterWise() override ;

    virtual Shape* Clone()const override
    {
        return new LleftShape(*this); 
    }

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;

    virtual char* FindBestSpot(Board& playerBoard, int level);
    char* FindPath(int row, int col, Board& playerBoard, int rotate);
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y);

};

