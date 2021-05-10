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

char* Bomb::FindBestSpot(Board& playerBoard,int level)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0;
    int mid = (LeftBoardPlayer1 + rightBoardPlayer1) / 2,abs1,abs2;
    Point StartPoint(1 + LeftBoardPlayer2, 1);
    Bomb* temp = new Bomb(StartPoint);
    for (int i = 1; i < rightBoardPlayer1; i++)
    {
        temp->CreateDropBomb(playerBoard);
        UpdateBestCurPosition(*temp, &x, &y);
        if (level == easy) {
            //  if (CheckRow(playerBoard, y))
              //    return  FindPath(y, x, playerBoard,i);
        }

        if (max_depth == 0 || max_depth > y)
        {
            max_depth = y;
            best_col = x;
        }
        else if (max_depth == y) //check aprox to mid
        {
            (best_col - mid) < 0 ? abs1 = (best_col - mid) * (-1) : abs1 = (best_col - mid);
            (x - mid) < 0 ? abs2 = (x - mid) * (-1) : abs2 = (x - mid);
            if (abs2 < abs1 )
            {
                max_depth = y;
                best_col = x;
            }
        }
        
        temp->body.setX(i + LeftBoardPlayer2 + 1);
        temp->body.setY(1);
    }
    
    delete temp;
    return  FindPath(max_depth, best_col, playerBoard);
}

void Bomb::UpdateBestCurPosition(Objects& obj, int* x, int* y)
{
    *x = obj.getPointByIdx(0).getx() - LeftBoardPlayer2;
    *y = obj.getPointByIdx(0).gety();
}

void Bomb::CreateDropBomb(Board& playerBoard)
{
    bool flag = true;
    int x, y;
    while (flag) {
        x = body.getx() - LeftBoardPlayer2;
        y = body.gety() + 1;

        if (playerBoard.getCharAtBoard(y, x) != ' ')
            flag = false;

        if (flag)
        {
            body.move();          
        }
    }
}

char* Bomb::FindPath(int row, int col, Board& playerBoard)
{
    char* commands = new char[10];
    int x = body.getx() - LeftBoardPlayer2;
    int y = body.gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter;
    
    Counter = col - x;
    if (Counter < 0)
        counterLeft = Counter * (-1);
    else if (Counter > 0)
        counterRight = Counter;

    while (counterLeft)
    {
        commands[i] = Left1;
        counterLeft--;
        i++;
    }
    while (counterRight)
    {
        commands[i] = Right1;
        counterRight--;
        i++;
    }


    commands[i] = '\0';
    return commands;
}
