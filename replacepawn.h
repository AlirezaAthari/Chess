#ifndef REPLACEPAWN_H
#define REPLACEPAWN_H

#include <QDialog>

namespace Ui {
class ReplacePawn;
}

class ReplacePawn : public QDialog
{
    Q_OBJECT

public:
    explicit ReplacePawn(QWidget *parent = nullptr);
    ~ReplacePawn();

private slots:
    void on_comboBox_activated(int index);

    void on_buttonBox_accepted();

private:
    Ui::ReplacePawn *ui;
    int choosen;
};

#endif // REPLACEPAWN_H
