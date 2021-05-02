#include "Bomb.h"

Bomb::Bomb(const Point& point, int _direction )
{
    body = point;
    direction = _direction;
}

void Bomb::move(char direction)
{

    body.draw(' ');
    body.move(direction);
    setTextColor(color);
    draw();

}
