#pragma once
#include "Board.h"
#include"Objects.h"

class Shape  : public Objects
{
protected:

    enum { SIZE = 4 };
    Point body[SIZE];
    
     
public:
    Shape();
    Shape(const Shape& other);
   
    ~Shape();
     
   // const int getSerialNumber() const{ return serialNumber; } //Returns the shape's serial number
  virtual const Point& getPointByIdx(int idx) const override{ return body[idx]; } //Returns the wanted point in the body of the shape
 //   const Color getColor() const{ return color; } //Returns shapes color

    //void setSerialNumber(int serialNum) { serialNumber = serialNum; } //Sets the shape's serial number
    //void setDirection(int dir) { direction = dir; }

    /* Shape& Square(Point StartPoint, int direction = Rotate0); //Creates Square by direction
    Shape& LleftShape(Point StartPoint, int direction = Rotate0);//Creates L left by direction
    Shape& LrightShape(Point StartPoint, int direction = Rotate0);//Creates L right by direction
    Shape& RowShape(Point StartPoint, int direction = Rotate0);//Creates Row by direction
    Shape& ZleftShape(Point StartPoint, int direction = Rotate0);//Creates Z left by direction
    Shape& ZrightShape(Point StartPoint, int direction = Rotate0);//Creates Z right by direction
    Shape& PlusShape(Point StartPoint, int direction = Rotate0);//Creates Plus by direction

    */

    void initShape();
    virtual void draw() const override ; // Printing the shape to the screen


    virtual void move(char direction = Drop1) override; //Moving the shape by direction (?)

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const = 0;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const = 0;



    /*
    bool CheckLleftRotateClockWise(int playerNumber, Board& boardGameForPlayer)const; //Returns true if a clockwise rotation of L left is possible according to the current board
    bool CheckLRightRotateClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a clockwise rotation of L right is possible according to the current board
    bool CheckRowShapeRotateClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a clockwise rotation of Row is possible according to the current board
    bool CheckZleftRotateClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a clockwise rotation of Z left is possible according to the current board
    bool CheckZRightRotateClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a clockwise rotation of Z right is possible according to the current board
    bool CheckPlusRotateClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a clockwise rotation of Plus is possible according to the current board

    */

    bool CheckLleftRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of L left is possible according to the current board
    bool CheckLRightRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of L right is possible according to the current board
    bool CheckPlusRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of Plus is possible according to the current board

    virtual void RotateClockWise () = 0  ; //Rotates the shape clock wise
   
    virtual void RotateCounterWise() = 0; //Rotates the shape counter clock wise
    

    const Shape& operator=(const Shape& other);

    virtual Shape* Clone()const = 0 {};
};

