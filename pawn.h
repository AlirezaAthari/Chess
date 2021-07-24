#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include "chessman.h"

class Pawn : public chessman
{
    Q_OBJECT
public:
    explicit Pawn(QObject *parent = nullptr);

signals:

};

#endif // PAWN_H
