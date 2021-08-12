#include "cell.h"
#include "qdebug.h"
#include "globals.h"
#include "chessman.h"
#include "pawn.h"

Cell::Cell(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    if (resetGame)
    {
        whiteDeaths.clear();
        blackDeaths.clear();
        resetGame = false;
    }
    setRect(0, 0, 120, 120);
    setAddress("NONE");
    setOccupied(false);
    setPieceColor("NONE");
    piece = NULL;
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (piece && piece == movingPiece)
    {
        piece->mousePressEvent(event);
        return;
    }
    if (movingPiece)
    {

        QString movingSerial = "";

        if (getPieceColor() == movingPiece->getColor())
            return;
        unsigned int temp = 0;
        QList<Cell *> moves = movingPiece->getCells();

        for (int i = 0; i < moves.size(); i++)
        {
            if (this == moves.at(i))
                temp++;
        }
        if (temp == 0)
            return;
        changeTurn();
        if (movingPiece->getColor() == "White")
            movingSerial.append("W");
        else
            movingSerial.append("B");
        movingSerial.append(movingPiece->getSymbol());
        movingSerial.append("R" + QString::number(movingPiece->getCell()->row) + "C" + QString::number(movingPiece->getCell()->column));
        movingPiece->cellDecolor();
        movingPiece->firstmove = false;
        if (this->hasPiece())
        {
            this->setOccupied(false);
            this->piece->setCell(nullptr);
            addPieceToDeaths(this->piece);
            movingSerial.append(this->piece->getSymbol());
        }
        else
            movingSerial.append("N");
        movingPiece->getCell()->setOccupied(false);
        movingPiece->getCell()->resetCellColor();
        movingPiece->getCell()->piece = nullptr;
        setPiece(movingPiece);
        movingSerial.append("R" + QString::number(movingPiece->getCell()->row) + "C" + QString::number(movingPiece->getCell()->column));
        movesSeries.append(movingSerial);
        movingPiece = nullptr;
    }
}

void Cell::addPieceToDeaths(chessman *p)
{
    if (p->getColor() == "White")
    {
        whiteDeaths.append(p);
        int j = 0;
        int k = 0;
        for (int i = 0; i < whiteDeaths.size(); i++)
        {
            if (j == 2)
            {
                k++;
                j = 0;
            }
            whiteDeaths[i]->setPos(1165 + 90 * j++, 0 + 120 * k);
        }
    }
    else
    {
        blackDeaths.append(p);
        int j = 0;
        int k = 0;
        for (int i = 0; i < blackDeaths.size(); i++)
        {
            if (j == 2)
            {
                k++;
                j = 0;
            }
            blackDeaths[i]->setPos(0 + 90 * j++, 0 + 120 * k);
        }
    }
    alives.removeAll(p);
}

void Cell::setOccupied(bool o)
{
    occupied = o;
    if (o)
        setPieceColor(piece->getColor());
    else
        setPieceColor("NONE");
}

void Cell::setAddress(QString a)
{
    address = a;
}

void Cell::setPiece(chessman *p)
{
    p->setPos(x() + 60 - p->pixmap().width() / 2, y() + 60 - p->pixmap().width() / 2);
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
