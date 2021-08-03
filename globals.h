#ifndef GLOBALS_H
#define GLOBALS_H

#include "chessman.h"
#include "cell.h"

class globalcontainer
{
public:
static Cell * chessBoard[8][8];
static chessman * movingPiece ;
};
#endif // GLOBALS_H
