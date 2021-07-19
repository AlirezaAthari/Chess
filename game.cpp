#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
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

