#include "login.h"
#include "ui_login.h"

LOGIN::LOGIN(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LOGIN)
{
    ui->setupUi(this);
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_btn_login_clicked()
{
    //在数据库里验证用户名和密码

    //失败提示

    //成功进入

    emit sendLoginSuccess();
    close();
}


void LOGIN::on_btn_exit_clicked()
{
    exit(0);
}

