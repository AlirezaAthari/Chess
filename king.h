#ifndef KING_H
#define KING_H

#include "chessman.h"
#include "cell.h"
#include "chessman.h"
#include "chessboard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
class King : public chessman
{
public:
    King(QString, QGraphicsItem * = nullptr) ;
    virtual void setImage() ;
    virtual void moves(Cell * cb[][8]) ;

signals:

};

#endif
