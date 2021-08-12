
#include "king.h"

King::King(QString color, QGraphicsItem *parent) : chessman(color, 'K', parent)
{
  setImage();
}

void King::setImage()
{
  if (getColor() == "White")
  {
    setPixmap(QPixmap(":/images/White/king.png"));
  }
  else
  {
    setPixmap(QPixmap(":/images/Black/king.png"));
  }
}

void King::moves(Cell *cb[][8])
{

  cells.clear();
  int row = getCell()->row;
  int column = getCell()->column;

  if (column > 0 && row > 0 && !(cb[row - 1][column - 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row - 1][column - 1]);
    cb[row - 1][column - 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (column < 7 && row > 0 && !(cb[row - 1][column + 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row - 1][column + 1]);
    cb[row - 1][column + 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (row > 0 && !(cb[row - 1][column]->getPieceColor() == getColor()))
  {
    cells.append(cb[row - 1][column]);
    cb[row - 1][column]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (row < 7 && !(cb[row + 1][column]->getPieceColor() == getColor()))
  {
    cells.append(cb[row + 1][column]);
    cb[row + 1][column]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (column > 0 && !(cb[row][column - 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row][column - 1]);
    cb[row][column - 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (column < 7 && !(cb[row][column + 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row][column + 1]);
    cb[row][column + 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (column > 0 && row < 7 && !(cb[row + 1][column - 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row + 1][column - 1]);
    cb[row + 1][column - 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }

  if (column < 7 && row < 7 && !(cb[row + 1][column + 1]->getPieceColor() == getColor()))
  {
    cells.append(cb[row + 1][column + 1]);
    cb[row + 1][column + 1]->setColor(Qt::darkRed);
    if (cells.last()->hasPiece())
    {
      cells.last()->setColor(Qt::red);
    }
  }
}
