#ifndef KNIGHT_H
#define KNIGHT_H

#include <QObject>
#include "chessman.h"

class Knight : public chessman
{
    Q_OBJECT
public:
    explicit Knight(QObject *parent = nullptr);

signals:

};

#endif // KNIGHT_H
