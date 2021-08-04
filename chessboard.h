#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "cell.h"

class ChessBoard
{
public:
    ChessBoard();
    void drawBoard(QVector<QVector<Cell *>> &  ,int , int );
    QString movePiece();
private:
};

#endif // CHESSBOARD_H
