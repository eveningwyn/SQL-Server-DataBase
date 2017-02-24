#include "logindlg.h"
#include "ui_logindlg.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "configfile.h"
#include "connection.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    ui->serverConfigWidget->hide();
    ishide = false;
    updateConfig();
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_loginBtn_clicked()
{
    QString userName = ui->userNameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.exec("select UserID,PWD from account");

    while(query.next())
    {
        accept();
        return;
        if((userName==query.value("UserID").toString()) && (password==query.value("PWD").toString()))
        {
            accept();
            return;
        }
    }

    QMessageBox::warning(this, tr("Waring"),tr("User name or Password error!"),QMessageBox::Yes);
    ui->userNameLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->userNameLineEdit->setFocus();
}

void LoginDlg::updateConfig()
{
    QString hostName;
    QString databaseName;
    QString uid;
    QString pwd;
    configOut(hostName,databaseName,uid,pwd);

    ui->serverNameLineEdit->setText(hostName);
    ui->databaseLineEdit->setText(databaseName);
    ui->uidLineEdit->setText(uid);
    ui->pwdLineEdit->setText(pwd);
}

void LoginDlg::on_cancelBtn_clicked()
{
    close();
}

void LoginDlg::on_configBtn_clicked()
{
    if(false == ishide)
    {
        updateConfig();
        ui->serverConfigWidget->show();
        ishide = true;
    }
    else
    {
        ui->serverConfigWidget->hide();
        ishide = false;
    }
}

void LoginDlg::on_setParametesBtn_clicked()
{
    QString hostName = ui->serverNameLineEdit->text();
    QString databaseName = ui->databaseLineEdit->text();
    QString uid = ui->uidLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();

    QSqlDatabase db;                            //保存所连接的数据库对象
    if(!createConnection(hostName,databaseName,uid,pwd,db))
        return;

    if(QMessageBox::Ok == QMessageBox::warning(this, tr("Waring"),tr("Please confirm whether or not to configure the database parameters!"),QMessageBox::Ok|QMessageBox::Cancel))
    {
        configIn(hostName,databaseName,uid,pwd);
        QMessageBox::warning(this, tr("Waring"),tr("The database configuration parameter has been updated!"),QMessageBox::Ok);
        return;
    }
}
