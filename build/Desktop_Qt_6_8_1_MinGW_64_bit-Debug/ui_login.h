/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LOGIN
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Username;
    QLabel *label_3;
    QLineEdit *lineEdit_Password;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_exit;
    QPushButton *btn_login;

    void setupUi(QWidget *LOGIN)
    {
        if (LOGIN->objectName().isEmpty())
            LOGIN->setObjectName("LOGIN");
        LOGIN->resize(400, 240);
        gridLayout_3 = new QGridLayout(LOGIN);
        gridLayout_3->setObjectName("gridLayout_3");
        widget_2 = new QWidget(LOGIN);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_Username = new QLineEdit(widget_2);
        lineEdit_Username->setObjectName("lineEdit_Username");
        lineEdit_Username->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0.7);"));
        lineEdit_Username->setMaxLength(32);

        gridLayout_2->addWidget(lineEdit_Username, 0, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_Password = new QLineEdit(widget_2);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0.7);"));
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(lineEdit_Password, 1, 1, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        label = new QLabel(LOGIN);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"            font-size: 40px;\n"
"            font-weight: bold;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        widget = new QWidget(LOGIN);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 50));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(2, 2, 2, 2);
        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setMinimumSize(QSize(142, 32));
        btn_exit->setStyleSheet(QString::fromUtf8("\n"
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
"       "));

        gridLayout->addWidget(btn_exit, 1, 1, 1, 1);

        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setMinimumSize(QSize(142, 32));

        gridLayout->addWidget(btn_login, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget, 3, 0, 1, 1);


        retranslateUi(LOGIN);

        QMetaObject::connectSlotsByName(LOGIN);
    } // setupUi

    void retranslateUi(QWidget *LOGIN)
    {
        LOGIN->setWindowTitle(QCoreApplication::translate("LOGIN", "\347\231\273\345\275\225", nullptr));
        LOGIN->setStyleSheet(QCoreApplication::translate("LOGIN", "\n"
"     QWidget {\n"
"        background-color: #e6f3ff;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"     }\n"
"     QLabel {\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: #333;\n"
"     }\n"
"     QLineEdit {\n"
"        font-size: 14px;\n"
"        padding: 5px;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 3px;\n"
"     }\n"
"     QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        border-radius: 5px;\n"
"        padding: 10px 20px;\n"
"        border: 1px solid #4CAF50;\n"
"        min-width: 100px;\n"
"     }\n"
"     QPushButton:hover {\n"
"        background-color: #45a049;\n"
"     }\n"
"     QPushButton:pressed {\n"
"        background-color: #388E3C;\n"
"     }\n"
"     QLabel#label {\n"
"        font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN\";\n"
"        font-size: 20px;\n"
"     }\n"
"   ", nullptr));
        label_2->setText(QCoreApplication::translate("LOGIN", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_Username->setPlaceholderText(QCoreApplication::translate("LOGIN", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("LOGIN", "\345\257\206   \347\240\201", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("LOGIN", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("LOGIN", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_exit->setText(QCoreApplication::translate("LOGIN", "\351\200\200\345\207\272", nullptr));
        btn_login->setText(QCoreApplication::translate("LOGIN", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LOGIN: public Ui_LOGIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
