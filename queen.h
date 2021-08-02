#ifndef QUEEN_H
#define QUEEN_H

#include "chessman.h"
class Queen : public chessman
{

public:
   queen(QString, QGraphicsItem * = nullptr) ;
   virtual void setImage() ;
   virtual void moves(Cell * cb[][8]) ;

};

#endif 
