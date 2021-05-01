
#pragma once
#include"Shape.h"

class Bomb : public Shape
{
private:
    int num;
    Point body ;

public:
    Bomb() { num = 2; };

    virtual void RotateClockWise() override {};
    virtual void RotateCounterWise() override {};
    virtual Shape* Clone()const override { return nullptr; };
};

