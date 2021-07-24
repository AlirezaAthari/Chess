#ifndef ROOK_H
#define ROOK_H

#include <QObject>
#include "chessman.h"

class Rook : public chessman
{
    Q_OBJECT
public:
    explicit Rook(QObject *parent = nullptr);

signals:

};

#endif // ROOK_H
