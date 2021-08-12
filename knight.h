#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessman.h"
#include "cell.h"
#include "chessman.h"
#include "chessboard.h"
#include "game.h"

class Knight : public chessman
{
public:
   Knight(QString, QGraphicsItem * = nullptr);
   virtual void setImage();
   virtual void moves(Cell *cb[][8]);
};

#endif
