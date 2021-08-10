#include "replacepawn.h"
#include "ui_replacepawn.h"
#include "globals.h"

ReplacePawn::ReplacePawn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplacePawn)
{
    ui->setupUi(this);
}

ReplacePawn::~ReplacePawn()
{
    delete ui;
}

void ReplacePawn::on_comboBox_activated(int index)
{
    choosen = index;
}


void ReplacePawn::on_buttonBox_accepted()
{
    replacePawnChoose = choosen;
}

