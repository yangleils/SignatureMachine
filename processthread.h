#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QString>


/** 二维码信息结构体定义 **/
struct QRcodeMessage
{
    QString receivedString;   // 二维码扫描仪上传信息
    QString proposer;         // 申请人
    QString sealType;         // 盖章类型
    int totalNumber;          // 盖章总次数
    int remainingNumber;      // 盖章剩余次数
};

/** 系统状态结构体定义 **/
struct SystemStatus
{
  bool QRcodeScanner;
  bool camera;
  bool slaveSystem;
};

/** 执行流程结构体定义 **/
struct OperatingProcess
{
    bool stage001;          // 读取并识别二维码信息
    bool stage002;          // 等待系统准备完毕
    bool stage003;
    bool stage004;
    bool stage005;
    bool stage006;
};


class ProcessThread : public QThread
{
public:
    void stop(){stopped = true;}

    bool getStatus()
    {
        return stopped;
    }


    static ProcessThread* getInstance()
    {
        if(singleton == 0)
            singleton = new ProcessThread();
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

    // 结构对象定义
    static struct SystemStatus *system;
    static struct OperatingProcess *operation;
    static struct QRcodeMessage *QRcode;

protected:
    void run();

private:
    ProcessThread();
    static ProcessThread* singleton;
    volatile bool stopped;
};

#endif // PROCESSTHREAD_H
