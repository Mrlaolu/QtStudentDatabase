#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stusqlite.h"
#include <QMainWindow>
#include "dialog_addstu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void TreeWidgetInit();
    void StudentInit();

private slots:
    void on_btn_main_exit_clicked();

    void on_btn_create_clicked();

    void on_btn_refresh_clicked();

    void on_btn_add_clicked();

    void table_refresh();            //表格刷新

    void on_btn_delete_clicked();

    void on_btn_change_clicked();

    void on_btn_search_clicked();

private:
    Ui::MainWindow *ui;
    stuSqlite * stuSqlitePtr;
    Dialog_AddStu dlgAddStu;
    int mode;
};
#endif // MAINWINDOW_H
