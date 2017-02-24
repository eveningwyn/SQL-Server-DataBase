#include "selldialog.h"
#include "ui_selldialog.h"
#include <QPushButton>

SellDialog::SellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellDialog)
{
    ui->setupUi(this);
}

SellDialog::~SellDialog()
{
    delete ui;
}

void SellDialog::on_sellButtonBox_clicked(QAbstractButton *button)
{
    if(ui->sellButtonBox->button(QDialogButtonBox::Ok)  == button)
    {
        accept();
    }
    close();
}
