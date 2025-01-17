#include "dialog_addstu.h"
#include "ui_dialog_addstu.h"

#include <QMessageBox>
Dialog_AddStu::Dialog_AddStu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_AddStu)
{
    ui->setupUi(this);
    qDebug() <<1;
}

Dialog_AddStu::~Dialog_AddStu()
{
    delete ui;
}

void Dialog_AddStu::on_pushButton_save_clicked()
{
    auto SqlPtr = stuSqlite::getinstance();
    StuInfo info;
    info.SNo = ui->lineEdit_SNo->text();
    info.SName = ui->lineEdit_SName->text();
    info.Sex = ui->comboBox_Sex->currentText();
    info.Birth = ui->dateEdit_Birth->text();
    info.InDate = ui->dateEdit_InDate->text();
    info.Major = ui->lineEdit_Major->text();
    info.Class = ui->lineEdit_Class->text();
    info.Tele = ui->lineEdit_Tele->text();

    QString feedback;
    if(isAdd){
        if(!info.SNo.isEmpty() && SqlPtr->addStu(info)) feedback = "成功添加学号\'"+info.SNo+"\'的学生";
        else feedback = "添加失败";
        QMessageBox::information(nullptr,"添加结果",feedback);
    }else{
        if(SqlPtr->updateStuInfo(info)) feedback = "成功修改学号\'"+info.SNo+"\'的学生";
        else feedback = "修改失败";
        QMessageBox::information(nullptr,"修改结果",feedback);
    }
    close();

}


void Dialog_AddStu::on_pushButton_cancel_clicked()
{
    close();
}

void Dialog_AddStu::setType(int access,bool _isAdd,StuInfo _in)
{
    isAdd = _isAdd;
    in = _in;
    MainAccess = access;

    if(1 == MainAccess){

        if(isAdd){
            this->setWindowTitle("添加学生信息");
            ui->lineEdit_SNo->clear();
            ui->lineEdit_SName->clear();
            ui->lineEdit_Major->clear();
            ui->comboBox_Sex->setCurrentText("未知");
            ui->dateEdit_Birth->setDate(QDate(1970,1,1));
            ui->dateEdit_InDate->setDate(QDate(1970,1,1));
            ui->lineEdit_Class->clear();
            ui->lineEdit_Tele->clear();
        }
        else {
            this->setWindowTitle("修改学生信息");
            ui->lineEdit_SNo->setText(in.SNo);
            ui->lineEdit_SName->setText(in.SName);
            ui->lineEdit_Major->setText(in.Major);
            ui->comboBox_Sex->setCurrentText(in.Sex);
            ui->dateEdit_Birth->setDate(QDate::fromString(in.Birth,"yyyy-MM-dd"));
            ui->dateEdit_InDate->setDate(QDate::fromString(in.InDate,"yyyy"));
            ui->lineEdit_Class->setText(in.Class);
            ui->lineEdit_Tele->setText(in.Tele);
        }

    }else if(2 == MainAccess){
        if(!isAdd){
            this->setWindowTitle("修改学生信息");
            ui->lineEdit_SNo->setText(in.SNo);
            ui->lineEdit_SNo->setEnabled(false);
            ui->lineEdit_SName->setText(in.SName);
            ui->lineEdit_Major->setText(in.Major);
            ui->comboBox_Sex->setCurrentText(in.Sex);
            ui->dateEdit_Birth->setDate(QDate::fromString(in.Birth,"yyyy-MM-dd"));
            ui->dateEdit_InDate->setDate(QDate::fromString(in.InDate,"yyyy"));
            ui->lineEdit_Class->setText(in.Class);
            ui->lineEdit_Tele->setText(in.Tele);
        }
    }



}

