#include "globals.h"

bool secondMove = false;
bool mated = false;
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
int positiveplayer1 = 0;
int positiveplayer2 = 0;
void changeTurn()
{
    if (turn == "Black")
        turn = "White";
    else
        turn = "Black";
    turnDisplay->setPlainText(turn);
}

void undoMove()
{
    QString lastMove = movesSeries.last();
    movesSeries.pop_back();
    QString piece;
    QString destination;
    QString origin;
    QString deathPiece;
    for (int i = 0; i < lastMove.size(); i++)
    {
        if (i < 2)
            piece.append(lastMove.at(i));
        else if (i > 1 && i < 6)
            destination.append(lastMove.at(i));
        else if (i == 6)
            deathPiece.append(lastMove.at(i));
        else
            origin.append(lastMove.at(i));
    }
    int i = static_cast<QString>(origin[1]).toInt();
    int j = static_cast<QString>(origin[3]).toInt();
    int m = static_cast<QString>(destination[1]).toInt();
    int n = static_cast<QString>(destination[3]).toInt();
    chessBoard[i][j]->setOccupied(false);
    if (chessBoard[i][j]->piece->getSymbol() == 'P')
    {
        if (chessBoard[i][j]->piece->getColor() == "White" && m == 6)
        {
            chessBoard[i][j]->piece->firstmove = true;
        }
        else if (chessBoard[i][j]->piece->getColor() == "Black" && m == 1)
            chessBoard[i][j]->piece->firstmove = true;
    }
    chessBoard[m][n]->setPiece(chessBoard[i][j]->piece);
    if (chessBoard[m][n]->piece->getColor() == "White")
    {
        positiveplayer1 -= 5;
    }
    else
    {
        positiveplayer2 -= 5;
    }
    player1Point->setPlainText(QString::number(positiveplayer1));
    player2Point->setPlainText(QString::number(positiveplayer2));
    chessBoard[i][j]->piece = nullptr;
    if (deathPiece == "N")
        return;
    else
    {
        if (piece[0] == 'W')
        {
            chessBoard[i][j]->setPiece(blackDeaths.last());
            chessBoard[i][j]->piece->isDead = false;
            blackDeaths.pop_back();
        }
        else
        {
            chessBoard[i][j]->setPiece(whiteDeaths.last());
            chessBoard[i][j]->piece->isDead = false;
            whiteDeaths.pop_back();
        }
        chessBoard[i][j]->setOccupied(true);
    }
}
