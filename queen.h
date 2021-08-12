#ifndef QUEEN_H
#define QUEEN_H

#include "chessman.h"
#include "cell.h"
#include "chessman.h"
#include "chessboard.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
class Queen : public chessman
{

public:
   Queen(QString, QGraphicsItem * = nullptr);
   virtual void setImage();
   virtual void moves(Cell *cb[][8]);
};

#endif
