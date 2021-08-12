#ifndef BISHOP_H
#define BISHOP_H

#include "chessman.h"
#include "cell.h"
#include "game.h"
class Bishop : public chessman
{
public:
    Bishop(QString, QGraphicsItem * = nullptr);
    virtual void setImage();
    virtual void moves(Cell *cb[][8]);
};

#endif
