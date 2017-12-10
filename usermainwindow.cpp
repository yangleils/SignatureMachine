#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

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
    ;

}
