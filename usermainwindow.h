#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include "ssql.h"
#include <QTimer>

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = 0);
    ~UserMainWindow();

private slots:
    void on_pushButton_clicked();

    void updateInterface();

private:
    Ui::UserMainWindow *ui;
    // SSQL* dataBase;

    /**   界面更新定时器  **/
    QTimer *updateTimer;
};

#endif // USERMAINWINDOW_H
