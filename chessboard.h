#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "cell.h"

class ChessBoard
{
public:
    ChessBoard();
    void drawBoard(QVector<QVector<Cell *>> &, int, int);

private:
};

#endif // CHESSBOARD_H
