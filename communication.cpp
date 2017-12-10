#include "communication.h"
#include "ui_communication.h"
#include <QMessageBox>
#include "adverification.h"
#include "userverification.h"

Communication* Communication::singleton = 0;

Communication::Communication(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Communication)
{
    ui->setupUi(this);

    // 二维码扫描仪通信参数初始化
    ui->QRcodeBuadrateComboBox->setCurrentIndex(3);
    ui->QRcodeDataBitComboBox->setCurrentIndex(3);
    ui->QRcodeStopBitComboBox->setCurrentIndex(0);
    ui->QRcodeParityBitComboBox->setCurrentIndex(2);

    // 下位机通信参数初始化
    ui->systemBuadrateComboBox->setCurrentIndex(3);
    ui->systemDataBitComboBox->setCurrentIndex(3);
    ui->systemStopBitComboBox->setCurrentIndex(0);
    ui->systemParityBitComboBox->setCurrentIndex(2);

    // 串口对象初始化
    QRcodeSerialPort = NULL;
    systemSerialPort = NULL;

    // 自动添加本机串口设备
    portList = QSerialPortInfo::availablePorts();
    for(int i=0; i<portList.size(); i++)
    {
       ui->QRcodeSerialPortComboBox->addItem(portList.at(i).portName());
       ui->systemSerialPortComboBox->addItem(portList.at(i).portName());
    }


    ui->connectPushButton->setEnabled(true);
    ui->resetPushButton->setEnabled(false);
}

Communication::~Communication()
{
    if(QRcodeSerialPort->isOpen())
        QRcodeSerialPort->close();
    if(systemSerialPort->isOpen())
        systemSerialPort->close();
    if(!QRcodeSerialPort)
    {
        delete QRcodeSerialPort;
        QRcodeSerialPort = NULL;
    }
    if(!systemSerialPort)
    {
        delete systemSerialPort;
        systemSerialPort = NULL;
    }
    delete ui;
}


void Communication::on_connectPushButton_clicked()
{
    QRcodeSerialPort = new QSerialPort(ui->QRcodeSerialPortComboBox->currentText());
    bool QRcodeState = QRcodeSerialPort->open(QIODevice::ReadWrite);

    systemSerialPort = new QSerialPort(ui->systemSerialPortComboBox->currentText());
    bool systemState = systemSerialPort->open(QIODevice::ReadWrite);

    if(QRcodeState && systemState)
    {
        QMessageBox::information(this, tr("提示信息"), tr("系统通信建立成功"), QMessageBox::Ok);
        // 按键状态转换
        ui->connectPushButton->setEnabled(false);
        ui->resetPushButton->setEnabled(true);
        if(AdVerification::isCkecked)
        {
            administerInterface = new AdministerMainWindow();
            administerInterface->show();
            this->hide();
            return;
        }
        else if(UserVerification::isChecked)
        {
            userInterface = new UserMainWindow();
            userInterface->show();
            this->hide();
            return;
        }
    }
    else
    {
        if(QRcodeSerialPort->isOpen())
            QRcodeSerialPort->close();
        if(systemSerialPort->isOpen())
            systemSerialPort->close();

        if(!QRcodeSerialPort)
        {
            delete QRcodeSerialPort;
            QRcodeSerialPort = NULL;
        }
        if(!systemSerialPort)
        {
            delete systemSerialPort;
            systemSerialPort = NULL;
        }
        QMessageBox::warning(this, tr("提示信息"), tr("系统通信建立失败"), QMessageBox::Ok);

    }

}

void Communication::on_resetPushButton_clicked()
{
    // 二维码扫描仪通信参数初始化
    ui->QRcodeBuadrateComboBox->setCurrentIndex(3);
    ui->QRcodeDataBitComboBox->setCurrentIndex(3);
    ui->QRcodeStopBitComboBox->setCurrentIndex(0);
    ui->QRcodeParityBitComboBox->setCurrentIndex(2);

    // 下位机通信参数初始化
    ui->systemBuadrateComboBox->setCurrentIndex(3);
    ui->systemDataBitComboBox->setCurrentIndex(3);
    ui->systemStopBitComboBox->setCurrentIndex(0);
    ui->systemParityBitComboBox->setCurrentIndex(2);


    // 关闭并释放串口对象
    if(QRcodeSerialPort->isOpen())
        QRcodeSerialPort->close();
    if(systemSerialPort->isOpen())
        systemSerialPort->close();

    if(!QRcodeSerialPort)
    {
        delete QRcodeSerialPort;
        QRcodeSerialPort = NULL;
    }
    if(!systemSerialPort)
    {
        delete systemSerialPort;
        systemSerialPort = NULL;
    }

    // 按键状态转换
    ui->connectPushButton->setEnabled(false);
    ui->resetPushButton->setEnabled(true);
}
