#ifndef PAWN_H
#define PAWN_H

#include "chessman.h"
#include "cell.h"
#include "chessman.h"
#include "chessboard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
class Pawn : public chessman
{
public:
   Pawn(QString, QGraphicsItem * = nullptr);
   virtual void setImage();
   virtual void moves(Cell *cb[][8]);
};

#endif
