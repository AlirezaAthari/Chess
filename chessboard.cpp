#include "chessboard.h"
#include "qdebug.h"

ChessBoard::ChessBoard()
{

}

void ChessBoard::drawBoard(QVector<QVector<Cell *>> & cells ,int x, int y)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Cell *c = new Cell();
            if((i+j)%2==0)
            c->setCellColor(QColor(102 , 51 , 0));
            else
            c->setCellColor(QColor(255 , 153 , 51));
            c->setPos(x+j*120,y+i*120);
            c->row = i;
            c->column = j;
            cells[i].append(c);
        }
    }

}


QString ChessBoard::movePiece()
{

}
