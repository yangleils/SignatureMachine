#include "users.h"
#include "ui_users.h"
#include "userverification.h"
#include "adverification.h"


Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
    user = new UserVerification();
    administer = new AdVerification();
    this->setWindowTitle(tr("盖章信息管理系统"));
}

Users::~Users()
{
    delete ui;
}

void Users::on_administerBtn_clicked()
{
    administer->show();
    this->hide();
}

void Users::on_userBtn_clicked()
{
    user->show();
    this->hide();
}
