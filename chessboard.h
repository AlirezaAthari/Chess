#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "cell.h"

class ChessBoard
{
public:
    ChessBoard();
    QVector<QVector<Cell *>> drawBoard(int x, int y);
    QString movePiece();
private:
};

#endif // CHESSBOARD_H
