#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "stusqlite.h"
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow MainPage;
    // w.show();

    //登录界面创建与显示
    LOGIN WindowLogin;
    WindowLogin.show();
    qDebug() << QFile::exists(":/icons/down_arrow.png");  // 检查文件是否存在
    //登录成功后传回
    auto MainPageShowFunc = [&](){
        MainPage.show();
    };
    MainWindow::connect(&WindowLogin,&LOGIN::sendLoginSuccess,&MainPage,MainPageShowFunc);

    MainWindow::connect(&WindowLogin, &LOGIN::usernameEntered, &MainPage, &MainWindow::onUsernameEntered);
    MainPage.TreeWidgetInit();

    stuSqlite db;

    return a.exec();
}
