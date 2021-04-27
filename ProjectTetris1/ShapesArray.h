#pragma once
#include"Shape.h"
class ShapesArray
{
private:
    enum { NumOfShapes = 7 };
 
    int player;
    Shape* AllShapesArray;

public:
    //Creates all shapes
    ShapesArray(int _player=1) ;
    ~ShapesArray();

    Shape getShape(int idx) { return AllShapesArray[idx]; } //Returns shape by index
    void InitColorsShapesArray(); //Sets color to each shape
};

