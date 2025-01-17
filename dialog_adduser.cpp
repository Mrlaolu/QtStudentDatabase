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

void Dialog_AddUser::setType(bool _isAdd, UserInfo _in)
{
    isAdd = _isAdd;
    in = _in;

    if(isAdd){
        this->setWindowTitle("添加账号信息");
        ui->lineEdit_Username->clear();
        ui->lineEdit_Password->clear();
    }
    else {
        this->setWindowTitle("修改学生信息");
        ui->lineEdit_Username->setText(in.Username);
        ui->comboBox_Access->setEditText(QString::number(in.Access));
    }
}

void Dialog_AddUser::on_pushButton_save_clicked()
{
    auto SqlPtr = stuSqlite::getinstance();
    UserInfo info;
    info.Password = ui->lineEdit_Password->text();
    info.Username = ui->lineEdit_Username->text();
    info.Access = ui->comboBox_Access->currentText().toInt();

    QString feedback;
    if(isAdd){
        if(!info.Username.isEmpty() && SqlPtr->addUser(info)) feedback = "成功添加用户名为\'"+info.Username+"\'的账号信息";
        else feedback = "添加失败";
        QMessageBox::information(nullptr,"添加结果",feedback);
    }else{
        if(SqlPtr->updateUser(info)) feedback = "成功修改用户名为\'"+info.Username+"\'的账号信息";
        else feedback = "修改失败";
        QMessageBox::information(nullptr,"修改结果",feedback);
    }
    close();
}

