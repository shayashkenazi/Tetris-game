#include "Square.h"

Square::Square(Point StartPoint, int direction)  {

    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _Square; // update the serial number of the shape
}

void Square::RotateClockWise()
{
}

void Square::RotateCounterWise()
{
}

char* Square::FindBestSpot(Board& playerBoard)
{
    char* path = nullptr;
    int point_rating = 0, depth_rating = 0, row_rating = 0;


    for (int i = Bottom-1; i > 1; i--)
    {
        for (int j = 1; j < rightBoardPlayer1; j++)
        {
            if (playerBoard.getCharAtBoard(i, j) == space && playerBoard.getCharAtBoard(i, j + 1) == space)
            {
                row_rating = 2;
                if (playerBoard.getCharAtBoard(i - 1, j) == space && playerBoard.getCharAtBoard(i - 1, j + 1) == space)
                {
                    if(path = FindPath(i, j, playerBoard))
                        return path;
                }
                
            }
        }
    }
}
char* Square::FindPath(int row, int col, Board& playerBoard)
{
    char* commands = new char[10];
    int x = body[3].getx() - LeftBoardPlayer2;
    int y = body[3].gety();
    int i = 0;

    while (x != col && y != row)
    {
        if (row < x && playerBoard.getCharAtBoard(x - 1, y + 1) == space)
        {
            commands[i] = Left;
            x--;
        }
        else if (row > x && playerBoard.getCharAtBoard(x + 1, y + 1) == space)
        {
            commands[i] = Right;
            x++;
        }
        y++;
        i++;
    }
    commands[i] = '\0';
    return commands;
}

//