#ifndef BISHOP_H
#define BISHOP_H

#include <QObject>
#include "chessman.h"

class Bishop : public chessman
{
    Q_OBJECT
public:
    explicit Bishop(QObject *parent = nullptr);

signals:

};

#endif // BISHOP_H
