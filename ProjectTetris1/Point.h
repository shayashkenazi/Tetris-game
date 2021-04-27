#pragma once


#include <iostream>
#include "gotoxy.h"
#include "enum.h"
using namespace std;

class Point {
private:    
    int x ;
    int y;
    char ch =' ';


public:

    //ctor
    Point() :x(0),y(0),ch(' ') {};
    ~Point() {};
    Point(int _x, int _y, char _ch = '@') : x(_x), y(_y), ch(_ch) {};

    // get data members
    const int getx() const{ return x; }
    const int gety() const { return y; }
    const char getCh() const { return ch; }
     
    void setCh(char _ch) { ch = _ch; } //Sets points char
    void draw(char ch) const; //Draws a point to the screen by char
    void draw() const;//Draws a point to the screen 

    void move(char direction = Drop1);
};
