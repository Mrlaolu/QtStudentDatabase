#include "stusqlite.h"

stuSqlite* stuSqlite::ptrstuSql = nullptr;

stuSqlite::stuSqlite(QObject *parent)
    : QObject{parent}
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\OneDrive - pop.zjgsu.edu.cn\\SMS\\data.db");

    if (!db.open()) {
        QMessageBox::warning(nullptr, tr("Unable to open database"),
                             tr("An error occurred while "
                                "opening the connection: %1") .arg(db.lastError().text()));
    }

    auto str = QCoreApplication::applicationDirPath() + "data.db";          //软件路径获取
    qDebug() << str;
    qDebug() << "Success open database";

}

quint32 stuSqlite::getStuCnt()
{
    QSqlQuery sql(db);
    sql.exec("SELECT COUNT(*) FROM Student");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<StuInfo> stuSqlite::getPageStu(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> l;
    QSqlQuery sql(db);
    QString strSql = QString("SELECT * FROM Student ORDER BY SNo LIMIT %1 OFFSET %2").arg(uiCnt).arg(page*uiCnt);
    sql.exec(strSql);

    StuInfo info;
    while(sql.next()){
        info.SNo = sql.value(0).toString();
        info.SName = sql.value(1).toString();
        info.Sex = sql.value(2).toString();
        info.InDate = sql.value(3).toString();
        info.Birth = sql.value(4).toString();
        info.Major = sql.value(5).toString();
        info.Class = sql.value(6).toString();
        info.Tele = sql.value(7).toString();
        l.push_front(info);
    }
    return l;
}

bool stuSqlite::addStu(StuInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("INSERT INTO Student VALUES ('%1','%2','%3','%4','%5','%6','%7','%8');").
                     arg(info.SNo).arg(info.SName).arg(info.Sex).arg(info.InDate).
                     arg(info.Birth).arg(info.Major).arg(info.Class).arg(info.Tele);
    return sql.exec(strSql);
}

bool stuSqlite::delStu(QString SNo)
{
    QSqlQuery sql(db);

    return  sql.exec(QString("DELETE FROM Student WHERE SNo = '%1'").arg(SNo));
}

void stuSqlite::clearStuTable()
{
    QSqlQuery sql(db);
    sql.exec(QString("DELETE FROM Student"));
}

bool stuSqlite::updateStuInfo(StuInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("Update Student SET SNo='%1',SName='%2', Sex='%3' ,InDate='%4' ,Birth='%5', Major='%6', Class='%7', Tele='%8' WHERE SNo='%9'").
                     arg(info.SNo).arg(info.SName).arg(info.Sex).arg(info.InDate).
                     arg(info.Birth).arg(info.Major).arg(info.Class).arg(info.Tele).arg(info.SNo);
    return sql.exec(strSql);
}

QList<UserInfo> stuSqlite::getALLUser()
{
    QList<UserInfo> l;
    QSqlQuery sql(db);
    QString strSql = QString("SELECT * FROM User");
    sql.exec(strSql);

    UserInfo info;
    while(sql.next()){
        info.Username = sql.value(0).toString();
        info.Password = sql.value(1).toString();
        info.Access = sql.value(2).toInt();
        l.push_front(info);
    }
    return l;
}

bool stuSqlite::isExistUser(QString Username)
{
    QSqlQuery sql(db);
    sql.exec(QString("SELECT * FROM User WHERE Username='%1'").arg(Username));
    return sql.next();
}

bool stuSqlite::isCurrentLoginUser(QString Username, QString Password)
{
    QSqlQuery sql(db);
    sql.exec(QString("SELECT * FROM User WHERE Username='%1' AND Password='%2'").arg(Username).arg(Password));
    return sql.next();
}

bool stuSqlite::updateUser(UserInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("Update User SET Username='%1',Password='%2', Access='%3' WHERE Username='%1'").
                    arg(info.Username).arg(info.Password).arg(info.Access);
    return sql.exec(strSql);
}

bool stuSqlite::addUser(UserInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("INSERT INTO User VALUES ('%1','%2','%3');").
                     arg(info.Username).arg(info.Password).arg(info.Access);
    bool ret = sql.exec(strSql);
    qDebug() << sql.lastError().text();
    return ret;
}

bool stuSqlite::delUser(QString Username)
{
    QSqlQuery sql(db);
    bool ret = sql.exec(QString("DELETE FROM User WHERE Username='%1'").arg(Username));
    qDebug() << 111 << sql.lastError().text();
    return ret;
}

QList<UserInfo> stuSqlite::singalSeachUser(QString key, QString context)
{
    QList<UserInfo> l;
    QSqlQuery sql(db);
    QString strSql;

    QMap<QString, QString> UserWordToKey;
    {   //初始化stu表
        UserWordToKey["用户名"] = "Username";
        UserWordToKey["密码"] = "Password";
        UserWordToKey["权限"] = "Access";
    }
    key = UserWordToKey[key];

    if(context.isEmpty()) strSql = QString("SELECT * FROM User");
    else strSql = QString("SELECT * FROM User WHERE %1 Like '%2\%'").arg(key).arg(context);
    qDebug() << strSql;
    sql.exec(strSql);

    UserInfo info;
    while(sql.next()){
        info.Username = sql.value(0).toString();
        info.Password = sql.value(1).toString();
        info.Access = sql.value(2).toInt();
        l.push_front(info);
    }
    return l;
}

int stuSqlite::getAccessUser(QString Username)
{
    QSqlQuery sql(db);
    sql.exec(QString("SELECT * FROM User WHERE Username='%1'").arg(Username));
    while(sql.next()){
        return sql.value(2).toInt();
    }
    return 0;
}

QList<StuInfo> stuSqlite::singalSeachStu(QString key, QString context)
{
    QList<StuInfo> l;
    QSqlQuery sql(db);
    QString strSql;

    QMap<QString, QString> stuWordToKey;
    {   //初始化stu表
        stuWordToKey["学号"] = "SNo";
        stuWordToKey["姓名"] = "SName";
        stuWordToKey["性别"] = "Sex";
        stuWordToKey["入学日期"] = "InData";
        stuWordToKey["生日"] = "Birth";
        stuWordToKey["专业"] = "Major";
        stuWordToKey["班级"] = "Class";
        stuWordToKey["联系电话"] = "Tele";
    }
    key = stuWordToKey[key];

    if(context.isEmpty()) strSql = QString("SELECT * FROM Student");
    else strSql = QString("SELECT * FROM Student WHERE %1 Like '%2\%'").arg(key).arg(context);
    qDebug() << strSql;
    sql.exec(strSql);

    StuInfo info;
    while(sql.next()){
        info.SNo = sql.value(0).toString();
        info.SName = sql.value(1).toString();
        info.Sex = sql.value(2).toString();
        info.InDate = sql.value(3).toString();
        info.Birth = sql.value(4).toString();
        info.Major = sql.value(5).toString();
        info.Class = sql.value(6).toString();
        info.Tele = sql.value(7).toString();
        l.push_front(info);
    }
    return l;
}


//************************课程表功能区****************************//
quint32 stuSqlite::getCourseCnt()
{
    QSqlQuery sql(db);
    sql.exec("SELECT COUNT(*) FROM Course");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<CourseInfo> stuSqlite::getCourse()
{
    QList<CourseInfo> l;
    QSqlQuery sql(db);
    QString strSql = QString("SELECT * FROM Course");
    sql.exec(strSql);

    CourseInfo info;
    while(sql.next()){
        info.CNo = sql.value(0).toString();
        info.CName = sql.value(1).toString();
        info.CTeacher = sql.value(2).toString();
        info.CAdder = sql.value(3).toString();
        info.CTime = sql.value(4).toString();
        info.Credit = sql.value(5).toReal();
        l.push_front(info);
    }
    return l;
}

QList<CourseInfo> stuSqlite::singalSeachCoures(QString key, QString context)
{
    QList<CourseInfo> l;
    QSqlQuery sql(db);
    QString strSql;

    QMap<QString, QString> CourseWordToKey;
    {   //初始化stu表
        CourseWordToKey["课程号"] = "CNo";
        CourseWordToKey["课程名"] = "CName";
        CourseWordToKey["授课老师"] = "CTeacher";
        CourseWordToKey["授课地点"] = "CAdder";
        CourseWordToKey["授课时间"] = "CTime";
        CourseWordToKey["学分"] = "Credit";
    }
    key = CourseWordToKey[key];

    if(context.isEmpty()) strSql = QString("SELECT * FROM Course");
    else strSql = QString("SELECT * FROM Course WHERE %1 Like '%2\%'").arg(key).arg(context);
    qDebug() << strSql;
    sql.exec(strSql);

    CourseInfo info;
    while(sql.next()){
        info.CNo = sql.value(0).toString();
        info.CName = sql.value(1).toString();
        info.CTeacher = sql.value(2).toString();
        info.CAdder = sql.value(3).toString();
        info.CTime = sql.value(4).toString();
        info.Credit = sql.value(5).toReal();
        l.push_front(info);
    }
    return l;
}

bool stuSqlite::addCourse(CourseInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("INSERT INTO Course VALUES ('%1','%2','%3','%4','%5','%6')").
                     arg(info.CNo).arg(info.CName).arg(info.CTeacher).arg(info.CAdder).
                     arg(info.CTime).arg(info.Credit);

    return sql.exec(strSql);
}

bool stuSqlite::delCourse(QString CNo)
{
    QSqlQuery sql(db);
    bool ret = sql.exec(QString("DELETE FROM Course WHERE CNo='%1'").arg(CNo));
    qDebug() << 111 << sql.lastError().text();
    return ret;
}

bool stuSqlite::updateCourseInfo(CourseInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("Update Course SET CNo='%1',CName='%2', CTeacher='%3' ,CAdder='%4' ,CTime='%5', Credit='%6' WHERE CNo='%1'").
                     arg(info.CNo).arg(info.CName).arg(info.CTeacher).arg(info.CAdder).
                     arg(info.CTime).arg(info.Credit);
    qDebug() << 111 << strSql << " " << sql.lastError().text();
    return sql.exec(strSql);
}


//************************选课表功能区****************************//
QList<PickInfo> stuSqlite::getPick()
{
    return singalSeachPick("学号","");
}

quint32 stuSqlite::getPickCnt()
{
    QSqlQuery sql(db);
    sql.exec("SELECT COUNT(*) FROM Pick");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<PickInfo> stuSqlite::singalSeachPick(QString key, QString context)
{
    QList<PickInfo> l;
    QSqlQuery sql(db);
    QString strSql;

    QMap<QString, QString> PickWordToKey;
    {   //初始化stu表
        PickWordToKey["学号"] = "SNo";
        PickWordToKey["课程号"] = "CNo";
        PickWordToKey["成绩"] = "Score";
    }
    key = PickWordToKey[key];

    if(context.isEmpty()) strSql = QString("SELECT * FROM Pick");
    else strSql = QString("SELECT * FROM Pick WHERE %1 Like '%2\%'").arg(key).arg(context);
    qDebug() << strSql;
    sql.exec(strSql);

    PickInfo info;
    while(sql.next()){
        info.SNo = sql.value(0).toString();
        info.CNo = sql.value(1).toString();
        info.Score = QString(sql.value(2).toString()).toInt();
        l.push_front(info);
    }
    return l;
}

bool stuSqlite::addPick(PickInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("INSERT INTO Pick VALUES ('%1','%2','%3')").
                     arg(info.SNo).arg(info.CNo).arg(info.Score);
    sql.exec("PRAGMA foreign_keys = ON;");
    return sql.exec(strSql);
}

bool stuSqlite::delPick(QString SNo,QString CNo)
{
    QSqlQuery sql(db);
    QString command = QString("DELETE FROM Pick WHERE SNo='%1'AND CNo='%2'").arg(SNo).arg(CNo);
    bool ret = sql.exec(command);
    qDebug() << 111 << command;
    sql.exec("PRAGMA foreign_keys = ON;");
    return ret;
}

bool stuSqlite::updatePickInfo(PickInfo info)
{
    QSqlQuery sql(db);
    QString strSql= QString("Update Pick SET SNo='%1',CNo='%2', Score='%3' WHERE SNo='%1'AND CNo='%2'").
                     arg(info.SNo).arg(info.CNo).arg(info.Score);
    qDebug() << 111 << strSql << " " << sql.lastError().text();
    sql.exec("PRAGMA foreign_keys = ON;");
    return sql.exec(strSql);
}







