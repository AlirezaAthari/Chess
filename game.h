#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include "chessboard.h"
#include "cell.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    void setBoard();
    void setTitle(const QString &);
    void setWhite(const QString &);
    void setBlack(const QString &);
    void changeTurn ();
    QString getTurn();
    void setWhiteMans();
    void setBlackMans();
    void addPieceToDeaths(chessman *);
    void addPiece();
    void reset();
    void endGame();
    QList <chessman *> alives;
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Game *ui;
    QString black;
    QString white;
    QString title;
    QString turn = "White";
    ChessBoard * cb;
    QGraphicsScene chessScene;
    QList <chessman *> whites;
    QList <chessman *> blacks;
    QList <chessman *> blackDeaths;
    QList <chessman *> whiteDeaths;
};
#endif // GAME_H
