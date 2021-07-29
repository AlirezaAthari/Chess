#include "chessman.h"

chessman::chessman(QString color  , QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    this->color = color;
    piecePlaced = true;
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
    if (c->hasPiece())
    {
        c->setColor(Qt::blue);
        return true;
    }
    else {
        cells.last()->setColor(Qt::red);
        return false;
    }
}

void chessman::cellDecolor()
{
    for(size_t i = 0 ;i < cells.size() ; i++)
    {
        cells.at(i)->resetCellColor();
    }
}
