#include "game.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // qt creator
    Login w; // We create an object from the login class
    w.show(); // to show the window of login
    return a.exec();
}
