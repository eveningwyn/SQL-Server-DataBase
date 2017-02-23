#include "logindlg.h"
#include "ui_logindlg.h"
#include <QSqlQuery>
#include <QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
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

void LoginDlg::on_cancelBtn_clicked()
{
    close();
}
