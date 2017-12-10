#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "administermainwindow.h"
#include "usermainwindow.h"

namespace Ui {
class Communication;
}

class Communication : public QMainWindow
{
    Q_OBJECT

public:    
    static Communication* getInstance()
    {
        if(singleton == 0)
            singleton = new Communication();
        return singleton;
    }

    static void destory()
    {
        if(singleton != 0)
        {
            delete singleton;
            singleton = 0;
        }
    }

    /** 类属成员函数定义 **/
    // 下位机相关

    // 二维码扫描仪相关

    // 相机相关

    // 统一接口封装


private:
    explicit Communication(QWidget *parent = 0);
    ~Communication();

private slots:
    void on_connectPushButton_clicked();
    void on_resetPushButton_clicked();

private:
    Ui::Communication *ui;

    /** 串口对象定义 **/
    QSerialPort *QRcodeSerialPort;
    QSerialPort *systemSerialPort;

    // 自动添加本机串口设备
    QList<QSerialPortInfo> portList;

    // 单例对象指针
    static Communication* singleton;

    // 用户、管理员界面对象
    AdministerMainWindow *administerInterface;
    UserMainWindow *userInterface;
};

#endif // COMMUNICATION_H
