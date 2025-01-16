    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NameGen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stuSqlitePtr(nullptr)
{
    ui->setupUi(this);
    mode = -1;
}

void MainWindow::TreeWidgetInit(){

    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("学生管理系统");           //设置标题
    ui->treeWidget->setColumnCount(1);

    QTreeWidgetItem *TreeTopptr = new QTreeWidgetItem(ui->treeWidget,QStringList("学生管理系统"));            //设置树形表头
    ui->treeWidget->addTopLevelItem(TreeTopptr);

    QTreeWidgetItem *TreeChildptr[2] = {new QTreeWidgetItem(TreeTopptr,QStringList("学生管理")),new QTreeWidgetItem(TreeTopptr,QStringList("管理员管理"))};          //设置树形表孩子
    for(int i = 0;i < 2;++i)
        TreeTopptr->addChild(TreeChildptr[i]);

    ui->treeWidget->expandAll();        //默认展开树形表

    stuSqlitePtr = stuSqlite::getinstance();
}

void MainWindow::StudentInit()
{
    mode = 1;
    QStringList l({"学号","姓名","性别","入学日期","生日","专业","班级","联系电话"});

    for(int i = 0;i < l.size();++i)
        ui->comboBox_sreach->addItem(l[i]);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_main_exit_clicked()
{
    exit(0);
}


void MainWindow::on_btn_create_clicked()        //生成1000条学生数据
{

    QRandomGenerator generator;
    QList<QString>Sexlist = {"男","女"};
    QList<QString> MajorList = {
        "计算机科学与技术", "软件工程", "电子信息工程", "机械工程",
        "土木工程", "自动化", "金融学", "会计学",
        "法学", "英语"
    };
    int CreateCnt = 0;
    int NowOrder = stuSqlitePtr->getStuCnt();
    for(int i = 0;i < 100;++i){
        StuInfo info;
        info.SNo = "S"+QString::number(++NowOrder);
        info.SName = generateName(generator.bounded(2, 5));             //[a,b)

        info.Sex = Sexlist[generator.bounded(0,2)];
        info.Birth = QString::number(generator.bounded(2001,2006))+"-"+QString::number(generator.bounded(1,13))+"-"+QString::number(generator.bounded(1,31));
        info.InDate = QString::number(generator.bounded(2021,2025));
        info.Major = MajorList[generator.bounded(0,MajorList.size())];
        info.Tele = "1";
        for(int j = 1;j < 11;++j)info.Tele.push_back(QString::number(generator.bounded(0,10)));
        info.Class = QString(info.Major[0]) + info.Major[1] + info.InDate[2] + info.InDate[3] + "0" + QString::number(generator.bounded(1,4));
        if("计" == info.Major[0]){info.Class[1] = info.Major[3];}
        CreateCnt += stuSqlitePtr->addStu(info);
    }
    qDebug() << "已创建" << CreateCnt << "个学生";
    table_refresh();
}

void MainWindow::on_btn_refresh_clicked()
{
    table_refresh();
}


void MainWindow::on_btn_add_clicked()
{
    dlgAddStu.setType(true);
    dlgAddStu.exec();
    table_refresh();
}

void MainWindow::table_refresh()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","姓名","性别","入学日期","生日","专业","班级","联系电话"}));  // 清空表头内容

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int StuCnt = stuSqlitePtr->getStuCnt();
    qDebug() << "刷新到" << StuCnt << "个数据";
    ui->tableWidget->setRowCount(StuCnt);
    QList<StuInfo>l = stuSqlitePtr->getPageStu(0,StuCnt);
    for(int i = 0;i < StuCnt;++i){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].SNo));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].SName));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].Sex));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].InDate));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].Birth));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(l[i].Major));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(l[i].Class));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(l[i].Tele));
    }
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);               //设置表头自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::on_btn_delete_clicked()
{
    QList<QTableWidgetSelectionRange>ranges = ui->tableWidget->selectedRanges();
    int sum = 0,delsum = 0;
    int count = ranges.count();
    for(int i = 0;i < count;++i){
        int topRow=ranges.at(i).topRow();
        int bottomRow=ranges.at(i).bottomRow();
        sum += bottomRow - topRow  + 1;
        for(int j=topRow;j<=bottomRow;j++)
        {
            QString DSNo = ui->tableWidget->item(j,0)->text();
            delsum += stuSqlitePtr->delStu(DSNo);
        }
    }
    table_refresh();
    QMessageBox::information(nullptr,"信息",QString("一共选中%1个学生信息，其中有%2个删除成功").arg(sum).arg(delsum));
}


void MainWindow::on_btn_change_clicked()
{
    StuInfo info;
    int NowRow = ui->tableWidget->currentRow();
    if(NowRow >= 0){
        info.SNo = ui->tableWidget->item(NowRow,0)->text();
        info.SName = ui->tableWidget->item(NowRow,1)->text();
        info.Sex = ui->tableWidget->item(NowRow,2)->text();
        info.InDate = ui->tableWidget->item(NowRow,3)->text();
        info.Birth = ui->tableWidget->item(NowRow,4)->text();
        info.Major = ui->tableWidget->item(NowRow,5)->text();
        info.Class = ui->tableWidget->item(NowRow,6)->text();
        info.Tele = ui->tableWidget->item(NowRow,7)->text();
        dlgAddStu.setType(false,info);
        dlgAddStu.exec();
        table_refresh();
    }
}


void MainWindow::on_btn_search_clicked()
{
    QString context = ui->lineEdit_sreach->text();
    QList<StuInfo>l = stuSqlitePtr->singalSeachStu(ui->comboBox_sreach->currentText(),ui->lineEdit_sreach->text());
    qDebug() << l.size();
    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","姓名","性别","入学日期","生日","专业","班级","联系电话"}));  // 清空表头内容

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(l.size());

    for(int i = 0;i < l.size();++i){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].SNo));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].SName));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].Sex));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].InDate));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].Birth));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(l[i].Major));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(l[i].Class));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(l[i].Tele));
    }
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);               //设置表头自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

