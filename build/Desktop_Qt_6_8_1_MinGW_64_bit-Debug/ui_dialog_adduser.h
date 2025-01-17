/********************************************************************************
** Form generated from reading UI file 'dialog_adduser.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDUSER_H
#define UI_DIALOG_ADDUSER_H

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

class Ui_Dialog_AddUser
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label_Username;
    QLineEdit *lineEdit_Username;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QLabel *label_Access;
    QComboBox *comboBox_Access;

    void setupUi(QDialog *Dialog_AddUser)
    {
        if (Dialog_AddUser->objectName().isEmpty())
            Dialog_AddUser->setObjectName("Dialog_AddUser");
        Dialog_AddUser->resize(400, 300);
        layoutWidget = new QWidget(Dialog_AddUser);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 220, 341, 40));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget_2 = new QWidget(Dialog_AddUser);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(30, 20, 341, 180));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Username = new QLabel(layoutWidget_2);
        label_Username->setObjectName("label_Username");

        gridLayout->addWidget(label_Username, 0, 0, 1, 1);

        lineEdit_Username = new QLineEdit(layoutWidget_2);
        lineEdit_Username->setObjectName("lineEdit_Username");

        gridLayout->addWidget(lineEdit_Username, 0, 1, 1, 1);

        label_Password = new QLabel(layoutWidget_2);
        label_Password->setObjectName("label_Password");

        gridLayout->addWidget(label_Password, 1, 0, 1, 1);

        lineEdit_Password = new QLineEdit(layoutWidget_2);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Password, 1, 1, 1, 1);

        label_Access = new QLabel(layoutWidget_2);
        label_Access->setObjectName("label_Access");

        gridLayout->addWidget(label_Access, 2, 0, 1, 1);

        comboBox_Access = new QComboBox(layoutWidget_2);
        comboBox_Access->addItem(QString());
        comboBox_Access->addItem(QString());
        comboBox_Access->setObjectName("comboBox_Access");

        gridLayout->addWidget(comboBox_Access, 2, 1, 1, 1);


        retranslateUi(Dialog_AddUser);

        QMetaObject::connectSlotsByName(Dialog_AddUser);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddUser)
    {
        Dialog_AddUser->setWindowTitle(QCoreApplication::translate("Dialog_AddUser", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        Dialog_AddUser->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"     QDialog {\n"
"        background-color: #e6f3ff;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"     }\n"
"   ", nullptr));
        pushButton_save->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
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
        pushButton_save->setText(QCoreApplication::translate("Dialog_AddUser", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
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
        pushButton_cancel->setText(QCoreApplication::translate("Dialog_AddUser", "\345\217\226\346\266\210", nullptr));
        label_Username->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_Username->setText(QCoreApplication::translate("Dialog_AddUser", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_Username->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_Password->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_Password->setText(QCoreApplication::translate("Dialog_AddUser", "\345\257\206\347\240\201", nullptr));
        lineEdit_Password->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QLineEdit {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
        label_Access->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QLabel {\n"
"            font-size: 14px;\n"
"            font-weight: bold;\n"
"            color: #333;\n"
"         }\n"
"       ", nullptr));
        label_Access->setText(QCoreApplication::translate("Dialog_AddUser", "\346\235\203\351\231\220", nullptr));
        comboBox_Access->setItemText(0, QCoreApplication::translate("Dialog_AddUser", "1", nullptr));
        comboBox_Access->setItemText(1, QCoreApplication::translate("Dialog_AddUser", "2", nullptr));

        comboBox_Access->setStyleSheet(QCoreApplication::translate("Dialog_AddUser", "\n"
"         QComboBox {\n"
"            font-size: 14px;\n"
"            padding: 5px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 3px;\n"
"         }\n"
"       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AddUser: public Ui_Dialog_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDUSER_H
