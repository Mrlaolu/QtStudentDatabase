#include "dialog_addcourse.h"
#include "ui_dialog_addcourse.h"
#include <QRegularExpressionValidator>

dialog_addCourse::dialog_addCourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_addCourse)
{
    ui->setupUi(this);
}

dialog_addCourse::~dialog_addCourse()
{
    delete ui;
}

void dialog_addCourse::setType(bool _isAdd, CourseInfo _in)
{
    // ui->lineEdit_Credit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]*\\.?[0-9]+$")));
    isAdd = _isAdd;
    in = _in;
    if(isAdd){
        this->setWindowTitle("添加课程信息");
        ui->lineEdit_CNo->clear();
        ui->lineEdit_CName->clear();
        ui->lineEdit_CTeacher->clear();
        ui->lineEdit_CAdder->clear();
        ui->comboBox_CTime->setEditText("星期一");
        ui->timeEdit_CTime->setDate(QDate::fromString(QString("00:00:00"),"HH:mm:ss"));
        ui->lineEdit_Credit->clear();
    }
    else {
        this->setWindowTitle("修改课程信息");
        ui->lineEdit_CNo->setText(in.CNo);
        ui->lineEdit_CName->setText(in.CName);
        ui->lineEdit_CTeacher->setText(in.CTeacher);
        ui->lineEdit_CAdder->setText(in.CAdder);
        ui->comboBox_CTime->setEditText(QString(in.CTime).slice(0,3));
        if(in.CTime.length() == 12){
            qDebug() << in.CTime;
            ui->timeEdit_CTime->setTime(QTime::fromString(in.CTime.slice(4,8)));
        }

        ui->lineEdit_Credit->setText(QString::number(in.Credit));
        qDebug() << in.Credit;
    }
}

void dialog_addCourse::on_pushButton_cancel_clicked()
{
    close();
}


void dialog_addCourse::on_pushButton_save_clicked()
{
    auto SqlPtr = stuSqlite::getinstance();
    CourseInfo info;
    info.CNo = ui->lineEdit_CNo->text();
    info.CName = ui->lineEdit_CName->text();
    info.CTeacher = ui->lineEdit_CTeacher->text();
    info.CAdder = ui->lineEdit_CAdder->text();
    info.CTime = ui->comboBox_CTime->currentText() + " " + ui->timeEdit_CTime->text();
    info.Credit = ui->lineEdit_Credit->text().toDouble();

    QString feedback;
    if(isAdd){
        if(!info.CNo.isEmpty() && SqlPtr->addCourse(info)) feedback = "成功添加课程号\'"+info.CNo+"\'的课程";
        else feedback = "添加失败";
        QMessageBox::information(nullptr,"添加结果",feedback);
    }else{
        if(SqlPtr->updateCourseInfo(info)) feedback = "成功修改课程号\'"+info.CNo+"\'的课程";
        else feedback = "修改失败";
        QMessageBox::information(nullptr,"修改结果",feedback);
    }
    close();
}

