#include "processthread.h"
#include <QDebug>


ProcessThread* ProcessThread::singleton = NULL;



struct OperatingProcess* ProcessThread::operation = NULL;
struct QRcodeMessage* ProcessThread::QRcode = NULL;
struct SystemStatus* ProcessThread::system = NULL;

ProcessThread::ProcessThread()
{
    stopped = false;
    /** 结构体对象初始化 **/

    // 系统状态信息
    system = new SystemStatus();
    system->camera = false;
    system->QRcodeScanner = false;
    system->slaveSystem = false;

    // 执行进程初始化
    operation = new OperatingProcess();
    operation->stage001 = true;
    operation->stage002 = false;
    operation->stage003 = false;
    operation->stage004 = false;
    operation->stage005 = false;
    operation->stage006 = false;

    // 二维码信息初始化
    QRcode = new QRcodeMessage();
    QRcode->proposer = "";
    QRcode->remainingNumber = 0;
    QRcode->sealType = "";
    QRcode->totalNumber = 0;
}

void ProcessThread::run()
{
    while(!stopped)
    {
        /** 接受下位机系统信息 **/


        /** 接受并更新二维码扫描仪的上传信息


        /** 流程执行部分 **/
        if(operation->stage001)
        {



            // 进程变量状态更新
            operation->stage001 = false;
            operation->stage002 = true;
            operation->stage003 = false;
            operation->stage004 = false;
            operation->stage005 = false;
            operation->stage006 = false;
        }
        else if(operation->stage002)
        {



            // 进程变量状态更新
            operation->stage001 = false;
            operation->stage002 = false;
            operation->stage003 = true;
            operation->stage004 = false;
            operation->stage005 = false;
            operation->stage006 = false;
        }
        else if(operation->stage003)
        {


            // 进程变量状态更新
            operation->stage001 = false;
            operation->stage002 = false;
            operation->stage003 = false;
            operation->stage004 = true;
            operation->stage005 = false;
            operation->stage006 = false;
        }
        else if(operation->stage004)
        {


            // 进程变量状态更新
            operation->stage001 = false;
            operation->stage002 = false;
            operation->stage003 = false;
            operation->stage004 = false;
            operation->stage005 = true;
            operation->stage006 = false;
        }
        else if(operation->stage005)
        {


            // 进程变量状态更新
            operation->stage001 = false;
            operation->stage002 = false;
            operation->stage003 = false;
            operation->stage004 = false;
            operation->stage005 = false;
            operation->stage006 = true;
        }
        else if(operation->stage006)
        {


            // 进程变量状态更新
            operation->stage001 = true;
            operation->stage002 = false;
            operation->stage003 = false;
            operation->stage004 = false;
            operation->stage005 = false;
            operation->stage006 = false;
        }
    }
    stopped = false;
}
