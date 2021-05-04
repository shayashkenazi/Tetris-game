#pragma once
#include "Shape.h"
class LleftShape : public Shape
{
public:
    LleftShape(Point StartPoint, int direction = Rotate0);//Creates L left by direction
    
   void UpdateLleftShape(Point StartPoint, int direction = Rotate0);//Creates L left by direction

    virtual void RotateClockWise() override ;
    virtual void RotateCounterWise() override ;

    virtual Shape* Clone()const override
    {
        return new LleftShape(*this); 
    }

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;

    virtual char* FindBestSpot(Board& playerBoard) { return nullptr; }

};

