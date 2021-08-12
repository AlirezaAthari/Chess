#ifndef GLOBALS_H
#define GLOBALS_H

#include "chessman.h"
#include "cell.h"

extern QGraphicsScene *chessScene;
extern QVector<QString> movesSeries;
extern QList<chessman *> blackDeaths;//A qlist for pointers of the chessman
extern QList<chessman *> whiteDeaths;//A qlist for pointers of the chessman
extern bool startGame;
extern bool resetGame;
extern Cell *chessBoard[8][8];//Two-dimensional array for pointers of the global class
extern chessman *movingPiece;
extern QString turn;
extern void changeTurn();
extern QList<chessman *> alives;//A qlist for pointers of the chessman
extern int positiveplayer1 ;//positive points fot user1 ;
extern int negativeplayer1 ;//negative points fot user1 ;
extern int positiveplayer2 ;//positive points fot user2 ;
extern int negativeplayer2 ;//negative points fot user2 ;
#endif // GLOBALS_H
