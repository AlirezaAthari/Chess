#include "chessboard.h"
#include "cell.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"

ChessBoard::ChessBoard()
{

}

QVector<QVector<Cell *>> ChessBoard::drawBoard(int x, int y)
{

    QVector<QVector<Cell *>> cells;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Cell *c = new Cell();

            if((i+j)%2==0)
            c->setColor(QColor(102 , 51 , 0));
            else
            c->setColor(QColor(255 , 153 , 51));

            c->setPos(x+j*80,y+i*80);
            c->row = i;
            c->column = j;
            cells[i][j] = c;
        }
    }
    return cells;


}


QString ChessBoard::movePiece()
{

}
