#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include <QGraphicsView>
#include "chessboard.h"
#include "cell.h"
#include <QAbstractScrollArea>
#include "ui_game.h"
#include "chessboard.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "rook.h"
#include <QGraphicsScene>

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
    void setWhiteMans();
    void setBlackMans();
    void addPieceToDeaths(chessman *);
    void addPiece();
    void reset();
    void endGame();
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_startPushButton_clicked();

    void on_undoPushButton_clicked();

    void on_resetPushButton_clicked();

private:
    Ui::Game *ui;
    QString black;
    QString white;
    QString title;
    ChessBoard * cb;
    QGraphicsScene *chessScene;
    QList <chessman *> whites;
    QList <chessman *> blacks;/*
    QList <chessman *> blackDeaths;
    QList <chessman *> whiteDeaths;*/
};
#endif // GAME_H
