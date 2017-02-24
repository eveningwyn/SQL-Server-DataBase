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

private slots:
    void on_newProductBtn_clicked();

    void on_delProductBtn_clicked();

    void on_newClientBtn_clicked();

    void on_delClientBtn_clicked();

    void on_sellBtn_clicked();

    void on_deletHistoryBtn_clicked();

    void on_exitBtn_clicked();

    void on_searchBtn_clicked();

    void on_showAllBtn_clicked();

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
