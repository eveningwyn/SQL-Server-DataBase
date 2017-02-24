#include "warehousemanager.h"
#include <QApplication>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "logindlg.h"
#include "configfile.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString hostName;//服务器名称
    QString databaseName;//数据库名称
    QString uid;//登录名
    QString pwd;//登录密码
    configOut(hostName,databaseName,uid,pwd);

    QSqlDatabase db;//保存所连接的数据库对象
    if(!createConnection(hostName,databaseName,uid,pwd,db))
    {}

    WarehouseManager w;
    LoginDlg dlg;
    if(dlg.exec() == QDialog::Accepted) // 利用Accepted返回值判断按钮是否被按下
    {
        w.initialize();
        w.show();                      // 如果被按下，显示主窗口
        return a.exec();               // 程序一直执行，直到主窗口关闭
    }
    else
        return 0;
}
