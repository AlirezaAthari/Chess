#include "queen.h"
#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>


queen::queen(QString color , QGraphicsItem *parent):chessman(color , 'Q' , parent)
{
  setImage() ;
}


void Queen::setImage()
{
  if(getcolor() == "white")
  {
    setPixmap(QPixmap(":/images/queen1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/queen.png") ) ;
  }
}


void Queen::moves(Cell * cb[][8])
{
  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  //For up
  for(int i = row - 1 , j = column ; i >= 0 ; i--)
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

  //For Down
  for(int i = row + 1 , j = column ; i <= 7 ; i++)
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

  //For left
  for(int i = row , j = column - 1 ; j >= 0 ; j--)
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

  //For Right
  for(int i = row , j = column + 1 ; j <= 7 ; j++)
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
