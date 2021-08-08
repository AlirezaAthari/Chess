#include "cell.h"
#include "qdebug.h"
#include "globals.h"
#include "chessman.h"

Cell::Cell( QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    if(resetGame)
    {
        whiteDeaths.clear();
        blackDeaths.clear();
    }
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

    if(piece && piece == movingPiece)
    {
        piece->mousePressEvent(event);
        return;
    }
    if(movingPiece)
    {

        if(getPieceColor() == movingPiece->getColor())
            return;
        unsigned int temp = 0;
        for(size_t i = 0 ; i < piece->moveCells.size() ; i++)
        {
            if(this == piece->moveCells.at(i))
                temp++;
        }
        if (temp == 0)
            return;
        movingPiece->cellDecolor();
        movingPiece->firstmove = false;
        if(this->hasPiece())
        {
            this->setOccupied(false);
            this->piece->setCell(nullptr);
            addPieceToDeaths(this->piece);
        }

    }


}

void Cell::addPieceToDeaths(chessman * p)
{
    if(p->getColor() == "White") {
        whiteDeaths.append(p);
        for(size_t i = 0 , j = 0 , k = 0 ; i<whiteDeaths.size(); i++) {
                if(j == 16){
                    k++;
                    j = 0;
                }
                whiteDeaths[i]->setPos(30 + 50*j++,720 + 100*k);
        }
    }
    else{
        blackDeaths.append(p);
        for(size_t i = 0 , j = 0 , k = 0; i<blackDeaths.size(); i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            blackDeaths[i]->setPos(600 + 50*j++,720 + 100*k);
        }
    }
    alives.removeOne(p);

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

void Cell::setCellColor(QColor c)
{
    cellColor = c;
    setColor(c);
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
