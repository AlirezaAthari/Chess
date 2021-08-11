#include "replacepawn.h"
#include "ui_replacepawn.h"
#include "globals.h"
#include "qdebug.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
ReplacePawn::ReplacePawn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplacePawn)
{
    ui->setupUi(this);
}

ReplacePawn::~ReplacePawn()
{
    delete ui;
}

void ReplacePawn::on_comboBox_activated(int index)
{
    choosen = index;
}


void ReplacePawn::on_buttonBox_accepted()
{
    switch (choosen)
    {
        case 0 : break;
        case 1 :
        {
        int i = movingPiece->getCell()->row;
        int j = movingPiece->getCell()->column;
        movingPiece->cellDecolor();
        movingPiece->getCell()->setOccupied(false);
        movingPiece->getCell()->resetCellColor();
        movingPiece->setPos(x() + 10000 , y() + 10000);
        alives.removeAll(movingPiece);
        movingPiece->getCell()->piece = nullptr;
        Queen *q;
        q = new Queen(movingPiece->getColor());
        alives.append(q);
        chessBoard[i][j]->setPiece(q);
        chessScene->addItem(q);
        }
    }
    movingPiece = nullptr;
    this->close();
}


void ReplacePawn::on_buttonBox_rejected()
{
    this->close();
}

