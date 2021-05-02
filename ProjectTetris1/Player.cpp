#include "Player.h"

Player::Player(int player) : boardGameForPlayer(), shapesarray(player), playerNumber(player)
{
}

Player::~Player()
{
}
const int Player::getWinner() const
{
    return winner;
}

void const Player::printboard() const
{
    boardGameForPlayer.PrintBoardGame(playerNumber);
}

void Player::UpdateBoard(const Objects& shape)
{
    if (typeid(shape) == typeid(Bomb))
    {
        boardGameForPlayer.Explosion(shape.getPointByIdx(0));
    //    UpdateBoardExplosion(shape.getPointByIdx(0));
        
    }
    else {
        for (int i = 0; i < 4; i++)
        {
            boardGameForPlayer.setPointAtBoard(shape.getPointByIdx(i), shape.getColor());
        }
    }

}

void Player::UpdateBoardExplosion(const Point& point)
{
   
  

    for (int i =Bottom-2 ; i > TopBoard ; i--)
    {
        for (int j =1; j < rightBoardPlayer1; j++)
        {        
                boardGameForPlayer.DropPoint(j, i);
            
        }

    }
  

}

bool Player::IsPossible(const Objects& shape, char movement)
{
    int serialNum = shape.getSerialNumber();
    int x, y;
    if (Right1 == movement || Right1B == movement || Right2 == movement || Right2B == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx() + 1;
            else
                x = shape.getPointByIdx(i).getx() + 1 - LeftBoardPlayer2;
            y = shape.getPointByIdx(i).gety();
            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
    }
    if (Left1 == movement || Left1B == movement || Left2 == movement || Left2B == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx() - 1;
            else
                x = shape.getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;
            y = shape.getPointByIdx(i).gety();
            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
    }
    if (Drop1 == movement || Drop1B == movement || Drop2 == movement || Drop2B == movement || MoveDown == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx();
            else
                x = shape.getPointByIdx(i).getx() - LeftBoardPlayer2;

            y = shape.getPointByIdx(i).gety() + 1;
            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
    }

    if (RotateClockWise1 == movement || RotateClockWise1B == movement || RotateClockWise2 == movement || RotateClockWise2B == movement)
    {
        return  shape.CheckRotate(playerNumber, boardGameForPlayer);
        /*switch (shape.getSerialNumber())
        {
        case _Square:
        {
            return true;
            break;
        }

        case _LleftShape:
        {
            return shape.CheckLleftRotateClockWise(playerNumber,boardGameForPlayer);
            break;
        }
        case _LrightShape:
        {
            return shape.CheckLRightRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }

        case _RowShape:
        {
            return shape.CheckRowShapeRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _ZleftShape:
        {
            return shape.CheckZleftRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _ZrightShape:
        {
            return shape.CheckZRightRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _PlusShape:
        {
            return shape.CheckPlusRotateClockWise(playerNumber, boardGameForPlayer);

            break;
        }
        }*/
    }
    if (RotateCounterClockWise1 == movement || RotateCounterClockWise1B == movement || RotateCounterClockWise2 == movement || RotateCounterClockWise2B == movement)
    {
        return  shape.CheckCounterRotate(playerNumber, boardGameForPlayer);
        /*switch (shape.getSerialNumber())
        {
        case _Square:
        {
            return true;
            break;
        }

        case _LleftShape:
        {
            return shape.CheckLleftRotateCounterClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _LrightShape:
        {
            return shape.CheckLRightRotateCounterClockWise(playerNumber, boardGameForPlayer);
            break;
        }

        case _RowShape:
        {
            return shape.CheckRowShapeRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _ZleftShape:
        {
            return shape.CheckZleftRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _ZrightShape:
        {
            return shape.CheckZRightRotateClockWise(playerNumber, boardGameForPlayer);
            break;
        }
        case _PlusShape:
        {
            return shape.CheckPlusRotateCounterClockWise(playerNumber, boardGameForPlayer);

            break;
        }
        }*/
    }

    return true;
}


bool Player::CheckGameOver(Objects& shape)
{
    int col;
    
    for (int col = 1; col < rightBoardPlayer1-1; col++)
    {
        if (boardGameForPlayer.getCharAtBoard(TopBoard + 1, col) != ' ')
        {
            winner = 0;
            return false;
        }
    }
    return true;
}

void Player::CheckRow()
{
    bool flag; 
    for (int i = 1; i < Rows-1; i++)
    {
        flag = true;
        for (int j = 1; j < Cols -1; j++)
        {
            if (boardGameForPlayer.getCharAtBoard(i, j) == ' ')
                flag = false;
        }

        if (flag == true)
        {
            boardGameForPlayer.UpdateBoardByRow(i);
        }
    }
    //printboard();
}

