#include "rook.h"

Rook::Rook(QString color,QGraphicsItem *parent):chessman(color, 'R' , parent)
{
    setImage();
}


void Rook::setImage()
{
    if(getColor() == "White")
        setPixmap(QPixmap(":/images/White/rook.png"));
    else
        setPixmap(QPixmap(":/images/Black/rook.png"));
}

void Rook::moves(Cell * cb[][8])
{
    cells.clear();
    int row = getCell()->row;
    int column = getCell()->column;
    for(int i = row-1,j = column; i >= 0 ; i--)
    {
       if(cb[i][j]->getPieceColor() == getColor() )
       {
           break;
       }
       else
       {
           cells.append(cb[i][j]);
           if(cellColorise(cells.last()))
               break;
        }
    }
      for(size_t i = row+1,j = column; i < 8 ; i++)
      {
        if(cb[i][j]->getPieceColor() == getColor() )
        {
            break;
        }
        else
        {
            cells.append(cb[i][j]);
            if(cellColorise(cells.last()))
            {
                break;
            }
        }
     }
       for(int i = row,j = column-1; j >= 0 ; j--)
       {
         if(cb[i][j]->getPieceColor() == getColor() )
         {
             break;
         }
         else
         {
             cells.append(cb[i][j]);
             if(cellColorise(cells.last()))
                break;
         }
        }
        for(size_t i = row,j = column+1; j < 8 ; j++)
        {
              if(cb[i][j]->getPieceColor() == getColor() )
              {
                  break;
              }
              else
              {
                  cells.append(cb[i][j]);
                  if(cellColorise(cells.last()))
                      break;
              }
        }
}

