#include "pawn.h"
#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"

pawn::pawn(QString color , QGraphicsItem *parent):chessman(color , 'P' , parent)
{
  setImage() ;
  firstmove = true ;
}


void Pawn::setImage()
{
  if(getcolor() == "white")
  {
    setPixmap(QPixmap(":/images/pawn1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/pawn.png") ) ;
  }
}



void Pawn::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  if(this->getColor() == "white")
  {
    if(column > 0 && row > 0 && cb[row - 1][column - 1]->getPieceColor() == "black")
    {
      cells.append(cb[row - 1][column - 1]) ;
      cellcolorise(cells.last() ) ;
    }
    if(column < 7 && row > 0 && cb[row - 1][column + 1]->getPieceColor() == "black")
    {
      cells.append(cb[row - 1][column + 1]) ;
      cellcolorise(cells.last() ) ;
    }
    if(row > 0 && (!cb[row - 1][column]->hasPiece() ) )
    {
      cells.append(cb[row - 1][column]) ;
      cellcolorise(cells.last() ) ;
      if(firstMove && !cb[row - 2][column]->hasPiece() )
      {
        cells.append(cb[row - 2][column]) ;
        cellcolorise(cells.last() ) ;
      }
    }
  }
  else
  {
    if(column > 0 && row < 7 && cb[row + 1][column - 1]->getPieceColor() == "white")
    {//left
      cells.append(cb[row + 1][column - 1]) ;
      cellcolorise(cells.last() ) ;
    }
    if(column < 7 && row <  7 && cb[row + 1][column + 1]->getPieceColor() == "white")
    {//right
      cells.append(cb[row + 1][column + 1]) ;
      cellcolorise(cells.last() ) ;
    }
    if(row < 7 && (!cb[row +1 ][column]->hasPiece() ) )
    {
      cells.append(cb[row + 1][column]) ;
      cellcolorise(cells.last() ) ;
      if(firstMove && !cb[row + 2][column]->hasPiece() )
      {
        cells.append(cb[row + 2][column]) ;
        cellcolorise(cells.last() ) ;
      }
    }
  }

}
