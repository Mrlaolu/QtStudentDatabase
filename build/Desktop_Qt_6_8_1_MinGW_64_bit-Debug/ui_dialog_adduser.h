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
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Password;
    QLabel *label_2;
    QLabel *label;
    QComboBox *comboBox_Access;
    QLabel *label_3;
    QLineEdit *lineEdit_Username;

    void setupUi(QDialog *Dialog_AddUser)
    {
        if (Dialog_AddUser->objectName().isEmpty())
            Dialog_AddUser->setObjectName("Dialog_AddUser");
        Dialog_AddUser->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_AddUser->sizePolicy().hasHeightForWidth());
        Dialog_AddUser->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(Dialog_AddUser);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 250, 341, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget1 = new QWidget(Dialog_AddUser);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 80, 331, 111));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Password = new QLineEdit(layoutWidget1);
        lineEdit_Password->setObjectName("lineEdit_Password");

        gridLayout->addWidget(lineEdit_Password, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_Access = new QComboBox(layoutWidget1);
        comboBox_Access->addItem(QString());
        comboBox_Access->addItem(QString());
        comboBox_Access->setObjectName("comboBox_Access");

        gridLayout->addWidget(comboBox_Access, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_Username = new QLineEdit(layoutWidget1);
        lineEdit_Username->setObjectName("lineEdit_Username");

        gridLayout->addWidget(lineEdit_Username, 0, 1, 1, 1);


        retranslateUi(Dialog_AddUser);

        QMetaObject::connectSlotsByName(Dialog_AddUser);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddUser)
    {
        Dialog_AddUser->setWindowTitle(QCoreApplication::translate("Dialog_AddUser", "Dialog", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_AddUser", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog_AddUser", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_AddUser", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("Dialog_AddUser", "\347\224\250\346\210\267\345\220\215", nullptr));
        comboBox_Access->setItemText(0, QCoreApplication::translate("Dialog_AddUser", "1", nullptr));
        comboBox_Access->setItemText(1, QCoreApplication::translate("Dialog_AddUser", "2", nullptr));

        label_3->setText(QCoreApplication::translate("Dialog_AddUser", "\346\235\203\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AddUser: public Ui_Dialog_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDUSER_H
