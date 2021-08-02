#ifndef KING_H
#define KING_H

#include "chessman.h"
class King : public chessman
{
public:
    king(QString, QGraphicsItem * = nullptr) ;
    virtual void setImage() ;
    void findUnSafeLocation() ;
    virtual void moves(Cell * cb[][8]) ;

signals:

};

#endif
