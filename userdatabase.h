#ifndef USERDATABASE_H
#define USERDATABASE_H


#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>

static bool userCreateConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open user database","Unable to establish a database connection.",QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("select * from user");
    query.next();


    if(query.value(0).toString().size()==0)
    {
        query.exec("create table user(name varchar(20) primary key, password varchar(20))");
        query.exec("insert into user values('user', 'user')");
    }

    return true;
}



#endif // USERDATABASE_H
