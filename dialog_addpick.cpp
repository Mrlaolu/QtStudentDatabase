#include "dialog_addpick.h"
#include "ui_dialog_addpick.h"

Dialog_AddPick::Dialog_AddPick(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_AddPick)
{
    ui->setupUi(this);
}

Dialog_AddPick::~Dialog_AddPick()
{
    delete ui;
}

void Dialog_AddPick::setType(int access,bool _isAdd,QMap<QString,QString>* _StuMap,QMap<QString,QString>* _CourseMap,PickInfo _in)
{
    StuMap = *_StuMap;
    CourseMap = *_CourseMap;
    isAdd = _isAdd;
    in = _in;
    MainAccess = access;

    ui->comboBox_SNo->clear();
    for (auto key : StuMap.keys()) {
        ui->comboBox_SNo->addItem(key);
    }
    ui->comboBox_CNo->clear();
    for (auto key : CourseMap.keys()) {
        ui->comboBox_CNo->addItem(key);
    }


    if(1 == MainAccess){
        ui->comboBox_SNo->setEditable(true);
        if(isAdd){
            this->setWindowTitle("添加选课信息");
            ui->lineEdit_Score->clear();
            ui->comboBox_SNo->setEditText("");
            ui->label_CName->setText("未知");
            ui->comboBox_CNo->setEditText("");
            ui->label_SName->setText("未知");
            ui->lineEdit_Score->setText("");
        }
        else {
            this->setWindowTitle("修改课程信息");
            qDebug() << in.SNo;
            ui->comboBox_SNo->setEditText(in.SNo);
            ui->label_SName->setText(StuMap[in.SNo]);
            ui->comboBox_CNo->setEditText(in.CNo);
            ui->label_CName->setText(CourseMap[in.CNo]);
            ui->lineEdit_Score->setText(QString::number(in.Score));
        }
    }else if(2 == MainAccess){
        ui->comboBox_SNo->setEditable(false);
        ui->label_SName->setText(StuMap[in.SNo]);
        ui->comboBox_SNo->setEditable(false);
        if(isAdd){
            this->setWindowTitle("添加选课信息");
            ui->comboBox_CNo->setEditText("");
            ui->label_SName->setText("未知");
            ui->lineEdit_Score->setText("");
        }
        else {
            this->setWindowTitle("修改课程信息");
            qDebug() << in.SNo;

            ui->comboBox_CNo->setEditText(in.CNo);
            ui->label_CName->setText(CourseMap[in.CNo]);
            ui->lineEdit_Score->setText(QString::number(in.Score));
        }
    }

}

void Dialog_AddPick::on_comboBox_SNo_currentTextChanged(const QString &arg1)
{
    if(StuMap.count(arg1))ui->label_SName->setText(StuMap[arg1]);
    else ui->label_SName->setText("未知");
}


void Dialog_AddPick::on_comboBox_CNo_currentTextChanged(const QString &arg1)
{
    if(CourseMap.count(arg1))ui->label_CName->setText(CourseMap[arg1]);
    else ui->label_CName->setText("未知");
}


void Dialog_AddPick::on_pushButton_save_clicked()
{
    auto SqlPtr = stuSqlite::getinstance();
    PickInfo info;
    info.SNo = ui->comboBox_SNo->currentText();
    info.CNo = ui->comboBox_CNo->currentText();
    info.Score = ui->lineEdit_Score->text().toInt();

    QString feedback;

        if(isAdd){
            if(!info.SNo.isEmpty() && !info.CNo.isEmpty() && SqlPtr->addPick(info)) feedback = "成功添加学号为\'"+info.SNo+"\'课程号为\'"+info.CNo+"\'的选课信息";
            else feedback = "添加失败";
            QMessageBox::information(nullptr,"添加结果",feedback);
        }else{
            if(SqlPtr->updatePickInfo(info)) feedback = "成功添加修改为\'"+info.SNo+"\'课程号为\'"+info.CNo+"\'的选课信息";
            else feedback = "修改失败";
            QMessageBox::information(nullptr,"修改结果",feedback);
        }


    close();
}


void Dialog_AddPick::on_pushButton_cancel_clicked()
{
    close();
}

