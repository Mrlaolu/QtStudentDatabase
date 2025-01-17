#ifndef DIALOG_ADDPICK_H
#define DIALOG_ADDPICK_H
#include "stusqlite.h"
#include <QDialog>

namespace Ui {
class Dialog_AddPick;
}

class Dialog_AddPick : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddPick(QWidget *parent = nullptr);
    ~Dialog_AddPick();
    void setType(bool _isAdd,QMap<QString,QString>* _StuMap,QMap<QString,QString>* _CourseMap,PickInfo _in = {});


private slots:
    void on_comboBox_SNo_currentTextChanged(const QString &arg1);

    void on_comboBox_CNo_currentTextChanged(const QString &arg1);

    void on_pushButton_save_clicked();

private:
    Ui::Dialog_AddPick *ui;
    PickInfo in;
    QMap<QString,QString> StuMap;
    QMap<QString,QString> CourseMap;
    bool isAdd;
};

#endif // DIALOG_ADDPICK_H
