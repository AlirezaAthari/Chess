#include "login.h"
#include "ui_login.h"
#include "game.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    g = new Game(this);
    g->show();
    QString b = ui->black->text();
    QString w = ui->white->text();
    QString t = ui->title->text();
    g->setBlack(b);
    g->setWhite(w);
    g->setTitle(t);
    hide();
}

