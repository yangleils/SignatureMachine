#ifndef SSQL_H
#define SSQL_H

#include <QMainWindow>
#include <QTableView>
#include <QSqlTableModel>
#include <QDateTime>
#include <QImage>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QMessageBox>
#include <QSqlRecord>
#include <QTextCodec>
#include <QPixmap>
#include <QTimeEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QGridLayout>

namespace Ui {
class SSQL;
}

class SSQL : public QMainWindow
{
    Q_OBJECT

public:
    explicit SSQL(QWidget *parent = 0);
    ~SSQL();

    QWidget *w = new QWidget;
    QCheckBox *checkNameBox = new QCheckBox(tr("name"));
    QLineEdit *NameEdit = new QLineEdit;
    QCheckBox *checkTypeBox = new QCheckBox(tr("type"));
    QLineEdit *TypeEdit = new QLineEdit;
    QCheckBox *checktimeBox = new QCheckBox(tr("time_span"));
    QDateTimeEdit *FromTime = new QDateTimeEdit;
    QLabel *l = new QLabel("to");
    QDateTimeEdit *ToTime = new QDateTimeEdit;
    QPushButton *CaseSelectButton = new QPushButton(tr("search"));
    QPushButton *SelectAll = new QPushButton(tr("search_all"));
    QHBoxLayout *Hname = new QHBoxLayout;
    QHBoxLayout *Htype = new QHBoxLayout;
    QHBoxLayout *Htime = new QHBoxLayout;
    QVBoxLayout *Select = new QVBoxLayout;
    bool connect(const QString &dbname);
    QString Selectcase = NULL;
    QString pPathselect = "E:\\SoftWare\\Qt\\SignatureMachine-master";


public slots:
    void insert(const QString &name,
                const QString &type,
                const int num,
                const int again,
                const QString &reason,
                const QString &image);
    void search();

private:
    QTableView *view;
    QSqlTableModel *model;

public slots:
    void showpictures(const QModelIndex &);

private slots:
    void on_SelectAll_clicked();
    void on_CaseSelectButton_clicked();
    void on_checkNameBox_stateChanged(int arg1);
    void on_checkTypeBox_stateChanged(int arg1);
    void on_checktimeBox_stateChanged(int arg1);
};

#endif // SSQL_H
