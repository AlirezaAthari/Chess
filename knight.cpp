#include "knight.h"

Knight::Knight(QString color , QGraphicsItem *parent):chessman(color , 'H' , parent)
{
  setImage() ;
}

void Knight::setImage()
{
  if(getColor() == "White")
  {
    setPixmap(QPixmap(":/images/White/knight.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/Black/knight.png") ) ;
  }
}


void Knight::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;
  int i , j ;
  i = row - 2 ;
  j = column - 1 ;
  if(i >= 0 && j>= 0 && (cb[i][j]->getPieceColor() != getColor() ))
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row - 2 ;
  j = column + 1 ;
  if(i >= 0 && j < 8 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row + 2 ;
  j = column - 1 ;
  if(i < 8 && j >= 0 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row + 2 ;
  j = column + 1 ;
  if(i < 8 && j < 8 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row - 1 ;
  j = column - 2 ;
  if(i >= 0 && j >= 0 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row + 1 ;
  j = column - 2 ;
  if(i < 8 && j >= 0 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row - 1 ;
  j = column + 2 ;
  if(i >= 0 && j < 8 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }
  i = row + 1 ;
  j = column + 2 ;
  if(i < 8 && j < 8 && (cb[i][j]->getPieceColor() != getColor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->hasPiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

}
