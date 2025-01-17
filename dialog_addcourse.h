#ifndef DIALOG_ADDCOURSE_H
#define DIALOG_ADDCOURSE_H
#include "stusqlite.h"
#include <QDialog>

namespace Ui {
class dialog_addCourse;
}

class dialog_addCourse : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_addCourse(QWidget *parent = nullptr);
    ~dialog_addCourse();

    void setType(int,bool,CourseInfo = {});

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::dialog_addCourse *ui;
    CourseInfo in;
    bool isAdd;
    int MainAccess;
};

#endif // DIALOG_ADDCOURSE_H
