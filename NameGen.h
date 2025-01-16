#ifndef NAMEGEN_H
#define NAMEGEN_H
#include <QCoreApplication>
#include <QVector>
#include <QString>
#include <QRandomGenerator>
#include <QTextStream>
#include <ctime>

QString generateName(int nameLength) {
    QVector<QString> surnames = {"张", "李", "王", "赵", "刘", "陈", "杨", "黄", "周", "吴",
                                 "孙", "马", "林", "冯", "程", "曹", "高", "邓", "许", "潘",
                                 "秦", "宋", "唐", "许", "唐", "蒋", "杜", "邱", "谢"};

    QVector<QString> firstNames = {
        "伟", "娜", "芳", "丽", "强", "磊", "洋", "静", "涛", "明",
        "建国", "子琪", "文杰", "思雨", "海涛", "子涵", "思聪", "晓丽", "小龙",
        "晓东", "明辉", "国强", "俊杰", "嘉伟", "瑞雪", "文博", "雨桐", "宇轩",
        "俊杰", "一鸣", "思彤", "子晴", "思洁", "淑娟", "家豪", "小凡", "思妍",
        "若瑶", "子轩", "子诺", "楚涵", "奕辰", "乐乐", "宇浩", "佳怡", "子桐",
        "昊天", "欣怡", "心怡", "子萱", "小雪", "锦程", "晨曦", "雪婷", "思雅",
        "梓涵", "晨阳", "梓萱", "心瑶", "子璇", "诗雨", "曼婷", "依娜", "小洁",
        "东风", "千雪", "怡宁", "心雨", "雅婷", "家琪", "雅涵", "瑾瑜", "子悠"
    };

    int surnameIndex = QRandomGenerator::global()->bounded(surnames.size());
    QString fullName = surnames[surnameIndex];

    int nameLengthRemaining = nameLength - 1;

    while (nameLengthRemaining > 0) {
        int firstNameIndex = QRandomGenerator::global()->bounded(firstNames.size());
        QString firstName = firstNames[firstNameIndex];

        if (nameLengthRemaining >= firstName.length()) {
            fullName += firstName;
            nameLengthRemaining -= firstName.length();
        } else {
            fullName += firstName.left(nameLengthRemaining);
            break;
        }
    }

    return fullName;
}

#endif // NAMEGEN_H
