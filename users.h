#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "userverification.h"
#include "adverification.h"

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = 0);
    ~Users();

private slots:
    void on_administerBtn_clicked();
    void on_userBtn_clicked();

private:
    UserVerification *user;
    AdVerification *administer;
    Ui::Users *ui;
};

#endif // USERS_H
