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
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_CNo;
    QLabel *label_CName;
    QLabel *label_Class;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_CTime;
    QTimeEdit *timeEdit_CTime;
    QLabel *label_CTeacher;
    QLineEdit *lineEdit_CTeacher;
    QLineEdit *lineEdit_Credit;
    QLineEdit *lineEdit_CName;
    QLabel *lable_CNo;
    QLineEdit *lineEdit_CAdder;
    QLabel *label_CTime;
    QLabel *label_Credit;

    void setupUi(QDialog *dialog_addCourse)
    {
        if (dialog_addCourse->objectName().isEmpty())
            dialog_addCourse->setObjectName("dialog_addCourse");
        dialog_addCourse->resize(480, 480);
        layoutWidget = new QWidget(dialog_addCourse);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 430, 451, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        layoutWidget1 = new QWidget(dialog_addCourse);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(50, 100, 381, 261));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_CNo = new QLineEdit(layoutWidget1);
        lineEdit_CNo->setObjectName("lineEdit_CNo");

        gridLayout->addWidget(lineEdit_CNo, 0, 1, 1, 1);

        label_CName = new QLabel(layoutWidget1);
        label_CName->setObjectName("label_CName");

        gridLayout->addWidget(label_CName, 1, 0, 1, 1);

        label_Class = new QLabel(layoutWidget1);
        label_Class->setObjectName("label_Class");

        gridLayout->addWidget(label_Class, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox_CTime = new QComboBox(layoutWidget1);
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->addItem(QString());
        comboBox_CTime->setObjectName("comboBox_CTime");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_CTime->sizePolicy().hasHeightForWidth());
        comboBox_CTime->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox_CTime);

        timeEdit_CTime = new QTimeEdit(layoutWidget1);
        timeEdit_CTime->setObjectName("timeEdit_CTime");

        horizontalLayout_2->addWidget(timeEdit_CTime);


        gridLayout->addLayout(horizontalLayout_2, 5, 1, 1, 1);

        label_CTeacher = new QLabel(layoutWidget1);
        label_CTeacher->setObjectName("label_CTeacher");

        gridLayout->addWidget(label_CTeacher, 2, 0, 1, 1);

        lineEdit_CTeacher = new QLineEdit(layoutWidget1);
        lineEdit_CTeacher->setObjectName("lineEdit_CTeacher");

        gridLayout->addWidget(lineEdit_CTeacher, 2, 1, 1, 1);

        lineEdit_Credit = new QLineEdit(layoutWidget1);
        lineEdit_Credit->setObjectName("lineEdit_Credit");

        gridLayout->addWidget(lineEdit_Credit, 7, 1, 1, 1);

        lineEdit_CName = new QLineEdit(layoutWidget1);
        lineEdit_CName->setObjectName("lineEdit_CName");

        gridLayout->addWidget(lineEdit_CName, 1, 1, 1, 1);

        lable_CNo = new QLabel(layoutWidget1);
        lable_CNo->setObjectName("lable_CNo");

        gridLayout->addWidget(lable_CNo, 0, 0, 1, 1);

        lineEdit_CAdder = new QLineEdit(layoutWidget1);
        lineEdit_CAdder->setObjectName("lineEdit_CAdder");

        gridLayout->addWidget(lineEdit_CAdder, 3, 1, 1, 1);

        label_CTime = new QLabel(layoutWidget1);
        label_CTime->setObjectName("label_CTime");

        gridLayout->addWidget(label_CTime, 5, 0, 1, 1);

        label_Credit = new QLabel(layoutWidget1);
        label_Credit->setObjectName("label_Credit");

        gridLayout->addWidget(label_Credit, 7, 0, 1, 1);

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
        dialog_addCourse->setWindowTitle(QCoreApplication::translate("dialog_addCourse", "Dialog", nullptr));
        pushButton_save->setText(QCoreApplication::translate("dialog_addCourse", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("dialog_addCourse", "\345\217\226\346\266\210", nullptr));
        label_CName->setText(QCoreApplication::translate("dialog_addCourse", "\350\257\276\347\250\213\345\220\215", nullptr));
        label_Class->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\345\234\260\347\202\271", nullptr));
        comboBox_CTime->setItemText(0, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\270\200", nullptr));
        comboBox_CTime->setItemText(1, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\272\214", nullptr));
        comboBox_CTime->setItemText(2, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\270\211", nullptr));
        comboBox_CTime->setItemText(3, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\233\233", nullptr));
        comboBox_CTime->setItemText(4, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\344\272\224", nullptr));
        comboBox_CTime->setItemText(5, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\205\255", nullptr));
        comboBox_CTime->setItemText(6, QCoreApplication::translate("dialog_addCourse", "\346\230\237\346\234\237\345\244\251", nullptr));

        timeEdit_CTime->setDisplayFormat(QCoreApplication::translate("dialog_addCourse", "HH:mm:ss", nullptr));
        label_CTeacher->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\346\225\231\345\270\210", nullptr));
        lable_CNo->setText(QCoreApplication::translate("dialog_addCourse", "\350\257\276\347\250\213\345\217\267\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_CTime->setText(QCoreApplication::translate("dialog_addCourse", "\346\216\210\350\257\276\346\227\266\351\227\264", nullptr));
        label_Credit->setText(QCoreApplication::translate("dialog_addCourse", "\345\255\246\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_addCourse: public Ui_dialog_addCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDCOURSE_H
