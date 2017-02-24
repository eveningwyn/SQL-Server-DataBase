#ifndef NEWCLIENTDIALOG_H
#define NEWCLIENTDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class NewClientDialog;
}

class NewClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewClientDialog(QWidget *parent = 0);
    ~NewClientDialog();

private slots:
    void on_clientButtonBox_clicked(QAbstractButton *button);

private:
    Ui::NewClientDialog *ui;
};

#endif // NEWCLIENTDIALOG_H
