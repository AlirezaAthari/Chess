#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessman.h"

class Knight : public chessman
{
public:
   Rook(QString, QGraphicsItem * = nullptr) ;
   virtual void setImage() ;
   virtual void moves(Cell * cb[][8]) ;

signals:

};

#endif
