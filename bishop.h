#ifndef BISHOP_H
#define BISHOP_H
#include "chessman.h"

class Bishop : public chessman
{
public:
      Bishop(QString, QGraphicsItem * = nullptr);
      virtual void setImage();
      virtual void moves(cell * cb[][8]);

};

#endif 
