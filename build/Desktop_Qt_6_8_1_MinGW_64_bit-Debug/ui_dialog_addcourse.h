/********************************************************************************
** Form generated from reading UI file 'dialog_addcourse.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDCOURSE_H
#define UI_DIALOG_ADDCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_addCourse
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *lable_CNo;
    QLineEdit *lineEdit_CNo;
    QLabel *label_CName;
    QLineEdit *lineEdit_CName;
    QLabel *label_CTeacher;
    QLineEdit *lineEdit_CTeacher;
    QLabel *label_CClass;
    QLineEdit *lineEdit_CAdder;
    QLabel *label_CTime;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_CTime;
    QTimeEdit *timeEdit_CTime;
    QLabel *label_Credit;
    QLineEdit *lineEdit_Credit;

    void setupUi(QDialog *dialog_addCourse)
    {
        if (dialog_addCourse->objectName().isEmpty())
            dialog_addCourse->setObjectName("dialog_addCourse");
        dialog_addCourse->resize(400, 400);
        dialog_addCourse->setStyleSheet(QString::fromUtf8("\n"
"     QDialog {\n"
"        background-color: rgb(4, 131, 212);\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"     }\n"
"   "));
        layoutWidget = new QWidget(dialog_addCourse);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 350, 381, 44));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget_2 = new QWidget(dialog_addCourse);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 20, 361, 311));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lable_CNo = new QLabel(layoutWidget_2);
        lable_CNo->setObjectName("lable_CNo");

        gridLayout->addWidget(lable_CNo, 0, 0, 1, 1);

        lineEdit_CNo = new QLineEdit(layoutWidget_2);
        lineEdit_CNo->setObjectName("lineEdit_CNo");

        gridLayout->addWidget(lineEdit_CNo, 0, 1, 1, 1);

        label_CName = new QLabel(layoutWidget_2);
        label_CName->setObjectName("label_CName");

        gridLayout->addWidget(label_CName, 1, 0, 1, 1);

        lineEdit_CName = new QLineEdit(layoutWidget_2);
        lineEdit_CName->setObjectName("lineEdit_CName");

        gridLayout->addWidget(lineEdit_CName, 1, 1, 1, 1);

        label_CTeacher = new QLabel(layoutWidget_2);
        label_CTeacher->setObjectName("label_CTeacher");

        gridLayout->addWidget(label_CTeacher, 2, 0, 1, 1);

        lineEdit_CTeacher = new QLineEdit(layoutWidget_2);
        lineEdit_CTeacher->setObjectName("lineEdit_CTeacher");

        gridLayout->addWidget(lineEdit_CTeacher, 2, 1, 1, 1);

        label_CClass = new QLabel(layoutWidget_2);
        label_CClass->setObjectName("label_CClass");

        gridLayout->addWidget(label_CClass, 3, 0, 1, 1);

        lineEdit_CAdder = new QLineEdit(layoutWidget_2);
        lineEdit_CAdder->setObjectName("lineEdit_CAdder");

        gridLayout->addWidget(lineEdit_CAdder, 3, 1, 1, 1);

        label_CTime = new QLabel(layoutWidget_2);
        label_CTime->setObjectName("label_CTime");

        gridLayout->addWidget(label_CTime, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox_CTime = new QComboBox(layoutWidget_2);
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->setObjectName("comboBox_CTime");

        horizontalLayout_2->addWidget(comboBox_CTime);

        timeEdit_CTime = new QTimeEdit(layoutWidget_2);
        timeEdit_CTime->setObjectName("timeEdit_CTime");
        timeEdit_CTime->setMinimumSize(QSize(0, 35));
        timeEdit_CTime->setStyleSheet(QString::fromUtf8("           QTimeEdit {\n"
"                font-size: 14px;  <!-- \344\277\235\346\214\201\344\270\216\345\205\266\344\273\226\346\226\207\346\234\254\346\241\206\347\233\270\345\220\214\347\232\204\345\255\227\344\275\223\345\244\247\345\260\217 -->\n"
"                padding: 5px;  <!-- \344\277\235\346\214\201\344\270\200\350\207\264\347\232\204\345\206\205\350\276\271\350\267\235 -->\n"
"                border: 1px solid #ccc;  <!-- \344\277\235\346\214\201\344\270\200\350\207\264\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 -->\n"
"                border-radius: 3px;  <!-- \345\234\206\350\247\222\350\256\276\347\275\256\344\270\272\344\270\216\345\205\266\344\273\226\346\226\207\346\234\254\346\241\206\344\270\200\350\207\264 -->\n"
"            }"));

        horizontalLayout_2->addWidget(timeEdit_CTime);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        label_Credit = new QLabel(layoutWidget_2);
        label_Credit->setObjectName("label_Credit");

        gridLayout->addWidget(label_Credit, 5, 0, 1, 1);

        lineEdit_Credit = new QLineEdit(layoutWidget_2);
        lineEdit_Credit->setObjectName("lineEdit_Credit");

        gridLayout->addWidget(lineEdit_Credit, 5, 1, 1, 1);

        QWidget::setTabOrder(lineEdit_CNo, lineEdit_CName);
        QWidget::setTabOrder(lineEdit_CName, lineEdit_CTeacher);
        QWidget::setTabOrder(lineEdit_CTeacher, lineEdit_CAdder);
        QWidget::setTabOrder(lineEdit_CAdder, lineEdit_Credit);
        QWidget::setTabOrder(lineEdit_Credit, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_cancel);

        retranslateUi(dialog_addCourse);

        QMetaObject::connectSlotsByName(dialog_addCourse);
    } // setupUi

    void retranslateUi(QDialog *dialog_addCourse)
    {
        dialog_addCourse->setWindowTitle(QCoreApplication::translate("dialog_addCourse", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
        pushButton_save->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QPushButton {\n"
"            background-color: #4CAF50;\n"
"            color: white;\n"
"            font-size: 16px;\n"
"            font-weight: bold;\n"
"            border-radius: 5px;\n"
"            padding: 10px 20px;\n"
"            border: 1px solid #4CAF50;\n"
"            min-width: 100px;\n"
"         }\n"
"         QPushButton:hover {\n"
"            background-color: #45a049;\n"
"         }\n"
"         QPushButton:pressed {\n"
"            background-color: #388E3C;\n"
"         }\n"
"       ", nullptr));
        pushButton_save->setText(QCoreApplication::translate("dialog_addCourse", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QPushButton {\n"
"            background-color: #f44336;\n"
"            color: white;\n"
"            font-size: 16px;\n"
"            font-weight: bold;\n"
"            border-radius: 5px;\n"
"            padding: 10px 20px;\n"
"            border: 1px solid #f44336;\n"
"            min-width: 100px;\n"
"         }\n"
"         QPushButton:hover {\n"
"            background-color: #e53935;\n"
"         }\n"
"         QPushButton:pressed {\n"
"            background-color: #d32f2f;\n"
"         }\n"
"       ", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("dialog_addCourse", "\345\217\226\346\266\210", nullptr));
        lable_CNo->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        lable_CNo->setText(QCoreApplication::translate("dialog_addCourse", "\350\257\276\347\250\213\345\217\267\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        lineEdit_CNo->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_CName->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CName->setText(QCoreApplication::translate("dialog_addCourse", "\350\257\276\347\250\213\345\220\215", nullptr));
        lineEdit_CName->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_CTeacher->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CTeacher->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\346\225\231\345\270\210", nullptr));
        lineEdit_CTeacher->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_CClass->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CClass->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\345\234\260\347\202\271", nullptr));
        lineEdit_CAdder->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_CTime->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CTime->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\346\227\266\351\227\264", nullptr));
        comboBox_CTime->setItemText(0, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\270\200", nullptr));
        comboBox_CTime->setItemText(1, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\272\214", nullptr));
        comboBox_CTime->setItemText(2, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\270\211", nullptr));
        comboBox_CTime->setItemText(3, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\233\233", nullptr));
        comboBox_CTime->setItemText(4, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\272\224", nullptr));
        comboBox_CTime->setItemText(5, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\205\255", nullptr));
        comboBox_CTime->setItemText(6, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\244\251", nullptr));

        comboBox_CTime->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"           QComboBox {\n"
"              font-size: 14px;\n"
"              padding: 5px;\n"
"              border: 1px solid #ccc;\n"
"              border-radius: 3px;\n"
"           }\n"
"         ", nullptr));
        timeEdit_CTime->setDisplayFormat(QCoreApplication::translate("dialog_addCourse", "HH:mm", nullptr));
        label_Credit->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_Credit->setText(QCoreApplication::translate("dialog_addCourse", "\345\255\246\345\210\206", nullptr));
        lineEdit_Credit->setStyleSheet(QCoreApplication::translate("dialog_addCourse", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_addCourse: public Ui_dialog_addCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDCOURSE_H
