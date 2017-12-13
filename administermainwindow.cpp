#include "administermainwindow.h"
#include "ui_administermainwindow.h"
#include <QtDebug>
#include "processthread.h"

AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministerMainWindow)
{
    ui->setupUi(this);


    /** 流程执行线程启动 **/
    if(!ProcessThread::getInstance()->getStatus())
        ProcessThread::getInstance()->start();
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
