#include "globals.h"

QGraphicsScene *chessScene = nullptr;
QVector<QString> movesSeries = {};
bool startGame = false;
bool resetGame = false;
QList<chessman *> blackDeaths = {};
QList<chessman *> whiteDeaths = {};
QList<chessman *> alives = {};
Cell *chessBoard[8][8] = {};
chessman *movingPiece = nullptr;
QString turn = "White";
int positiveSuser1 = 0 ;
int negativeSuser1 = 0 ;
int positiveSuser2 = 0 ;
int negativeSuser2 = 0 ;

void changeTurn()
{
    if (turn == "Black")
        turn = "White";
    else
        turn = "Black";
}
