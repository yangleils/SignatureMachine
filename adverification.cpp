#include "adverification.h"
#include "ui_adverification.h"
#include "administerdatabase.h"


AdVerification::AdVerification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdVerification)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("身份验证"));
    administerInterface = new AdministerMainWindow();
}

AdVerification::~AdVerification()
{
    delete ui;
}

void AdVerification::on_enterBtn_clicked()
{


    if(!administerCreateConnection())
        return;

    QSqlQuery query;
    query.exec("select * from administer");
    while(query.next())
    {
        qDebug()<<query.value(0).toString()<<query.value(1).toString();
        if(query.value(0).toString() == ui->userNameLineEdit->text())
        {
           if((query.value(1).toString() == ui->passwordLineEdit->text()))
           {
              accept();
              administerInterface->show();
              this->hide();
           }
           else
               QMessageBox::warning(this, "Notification", "Password error, Please try again", QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this, "Notification", "Username error, Please try again", QMessageBox::Ok);
    }

}

void AdVerification::on_resetBtn_clicked()
{
    ui->userNameLineEdit->clear();
    ui->passwordLineEdit->clear();
}
