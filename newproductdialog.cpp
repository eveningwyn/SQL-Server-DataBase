#include "newproductdialog.h"
#include "ui_newproductdialog.h"
#include <QPushButton>

NewProductDialog::NewProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProductDialog)
{
    ui->setupUi(this);
}

NewProductDialog::~NewProductDialog()
{
    delete ui;
}

void NewProductDialog::on_productButtonBox_clicked(QAbstractButton *button)
{
    if(ui->productButtonBox->button(QDialogButtonBox::Ok)  == button)
    {
        accept();
    }
    close();
}
