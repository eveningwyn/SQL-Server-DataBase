#include "newclientdialog.h"
#include "ui_newclientdialog.h"
#include <QPushButton>

NewClientDialog::NewClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewClientDialog)
{
    ui->setupUi(this);
}

NewClientDialog::~NewClientDialog()
{
    delete ui;
}

void NewClientDialog::on_clientButtonBox_clicked(QAbstractButton *button)
{
    if(ui->clientButtonBox->button(QDialogButtonBox::Ok)  == button)
    {
        accept();
    }
    close();
}
