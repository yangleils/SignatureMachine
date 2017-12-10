#include "ssql.h"


SSQL::SSQL(QWidget *parent) :
    QMainWindow(parent)
{
    view = new QTableView;
    Hname->addWidget(checkNameBox);
    Hname->addWidget(NameEdit);
    Htype->addWidget(checkTypeBox);
    Htype->addWidget(TypeEdit);
    Htime->addWidget(checktimeBox);
    Htime->addWidget(FromTime);
    Htime->addWidget(l);
    Htime->addWidget(ToTime);
    Select->addLayout(Hname);
    Select->addLayout(Htype);
    Select->addLayout(Htime);
    Select->addWidget(CaseSelectButton);
    Select->addWidget(SelectAll);
    Select->addWidget(view);
    w->setLayout(Select);
    w->show();
    NameEdit->setEnabled(false);
    TypeEdit->setEnabled(false);
    ToTime->setEnabled(false);
    FromTime->setEnabled(false);
    QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(showpictures(const QModelIndex &)));
    QObject::connect(checkNameBox,SIGNAL(stateChanged(int)),this,SLOT(on_checkNameBox_stateChanged(int)));
    QObject::connect(checkTypeBox,SIGNAL(stateChanged(int)),this,SLOT(on_checkTypeBox_stateChanged(int)));
    QObject::connect(checktimeBox,SIGNAL(stateChanged(int)),this,SLOT(on_checktimeBox_stateChanged(int)));
    QObject::connect(SelectAll,SIGNAL(clicked(bool)),this,SLOT(on_SelectAll_clicked()));
    QObject::connect(CaseSelectButton,SIGNAL(clicked(bool)),this,SLOT(on_CaseSelectButton_clicked()));
    connect("signaturemachine");
    //地址中具体反斜杠的位置和个数，出现反斜杠的位置出现问题
    insert(tr("No1"),
           tr("education"),
           3,
           0,
           "NULL",
           "\\\\image"
           );
}

SSQL::~SSQL()
{
}

bool SSQL::connect(const QString &dbname)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName(dbname);
    db.setUserName("root");
    db.setPassword("mysql123");
    //db.open();
    if(!db.open()){
        QMessageBox::warning(NULL, "warning", "con't connect the mysql", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    else
    {
        return true;
    }
}


void SSQL::insert(const QString &name,
                  const QString &type,
                  const int num,
                  const int again,
                  const QString &reason,
                  const QString &image)
{
    QString time = "NULL";
    QString sql = QString("insert into memoryseal values(NULL,'"
                          + name + "','"
                          + type + "',"
                          + time + ","
                          + QString::number(num) + ","
                          + QString::number(again)+ ",'"
                          + reason + "','"
                          + image+"')"
                          );
    QSqlQuery query;
    if(query.exec(sql))
    {
        qDebug()<<"insert successful"<<endl;
    }
}

void SSQL::search()
{
    if (connect("signaturemachine"))
    {
        model = new QSqlTableModel;
        model->setTable("memoryseal");
        model->setSort(1, Qt::AscendingOrder);
        model->setHeaderData(1, Qt::Horizontal, tr("name"));
        model->setFilter(Selectcase);
        model->select();
        view->setModel(model);
        view->setSelectionMode(QAbstractItemView::SingleSelection);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        //表格宽带适合其中内容
        view->resizeColumnsToContents();
        //设置不可编辑表格内容
        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        view->setColumnHidden(0,true);
        view->show();
        Select->update();
        w->update();
    }
}



void SSQL::showpictures(const QModelIndex &)
{
    QModelIndex index = view->currentIndex();
    QSqlRecord record = model->record(index.row());
    QString data = record.value("image").toString();
    data = pPathselect+data;
    qDebug() << data << endl;
    QPixmap image_before;
    QPixmap image_after;
    image_before.load(data+"\\before.jpg");
    qDebug() << data+"\\before.image" <<endl;
    image_after.load(data+"\\after.jpg");
    QWidget *pic = new QWidget;
    pic->setWindowTitle(tr("盖章前和盖章后的图片"));
    QLabel *before = new QLabel;
    QLabel *after = new QLabel;
    before->setMinimumSize(600,600);
    after->setMinimumSize(600,600);
    before->clear();
    after->clear();
    before->setPixmap(image_before);
    after->setPixmap(image_after);
    before->show();
    after->show();
    QHBoxLayout *Hlayout_pic = new QHBoxLayout;
    Hlayout_pic->addWidget(before);
    Hlayout_pic->addWidget(after);
    pic->setLayout(Hlayout_pic);
    pic->show();

}



void SSQL::on_SelectAll_clicked()
{
    search();

}

void SSQL::on_CaseSelectButton_clicked()
{
    QString name = NameEdit->text();
    QString type = TypeEdit->text();
    QString Fromtime = FromTime->text();
    //QString FromtimeString = Fromtime.toString("yyyy-MM-dd hh:mm:ss");
    QString Totime = ToTime->text();
    //QString TotimeString = Totime.toString("yyyy-MM-dd hh:mm:ss");
    if(checkNameBox->isChecked())
    {
        //if(Selectcase != NULL)Selectcase += "and ";
        Selectcase = "name = '" + name + "'";
    }
    if(checkTypeBox->isChecked())
    {
        if(Selectcase != NULL)Selectcase += "and ";
        Selectcase += "type = '" + type + "'";
    }
    if(checktimeBox->isChecked())
    {
        if(Selectcase != NULL)Selectcase += "and ";
        Selectcase += "time > '" + Fromtime + "'" + "and " + "time < '" + Totime + "'";
    }
    qDebug() << Selectcase <<endl;
    search();
    Select->update();
    Selectcase.clear();
}

void SSQL::on_checkNameBox_stateChanged(int arg1)
{
    if(checkNameBox->isChecked())
    {
        NameEdit->setEnabled(true);
    }
    else
    {
        NameEdit->setEnabled(false);
    }
}

void SSQL::on_checkTypeBox_stateChanged(int arg1)
{
    if(checkTypeBox->isChecked())
    {
        TypeEdit->setEnabled(true);
    }
    else
    {
        TypeEdit->setEnabled(false);
    }
}

void SSQL::on_checktimeBox_stateChanged(int arg1)
{
    if(checktimeBox->isChecked())
    {
        FromTime->setEnabled(true);
        ToTime->setEnabled(true);
    }
    else
    {
        FromTime->setEnabled(false);
        ToTime->setEnabled(false);
    }
}
