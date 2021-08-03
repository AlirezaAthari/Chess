#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "game.h"
#include "ui_login.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    Game *g;
};

#endif // LOGIN_H
