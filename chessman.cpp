#include "chessman.h"
#include "globals.h"
#include "QDebug"
chessman::chessman(QString color, QChar symbol, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->color = color;
    piecePlaced = true;
    setSymbol(symbol);
    firstmove = true;
}

chessman::~chessman()
{
    for ( int i ; i < cells.size() ; i++ )
    {
        delete cells.at(i);
    }
    delete currentCell;
    delete this;
}

void chessman::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->isDead || mated)
        return;
    if (movingPiece == this)
    {
        movingPiece->cellDecolor();
        movingPiece->getCell()->resetCellColor();
        if(movingPiece->getColor() == "White")
        {
            positiveplayer1-- ;
        }
        else
        {
            positiveplayer2-- ;
        }

        player1Point->setPlainText(QString::number(positiveplayer1));
        player2Point->setPlainText(QString::number(positiveplayer2));
        movingPiece = nullptr;
        return;
    }

    if ((!this->getPiecePlaced()) || ((!movingPiece) && (turn != this->getColor())))
    {
        return;
    }

    if (!movingPiece)
    {
        movingPiece = this;
        movingPiece->getCell()->setColor(Qt::red);
        movingPiece->moves(chessBoard);

    }

    else if (this->getColor() != movingPiece->getColor())
    {
        this->getCell()->mousePressEvent(event);
    }
}

void chessman::setCell(Cell *c)
{
    currentCell = c;
}

void chessman::setColor(QString c)
{
    color = c;
}

Cell *chessman::getCell()
{
    return currentCell;
}

QString chessman::getColor()
{
    return color;
}

QChar chessman::getSymbol()
{
    return symbol;
}

QList<Cell *> chessman::getCells()
{
    return cells;
}

void chessman::setPiecePlaced(bool p)
{
    piecePlaced = p;
}

bool chessman::getPiecePlaced()
{
    return piecePlaced;
}

bool chessman::cellColorise(Cell *c)
{
    if (c->hasPiece())
    {
        c->setColor(Qt::red);
        return true;
    }
    else
    {
        cells.last()->setColor(Qt::darkRed);
        return false;
    }
}

void chessman::cellDecolor()
{
    for (int i = 0; i < cells.size(); i++)
    {
        cells.at(i)->resetCellColor();
    }
}

void chessman::setSymbol(QChar s)
{
    symbol = s;
}
