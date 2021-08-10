#include "globals.h"
int replacePawnChoose = 0;
bool startGame = false;
bool resetGame = false;
QList <chessman *> blackDeaths = {};
QList <chessman *> whiteDeaths = {};
QList <chessman *> alives = {};
Cell * chessBoard[8][8] = {};
chessman * movingPiece = nullptr;
QString turn = "White";
void changeTurn ()
{
    if(turn == "Black")
        turn = "White";
    else turn = "Black";
}
