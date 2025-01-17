#include "dialog_adduser.h"
#include "ui_dialog_adduser.h"

Dialog_AddUser::Dialog_AddUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_AddUser)
{
    ui->setupUi(this);
}

Dialog_AddUser::~Dialog_AddUser()
{
    delete ui;
}

void Dialog_AddUser::setType(int access,bool _isAdd, UserInfo _in)
{
    isAdd = _isAdd;
    in = _in;
    MainAccess = access;

    if(1 == MainAccess){
        ui->comboBox_Access->show();
        ui->label_Access->show();
        if(isAdd){
            this->setWindowTitle("添加账号信息");
            ui->lineEdit_Username->clear();
            ui->lineEdit_Password->clear();
        }
        else {
            this->setWindowTitle("修改学生信息");
            ui->lineEdit_Username->setText(in.Username);
            ui->comboBox_Access->setEditable(true);
            ui->comboBox_Access->setEditText("1");
            ui->comboBox_Access->setEditable(false);
        }
    }else if(2 == MainAccess){

        if(!isAdd) {
            this->setWindowTitle("修改学生信息");
            ui->lineEdit_Username->setText(in.Username);
            ui->comboBox_Access->hide();
            ui->label_Access->hide();
        }
    }

}

void Dialog_AddUser::on_pushButton_save_clicked()
{
    auto SqlPtr = stuSqlite::getinstance();
    UserInfo info;
    info.Password = ui->lineEdit_Password->text();
    info.Username = ui->lineEdit_Username->text();
    if(1 == MainAccess)info.Access = ui->comboBox_Access->currentText().toInt();
    else if(2 == MainAccess)info.Access = 2;

    QString feedback;
    if(isAdd){
        if(!info.Username.isEmpty() && SqlPtr->addUser(info)) feedback = "成功添加用户名为\'"+info.Username+"\'的账号信息";
        else feedback = "添加失败";
        QMessageBox::information(nullptr,"添加结果",feedback);
    }else{
        if( (info.Username != "root" || ("root" == info.Username && 1 == info.Access) )             //确保root账号权限为最高的一级
            && SqlPtr->updateUser(info)) feedback = "成功修改用户名为\'"+info.Username+"\'的账号信息";
        else feedback = "修改失败";
        QMessageBox::information(nullptr,"修改结果",feedback);
    }
    close();
}


void Dialog_AddUser::on_pushButton_cancel_clicked()
{
    close();
}

