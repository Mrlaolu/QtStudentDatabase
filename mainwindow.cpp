#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NameGen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stuSqlitePtr(nullptr)
{
    ui->setupUi(this);
    TableChoice = -1;
}

void MainWindow::TreeWidgetInit(){

    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("学生管理系统");           //设置标题
    ui->treeWidget->setColumnCount(1);

    //**************学生与课程管理***************//
    QTreeWidgetItem *TreeTopptrStu = new QTreeWidgetItem(ui->treeWidget,QStringList("学生与课程管理"));            //设置树形表头
    ui->treeWidget->addTopLevelItem(TreeTopptrStu);

    QTreeWidgetItem *TreeChildStu = new QTreeWidgetItem(TreeTopptrStu,QStringList("学生管理"));    //设置树形表孩子
    QTreeWidgetItem *TreeChildCour =new QTreeWidgetItem(TreeTopptrStu,QStringList("课程管理"));
    QTreeWidgetItem *TreeChildChoice =new QTreeWidgetItem(TreeTopptrStu,QStringList("选课管理"));

    TreeTopptrStu->addChild(TreeChildStu);
    TreeTopptrStu->addChild(TreeChildCour);
    TreeTopptrStu->addChild(TreeChildChoice);

    //**************后台账户管理***************//
    QTreeWidgetItem *TreeTopptrBack = new QTreeWidgetItem(ui->treeWidget,QStringList("后台账户管理"));            //设置树形表头
    ui->treeWidget->addTopLevelItem(TreeTopptrBack);

    QTreeWidgetItem *TreeChildAccount = new QTreeWidgetItem(TreeTopptrBack,QStringList("登录账户管理"));          //设置树形表孩子
    TreeTopptrBack->addChild(TreeChildAccount);



    ui->treeWidget->expandAll();        //默认展开树形表

    stuSqlitePtr = stuSqlite::getinstance();
}

void MainWindow::StudentInit()          //无需mode
{
    QStringList l({"学号","姓名","性别","入学日期","生日","专业","班级","联系电话"});
    TableChoice = 1;
    ui->comboBox_sreach->clear();
    for(int i = 0;i < l.size();++i)
        ui->comboBox_sreach->addItem(l[i]);
}

void MainWindow::CourseInit()
{
    QStringList l({"课程号","课程名","授课老师","授课地点","授课时间","学分"});
    TableChoice = 2;
    ui->comboBox_sreach->clear();
    for(int i = 0;i < l.size();++i)
        ui->comboBox_sreach->addItem(l[i]);
}

void MainWindow::PickInit()
{
    QStringList l({"学号","课程号","成绩"});
    TableChoice = 3;
    ui->comboBox_sreach->clear();
    for(int i = 0;i < l.size();++i)
        ui->comboBox_sreach->addItem(l[i]);
}

void MainWindow::UserInit()
{
    QStringList l({"用户名","密码","权限"});
    TableChoice = 3;
    ui->comboBox_sreach->clear();
    for(int i = 0;i < l.size();++i)
        ui->comboBox_sreach->addItem(l[i]);
}

void MainWindow::onUsernameEntered(const QString &username)
{
    ui->label_username->setText(username);
    int Access = stuSqlitePtr->getAccessUser(username);
    qDebug() << "权限：" << Access;
    if(Access < 1 || Access > 3){
        QMessageBox::information(nullptr,"错误","账户权限错误");
        exit(0);
    }else{
        MainAccess = Access;
        if(2 == MainAccess){
            ui->btn_add->hide();
            ui->btn_delete->hide();
            ui->btn_create->hide();
        }

    }
}

int MainWindow::getMainAccess()
{
    return MainAccess;
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

    if(1 == TableChoice){
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
            info.SNo = "S";
            NowOrder++;
            for(int j = QString::number(NowOrder).size();j <= 6;++j){
                info.SNo += "0";
            }
            info.SNo += QString::number(NowOrder);
            info.SName = generateName(generator.bounded(2, 5));             //[a,b)

            info.Sex = Sexlist[generator.bounded(0,2)];
            info.Birth = QString::number(generator.bounded(2001,2006))+"-"+QString::number(generator.bounded(10,13))+"-"+QString::number(generator.bounded(10,31));
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
    }else{
        QMessageBox::information(nullptr,"错误","请选择能随机创建数据的表格");
    }

}

void MainWindow::on_btn_refresh_clicked()
{
    table_refresh();
}


void MainWindow::on_btn_add_clicked()
{
    if(1 == MainAccess){

        if(1 == TableChoice){
            dlgAddStu.setType(MainAccess,true);
            dlgAddStu.exec();
            table_refresh();
        }else if(2 == TableChoice){
            dlgAddCourse.setType(MainAccess,true);
            dlgAddCourse.exec();
            table_refresh();
        }else if(3 == TableChoice){
            QList<StuInfo>Sl = stuSqlitePtr->getPageStu(0,stuSqlitePtr->getStuCnt());
            QMap<QString,QString>StuMap;
            for(auto it : Sl)StuMap[it.SNo] = it.SName;

            QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
            QMap<QString,QString>CourseMap;
            for(auto it : Cl)CourseMap[it.CNo] = it.CName;

            dlgAddPick.setType(MainAccess,true,&StuMap,&CourseMap);
            dlgAddPick.exec();
            table_refresh();
        }else if(4 == TableChoice){
            dlgAddUser.setType(MainAccess,true);
            dlgAddUser.exec();
            table_refresh();
        }
        else{
            QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
        }

    }else if(2 == MainAccess){

        if(3 == TableChoice){
            QList<StuInfo>Sl = stuSqlitePtr->singalSeachStu("学号",ui->label_username->text());
            QMap<QString,QString>StuMap;
            for(auto it : Sl)StuMap[it.SNo] = it.SName;

            QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
            QMap<QString,QString>CourseMap;
            for(auto it : Cl)CourseMap[it.CNo] = it.CName;

            dlgAddPick.setType(MainAccess,true,&StuMap,&CourseMap);
            dlgAddPick.exec();
            table_refresh();
        }
        else{
            QMessageBox::information(nullptr,"错误","您没有增加此表格信息的权限");
        }

    }
}

void MainWindow::table_refresh()
{
    if(1 == MainAccess){
        ui->btn_add->show();
        ui->btn_delete->show();
        ui->btn_search->show();
        ui->btn_delete->show();
        if(1 == TableChoice){
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
        }else if(2 == TableChoice){
            ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(6);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"课程号","课程名","授课老师","授课地点","授课时间","学分"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

            int CourseCnt = stuSqlitePtr->getCourseCnt();
            qDebug() << "刷新到" << CourseCnt << "个数据";
            ui->tableWidget->setRowCount(CourseCnt);
            QList<CourseInfo>l = stuSqlitePtr->getCourse();
            for(int i = 0;i < CourseCnt;++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].CNo));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].CName));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CTeacher));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].CAdder));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].CTime));
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(l[i].Credit)));
            }
        }else if(3 == TableChoice){
            ui->tableWidget->clear();

            ui->tableWidget->setColumnCount(5);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","学生姓名","课程号","课程名称","成绩"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

            QList<StuInfo>Sl = stuSqlitePtr->getPageStu(0,stuSqlitePtr->getStuCnt());
            QMap<QString,QString>StuMap;
            for(auto it : Sl)StuMap[it.SNo] = it.SName;
            QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
            QMap<QString,QString>CourseMap;
            for(auto it : Cl)CourseMap[it.CNo] = it.CName;

            int PickCnt = stuSqlitePtr->getPickCnt();
            qDebug() << "刷新到" << PickCnt << "个数据";
            ui->tableWidget->setRowCount(PickCnt);
            QList<PickInfo>l = stuSqlitePtr->getPick();

            for(int i = 0;i < l.size();++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].SNo));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(StuMap[l[i].SNo]));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CNo));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(CourseMap[l[i].CNo]));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(l[i].Score)));
            }
        }
        else if(4 == TableChoice){
            ui->tableWidget->clear();

            ui->tableWidget->setColumnCount(3);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"用户名","密码","权限"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


            QList<UserInfo>l = stuSqlitePtr->getALLUser();
            ui->tableWidget->setRowCount(l.size());

            for(int i = 0;i < l.size();++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].Username));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].Password));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(l[i].Access)));
            }
        }else{
            QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
        }

    }else if(2 == MainAccess){

        if(1 == TableChoice){
            ui->btn_add->hide();
            ui->btn_delete->hide();
            ui->btn_search->show();
            ui->btn_change->show();

            ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(8);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","姓名","性别","入学日期","生日","专业","班级","联系电话"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

            QList<StuInfo>l = stuSqlitePtr->singalSeachStu("学号",ui->label_username->text());
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
        }else if(2 == TableChoice){
            ui->btn_add->hide();
            ui->btn_delete->hide();
            ui->btn_search->show();
            ui->btn_change->hide();

            ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(6);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"课程号","课程名","授课老师","授课地点","授课时间","学分"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

            QList<CourseInfo>l = stuSqlitePtr->singalSeachCoures("课程号","");
            ui->tableWidget->setRowCount(l.size());
            for(int i = 0;i < l.size();++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].CNo));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].CName));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CTeacher));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].CAdder));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].CTime));
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(l[i].Credit)));
            }
        }else if(3 == TableChoice){
            ui->btn_add->hide();
            ui->btn_delete->hide();
            ui->btn_search->show();
            ui->btn_change->show();

            ui->tableWidget->clear();

            ui->tableWidget->setColumnCount(5);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","学生姓名","课程号","课程名称","成绩"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

            QList<StuInfo>Sl = stuSqlitePtr->singalSeachStu("学号",ui->label_username->text());
            QMap<QString,QString>StuMap;
            for(auto it : Sl)StuMap[it.SNo] = it.SName;

            QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
            QMap<QString,QString>CourseMap;
            for(auto it : Cl)CourseMap[it.CNo] = it.CName;



            QList<PickInfo>l = stuSqlitePtr->singalSeachPick("学号",ui->label_username->text());
            ui->tableWidget->setRowCount(l.size());
            for(int i = 0;i < l.size();++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].SNo));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(StuMap[l[i].SNo]));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CNo));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(CourseMap[l[i].CNo]));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(l[i].Score)));
            }
        }
        else if(4 == TableChoice){
            ui->btn_add->hide();
            ui->btn_delete->show();
            ui->btn_search->show();
            ui->btn_change->show();

            ui->tableWidget->clear();

            ui->tableWidget->setColumnCount(3);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList({"用户名","密码","权限"}));  // 清空表头内容

            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


            QList<UserInfo>l = stuSqlitePtr->singalSeachUser("用户名",ui->label_username->text());
            ui->tableWidget->setRowCount(l.size());

            for(int i = 0;i < l.size();++i){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].Username));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].Password));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(l[i].Access)));
            }
        }else{
            QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
        }

    }


    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);               //设置表头自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::on_btn_delete_clicked()
{
    QList<QTableWidgetSelectionRange>ranges = ui->tableWidget->selectedRanges();
    int sum = 0,delsum = 0;
    int count = ranges.count();

    if(1 == MainAccess){
        if(TableChoice >= 0){
            for(int i = 0;i < count;++i){
                int topRow=ranges.at(i).topRow();
                int bottomRow=ranges.at(i).bottomRow();
                sum += bottomRow - topRow  + 1;
                for(int j=topRow;j<=bottomRow;j++)
                {
                    QString Key1 = ui->tableWidget->item(j,0)->text();
                    QString Key2 = ui->tableWidget->item(j,2)->text();
                    if(1 == TableChoice){
                        delsum += stuSqlitePtr->delStu(Key1);
                    }else if(2 == TableChoice){
                        delsum += stuSqlitePtr->delCourse(Key1);
                    }else if(3 == TableChoice){
                        delsum += stuSqlitePtr->delPick(Key1,Key2);
                    }else if(4 == TableChoice){
                        if(Key1 != "root")delsum += stuSqlitePtr->delUser(Key1);            //确保root账户存在
                    }
                }
            }

            table_refresh();
            if(1 == TableChoice){
                QMessageBox::information(nullptr,"信息",QString("一共选中%1个学生信息，其中有%2个删除成功").arg(sum).arg(delsum));
            }else if(2 == TableChoice){
                QMessageBox::information(nullptr,"信息",QString("一共选中%1个课程信息，其中有%2个删除成功").arg(sum).arg(delsum));
            }else if(3 == TableChoice){
                QMessageBox::information(nullptr,"信息",QString("一共选中%1个选课信息，其中有%2个删除成功").arg(sum).arg(delsum));
            }else if(4 == TableChoice){
                QMessageBox::information(nullptr,"信息",QString("一共选中%1个账号信息，其中有%2个删除成功").arg(sum).arg(delsum));
            }
        }else{
            QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
        }
    }else if(2 == MainAccess){

            for(int i = 0;i < count;++i){
                int topRow=ranges.at(i).topRow();
                int bottomRow=ranges.at(i).bottomRow();
                sum += bottomRow - topRow  + 1;
                for(int j=topRow;j<=bottomRow;j++)
                {
                    QString Key1 = ui->tableWidget->item(j,0)->text();
                    QString Key2 = ui->tableWidget->item(j,2)->text();
                    if(3 == TableChoice && ui->tableWidget->item(j,4)->text().isEmpty()){           //只有成绩非空才能被删除
                        delsum += stuSqlitePtr->delPick(Key1,Key2);
                    }
                }
            }

            table_refresh();
            if(3 == TableChoice){
                QMessageBox::information(nullptr,"信息",QString("一共选中%1个选课信息，其中有%2个删除成功。请注意:有成绩的课程不能被删除").arg(sum).arg(delsum));
            }else{
                QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
            }
    }
}




void MainWindow::on_btn_change_clicked()
{
    if(1 == TableChoice){
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
            dlgAddStu.setType(MainAccess,false,info);
            dlgAddStu.exec();
            table_refresh();
        }
    }else if(2 == TableChoice){
        CourseInfo info;
        int NowRow = ui->tableWidget->currentRow();
        if(NowRow >= 0){
            info.CNo = ui->tableWidget->item(NowRow,0)->text();
            info.CName = ui->tableWidget->item(NowRow,1)->text();
            info.CTeacher = ui->tableWidget->item(NowRow,2)->text();
            info.CAdder = ui->tableWidget->item(NowRow,3)->text();
            info.CTime = ui->tableWidget->item(NowRow,4)->text();
            info.Credit = QString(ui->tableWidget->item(NowRow,5)->text()).toDouble();
            dlgAddCourse.setType(MainAccess,false,info);
            dlgAddCourse.exec();
            table_refresh();
        }
    }else if(3 == TableChoice){
        PickInfo info;
        int NowRow = ui->tableWidget->currentRow();
        if(NowRow >= 0){
            info.SNo = ui->tableWidget->item(NowRow,0)->text();
            info.CNo = ui->tableWidget->item(NowRow,2)->text();
            info.Score = QString(ui->tableWidget->item(NowRow,4)->text()).toDouble();

            QList<StuInfo>Sl = stuSqlitePtr->getPageStu(0,stuSqlitePtr->getStuCnt());
            QMap<QString,QString>StuMap;
            for(auto it : Sl)StuMap[it.SNo] = it.SName;

            QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
            QMap<QString,QString>CourseMap;
            for(auto it : Cl)CourseMap[it.CNo] = it.CName;

            dlgAddPick.setType(MainAccess,false,&StuMap,&CourseMap,info);
            dlgAddPick.exec();
            table_refresh();
        }
    }else if(4 == TableChoice){
        UserInfo info;
        int NowRow = ui->tableWidget->currentRow();
        if(NowRow >= 0){
            info.Username = ui->tableWidget->item(NowRow,0)->text();
            info.Password = ui->tableWidget->item(NowRow,1)->text();
            info.Access = ui->tableWidget->item(NowRow,2)->text().toInt();
            dlgAddUser.setType(MainAccess,false,info);
            dlgAddUser.exec();
            table_refresh();
        }

    }
    else{
        QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
    }

}


void MainWindow::on_btn_search_clicked()
{
    if(1 == TableChoice){
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
    }else if(2 == TableChoice){
        QList<CourseInfo>l = stuSqlitePtr->singalSeachCoures(ui->comboBox_sreach->currentText(),ui->lineEdit_sreach->text());
        qDebug() << l.size();
        ui->tableWidget->clear();

        ui->tableWidget->setColumnCount(6);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList({"课程号","课程名","授课老师","授课地点","授课时间","学分"}));  // 清空表头内容

        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(l.size());

        for(int i = 0;i < l.size();++i){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].CNo));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].CName));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CTeacher));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].CAdder));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].CTime));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(l[i].Credit));
        }
    }else if(3 == TableChoice){
        QList<PickInfo>l = stuSqlitePtr->singalSeachPick(ui->comboBox_sreach->currentText(),ui->lineEdit_sreach->text());
        qDebug() << l.size();
        ui->tableWidget->clear();

        ui->tableWidget->setColumnCount(5);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList({"学号","学生姓名","课程号","课程名称","成绩"}));  // 清空表头内容

        QList<StuInfo>Sl = stuSqlitePtr->getPageStu(0,stuSqlitePtr->getStuCnt());
        QMap<QString,QString>StuMap;
        for(auto it : Sl)StuMap[it.SNo] = it.SName;

        QList<CourseInfo>Cl = stuSqlitePtr->getCourse();
        QMap<QString,QString>CourseMap;
        for(auto it : Cl)CourseMap[it.CNo] = it.CName;

        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(l.size());

        for(int i = 0;i < l.size();++i){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].SNo));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(StuMap[l[i].SNo]));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].CNo));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(CourseMap[l[i].CNo]));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(l[i].Score));
        }
    }else if(4 == TableChoice){
        QList<UserInfo>l = stuSqlitePtr->singalSeachUser(ui->comboBox_sreach->currentText(),ui->lineEdit_sreach->text());
        qDebug() << l.size();
        ui->tableWidget->clear();

        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList({"用户名","密码","权限"}));  // 清空表头内容

        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(l.size());

        for(int i = 0;i < l.size();++i){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(l[i].Username));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(l[i].Password));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(l[i].Access)));
        }
    }else{
        QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
    }

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);               //设置表头自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)           //树形表选择操作
{
    QString itemStr = item->text(0);


    QMap<QString,int> itemModeMap;
    itemModeMap["学生管理"] = 1;
    itemModeMap["课程管理"] = 2;
    itemModeMap["选课管理"] = 3;
    itemModeMap["登录账户管理"] = 4;



    if(itemModeMap.count(itemStr)){
        TableChoice = itemModeMap[itemStr];
    }
    qDebug() << itemStr << "被选中 " << TableChoice;

    switch(TableChoice){
    case 1:
        StudentInit();
        table_refresh();
        break;
    case 2:
        CourseInit();
        table_refresh();
        break;
    case 3:
        PickInit();
        table_refresh();
    default:
        table_refresh();
    }
}


void MainWindow::on_checkBox_All_stateChanged(int arg1)
{
    qDebug() << "checkBox: " << arg1;
    if(TableChoice >= 1){
        if(2 == arg1){
            ui->tableWidget->selectAll();
        }else if(0 == arg1){
            ui->tableWidget->clearSelection();
        }

    }else{
        QMessageBox::information(nullptr,"错误","请先选择能进行操作的表格");
    }

}


void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QList<QTableWidgetSelectionRange> ll = ui->tableWidget->selectedRanges();
    int count = 0;
    for(int i = 0;i < ll.size();++i)count += ll[i].bottomRow() - ll[i].topRow() + 1;
    qDebug() << "selection:" << count;
    if(ui->tableWidget->rowCount() == count){
        ui->checkBox_All->setCheckState(Qt::Checked);
    }else if(0 == count){
        ui->checkBox_All->setCheckState(Qt::Unchecked);
    }else{
        ui->checkBox_All->setCheckState(Qt::PartiallyChecked);
    }
}


void MainWindow::on_checkBox_All_clicked()
{
    while(ui->checkBox_All->checkState() == Qt::PartiallyChecked)
        ui->checkBox_All->setCheckState(Qt::Checked);
}

