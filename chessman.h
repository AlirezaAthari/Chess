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
    chessman(QString , QChar , QGraphicsItem * = nullptr);
    void setCell(Cell *);
    void setColor(QString);
    virtual void setSymbol(QChar);
    Cell * getCell();
    QString getColor();
    QChar getSymbol();
    virtual void setImage() = 0;
    QList <Cell *> moveCells();
    virtual void moves(Cell * cb[][8]) = 0;
    void setPiecePlaced(bool);
    bool getPiecePlaced();
    bool cellColorise(Cell *);
    void cellDecolor();
    bool firstmove ;

    protected:
    QString color;
    QChar symbol;
    Cell *currentCell;
    bool piecePlaced;
    QList <Cell *> cells;
};

#endif // CHESSMAN_H
