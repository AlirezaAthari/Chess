#include "pawn.h"

Pawn::Pawn(QString color , QGraphicsItem *parent):chessman(color , 'P' , parent)
{
  setImage() ;
  firstmove = true ;
}


void Pawn::setImage()
{
  if(getColor() == "White")
  {
    setPixmap(QPixmap(":/images/White/pawn.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/Black/pawn.png") ) ;
  }
}



void Pawn::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  if(this->getColor() == "White")
  {
    if(column > 0 && row > 0 && cb[row - 1][column - 1]->getPieceColor() == "Black")
    {
      cells.append(cb[row - 1][column - 1]) ;
      cellColorise(cells.last() ) ;
    }
    if(column < 7 && row > 0 && cb[row - 1][column + 1]->getPieceColor() == "Black")
    {
      cells.append(cb[row - 1][column + 1]) ;
      cellColorise(cells.last() ) ;
    }
    if(row > 0 && (!cb[row - 1][column]->hasPiece() ) )
    {
      cells.append(cb[row - 1][column]) ;
      cellColorise(cells.last() ) ;
      if(firstmove && !cb[row - 2][column]->hasPiece() )
      {
        cells.append(cb[row - 2][column]) ;
        cellColorise(cells.last() ) ;
      }
    }
  }
  else
  {
    if(column > 0 && row < 7 && cb[row + 1][column - 1]->getPieceColor() == "White")
    {
      cells.append(cb[row + 1][column - 1]) ;
      cellColorise(cells.last() ) ;
    }
    if(column < 7 && row <  7 && cb[row + 1][column + 1]->getPieceColor() == "White")
    {
      cells.append(cb[row + 1][column + 1]) ;
      cellColorise(cells.last() ) ;
    }
    if(row < 7 && (!cb[row +1 ][column]->hasPiece() ) )
    {
      cells.append(cb[row + 1][column]) ;
      cellColorise(cells.last() ) ;
      if(firstmove && !cb[row + 2][column]->hasPiece() )
      {
        cells.append(cb[row + 2][column]) ;
        cellColorise(cells.last() ) ;
      }
    }
  }

}
