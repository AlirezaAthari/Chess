#ifndef ROOK_H
#define ROOK_H

#include "chessman.h"

class Rook : public chessman
{
public:
  Rook(QString, QGraphicsItem * = nullptr);
  virtual void setImage();
   virtual void moves(Cell * cb[][8]);

};

#endif
