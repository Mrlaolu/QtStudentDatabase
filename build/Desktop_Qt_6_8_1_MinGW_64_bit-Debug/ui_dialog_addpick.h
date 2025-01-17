/********************************************************************************
** Form generated from reading UI file 'dialog_addpick.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDPICK_H
#define UI_DIALOG_ADDPICK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_AddPick
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_SNo;
    QComboBox *comboBox_SNo;
    QLabel *label_SNameMark;
    QLabel *label_SName;
    QLabel *label_CNo;
    QComboBox *comboBox_CNo;
    QLabel *label_CNameMark;
    QLabel *label_CName;
    QLabel *label_Score;
    QLineEdit *lineEdit_Score;

    void setupUi(QDialog *Dialog_AddPick)
    {
        if (Dialog_AddPick->objectName().isEmpty())
            Dialog_AddPick->setObjectName("Dialog_AddPick");
        Dialog_AddPick->resize(404, 300);
        layoutWidget = new QWidget(Dialog_AddPick);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 240, 341, 44));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        widget = new QWidget(Dialog_AddPick);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 50, 341, 171));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_SNo = new QLabel(widget);
        label_SNo->setObjectName("label_SNo");

        gridLayout->addWidget(label_SNo, 0, 0, 1, 1);

        comboBox_SNo = new QComboBox(widget);
        comboBox_SNo->setObjectName("comboBox_SNo");

        gridLayout->addWidget(comboBox_SNo, 0, 1, 1, 1);

        label_SNameMark = new QLabel(widget);
        label_SNameMark->setObjectName("label_SNameMark");
        label_SNameMark->setStyleSheet(QString::fromUtf8("\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       "));

        gridLayout->addWidget(label_SNameMark, 1, 0, 1, 1);

        label_SName = new QLabel(widget);
        label_SName->setObjectName("label_SName");
        label_SName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_SName, 1, 1, 1, 1);

        label_CNo = new QLabel(widget);
        label_CNo->setObjectName("label_CNo");

        gridLayout->addWidget(label_CNo, 2, 0, 1, 1);

        comboBox_CNo = new QComboBox(widget);
        comboBox_CNo->setObjectName("comboBox_CNo");

        gridLayout->addWidget(comboBox_CNo, 2, 1, 1, 1);

        label_CNameMark = new QLabel(widget);
        label_CNameMark->setObjectName("label_CNameMark");
        label_CNameMark->setStyleSheet(QString::fromUtf8("\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       "));

        gridLayout->addWidget(label_CNameMark, 3, 0, 1, 1);

        label_CName = new QLabel(widget);
        label_CName->setObjectName("label_CName");
        label_CName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_CName, 3, 1, 1, 1);

        label_Score = new QLabel(widget);
        label_Score->setObjectName("label_Score");

        gridLayout->addWidget(label_Score, 4, 0, 1, 1);

        lineEdit_Score = new QLineEdit(widget);
        lineEdit_Score->setObjectName("lineEdit_Score");

        gridLayout->addWidget(lineEdit_Score, 4, 1, 1, 1);


        retranslateUi(Dialog_AddPick);

        QMetaObject::connectSlotsByName(Dialog_AddPick);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddPick)
    {
        Dialog_AddPick->setWindowTitle(QCoreApplication::translate("Dialog_AddPick", "\351\200\211\346\213\251\350\257\276\347\250\213\345\222\214\346\210\220\347\273\251", nullptr));
        Dialog_AddPick->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"     QDialog {\n"
"        background-color: #e6f3ff;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"     }\n"
"   ", nullptr));
        pushButton_save->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
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
        pushButton_save->setText(QCoreApplication::translate("Dialog_AddPick", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
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
        pushButton_cancel->setText(QCoreApplication::translate("Dialog_AddPick", "\345\217\226\346\266\210", nullptr));
        label_SNo->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_SNo->setText(QCoreApplication::translate("Dialog_AddPick", "\345\255\246\345\217\267", nullptr));
        comboBox_SNo->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QComboBox {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_SNameMark->setText(QCoreApplication::translate("Dialog_AddPick", "\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        label_SName->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_SName->setText(QString());
        label_CNo->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CNo->setText(QCoreApplication::translate("Dialog_AddPick", "\350\257\276\347\250\213\345\217\267", nullptr));
        comboBox_CNo->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QComboBox {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_CNameMark->setText(QCoreApplication::translate("Dialog_AddPick", "\350\257\276\347\250\213\345\220\215", nullptr));
        label_CName->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_CName->setText(QString());
        label_Score->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_Score->setText(QCoreApplication::translate("Dialog_AddPick", "\346\210\220\347\273\251", nullptr));
        lineEdit_Score->setStyleSheet(QCoreApplication::translate("Dialog_AddPick", "\n"
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
    class Dialog_AddPick: public Ui_Dialog_AddPick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDPICK_H
