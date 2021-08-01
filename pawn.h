#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
class Pawn:public ChessPiece
{
public:
   pawn(QString, QGraphicsItem * = nullptr);
   virtual void setImage();
    virtual void moves(Cell * cb[][8]);

 private:


};

#endif 
