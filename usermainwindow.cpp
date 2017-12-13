#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "processthread.h"
#include <QDebug>

using namespace cv;
using namespace std;

UserMainWindow::UserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    // dataBase = new SSQL();

    /** 界面更新定时器初始化  **/
    updateTimer = new QTimer();
    updateTimer->start(100);     // 每100ms更新一次

    /** 流程执行线程启动 **/
    if(!ProcessThread::getInstance()->getStatus())
        ProcessThread::getInstance()->start();


    /** 信号与槽函数关联 **/
    QObject::connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateInterface()));
}

UserMainWindow::~UserMainWindow()
{
    delete ui;
}

void UserMainWindow::on_pushButton_clicked()
{
    /**
    string imagePath = "C:\\Users\\yanglei\\Desktop\\SignatureMachine\\image.jpg";
    Mat img = imread(imagePath);
    imshow("imageTest", img);
    waitKey();
    return;
    **/
    // dataBase->search();
}

void UserMainWindow::updateInterface()
{

    // 二维码解析信息更新
    ui->QRcodelineEdit->setText(ProcessThread::QRcode->receivedString);
    ui->proposerLineEdit->setText(ProcessThread::QRcode->proposer);
    ui->sealTypeLineEdit->setText(ProcessThread::QRcode->sealType);
    ui->totalNumberLineEdit->setText(QString::number(ProcessThread::QRcode->totalNumber));
    ui->remainingNumberLineEdit->setText(QString::number(ProcessThread::QRcode->remainingNumber));

    // 盖章进度信息更新
    ui->progressBar->setMaximum(ProcessThread::QRcode->totalNumber);
    ui->progressBar->setValue(ProcessThread::QRcode->totalNumber - ProcessThread::QRcode->remainingNumber);

    // 系统通信状态更新
    if(ProcessThread::system->QRcodeScanner)
    {
        ui->QRcodeScannerLabel->setText(tr("通信正常"));
    }
    else
    {
        ui->QRcodeScannerLabel->setText(tr("通信异常"));
    }
    if(ProcessThread::system->camera)
    {
        ui->cameraLabel->setText(tr("通信正常"));
    }
    else
    {
        ui->cameraLabel->setText(tr("通信异常"));
    }
    if(ProcessThread::system->slaveSystem)
    {
        ui->slaveSystemLabel->setText(tr("通信正常"));
    }
    else
    {
        ui->slaveSystemLabel->setText(tr("通信异常"));
    }
}
