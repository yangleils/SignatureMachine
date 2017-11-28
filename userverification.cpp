#include "userverification.h"
#include "ui_userverification.h"
#include "userdatabase.h"


UserVerification::UserVerification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserVerification)
{
    ui->setupUi(this);
    userInterface = new UserMainWindow();
    this->setWindowTitle(tr("身份验证"));
}

UserVerification::~UserVerification()
{
    delete ui;
}

void UserVerification::on_enterBtn_clicked()
{
    if(!userCreateConnection())
        return;

    QSqlQuery query;
    query.exec("select * from user");
    while(query.next())
    {
        qDebug()<<query.value(0).toString()<<query.value(1).toString();
        if(query.value(0).toString() == ui->userNameLineEdit->text())
        {
           if((query.value(1).toString() == ui->passwordLineEdit->text()))
           {
              accept();
              userInterface->show();
              this->hide();
           }
           else
               QMessageBox::warning(this, "Notification", "Password error, Please try again", QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this, "Notification", "Username error, Please try again", QMessageBox::Ok);
    }
}

void UserVerification::on_resetBtn_clicked()
{
    ui->userNameLineEdit->clear();
    ui->passwordLineEdit->clear();
}
