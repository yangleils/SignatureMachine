#ifndef ADMINISTERDATABASE_H
#define ADMINISTERDATABASE_H


#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>

static bool administerCreateConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("administer.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open administer database","Unable to establish a database connection.",QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("select * from administer");
    query.next();


    if(query.value(0).toString().size()==0)
    {
        query.exec("create table administer(name varchar(20) primary key, password varchar(20))");
        query.exec("insert into administer values('administer', 'administer')");
    }

    return true;
}


#endif // ADMINISTERDATABASE_H
