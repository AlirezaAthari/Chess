#ifndef PAWN_H
#define PAWN_H

#include "chessman.h"
class Pawn:public Chessman
{
public:
   pawn(QString, QGraphicsItem * = nullptr);
   virtual void setImage();
   virtual void moves(Cell * cb[][8]);

private:


};

#endif
