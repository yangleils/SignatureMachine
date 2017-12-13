#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "userverification.h"
#include "adverification.h"
#include "administermainwindow.h"
#include "usermainwindow.h"

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

    // 用户、管理员身份认证对象
    UserVerification *user;
    AdVerification *administer;
    Ui::Users *ui;

    /** 静态全局变量定义 **/
public:
    // 用户、管理员界面对象
    static AdministerMainWindow *administerInterface;
    static UserMainWindow *userInterface;

    // 用户身份标识  ====> true:个人用户    false:管理员
    static bool identityFlag;

};

#endif // USERS_H
