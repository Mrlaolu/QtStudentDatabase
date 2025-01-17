#ifndef DIALOG_ADDUSER_H
#define DIALOG_ADDUSER_H
#include "stusqlite.h"
#include <QDialog>

namespace Ui {
class Dialog_AddUser;
}

class Dialog_AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddUser(QWidget *parent = nullptr);
    ~Dialog_AddUser();
    void setType(int access,bool _isAdd,UserInfo _in = {});

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Dialog_AddUser *ui;
    bool isAdd;
    UserInfo in;
    int MainAccess;
};

#endif // DIALOG_ADDUSER_H
