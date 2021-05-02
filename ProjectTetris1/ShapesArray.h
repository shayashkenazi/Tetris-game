#pragma once
#include"Shape.h"
#include "Bomb.h"


class ShapesArray
{
private:
    enum { NumOfShapes = 8 };
 
    int player;
    Objects** AllShapesArray;

public:
    //Creates all shapes
    ShapesArray(int _player=1) ;
    ~ShapesArray();

    Objects* getShape(int idx) { return AllShapesArray[idx]; } //Returns shape by index  //TODO : CHECK
    void InitColorsShapesArray(); //Sets color to each shape


};

