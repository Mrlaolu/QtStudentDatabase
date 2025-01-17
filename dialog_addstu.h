#ifndef DIALOG_ADDSTU_H
#define DIALOG_ADDSTU_H
#include "stusqlite.h"
#include <QDialog>


namespace Ui {
class Dialog_AddStu;
}

class Dialog_AddStu : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddStu(QWidget *parent = nullptr);
    ~Dialog_AddStu();
    void setType(int access,bool _isAdd,StuInfo _in = {});

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();



private:
    Ui::Dialog_AddStu *ui;
    bool isAdd;
    StuInfo in;
    int MainAccess;
};

#endif // DIALOG_ADDSTU_H
