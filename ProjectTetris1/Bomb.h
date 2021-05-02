
#pragma once

#include"Objects.h"
#include "Point.h"
class Bomb : public Objects
{
private:
    
    Point body ;

public:
    //Bomb() { body = Point(); }
    Bomb(const Point& point, int _direction = Rotate0);

    virtual Bomb* Clone()const override
    {
        return new Bomb(*this);
    }
  
    virtual void move(char direction = Drop1)override;

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer) const { return true; };
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const { return true; };

    virtual void draw() const override {
        setTextColor(color);
        body.draw();
    }
    virtual const Point& getPointByIdx(int idx) const override { return body; };

};

