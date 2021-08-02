#include "bishop.h"
#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"


bishop::bishop(QString color , QGraphicsItem *parent):chessman(color , 'B' , parent)
{
  setImage() ;
}

void Bishop::setImage()
{
  if(getcolor() == "white")
  {
    setPixmap(QPixmap(":/images/bishop1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/bishop.png") ) ;
  }
}



void Bishop::moves(cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  //For upper Left
  for(int i = row - 1 , j = column - 1 ; i >= 0 && j >=0 ; i-- , j--)
  {
    if(cb[i][j]->getpiececolor() == getcolor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellcolorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //For upper right
  for(int i = row - 1 , j = column + 1 ; i >= 0 && j <= 7 ; i-- , j++)
  {
    if(cb[i][j]->getpiececolor() == getcolor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellcolorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //For downward right
  for(int i = row + 1 , j = column + 1 ; i <= 7 && j <= 7 ; i++ , j++)
  {
    if(cb[i][j]->getpiececolor() == getcolor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellcolorise(cells.last() ) )
      {
        break ;
      }
    }
  }

  //For downward left
  for(int i = row + 1 , j = column - 1 ; i <= 7 && j >= 0 ; i++ , j--)
  {
    if(cb[i][j]->getpiececolor() == getcolor() )
    {
      break ;
    }
    else
    {
      cells.append(cb[i][j]) ;
      if(cellcolorise(cells.last() ) )
      {
        break ;
      }
    }
  }

}
