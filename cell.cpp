#include "cell.h"
#include "qdebug.h"
#include "globals.h"
#include "chessman.h"
#include "pawn.h"
#include "QMessageBox"

Cell::Cell(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    if (resetGame)
    {
        whiteDeaths.clear();
        blackDeaths.clear();
        resetGame = false;
    }
    setRect(0, 0, 120, 120);
    setOccupied(false);
    setPieceColor("NONE");
    piece = NULL;
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

Cell::~Cell()
{
    if (!resetGame)
        delete this;
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
        if (movingPiece->getColor() == "White")
            movingSerial.append("W");
        else
            movingSerial.append("B");
        movingSerial.append(movingPiece->getSymbol());
        movingSerial.append("R" + QString::number(movingPiece->getCell()->row) + "C" + QString::number(movingPiece->getCell()->column));
        movingPiece->cellDecolor();
        movingPiece->firstmove = false;
        if (movingPiece->getSymbol() == 'P')
        {
            if (movingPiece->getColor() == "White" && movingPiece->getCell()->row == 4)
                positiveplayer1 += 3;
            if (movingPiece->getColor() == "Black" && movingPiece->getCell()->row == 3)
                positiveplayer2 += 3;
        }
        if (this->hasPiece())
        {
            if (this->piece->getSymbol() == 'K')
            {
                if (this->piece->getColor() == "White")
                    positiveplayer2 += 50;
                else
                    positiveplayer1 += 50;
                mated = true;
                checkDisplay->setPlainText("Check Mated " + turn + " won!");
            }
            if (!secondMove)
            {
                if (this->piece->getColor() == "White")
                {
                    if (this->piece->getSymbol() == 'P')
                        positiveplayer2 += 3;
                    if (this->piece->getSymbol() == 'B')
                        positiveplayer2 += 8;
                    if (this->piece->getSymbol() == 'H')
                        positiveplayer2 += 8;
                    if (this->piece->getSymbol() == 'R')
                        positiveplayer2 += 8;
                    if (this->piece->getSymbol() == 'Q')
                        positiveplayer2 += 15;
                }
                else
                {
                    if (this->piece->getSymbol() == 'P')
                        positiveplayer1 += 3;
                    if (this->piece->getSymbol() == 'B')
                        positiveplayer1 += 8;
                    if (this->piece->getSymbol() == 'H')
                        positiveplayer1 += 8;
                    if (this->piece->getSymbol() == 'R')
                        positiveplayer1 += 8;
                    if (this->piece->getSymbol() == 'Q')
                        positiveplayer1 += 15;
                }
            }
            this->setOccupied(false);
            this->piece->setCell(nullptr);
            this->piece->isDead = true;
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
        if (movesSeries.size() >= 2 && !secondMove)
        {
            int i = movesSeries.size() - 1;
            if (movesSeries.at(i - 1).at(8) == movingSerial.at(3) && movesSeries.at(i - 1).at(10) == movingSerial.at(5) && movesSeries.at(i - 1).at(3) == movingSerial.at(8) && movesSeries.at(i - 1).at(5) == movingSerial.at(10))
            {
                if (movingPiece->getColor() == "White")
                    positiveplayer1 -= 2;
                else
                    positiveplayer2 -= 2;
            }
        }
        movesSeries.append(movingSerial);
        secondMove = false;
        movingPiece = nullptr;
        if (mated)
            return;
        changeTurn();
        checkThreads();
        if (willCheck())
        {
            if (turn == "White")
                positiveplayer2 -= 30;
            else
                positiveplayer1 -= 30;
            undoMove();
            changeTurn();
        }
        player1Point->setPlainText(QString::number(positiveplayer1));
        player2Point->setPlainText(QString::number(positiveplayer2));
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
            if (j == 3)
            {
                k++;
                j = 0;
            }
            whiteDeaths[i]->setPos(1525 + 90 * j++, 0 + 120 * k);
        }
    }
    else
    {
        blackDeaths.append(p);
        int j = 0;
        int k = 0;
        for (int i = 0; i < blackDeaths.size(); i++)
        {
            if (j == 3)
            {
                k++;
                j = 0;
            }
            blackDeaths[i]->setPos(231 + 90 * j++, 0 + 120 * k);
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
void Cell::setPiece(chessman *p)
{
    p->setPos(x() + 60 - p->pixmap().width() / 2, y() + 60 - p->pixmap().width() / 2);
    p->setCell(this);
    piece = p;
    setOccupied(true);
}

void Cell::setColor(QColor c)
{
    brush.setColor(c);
    setCellCurrentColor(c);
    setBrush(c);
}

void Cell::setCellColor(QColor c)
{
    cellPrimaryColor = c;
    setCellCurrentColor(c);
    setColor(c);
}

void Cell::resetCellColor()
{
    setColor(cellPrimaryColor);
}

void Cell::setPieceColor(QString c)
{
    pieceColor = c;
}

QColor Cell::getCellCurrentColor()
{
    return cellCurrentColor;
}

void Cell::setCellCurrentColor(QColor c)
{
    cellCurrentColor = c;
}

QString Cell::getPieceColor()
{
    return pieceColor;
}

bool Cell::hasPiece()
{
    return occupied;
}

void Cell::checkThreads()
{
    bool checked = false;
    QList<chessman *> pieces = alives;
    for (int i = 0; i < pieces.size(); i++)
    {
        pieces[i]->moves(chessBoard);
        pieces[i]->cellDecolor();
        QList<Cell *> cells = pieces[i]->getCells();
        for (int j = 0; j < cells.size(); j++)
        {
            if (cells.at(j)->hasPiece())
            {
                if (cells.at(j)->piece->getColor() == pieces.at(i)->getColor())
                    continue;
                if (cells.at(j)->piece->getSymbol() == 'K')
                {
                    cells.at(j)->setColor(Qt::darkRed);
                    pieces.at(i)->getCell()->setColor(Qt::darkRed);
                    checked = true;
                }
                if (pieces.at(i)->getColor() == "White")
                {
                    if (secondMove && turn == "Black")
                        continue;
                    if (cells.at(j)->piece->getSymbol() == 'P')
                        positiveplayer1 += 1;
                    if (cells.at(j)->piece->getSymbol() == 'H')
                        positiveplayer1 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'R')
                        positiveplayer1 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'B')
                        positiveplayer1 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'Q')
                        positiveplayer1 += 5;
                    if (cells.at(j)->piece->getSymbol() == 'K')
                    {
                        positiveplayer1 += 10;
                    }
                }
                else
                {
                    if (secondMove && turn == "White")
                        continue;
                    if (cells.at(j)->piece->getSymbol() == 'P')
                        positiveplayer2 += 1;
                    if (cells.at(j)->piece->getSymbol() == 'H')
                        positiveplayer2 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'R')
                        positiveplayer2 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'B')
                        positiveplayer2 += 2;
                    if (cells.at(j)->piece->getSymbol() == 'Q')
                        positiveplayer2 += 5;
                    if (cells.at(j)->piece->getSymbol() == 'K')
                    {
                        positiveplayer2 += 10;
                    }
                }
            }
        }
    }
    secondMove = false;
    if (checked)
        checkDisplay->setVisible(true);
    else
    {
        checkDisplay->setVisible(false);
        for (int i = 0; i < pieces.size(); i++)
            pieces.at(i)->getCell()->resetCellColor();
    }
}

bool Cell::willCheck()
{
    QList<chessman *> pieces = alives;
    for (int i = 0; i < pieces.size(); i++)
    {
        if (pieces.at(i)->getCell()->getCellCurrentColor() == Qt::darkRed && pieces.at(i)->getSymbol() == 'K')
        {
            if (turn == pieces.at(i)->getColor())
                return false;
            else
                return true;
        }
    }

    return false;
}
