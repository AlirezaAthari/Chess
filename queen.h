#ifndef QUEEN_H
#define QUEEN_H

#include <QObject>
#include "chessman.h"
class Queen : public chessman
{
    Q_OBJECT
public:
    explicit Queen(QObject *parent = nullptr);

signals:

};

#endif // QUEEN_H
