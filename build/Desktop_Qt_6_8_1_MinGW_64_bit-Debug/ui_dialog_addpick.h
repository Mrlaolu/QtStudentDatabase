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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_AddPick
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_SNo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_SNameMark;
    QLabel *label_SName;
    QLineEdit *lineEdit_Score;
    QLabel *label_Score;
    QLabel *label_CNo;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_CNo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_CNameMark;
    QLabel *label_CName;
    QLabel *label_SNo;

    void setupUi(QDialog *Dialog_AddPick)
    {
        if (Dialog_AddPick->objectName().isEmpty())
            Dialog_AddPick->setObjectName("Dialog_AddPick");
        Dialog_AddPick->resize(400, 300);
        layoutWidget = new QWidget(Dialog_AddPick);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 240, 341, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget1 = new QWidget(Dialog_AddPick);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 60, 341, 148));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        comboBox_SNo = new QComboBox(layoutWidget1);
        comboBox_SNo->setObjectName("comboBox_SNo");
        comboBox_SNo->setEditable(true);

        verticalLayout->addWidget(comboBox_SNo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_SNameMark = new QLabel(layoutWidget1);
        label_SNameMark->setObjectName("label_SNameMark");

        horizontalLayout_2->addWidget(label_SNameMark);

        label_SName = new QLabel(layoutWidget1);
        label_SName->setObjectName("label_SName");

        horizontalLayout_2->addWidget(label_SName);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        lineEdit_Score = new QLineEdit(layoutWidget1);
        lineEdit_Score->setObjectName("lineEdit_Score");

        gridLayout->addWidget(lineEdit_Score, 2, 1, 1, 1);

        label_Score = new QLabel(layoutWidget1);
        label_Score->setObjectName("label_Score");

        gridLayout->addWidget(label_Score, 2, 0, 1, 1);

        label_CNo = new QLabel(layoutWidget1);
        label_CNo->setObjectName("label_CNo");

        gridLayout->addWidget(label_CNo, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        comboBox_CNo = new QComboBox(layoutWidget1);
        comboBox_CNo->setObjectName("comboBox_CNo");
        comboBox_CNo->setEditable(true);

        verticalLayout_2->addWidget(comboBox_CNo);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_CNameMark = new QLabel(layoutWidget1);
        label_CNameMark->setObjectName("label_CNameMark");

        horizontalLayout_3->addWidget(label_CNameMark);

        label_CName = new QLabel(layoutWidget1);
        label_CName->setObjectName("label_CName");

        horizontalLayout_3->addWidget(label_CName);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        label_SNo = new QLabel(layoutWidget1);
        label_SNo->setObjectName("label_SNo");

        gridLayout->addWidget(label_SNo, 0, 0, 1, 1);


        retranslateUi(Dialog_AddPick);

        QMetaObject::connectSlotsByName(Dialog_AddPick);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddPick)
    {
        Dialog_AddPick->setWindowTitle(QCoreApplication::translate("Dialog_AddPick", "Dialog", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_AddPick", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog_AddPick", "\345\217\226\346\266\210", nullptr));
        label_SNameMark->setText(QCoreApplication::translate("Dialog_AddPick", "\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        label_SName->setText(QCoreApplication::translate("Dialog_AddPick", "TextLabel", nullptr));
        label_Score->setText(QCoreApplication::translate("Dialog_AddPick", "\346\210\220\347\273\251", nullptr));
        label_CNo->setText(QCoreApplication::translate("Dialog_AddPick", "\350\257\276\347\250\213\345\217\267", nullptr));
        label_CNameMark->setText(QCoreApplication::translate("Dialog_AddPick", "\350\257\276\347\250\213\345\220\215", nullptr));
        label_CName->setText(QCoreApplication::translate("Dialog_AddPick", "TextLabel", nullptr));
        label_SNo->setText(QCoreApplication::translate("Dialog_AddPick", "\345\255\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AddPick: public Ui_Dialog_AddPick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDPICK_H
