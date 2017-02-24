#ifndef NEWPRODUCTDIALOG_H
#define NEWPRODUCTDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class NewProductDialog;
}

class NewProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProductDialog(QWidget *parent = 0);
    ~NewProductDialog();

private slots:
    void on_productButtonBox_clicked(QAbstractButton *button);

private:
    Ui::NewProductDialog *ui;
};

#endif // NEWPRODUCTDIALOG_H
