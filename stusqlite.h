#ifndef STUSQLITE_H
#define STUSQLITE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QCoreApplication>

//与表中定义
struct StuInfo{
    QString SNo;
    QString SName;
    QString Sex;
    QString InDate;
    QString Birth;
    QString Major;
    QString Class;
    QString Tele;
};

struct PickInfo{
    QString SNo;
    QString CNo;
    qreal Score;
};

struct CourseInfo{
    QString CNo;
    QString CName;
    QString CTeacher;
    QString CAdder;
    QString CTime;
    qreal Credit;
};

struct UserInfo{
    QString Username;
    QString Password;
    QString Access;
};

class stuSqlite : public QObject
{
    Q_OBJECT
public:
    static stuSqlite *ptrstuSql;
    static stuSqlite *getinstance(){
        if(nullptr == ptrstuSql){
            ptrstuSql = new stuSqlite;
        }
        return ptrstuSql;
    }

    explicit stuSqlite(QObject *parent = nullptr);

    quint32 getStuCnt();      //查询学生总人数

    QList<StuInfo> getPageStu(quint32,quint32);      //查询第几页学生数据,页数从第0页开始

    bool addStu(StuInfo);       //增加学生

    bool delStu(QString);       //删除学生

    void clearStuTable();       //清空学生表

    bool updateStuInfo(StuInfo);        //更新学生数据

    QList<UserInfo> getALLUser();       //查询所有用户

    bool isExistUser(QString);               //查询用户名是否存在

    bool isCurrentLoginUser(QString,QString);

    bool updateUser(UserInfo);      //更新用户信息

    bool addUser(UserInfo info);        //添加单个用户;

    bool delUser(QString);              //删除单个用户

    QList<StuInfo> singalSeachStu(QString,QString);      //学生单个指定信息的搜索


    quint32 getCourseCnt();                 //获得课程总数

    QList<CourseInfo> getCourse();          //获得课程全部信息

    QList<CourseInfo> singalSeachCoures(QString,QString);      //查单个课程信息

    bool addCourse(CourseInfo);             //添加课程信息

    bool delCourse(QString);             //删除课程信息

    bool updateCourseInfo(CourseInfo);


    //**********选课***********//
    QList<PickInfo> getPick();

    quint32 getPickCnt();

    QList<PickInfo> singalSeachPick(QString,QString);

    bool addPick(PickInfo);

    bool delPick(QString,QString);

    bool updatePickInfo(PickInfo);


signals:
private:
    QSqlDatabase db;
};


#endif // STUSQLITE_H
