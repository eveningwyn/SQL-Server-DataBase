#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class WarehouseManager;
}

class WarehouseManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit WarehouseManager(QWidget *parent = 0);
    ~WarehouseManager();
    void initialize();

private:
    Ui::WarehouseManager *ui;
    QSqlTableModel *storageModel;
    QSqlTableModel *clientModel;
    QSqlTableModel *sellModel;
    void initStorageTableModel();
    void initClientTableModel();
    void initSellTableModel();
};

#endif // WAREHOUSEMANAGER_H
