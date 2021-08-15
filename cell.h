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
    ~Cell();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void addPieceToDeaths(chessman *);
    void setOccupied(bool);
    void setPiece(chessman *);
    void setColor(QColor);
    void setCellColor(QColor);
    void resetCellColor();
    void setPieceColor(QString);
    QColor getCellCurrentColor();
    void setCellCurrentColor(QColor);
    QString getPieceColor();
    bool hasPiece();
    void checkThreads();
    bool willCheck();
    chessman *piece;
    int row;
    int column;

private:
    bool occupied;
    QBrush brush;
    QColor cellPrimaryColor;
    QColor cellCurrentColor;
    QString pieceColor;
};

#endif // CELL_H
