#include "login.h"
#include "qdebug.h"

Login::Login(QWidget *parent) : QDialog(parent),
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
    QString b = ui->black->text();
    QString w = ui->white->text();
    QString t = ui->title->text();
    g = new Game(t, w, b, this);
    g->show();
    hide();
}
