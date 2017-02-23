#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

/**函数介绍：创建数据库连接**/
static bool createConnection(QString hostName,QString databaseName,QString uid,QString pwd,QSqlDatabase &db)
{
    db = QSqlDatabase::addDatabase("QODBC");
    // 注意,对于express版本数据库, 一定要加后缀 SERVER=服务器名\\sqlexpress
    QString dsn = QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;"
                               "DATABASE=%2;").arg(hostName).arg(databaseName);
    db.setDatabaseName(dsn);            //数据库名,SQL server2008需要使用DSN字符串形式设置数据库名称
    db.setUserName(uid);                //登录名UID
    db.setPassword(pwd);                //密码PWD
    db.setHostName(hostName);           //数据库服务器

    if(!db.open())
    {
        QSqlError error = db.lastError();
        QMessageBox::warning (0, "Warning", QString("Failed to open database! Error: %1").arg(error.text()));
        return false;
    }
    return true;
}

#endif // CONNECTION_H
