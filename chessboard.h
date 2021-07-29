#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include <QObject>
#include "chessman.h"

class ChessBoard
{
public:
    ChessBoard();
    QVector<QVector<Cell *>> drawBoard(int x, int y);

    QString movePiece();
private:
};

#endif // CHESSBOARD_H
