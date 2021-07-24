#include "cell.h"

Cell::Cell( QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setAddress("");
    setPiece(NULL);
    setOccupied(false);
    setPieceColor("");
    piece = NULL;
    setRect(0,0,80,80);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void Cell::setOccupied(bool o)
{
    occupied = o;
    if(o)
        setPieceColor(piece->getColor());
    else
        setPieceColor("");
}

void Cell::setAddress(QString a)
{
    address = a;
}

void Cell::setPiece(chessman * p)
{
    p->setPos(x()+40- p->pixmap().width()/2  ,y()+40-p->pixmap().width()/2);
    p->setCell(this);
    piece = p;
    setOccupied(true);
}

void Cell::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void Cell::resetCellColor()
{
    setColor(cellColor);
}

QString Cell::getAddress()
{
    return address;
}

QString Cell::getPieceColor()
{
    return piece->getColor();
}

bool Cell::hasPiece()
{
    return occupied;
}
