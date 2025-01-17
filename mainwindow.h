#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stusqlite.h"
#include <QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "dialog_addstu.h"
#include "dialog_addcourse.h"

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
    void CourseInit();
    void PickInit();

private slots:
    void on_btn_main_exit_clicked();

    void on_btn_create_clicked();

    void on_btn_refresh_clicked();

    void on_btn_add_clicked();

    void table_refresh();            //表格刷新

    void on_btn_delete_clicked();

    void on_btn_change_clicked();

    void on_btn_search_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);  //树形表选择操作

    void on_checkBox_All_stateChanged(int arg1);    //全选键

    void on_tableWidget_itemSelectionChanged();    //表格变化时 全选键也跟着变化

    void on_checkBox_All_clicked();

private:
    Ui::MainWindow *ui;
    stuSqlite * stuSqlitePtr;
    Dialog_AddStu dlgAddStu;
    dialog_addCourse dlgAddCourse;
    int TableChoice;
    int AdminOrStudent;
};
#endif // MAINWINDOW_H
