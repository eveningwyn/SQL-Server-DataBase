#ifndef SELLDIALOG_H
#define SELLDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class SellDialog;
}

class SellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SellDialog(QWidget *parent = 0);
    ~SellDialog();

private slots:
    void on_sellButtonBox_clicked(QAbstractButton *button);

private:
    Ui::SellDialog *ui;
};

#endif // SELLDIALOG_H
