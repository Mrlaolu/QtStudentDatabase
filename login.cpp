#include "login.h"
#include "ui_login.h"
#include <stusqlite.h>

LOGIN::LOGIN(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_btn_login_clicked()
{
    //在数据库里验证用户名和密码
    auto stuSql = stuSqlite::getinstance();

    //失败提示
    if(stuSql->isExistUser(ui->lineEdit_Username->text())){
        if(stuSql->isCurrentLoginUser(ui->lineEdit_Username->text(),ui->lineEdit_Password->text())){
            emit sendLoginSuccess();
            close();
        }else{
            QMessageBox::information(nullptr,"错误","密码不正确");
        }
    }else{
        QMessageBox::information(nullptr,"错误","账号不存在");
    }
    //成功进入


}


void LOGIN::on_btn_exit_clicked()
{
    exit(0);
}

