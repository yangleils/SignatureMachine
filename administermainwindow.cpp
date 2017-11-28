#include "administermainwindow.h"
#include "ui_administermainwindow.h"
#include <QtDebug>

AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministerMainWindow)
{
    ui->setupUi(this);


}

AdministerMainWindow::~AdministerMainWindow()
{
    delete ui;
}

void AdministerMainWindow::on_pushButton_3_clicked()
{
    ui->progressBar->setValue(100);
    qDebug() << "testing...";
}
