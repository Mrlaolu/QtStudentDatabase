#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "stusqlite.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow MainPage;
    // w.show();

    //登录界面创建与显示
    LOGIN WindowLogin;
    WindowLogin.show();

    //登录成功后传回
    auto MainPageShowFunc = [&](){
        MainPage.show();
    };
    MainWindow::connect(&WindowLogin,&LOGIN::sendLoginSuccess,&MainPage,MainPageShowFunc);

    MainPage.TreeWidgetInit();

    stuSqlite db;

    return a.exec();
}
