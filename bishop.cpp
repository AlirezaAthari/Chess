#include "bishop.h"

Bishop::Bishop(QString color, QGraphicsItem *parent) : chessman(color, 'B', parent)
{
  setImage();
}

void Bishop::setImage()
{
  if (getColor() == "White")
  {
    setPixmap(QPixmap(":/images/White/bishop.png"));
  }
  else
  {
    setPixmap(QPixmap(":/images/Black/bishop.png"));
  }
}

void Bishop::moves(Cell *cb[][8])
{
  cells.clear();
  int row = getCell()->row;
  int column = getCell()->column;
  for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
  {
    if (cb[i][j]->getPieceColor() == getColor())
    {
      break;
    }
    else
    {
      cells.append(cb[i][j]);
      if (cellColorise(cells.last()))
      {
        break;
      }
    }
  }
  for (int i = row - 1, j = column + 1; i >= 0 && j < 8; i--, j++)
  {
    if (cb[i][j]->getPieceColor() == getColor())
    {
      break;
    }
    else
    {
      cells.append(cb[i][j]);
      if (cellColorise(cells.last()))
      {
        break;
      }
    }
  }
  for (int i = row + 1, j = column + 1; i < 8 && j < 8; i++, j++)
  {
    if (cb[i][j]->getPieceColor() == getColor())
    {
      break;
    }
    else
    {
      cells.append(cb[i][j]);
      if (cellColorise(cells.last()))
      {
        break;
      }
    }
  }
  for (int i = row + 1, j = column - 1; i < 8 && j >= 0; i++, j--)
  {
    if (cb[i][j]->getPieceColor() == getColor())
    {
      break;
    }
    else
    {
      cells.append(cb[i][j]);
      if (cellColorise(cells.last()))
      {
        break;
      }
    }
  }
}
