#include "users.h"
#include "ui_users.h"
#include "userverification.h"
#include "adverification.h"

/** 静态全局变量初始化 **/
bool Users::identityFlag = true;
AdministerMainWindow* Users::administerInterface = NULL;
UserMainWindow* Users::userInterface = NULL;

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);

    // 身份验证窗口
    user = new UserVerification();
    administer = new AdVerification();

    // 界面操作窗口
    administerInterface = new AdministerMainWindow();
    userInterface = new UserMainWindow();

    // 标题
    this->setWindowTitle(tr("盖章信息管理系统"));
}

Users::~Users()
{
    delete ui;
}

void Users::on_administerBtn_clicked()
{
    identityFlag = false;
    administer->show();
    this->hide();
}

void Users::on_userBtn_clicked()
{
    user->show();
    this->hide();
}
