#include "rook.h"
#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"

Rook::Rook(QString color , QGraphicsItem *parent):chessman(color , 'R' , parent)
{
  setImage() ;
}


void Rook::setImage()
{
  if(getColor() == "White")
  {
    setPixmap(QPixmap(":/images/rook1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/rook.png") ) ;
  }
}

void Rook::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  //for Up
  for(size_t i = row - 1 , j = column ; i >= 0 ; i--)
  {
    if(cb[i][j]->getPieceColor() == getColor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellColorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //for Down
  for(size_t i = row + 1 , j = column ; i < 8 ; i++)
  {
    if(cb[i][j]->getPieceColor() == getColor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellColorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //for Left
  for(size_t i = row , j = column - 1 ; j >= 0 ; j--)
  {
    if(cb[i][j]->getPieceColor() == getColor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellColorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //for Right
  for(size_t i = row , j = column + 1 ; j < 8 ; j++)
  {
    if(cb[i][j]->getPieceColor() == getColor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellColorise(cells.last() ) )
      {
        break ;
      }
    }
  }

}
