#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(Shape& other)
{

    for (int i = 0; i < SIZE; i++)
        body[i] = other.body[i];

    direction = other.direction;
    serialNumber = other.serialNumber;
    color = other.color;

}
Shape::~Shape()
{

}

/*Shape& Shape::Square(Point StartPoint, int direction)
{
    
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _Square; // update the serial number of the shape

    return *this;
}

Shape& Shape::LleftShape(Point StartPoint, int direction)
{
    StartPoint.setCh('@');
    
    switch (direction)
    {
    case Rotate0://
    {       
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() + 1 , StartPoint.gety(), StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LleftShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1: 
    {
        StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() - 1, StartPoint.getCh());

        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() , StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() +1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LleftShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    case Rotate2: 
    {
        StartPoint = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
      
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety() , StartPoint.getCh());
        body[2] = Point(StartPoint.getx()+2, StartPoint.gety() , StartPoint.getCh());
        body[3] = Point(StartPoint.getx() , StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LleftShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate3:
    {
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety()+1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx()+1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LleftShape; // update the serial number of the shape
        this->direction = direction;
        break;    }
    }
    return *this;
}

Shape& Shape::LrightShape(Point StartPoint, int direction)
{
 
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
              StartPoint = Point(StartPoint.getx()- 1, StartPoint.gety()+1 , StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;    
    }
    case Rotate2:
    {
        StartPoint = Point(StartPoint.getx()-1, StartPoint.gety() , StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        body[3] = Point(StartPoint.getx()+2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate3:
    {

        StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() , StartPoint.gety()+1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() , StartPoint.gety()+2 , StartPoint.getCh());
        body[3] = Point(StartPoint.getx()-1 , StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _LrightShape; // update the serial number of the shape
        this->direction = direction;
        break;    }
    }
    return *this;
    

}

Shape& Shape::RowShape(Point StartPoint, int direction)
{
 //send body[1]
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 2, StartPoint.gety() + 2 , StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 3, StartPoint.gety(), StartPoint.getCh());
        serialNumber = _RowShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        StartPoint = Point(StartPoint.getx() +2 , StartPoint.gety() -2 , StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() , StartPoint.gety() + 3, StartPoint.getCh());
        serialNumber = _RowShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
  
    }
    return *this;
    
}

Shape& Shape::ZleftShape(Point StartPoint, int direction)
{
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 2, StartPoint.gety()+1 , StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape     
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    }
   

    return *this;
}

Shape& Shape::ZrightShape(Point StartPoint,int direction)
{
 
    switch (direction)
    {
    case Rotate0:
    {

        if (body[0].getx() != 0 )  //if it is not the start row
           StartPoint = Point(StartPoint.getx() - 1 , StartPoint.gety() + 2 , StartPoint.getCh());
        else
            StartPoint = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        serialNumber = _ZrightShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        
        StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 2, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _ZrightShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    }
    
    return *this;
}

Shape& Shape::PlusShape(Point StartPoint, int direction)
{
    
    switch (direction)
    {
    case Rotate0:
    {

        if (body[0].getx() != 0)  //if it is not the start row
            StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        else
            StartPoint = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety(), StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    case Rotate2:
    {
        StartPoint = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx()+1, StartPoint.gety() , StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 2, StartPoint.gety() , StartPoint.getCh());
        body[3] = Point(StartPoint.getx() +1, StartPoint.gety() + 1 , StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;
    }
    case Rotate3:
    {
        StartPoint = Point(StartPoint.getx() + 1, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() , StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx(), StartPoint.gety() + 2, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() -1, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _PlusShape; // update the serial number of the shape
        this->direction = direction;
        break;    
    }
    }
    return *this;   
    
}
*/

void Shape::initShape()
{

    for (int i = 0; i < SIZE; i++)
    {
        body[i] = Point(0, 0, ' ');
    }
}

void Shape::draw() const
{
    setTextColor(color);

    for (int i = 0; i < SIZE; i++)
    {
        body[i].draw();
    }
}

void Shape::move(char direction)
{
    for (int i = 0; i < SIZE; i++)
    {
        body[i].draw(' ');
    }
    if (RotateClockWise1 == direction || RotateClockWise1B == direction || RotateClockWise2 == direction || RotateClockWise2B == direction)
    {
        RotateClockWise();
    }
    else if (RotateCounterClockWise1 == direction || RotateCounterClockWise1B == direction || RotateCounterClockWise2 == direction || RotateCounterClockWise2B == direction)
    {
        RotateCounterWise();
    }
    else {
        for (int i = 0; i < SIZE; i++)
        {
            body[i].move(direction);
        }
    }
    setTextColor(color);
    draw();
}

 bool Shape ::CheckLleftRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x= getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx() ;
        }
        else
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate1:
    {
     
        for (int i = 0; i < 3; i++)
        {
            if (i != 2)
            {
                if (playerNumber == Player1) //check if the shape is on the left frame
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1;
                }
                else
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
                }

                if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                    return false;
            }
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 2;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 2 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2:
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() +1 ;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 2;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety()+ 2;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    case Rotate3:
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() -1 ;
        }
        else
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() -2 ;
        }
        else
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() -2 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    }

    return true;

}

bool Shape::CheckLRightRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(0).gety();
            x = getPointByIdx(0).getx() + 1 ;
        }
        else
        {
            y = getPointByIdx(0).gety();
            x = getPointByIdx(0).getx() + 1  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;


        break;

    }
    case Rotate1:
    {

        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(0).gety();
            x = getPointByIdx(0).getx() - 1;
        }
        else
        {
            y = getPointByIdx(0).gety();
            x = getPointByIdx(0).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2:
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() - 1;
        }
        else
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety() - 1 ;
            x = getPointByIdx(2).getx() ;
        }
        else
        {
            y = getPointByIdx(2).gety() - 1 ;
            x = getPointByIdx(2).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    case Rotate3:
    {
        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() + 1;
        }
        else
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety() - 1;
            x = getPointByIdx(3).getx() ;
        }
        else
        {
            y = getPointByIdx(3).gety() - 1;
            x = getPointByIdx(3).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    }

    return true;
}

bool Shape::CheckRowShapeRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx() ;
        }
        else
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx()  - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() + 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() + 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate1:
    {

        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() - 1 ;
        }
        else
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() + 1;
        }
        else
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() + 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() - 2;
        }
        else
        {
            y = getPointByIdx(2).gety() ;
            x = getPointByIdx(2).getx() - 2 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break; 
    }
    }
    return true;


}

bool Shape::CheckZleftRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate1:
    {

        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() - 1;
        }
        else
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1;
        }
        else
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
       

        break;
    }
    }
    return true;
}

bool Shape::CheckZRightRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() ;
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(3).gety() + 1;
            x = getPointByIdx(3).getx() ;
        }
        else
        {
            y = getPointByIdx(3).gety() + 1;
            x = getPointByIdx(3).getx()  - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;

        break;

    }
    case Rotate1:
    {

        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;


        break;
    }
    }
    return true;
    
    
}

bool Shape::CheckPlusRotateClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 1
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1 ;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        
        break;

    }
    case Rotate1: // from 1 -> 2
    {

        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

        
    }
    case Rotate2: // from 2 -> 3
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
        
    }
    case Rotate3: // from 3 -> 0
    {
        for (int i = 0; i < 3; i++)
        {
            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() + 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;
        }
       
        break;
    }
}
    return true;
}

bool Shape::CheckLleftRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {

        for (int i = 0; i < 3; i++)
        {
            
                if (playerNumber == Player1) //check if the shape is on the left frame
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1;
                }
                else
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
                }

                if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                    return false;
            
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() - 1;
        }
        else
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(0).gety() -1;
            x = getPointByIdx(0).getx();
        }
        else
        {
            y = getPointByIdx(0).gety() - 1;
            x = getPointByIdx(0).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() + 1;
        }
        else
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(0).gety() + 1;
            x = getPointByIdx(0).getx() ;
        }
        else
        {
            y = getPointByIdx(0).gety() + 1;
            x = getPointByIdx(0).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    }
    return true;
}

bool Shape::CheckLRightRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() -2;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety()  + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 2;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 2;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 2;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 2 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;

    }
    }

    return true;
}

bool Shape::CheckPlusRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{

    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
       if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1 ;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {

        for (int i = 0; i < 3; i++)
        {

            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
                return false;

        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
       
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != ' ')
            return false;
        
        break;

    }
    }

    return true;

}

void Shape::RotateClockWise()
{
    
}

void Shape::RotateCounterWise()
{
   
}

const Shape& Shape::operator=(const Shape& other)
{
    for (int i = 0; i < SIZE; i++)
        body[i] = other.body[i];
    direction = other.direction;
    serialNumber = other.serialNumber;
    color = other.color;

    return *this;
}





