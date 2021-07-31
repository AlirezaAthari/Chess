#include "chessman.h"

chessman::chessman(QString color  , QChar symbol ,QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    this->color = color;
    piecePlaced = true;
    setSymbol(symbol);
}

void chessman::setCell(Cell * c)
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

void chessman::setPiecePlaced(bool p)
{
    piecePlaced = p;
}

bool chessman::getPiecePlaced()
{
    return piecePlaced;
}

bool chessman::cellColorise(Cell * c)
{
    if (!c->hasPiece())
    {
        cells.last()->setColor(Qt::red);
        return false;
    }
    c->setColor(Qt::darkRed);
    return true;
}

void chessman::cellDecolor()
{
    for(size_t i = 0 ;i < cells.size() ; i++)
    {
        cells.at(i)->resetCellColor();
    }
}


void chessman::setSymbol(QChar s)
{
    symbol = s;
}

