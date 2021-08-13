#include "globals.h"


QGraphicsTextItem *player1Point = nullptr;
QGraphicsTextItem *player2Point = nullptr;
QGraphicsTextItem *checkDisplay = nullptr;
QGraphicsTextItem *turnDisplay = nullptr;
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
void changeTurn()
{
    if (turn == "Black")
        turn = "White";
    else
        turn = "Black";
    turnDisplay->setPlainText(turn);
}
