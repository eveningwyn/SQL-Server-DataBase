#include "warehousemanager.h"
#include "ui_warehousemanager.h"
#include <QDateTime>
#include <QMessageBox>
#include <QSqlError>
#include "newproductdialog.h"
#include "newclientdialog.h"
#include "selldialog.h"

WarehouseManager::WarehouseManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WarehouseManager)
{
    ui->setupUi(this);
}

WarehouseManager::~WarehouseManager()
{
    delete ui;
}

void WarehouseManager::initStorageTableModel()
{
    storageModel = new QSqlTableModel(this);
    storageModel->setTable("storage");
    storageModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    storageModel->select(); //选取整个表的所有行
    //不显示id属性列,如果这时添加记录，则该属性的值添加不上
//    storageModel->removeColumn(0);
    ui->storageTableView->setModel(storageModel);
}

void WarehouseManager::initClientTableModel()
{
    clientModel = new QSqlTableModel(this);
    clientModel->setTable("client");
    clientModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    clientModel->select(); //选取整个表的所有行
    //不显示id属性列,如果这时添加记录，则该属性的值添加不上
//    clientModel->removeColumn(0);
    ui->clientTableView->setModel(clientModel);
}

void WarehouseManager::initSellTableModel()
{
    sellModel = new QSqlTableModel(this);
    sellModel->setTable("sell");
    sellModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sellModel->select(); //选取整个表的所有行
    //不显示id属性列,如果这时添加记录，则该属性的值添加不上
//    sellModel->removeColumn(0);
    ui->sellTableView->setModel(sellModel);
}

void WarehouseManager::initialize()
{
    initStorageTableModel();
    initClientTableModel();
    initSellTableModel();
}

void WarehouseManager::on_newProductBtn_clicked()
{
//    int rowNum = storageModel->rowCount(); //获得表的行数
//    int id = rowNum +1;
//    storageModel->insertRow(rowNum); //添加一行
//    storageModel->setData(storageModel->index(rowNum,0),id);
//    QDateTime time = QDateTime::currentDateTime();
//    QString timeString; = time.toString("yyyyMMdd");
//    storageModel->setData(storageModel->index(rowNum,2),timeString);

    NewProductDialog newProductDlg;
    if(newProductDlg.exec() == QDialog::Accepted)
    {

    }
}

void WarehouseManager::on_delProductBtn_clicked()
{
    //获取选中的行
    int curRow = ui->storageTableView->currentIndex().row();
    if(-1==curRow)
        return;
    //删除该行
    storageModel->removeRow(curRow);
    if(QMessageBox::No == QMessageBox::warning(this,tr("Warning"),tr("Delete the current row?"),QMessageBox::Yes,QMessageBox::No))
    {
       storageModel->revertAll(); //如果不删除，则撤销
    }
    else
        storageModel->submitAll(); //否则提交，在数据库中删除该行
}

void WarehouseManager::on_newClientBtn_clicked()
{
    NewClientDialog newClientDlg;
    if(newClientDlg.exec() == QDialog::Accepted)
    {

    }
}

void WarehouseManager::on_delClientBtn_clicked()
{
    //获取选中的行
    int curRow = ui->clientTableView->currentIndex().row();
    if(-1==curRow)
        return;
    //删除该行
    clientModel->removeRow(curRow);
    if(QMessageBox::No == QMessageBox::warning(this,tr("Warning"),tr("Delete the current row?"),QMessageBox::Yes,QMessageBox::No))
    {
       clientModel->revertAll(); //如果不删除，则撤销
    }
    else
        clientModel->submitAll(); //否则提交，在数据库中删除该行
}

void WarehouseManager::on_sellBtn_clicked()
{
    SellDialog sellDlg;
    if(sellDlg.exec() == QDialog::Accepted)
    {

    }
}

void WarehouseManager::on_deletHistoryBtn_clicked()
{
    //获取选中的行
    int curRow = ui->sellTableView->currentIndex().row();
    if(-1==curRow)
        return;

    //删除该行
    sellModel->removeRow(curRow);
    if(QMessageBox::No == QMessageBox::warning(this,tr("Warning"),tr("Delete the current row?"),QMessageBox::Yes,QMessageBox::No))
    {
       sellModel->revertAll(); //如果不删除，则撤销
    }
    else
        sellModel->submitAll(); //否则提交，在数据库中删除该行
}

void WarehouseManager::on_exitBtn_clicked()
{
    if(QMessageBox::Yes == QMessageBox::warning(this,tr("Warning"),tr("Quit Application?"),QMessageBox::Yes,QMessageBox::No))
    {
        close();
    }
}

void WarehouseManager::on_searchBtn_clicked()
{
    QString clientName = ui->clientNameLineEdit->text();
    //根据姓名进行筛选
    sellModel->setFilter(QString("ClientName like '%%1%'").arg(clientName));
        //显示结果
    sellModel->select();
}

void WarehouseManager::on_showAllBtn_clicked()
{
    sellModel->setTable("sell");//重新关联表
    sellModel->select();//再次显示整个表的内容
}
