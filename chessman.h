#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "QGraphicsItem"
#include "cell.h"

class Cell;
class chessman :public QGraphicsPixmapItem
{
public:
    chessman(QString = "" , QGraphicsItem * = nullptr);
    void setCell(Cell *);
    void setColor(QString);
    virtual void setSymbol(QChar) = 0;
    Cell * getCell();
    QString getColor();
    virtual QChar getSymbol() = 0;
    virtual void setImage() = 0;
    QList <Cell *> moveCells();
    virtual void moves() = 0;
    void setPiecePlaced(bool);
    bool getPiecePlaced();
    bool cellColorise(Cell *);
    void cellDecolor();

private:
    QString color;
    QChar symbol;
    Cell *currentCell;
    bool piecePlaced;
    QList <Cell *> cells;
};

#endif // CHESSMAN_H
