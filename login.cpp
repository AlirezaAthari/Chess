#include "login.h"
#include "qdebug.h"
#include "QMessageBox"

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
     if (b != "" && w != "" && t != "")
     {
         g = new Game(t, w, b, this);
         g->show(); // to show a game window
         hide(); // exit the login window
     }
     else // If the users name and title box is empty, this message will be printed
     {
         QMessageBox error;
         error.setText("Please fill all of the blanks!");
         error.exec();
         return;
     }
}
