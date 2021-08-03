#include "cell.h"
#include "chessman.h"
#include "chessBoard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"

king::king(QString color,QGraphicsItem *parent):chessman(color , 'K' , parent)
{
  setImage() ;
}

void King::setImage()
{
  if(getcolor() == "white")
  {
    setPixmap(QPixmap(":/images/king1.png") ) ;
  }
  else
  {
    setPixmap(QPixmap(":/images/king.png") ) ;
  }
}


void King::moves(Cell * cb[][8])
{

  cells.clear() ;
  int row = getCell()->row ;
  int column = getCell()->column ;

  if(column > 0 && row > 0 && !(cb[row - 1][column - 1]->getpiececolor() == getcolor() ) )
  { //up left
    cells.append(cb[row - 1][column - 1]) ;
    cb[row - 1][column - 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece())
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(column < 7 && row > 0 && !(cb[row - 1][column + 1]->getpiececolor() == getcolor() ) )
  { // up right
    cells.append(cb[row - 1][column + 1]) ;
    cb[row - 1][column + 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(row > 0 && !(cb[row - 1][column]->getpiececolor() == getcolor() ) )
  {//up
    cells.append(cb[row - 1][column]) ;
    cb[row - 1][column]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(row < 7 && !(cb[row + 1][column]->getpiececolor() == getcolor() ) )
  {//down
    cells.append(cb[row + 1][column]) ;
    cb[row + 1][column]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(column > 0 && !(cb[row][column - 1]->getpiececolor() == getcolor() ) )
  {// left
    cells.append(cb[row][column - 1]) ;
    cb[row][column - 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(column < 7 && !(cb[row][column + 1]->getpiececolor() == getcolor() ) )
  {//right
    cells.append(cb[row][column + 1]) ;
    cb[row][column + 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(column > 0 && row < 7  && !(cb[row + 1][column - 1]->getpiececolor() == getcolor() ) )
  {//down left
    cells.append(cb[row + 1][column -1 ]) ;
    cb[row + 1][column - 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  if(column < 7 && row < 7 && !(cb[row + 1][column + 1]->getpiececolor() == getcolor() ) )
  {//down right
    cells.append(cb[row + 1][column + 1]) ;
    cb[row + 1][column + 1]->setColor(Qt::darkRed) ;
    if(cells.last()->haspiece() )
    {
      cells.last()->setColor(Qt::red) ;
    }
  }

  findUnSafeLocation();
}



void King::findUnSafeLocation()
{
  QList <ChessPiece *> pList = game->alives ;
  for(size_t i = 0 , n = pList.size() ; i < n ; i++)
  {
    if(pList[i]->getcolor() != this->getcolor() )
    {
      QList <ChessBox *> bList = pList[i]->moveCells() ;
      for(size_t j = 0 , n = bList.size() ; j < n ; j++)
      {
        Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
        if(c)
        {
          continue ;
        }
        for(size_t k = 0 , n = cells.size() ; k < n ; k++)
        {
          if(bList[j] == cells [k])
          {
            cells[k]->setColor(Qt::blue) ;
          }
        }
      }
    }
  }
}
