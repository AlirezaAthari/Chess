#include "knight.h"
#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"

knight::knight(QString color , QGraphicsItem *parent):chessman(color , 'H' , parent)
{
  setImage() ;
}

void Knight::setImage()
{
  if(getcolor() == "white")
  {
    setPixmap(QPixmap(":/images/horse1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/horse.png") ) ;
  }
}


void Knight::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;
  int i , j ;

  //There are total 8 places where a night can move
  //1st up up left
  i = row - 2 ;
  j = column - 1 ;
  if(i >= 0 && j>= 0 && (cb[i][j]->getpiececolor() != getcolor() )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setcolor(Qt::red) ;
    }
    else
    {
      cells.last()->setcolor(Qt::darkRed) ;
    }
  }

  //2nd up up right
  i = row - 2 ;
  j = column + 1 ;
  if(i >= 0 && j <= 7 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //3rd down down left
  i = row + 2 ;
  j = column - 1 ;
  if(i <= 7 && j >= 0 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //4th  down down right
  i = row + 2 ;
  j = column + 1 ;
  if(i <= 7 && j <= 7 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //5th left left up
  i = row - 1 ;
  j = column - 2 ;
  if(i >= 0 && j >= 0 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //6th left left down
  i = row + 1 ;
  j = column - 2 ;
  if(i <= 7 && j >= 0 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //7th right right up
  i = row - 1 ;
  j = column + 2 ;
  if(i >= 0 && j <= 7 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

  //8th right right down
  i = row + 1 ;
  j = column + 2 ;
  if(i <= 7 && j <= 7 && (cb[i][j]->getpiececolor() != getcolor() ) )
  {
    cells.append(cb[i][j]) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
    else
    {
      cells.last()->setColor(Qt::darkRed) ;
    }
  }

}
