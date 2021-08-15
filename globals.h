#ifndef GLOBALS_H
#define GLOBALS_H

#include "chessman.h"
#include "cell.h"
extern bool secondMove;
extern bool mated;
extern QGraphicsTextItem *player1Point;
extern QGraphicsTextItem *player2Point;
extern QGraphicsTextItem *checkDisplay;
extern QGraphicsTextItem *turnDisplay;
extern QGraphicsScene *chessScene;
extern QVector<QString> movesSeries;
extern QList<chessman *> blackDeaths;
extern QList<chessman *> whiteDeaths;
extern bool startGame;
extern bool resetGame;
extern Cell *chessBoard[8][8];
extern chessman *movingPiece;
extern QString turn;
extern void changeTurn();
extern QList<chessman *> alives;
void changeTurn();
void undoMove();
extern QList<chessman *> alives;
extern int positiveplayer1 ;
extern int positiveplayer2 ;
#endif // GLOBALS_H
