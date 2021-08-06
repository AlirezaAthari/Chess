#include "cell.h"
#include "qdebug.h"

Cell::Cell( QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,80,80);
    setAddress("NONE");
    setOccupied(false);
    setPieceColor("NONE");
    piece = NULL;
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Cell::setOccupied(bool o)
{
    occupied = o;
    if(o)
        setPieceColor(piece->getColor());
    else
        setPieceColor("NONE");
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

void Cell::setPieceColor(QString c)
{
    pieceColor = c;
}

QString Cell::getAddress()
{
    return address;
}

QString Cell::getPieceColor()
{
    return pieceColor;
}

bool Cell::hasPiece()
{
    return occupied;
}
