#ifndef USERVERIFICATION_H
#define USERVERIFICATION_H

#include <QDialog>
#include "usermainwindow.h"

namespace Ui {
class UserVerification;
}

class UserVerification : public QDialog
{
    Q_OBJECT

public:
    explicit UserVerification(QWidget *parent = 0);
    ~UserVerification();

private slots:
    void on_enterBtn_clicked();
    void on_resetBtn_clicked();

private:
    Ui::UserVerification *ui;
    UserMainWindow *userInterface;
};

#endif // USERVERIFICATION_H
