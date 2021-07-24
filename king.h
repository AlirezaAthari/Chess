#ifndef KING_H
#define KING_H

#include <QObject>
#include "chessman.h"
class King : public chessman
{
    Q_OBJECT
public:
    explicit King(QObject *parent = nullptr);

signals:

};

#endif // KING_H
