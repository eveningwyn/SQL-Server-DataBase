#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private slots:
    void on_loginBtn_clicked();

    void on_cancelBtn_clicked();

    void on_configBtn_clicked();

    void on_setParametesBtn_clicked();

private:
    Ui::LoginDlg *ui;
    bool ishide;
    void updateConfig();
};

#endif // LOGINDLG_H
