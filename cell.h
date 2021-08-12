#ifndef CELL_H
#define CELL_H
#include <qbrush.h>
#include "chessman.h"
#include "QGraphicsRectItem"
#include "replacepawn.h"

class chessman;
class Cell : public QGraphicsRectItem
{
public:
    Cell(QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void addPieceToDeaths(chessman *);
    void setOccupied(bool);
    void setAddress(QString);
    void setPiece(chessman *);
    void setColor(QColor);
    void setCellColor(QColor);
    void resetCellColor();
    void setPieceColor(QString);
    QString getAddress();
    QString getPieceColor();
    bool hasPiece();
    chessman *piece;
    int row;
    int column;

private:
    bool occupied;
    QString address;
    QBrush brush;
    QColor cellColor;
    QString pieceColor;
    ReplacePawn *rp;
};

#endif // CELL_H
