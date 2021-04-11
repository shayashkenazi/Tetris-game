#include "ShapesArray.h"

ShapesArray::ShapesArray(int _player) : player(_player)
{
    AllShapesArray = new Shape[NumOfShapes];
    if (player == Player1) {
        AllShapesArray[0].Square(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard +1));
        AllShapesArray[1].LleftShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[2].LrightShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[3].RowShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[4].ZleftShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[5].ZrightShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[6].PlusShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
    }
    if (player == Player2)
    {
        AllShapesArray[0].Square(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard +1));
        AllShapesArray[1].LleftShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[2].LrightShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[3].RowShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[4].ZleftShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[5].ZrightShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[6].PlusShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
    }
}

ShapesArray::~ShapesArray()
{
    delete[] AllShapesArray;
}

void ShapesArray::InitColorsShapesArray()
{
    AllShapesArray[0].setColor(YELLOW);
    AllShapesArray[1].setColor(BROWN);
    AllShapesArray[2].setColor(BLUE);
    AllShapesArray[3].setColor(LIGHTBLUE);
    AllShapesArray[4].setColor(RED);
    AllShapesArray[5].setColor(GREEN);
    AllShapesArray[6].setColor(MAGENTA);

}
