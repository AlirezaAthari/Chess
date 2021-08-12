#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include <QGraphicsView>
#include "chessboard.h"
#include "cell.h"
#include <QAbstractScrollArea>
#include "ui_game.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "rook.h"
#include <QGraphicsScene>
#include "qabstractscrollarea.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Game;
}
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    void setBoard();
    void setWhiteMans();
    void setBlackMans();
    void addPieceToDeaths(chessman *);
    void addPiece(); //This function adds the pieces to each chess house after hitting the start button .
    void endGame();
    void openReplacePawn();
    Game(QString, QString, QString, QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_startPushButton_clicked();

    void on_undoPushButton_clicked();

    void on_resetPushButton_clicked();
    void on_replacePawnPushButton_clicked();

private:
    Ui::Game *ui;
    ChessBoard *cb;
    QVector<QVector<Cell *>> board;
    QList<chessman *> whites;
    QList<chessman *> blacks;
};
#endif // GAME_H
