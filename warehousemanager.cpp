#include "warehousemanager.h"
#include "ui_warehousemanager.h"

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
    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    storageModel->removeColumn(0);
    ui->storageTableView->setModel(storageModel);
    //使其不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void WarehouseManager::initClientTableModel()
{
    clientModel = new QSqlTableModel(this);
    clientModel->setTable("client");
    clientModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    clientModel->select(); //选取整个表的所有行
    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    clientModel->removeColumn(0);
    ui->clientTableView->setModel(clientModel);
    //使其不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void WarehouseManager::initSellTableModel()
{
    sellModel = new QSqlTableModel(this);
    sellModel->setTable("sell");
    sellModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sellModel->select(); //选取整个表的所有行
    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    sellModel->removeColumn(0);
    ui->sellTableView->setModel(sellModel);
    //使其不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void WarehouseManager::initialize()
{
    initStorageTableModel();
    initClientTableModel();
    initSellTableModel();
}
