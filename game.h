#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
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
    void changeTurn ();
    QString getTurn();
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    QString black;
    QString white;
    QString title;
    QString turn = "White";
};
#endif // GAME_H
