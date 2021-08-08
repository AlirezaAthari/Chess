#include "globals.h"
bool startGame = false;
bool resetGame = false;
QList <chessman *> alives = {0};
Cell * chessBoard[8][8] = {0};
chessman * movingPiece = nullptr;
QString turn = "White";
void changeTurn ()
{
    if(turn == "Black")
        turn = "White";
    else turn = "Black";
}
