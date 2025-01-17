/********************************************************************************
** Form generated from reading UI file 'dialog_addstu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDSTU_H
#define UI_DIALOG_ADDSTU_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_AddStu
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_Major;
    QLineEdit *lineEdit_Major;
    QLineEdit *lineEdit_SName;
    QLineEdit *lineEdit_SNo;
    QLabel *label_SName;
    QLabel *label_Sex;
    QLabel *label_InDate;
    QLineEdit *lineEdit_Class;
    QDateEdit *dateEdit_Birth;
    QLineEdit *lineEdit_Tele;
    QLabel *lable_SNo;
    QLabel *label_Tele;
    QDateEdit *dateEdit_InDate;
    QLabel *label_Birth;
    QLabel *label_Class;
    QComboBox *comboBox_Sex;

    void setupUi(QDialog *Dialog_AddStu)
    {
        if (Dialog_AddStu->objectName().isEmpty())
            Dialog_AddStu->setObjectName("Dialog_AddStu");
        Dialog_AddStu->resize(480, 480);
        Dialog_AddStu->setStyleSheet(QString::fromUtf8("\n"
"      QDialog {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"        color: white;\n"
"      }\n"
"\n"
"      QLabel {\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: white;\n"
"      }\n"
"\n"
"      QLineEdit, QComboBox, QDateEdit {\n"
"        background-color: #ffffff;\n"
"        color: #333;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        font-size: 14px;\n"
"      }\n"
"\n"
"      QLineEdit:focus, QComboBox:focus, QDateEdit:focus {\n"
"        border-color: #3498db;\n"
"      }\n"
"\n"
"      QPushButton {\n"
"        background-color: #3498db;\n"
"        color: white;\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        border-radius: 5px;\n"
"        padding: 10px 20px;\n"
"        border: none;\n"
"      }\n"
"\n"
"      QPushButton:hover {\n"
"        background-color: #2980b9;\n"
"      }\n"
"\n"
"      QPushButton:pressed {\n"
"  "
                        "      background-color: #2472a4;\n"
"      }\n"
"\n"
"      QComboBox {\n"
"        padding-left: 8px;\n"
"        font-size: 14px;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 5px;\n"
"      }\n"
"\n"
"      QComboBox::drop-down {\n"
"        subcontrol-origin: padding;\n"
"        subcontrol-position: right center;\n"
"        width: 20px;\n"
"        border-left: 1px solid #ccc;\n"
"      }\n"
"\n"
"      QComboBox::down-arrow {\n"
"        image: url(:/icons/down_arrow.png);\n"
"        width: 12px;\n"
"        height: 12px;\n"
"      }\n"
"\n"
"      QComboBox:hover {\n"
"        border-color: #3498db;\n"
"      }\n"
"\n"
"      QCheckBox {\n"
"        font-size: 14px;\n"
"        color: white;\n"
"      }\n"
"\n"
"      QDateEdit {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        font-size: 14px;\n"
"      }\n"
"    "));
        layoutWidget = new QWidget(Dialog_AddStu);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 420, 451, 40));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget1 = new QWidget(Dialog_AddStu);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 60, 381, 342));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Major = new QLabel(layoutWidget1);
        label_Major->setObjectName("label_Major");

        gridLayout->addWidget(label_Major, 5, 0, 1, 1);

        lineEdit_Major = new QLineEdit(layoutWidget1);
        lineEdit_Major->setObjectName("lineEdit_Major");

        gridLayout->addWidget(lineEdit_Major, 5, 2, 1, 1);

        lineEdit_SName = new QLineEdit(layoutWidget1);
        lineEdit_SName->setObjectName("lineEdit_SName");

        gridLayout->addWidget(lineEdit_SName, 1, 2, 1, 1);

        lineEdit_SNo = new QLineEdit(layoutWidget1);
        lineEdit_SNo->setObjectName("lineEdit_SNo");

        gridLayout->addWidget(lineEdit_SNo, 0, 2, 1, 1);

        label_SName = new QLabel(layoutWidget1);
        label_SName->setObjectName("label_SName");

        gridLayout->addWidget(label_SName, 1, 0, 1, 1);

        label_Sex = new QLabel(layoutWidget1);
        label_Sex->setObjectName("label_Sex");

        gridLayout->addWidget(label_Sex, 2, 0, 1, 1);

        label_InDate = new QLabel(layoutWidget1);
        label_InDate->setObjectName("label_InDate");

        gridLayout->addWidget(label_InDate, 3, 0, 1, 1);

        lineEdit_Class = new QLineEdit(layoutWidget1);
        lineEdit_Class->setObjectName("lineEdit_Class");

        gridLayout->addWidget(lineEdit_Class, 6, 2, 1, 1);

        dateEdit_Birth = new QDateEdit(layoutWidget1);
        dateEdit_Birth->setObjectName("dateEdit_Birth");
        dateEdit_Birth->setMinimumSize(QSize(0, 35));
        dateEdit_Birth->setDateTime(QDateTime(QDate(1969, 12, 31), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit_Birth, 4, 2, 1, 1);

        lineEdit_Tele = new QLineEdit(layoutWidget1);
        lineEdit_Tele->setObjectName("lineEdit_Tele");

        gridLayout->addWidget(lineEdit_Tele, 7, 2, 1, 1);

        lable_SNo = new QLabel(layoutWidget1);
        lable_SNo->setObjectName("lable_SNo");

        gridLayout->addWidget(lable_SNo, 0, 0, 1, 1);

        label_Tele = new QLabel(layoutWidget1);
        label_Tele->setObjectName("label_Tele");

        gridLayout->addWidget(label_Tele, 7, 0, 1, 1);

        dateEdit_InDate = new QDateEdit(layoutWidget1);
        dateEdit_InDate->setObjectName("dateEdit_InDate");
        dateEdit_InDate->setMinimumSize(QSize(0, 35));
        dateEdit_InDate->setDateTime(QDateTime(QDate(1969, 12, 29), QTime(0, 0, 0)));
        dateEdit_InDate->setMaximumDate(QDate(9998, 12, 31));
        dateEdit_InDate->setCurrentSection(QDateTimeEdit::Section::YearSection);
        dateEdit_InDate->setCurrentSectionIndex(0);

        gridLayout->addWidget(dateEdit_InDate, 3, 2, 1, 1);

        label_Birth = new QLabel(layoutWidget1);
        label_Birth->setObjectName("label_Birth");

        gridLayout->addWidget(label_Birth, 4, 0, 1, 1);

        label_Class = new QLabel(layoutWidget1);
        label_Class->setObjectName("label_Class");

        gridLayout->addWidget(label_Class, 6, 0, 1, 1);

        comboBox_Sex = new QComboBox(layoutWidget1);
        comboBox_Sex->addItem(QString());
        comboBox_Sex->addItem(QString());
        comboBox_Sex->addItem(QString());
        comboBox_Sex->setObjectName("comboBox_Sex");

        gridLayout->addWidget(comboBox_Sex, 2, 2, 1, 1);

        QWidget::setTabOrder(lineEdit_SNo, lineEdit_SName);
        QWidget::setTabOrder(lineEdit_SName, comboBox_Sex);
        QWidget::setTabOrder(comboBox_Sex, dateEdit_InDate);
        QWidget::setTabOrder(dateEdit_InDate, dateEdit_Birth);
        QWidget::setTabOrder(dateEdit_Birth, lineEdit_Major);
        QWidget::setTabOrder(lineEdit_Major, lineEdit_Class);
        QWidget::setTabOrder(lineEdit_Class, lineEdit_Tele);
        QWidget::setTabOrder(lineEdit_Tele, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_cancel);

        retranslateUi(Dialog_AddStu);

        QMetaObject::connectSlotsByName(Dialog_AddStu);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddStu)
    {
        Dialog_AddStu->setWindowTitle(QCoreApplication::translate("Dialog_AddStu", "\345\242\236\345\212\240\345\255\246\347\224\237", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_AddStu", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog_AddStu", "\345\217\226\346\266\210", nullptr));
        label_Major->setText(QCoreApplication::translate("Dialog_AddStu", "\344\270\223\344\270\232", nullptr));
        label_SName->setText(QCoreApplication::translate("Dialog_AddStu", "\345\247\223\345\220\215", nullptr));
        label_Sex->setText(QCoreApplication::translate("Dialog_AddStu", "\346\200\247\345\210\253", nullptr));
        label_InDate->setText(QCoreApplication::translate("Dialog_AddStu", "\345\205\245\345\255\246\345\271\264\344\273\275", nullptr));
        lable_SNo->setText(QCoreApplication::translate("Dialog_AddStu", "\345\255\246\345\217\267\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_Tele->setText(QCoreApplication::translate("Dialog_AddStu", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        dateEdit_InDate->setDisplayFormat(QCoreApplication::translate("Dialog_AddStu", "yyyy", nullptr));
        label_Birth->setText(QCoreApplication::translate("Dialog_AddStu", "\347\224\237\346\227\245", nullptr));
        label_Class->setText(QCoreApplication::translate("Dialog_AddStu", "\347\217\255\347\272\247", nullptr));
        comboBox_Sex->setItemText(0, QCoreApplication::translate("Dialog_AddStu", "\347\224\267", nullptr));
        comboBox_Sex->setItemText(1, QCoreApplication::translate("Dialog_AddStu", "\345\245\263", nullptr));
        comboBox_Sex->setItemText(2, QCoreApplication::translate("Dialog_AddStu", "\346\234\252\347\237\245", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog_AddStu: public Ui_Dialog_AddStu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDSTU_H
