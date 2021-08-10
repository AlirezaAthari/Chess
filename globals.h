#ifndef GLOBALS_H
#define GLOBALS_H

#include "chessman.h"
#include "cell.h"
extern int replacePawnChoose;
extern QList <chessman *> blackDeaths;
extern QList <chessman *> whiteDeaths;
extern bool startGame;
extern bool resetGame;
extern Cell * chessBoard[8][8];
extern chessman * movingPiece;
extern QString turn;
extern void changeTurn ();

extern QList <chessman *> alives;
#endif // GLOBALS_H
