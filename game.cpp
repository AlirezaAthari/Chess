#include "game.h"
#include <QAbstractScrollArea>
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->title->setText(title);
    ui->player_2->setText(black);
    ui->player_1->setText(white);
    ui->turn->setText(turn);
}

Game::~Game()
{
    delete ui;
}

void Game::setBlack(const QString & b)
{
    black = b;
}

void Game::setWhite(const QString & w)
{
    white = w;
}

void Game::setTitle(const QString & t)
{
    title = t;
}

void Game::changeTurn()
{
    if(getTurn() == "Black")
        turn = "White";
    else turn = "Black";
}

QString Game::getTurn()
{
    return  turn;
}


