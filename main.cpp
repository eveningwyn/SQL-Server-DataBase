#include "warehousemanager.h"
#include <QApplication>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "logindlg.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db;                            //保存所连接的数据库对象
    QString hostName = QString("A0601020160");  //服务器名称
    QString databaseName = QString("dbtemp");   //数据库名称
    QString uid = QString("testUser");          //登录名
    QString pwd = QString("123456");            //登录密码
    if(!createConnection(hostName,databaseName,uid,pwd,db))
        return -1;

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
