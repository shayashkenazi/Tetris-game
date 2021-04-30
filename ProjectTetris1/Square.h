#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(Point StartPoint, int direction = Rotate0);
	virtual void RotateClockWise() override;
	virtual void RotateCounterWise() override;


       

};

