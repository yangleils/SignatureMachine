#ifndef ADMINISTERMAINWINDOW_H
#define ADMINISTERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdministerMainWindow;
}

class AdministerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministerMainWindow(QWidget *parent = 0);
    ~AdministerMainWindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::AdministerMainWindow *ui;
};

#endif // ADMINISTERMAINWINDOW_H
