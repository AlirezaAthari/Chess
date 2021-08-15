#include "queen.h"

Queen::Queen(QString color, QGraphicsItem *parent) : chessman(color, 'Q', parent)
{
  setImage();
}

void Queen::setImage()
{
  if (getColor() == "White")
  {
    setPixmap(QPixmap(":/images/White/queen.png"));
  }
  else
  {
    setPixmap(QPixmap(":/images/Black/queen.png"));
  }
}

void Queen::moves(Cell *cb[][8])
{
  cells.clear();
  int row = getCell()->row;
  int column = getCell()->column;
  for (int i = row - 1, j = column; i >= 0; i--)
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
  for (int i = row + 1, j = column; i < 8; i++)
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
  for (int i = row, j = column - 1; j >= 0; j--)
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

  //For Right
  for (int i = row, j = column + 1; j < 8; j++)
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

  //For upper right
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
