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
    // if (!db.open()) {
    //     qDebug() << "Can't open database" << db.lastError();
    // }




    auto str = QCoreApplication::applicationDirPath() + "data.db";          //软件路径获取
    qDebug() << str;
    qDebug() << "Success open database";


    //test.............//

    // QSqlQuery q("",db);
    //  q.exec("INSERT INTO student VALUES ('2', 'TEST', '1990-01-01', 'Computer Science','','','','')");


    // StuInfo s;s.SNo = "test";
    // addStu(s);
    // for(int i = 0;i < 10;++i){
    //     s.SNo = QString::number(i);
    //     addStu(s);
    // }
    // getStuCnt();

    // getPageStu(2,3);
    // qDebug() << delStu("3");
    // // clearStuTable();
    // s.SNo = "4",s.SName = "SHUANG";
    // updateStuInfo(s);

    // UserInfo info;
    // for(int i = 0;i < 10;++i){
    //     info.Username = QString::number(i);
    //     addUser(info);
    // }
    // qDebug() << isExistUser("3");
    // qDebug() << delUser("2");
    // qDebug() << isExistUser("2");
    // updateUser({"3","123","ad"});
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
    QString strSql = QString("SELECT * FROM Username");
    sql.exec(strSql);

    UserInfo info;
    while(sql.next()){
        info.Username = sql.value(0).toString();
        info.Password = sql.value(1).toString();
        info.Access = sql.value(2).toString();
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


