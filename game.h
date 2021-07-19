#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    void setTitle(const QString &);
    void setWhite(const QString &);
    void setBlack(const QString &);
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    QString black;
    QString white;
    QString title;
};
#endif // GAME_H
