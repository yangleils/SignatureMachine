#ifndef ADVERIFICATION_H
#define ADVERIFICATION_H

#include <QDialog>
#include "administermainwindow.h"

namespace Ui {
class AdVerification;
}

class AdVerification : public QDialog
{
    Q_OBJECT

public:
    explicit AdVerification(QWidget *parent = 0);
    ~AdVerification();

private slots:
    void on_enterBtn_clicked();
    void on_resetBtn_clicked();

private:
    Ui::AdVerification *ui;
    AdministerMainWindow *administerInterface;
};

#endif // ADVERIFICATION_H
