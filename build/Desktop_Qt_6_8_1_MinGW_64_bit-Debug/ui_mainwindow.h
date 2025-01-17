/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QWidget *TopColomnWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *TopColomnhsp;
    QWidget *TopRightWidget;
    QGridLayout *gridLayout;
    QLabel *label_username;
    QPushButton *btn_main_exit;
    QLabel *label;
    QSpacerItem *TopColomnhspmid;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFormLayout *formLayout_2;
    QPushButton *btn_create;
    QPushButton *btn_refresh;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_TopStackedWidget;
    QCheckBox *checkBox_All;
    QLineEdit *lineEdit_sreach;
    QComboBox *comboBox_sreach;
    QPushButton *btn_search;
    QPushButton *btn_add;
    QPushButton *btn_change;
    QPushButton *btn_delete;
    QWidget *page_2;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1063, 611);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"      QWidget#centralwidget {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"      }\n"
"    "));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        TopColomnWidget = new QWidget(centralwidget);
        TopColomnWidget->setObjectName("TopColomnWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TopColomnWidget->sizePolicy().hasHeightForWidth());
        TopColomnWidget->setSizePolicy(sizePolicy1);
        TopColomnWidget->setMinimumSize(QSize(700, 50));
        TopColomnWidget->setAutoFillBackground(false);
        TopColomnWidget->setStyleSheet(QString::fromUtf8("\n"
"         background-color: #1e3c72;\n"
"         color: white;\n"
"         border-bottom: 2px solid #2a5298;\n"
"       "));
        gridLayout_2 = new QGridLayout(TopColomnWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        TopColomnhsp = new QSpacerItem(248, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(TopColomnhsp, 0, 0, 1, 1);

        TopRightWidget = new QWidget(TopColomnWidget);
        TopRightWidget->setObjectName("TopRightWidget");
        gridLayout = new QGridLayout(TopRightWidget);
        gridLayout->setObjectName("gridLayout");
        label_username = new QLabel(TopRightWidget);
        label_username->setObjectName("label_username");
        label_username->setStyleSheet(QString::fromUtf8("\n"
"               font-size: 14px;\n"
"               font-weight: bold;\n"
"               color: white;\n"
"             "));

        gridLayout->addWidget(label_username, 0, 0, 1, 1);

        btn_main_exit = new QPushButton(TopRightWidget);
        btn_main_exit->setObjectName("btn_main_exit");
        btn_main_exit->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                 background-color: #e74c3c;\n"
"                 color: white;\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 border-radius: 5px;\n"
"                 padding: 8px 16px;\n"
"                 border: none;\n"
"               }\n"
"               QPushButton:hover {\n"
"                 background-color: #c0392b;\n"
"               }\n"
"               QPushButton:pressed {\n"
"                 background-color: #a93226;\n"
"               }\n"
"             "));

        gridLayout->addWidget(btn_main_exit, 0, 1, 1, 1);


        gridLayout_2->addWidget(TopRightWidget, 0, 3, 1, 1);

        label = new QLabel(TopColomnWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(200, 50));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"            font-size: 24px;\n"
"            font-weight: bold;\n"
"            color: white;\n"
"          "));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        TopColomnhspmid = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(TopColomnhspmid, 0, 2, 1, 1);


        formLayout->setWidget(0, QFormLayout::SpanningRole, TopColomnWidget);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        page = new QWidget();
        page->setObjectName("page");
        formLayout_2 = new QFormLayout(page);
        formLayout_2->setObjectName("formLayout_2");
        btn_create = new QPushButton(page);
        btn_create->setObjectName("btn_create");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_create->sizePolicy().hasHeightForWidth());
        btn_create->setSizePolicy(sizePolicy3);
        btn_create->setStyleSheet(QString::fromUtf8("\n"
"             QPushButton {\n"
"               background-color: #f39c12;\n"
"               color: white;\n"
"               font-size: 14px;\n"
"               font-weight: bold;\n"
"               border-radius: 5px;\n"
"               padding: 8px 16px;\n"
"               border: none;\n"
"             }\n"
"             QPushButton:hover {\n"
"               background-color: #e67e22;\n"
"             }\n"
"             QPushButton:pressed {\n"
"               background-color: #d35400;\n"
"             }\n"
"           "));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, btn_create);

        btn_refresh = new QPushButton(page);
        btn_refresh->setObjectName("btn_refresh");
        sizePolicy3.setHeightForWidth(btn_refresh->sizePolicy().hasHeightForWidth());
        btn_refresh->setSizePolicy(sizePolicy3);
        btn_refresh->setStyleSheet(QString::fromUtf8("\n"
"             QPushButton {\n"
"               background-color: #3498db;\n"
"               color: white;\n"
"               font-size: 14px;\n"
"               font-weight: bold;\n"
"               border-radius: 5px;\n"
"               padding: 8px 16px;\n"
"               border: none;\n"
"             }\n"
"             QPushButton:hover {\n"
"               background-color: #2980b9;\n"
"             }\n"
"             QPushButton:pressed {\n"
"               background-color: #2472a4;\n"
"             }\n"
"           "));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, btn_refresh);

        tableWidget = new QTableWidget(page);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy4);
        tableWidget->setMinimumSize(QSize(0, 380));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"      background-color: #ffffff;\n"
"      border: 1px solid #ccc;\n"
"      border-radius: 5px;\n"
"      font-size: 14px;\n"
"      gridline-color: #ddd;\n"
"    }\n"
"\n"
"    QHeaderView::section {\n"
"      background-color: #1e3c72; /* \350\256\276\347\275\256\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"      color: white; \n"
"      padding: 8px;\n"
"      border: none;\n"
"      font-size: 14px;\n"
"      font-weight: bold;\n"
"    }\n"
"\n"
"    QTableWidget::item {\n"
"      padding: 8px;\n"
"    }\n"
"\n"
"    QTableWidget::item:selected {\n"
"      background-color: rgb(200, 230, 250); /* \351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"      color: black; /* \351\200\211\344\270\255\351\241\271\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QTableWidget::item:hover {\n"
"      background-color: rgb(173, 218, 243); /* \346\202\254\345\201\234"
                        "\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->verticalHeader()->setVisible(false);

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, tableWidget);

        gridLayout_TopStackedWidget = new QGridLayout();
        gridLayout_TopStackedWidget->setObjectName("gridLayout_TopStackedWidget");
        checkBox_All = new QCheckBox(page);
        checkBox_All->setObjectName("checkBox_All");
        checkBox_All->setMinimumSize(QSize(0, 30));
        checkBox_All->setStyleSheet(QString::fromUtf8("\n"
"               font-size: 14px;\n"
"               color: white;\n"
"             "));
        checkBox_All->setChecked(false);

        gridLayout_TopStackedWidget->addWidget(checkBox_All, 0, 0, 1, 1);

        lineEdit_sreach = new QLineEdit(page);
        lineEdit_sreach->setObjectName("lineEdit_sreach");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_sreach->sizePolicy().hasHeightForWidth());
        lineEdit_sreach->setSizePolicy(sizePolicy5);
        lineEdit_sreach->setMinimumSize(QSize(0, 30));
        lineEdit_sreach->setStyleSheet(QString::fromUtf8("\n"
"               font-size: 14px;\n"
"               padding: 5px 8px;\n"
"               border: 1px solid #ccc;\n"
"               border-radius: 3px;\n"
"               background-color: #ffffff;\n"
"               color: #333;\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(lineEdit_sreach, 0, 1, 1, 1);

        comboBox_sreach = new QComboBox(page);
        comboBox_sreach->setObjectName("comboBox_sreach");
        comboBox_sreach->setMinimumSize(QSize(0, 30));
        comboBox_sreach->setStyleSheet(QString::fromUtf8("\n"
"               QComboBox {\n"
"                 background-color: #ffffff;\n"
"                 border: 1px solid #ccc;\n"
"                 border-radius: 5px;\n"
"                 padding: 5px 8px;\n"
"                 font-size: 14px;\n"
"                 color: #333;\n"
"               }\n"
"               QComboBox::drop-down {\n"
"                 subcontrol-origin: padding;\n"
"                 subcontrol-position: right center;\n"
"                 width: 20px;\n"
"                 border-left: 1px solid #ccc;\n"
"               }\n"
"               QComboBox::down-arrow {\n"
"                 image: url(:/icons/down_arrow.png);\n"
"                 width: 12px;\n"
"                 height: 12px;\n"
"               }\n"
"               QComboBox:hover {\n"
"                 border-color: #3498db;\n"
"               }\n"
"               QComboBox:on {\n"
"                 border-color: #3498db;\n"
"               }\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(comboBox_sreach, 0, 2, 1, 1);

        btn_search = new QPushButton(page);
        btn_search->setObjectName("btn_search");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btn_search->sizePolicy().hasHeightForWidth());
        btn_search->setSizePolicy(sizePolicy6);
        btn_search->setMinimumSize(QSize(0, 30));
        btn_search->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                 background-color: #2ecc71;\n"
"                 color: white;\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 border-radius: 5px;\n"
"                 padding: 8px 16px;\n"
"                 border: none;\n"
"               }\n"
"               QPushButton:hover {\n"
"                 background-color: #27ae60;\n"
"               }\n"
"               QPushButton:pressed {\n"
"                 background-color: #219653;\n"
"               }\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(btn_search, 0, 3, 1, 1);

        btn_add = new QPushButton(page);
        btn_add->setObjectName("btn_add");
        btn_add->setMinimumSize(QSize(0, 30));
        btn_add->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                 background-color: #9b59b6;\n"
"                 color: white;\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 border-radius: 5px;\n"
"                 padding: 8px 16px;\n"
"                 border: none;\n"
"               }\n"
"               QPushButton:hover {\n"
"                 background-color: #8e44ad;\n"
"               }\n"
"               QPushButton:pressed {\n"
"                 background-color: #7d3c98;\n"
"               }\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(btn_add, 0, 4, 1, 1);

        btn_change = new QPushButton(page);
        btn_change->setObjectName("btn_change");
        btn_change->setMinimumSize(QSize(0, 30));
        btn_change->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                 background-color: #3498db;\n"
"                 color: white;\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 border-radius: 5px;\n"
"                 padding: 8px 16px;\n"
"                 border: none;\n"
"               }\n"
"               QPushButton:hover {\n"
"                 background-color: #2980b9;\n"
"               }\n"
"               QPushButton:pressed {\n"
"                 background-color: #2472a4;\n"
"               }\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(btn_change, 0, 5, 1, 1);

        btn_delete = new QPushButton(page);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setMinimumSize(QSize(0, 30));
        btn_delete->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                 background-color: #e74c3c;\n"
"                 color: white;\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 border-radius: 5px;\n"
"                 padding: 8px 16px;\n"
"                 border: none;\n"
"               }\n"
"               QPushButton:hover {\n"
"                 background-color: #c0392b;\n"
"               }\n"
"               QPushButton:pressed {\n"
"                 background-color: #a93226;\n"
"               }\n"
"             "));

        gridLayout_TopStackedWidget->addWidget(btn_delete, 0, 6, 1, 1);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, gridLayout_TopStackedWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        formLayout->setWidget(5, QFormLayout::FieldRole, stackedWidget);

        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget {\n"
"  background-color: #ffffff;\n"
"  border: 1px solid #ccc;\n"
"  border-radius: 5px;\n"
"  font-size: 14px;\n"
"}\n"
"\n"
"QTreeWidget::item {\n"
"  padding: 8px;\n"
"}\n"
"\n"
"QTreeWidget::item:selected {\n"
"  background-color: rgb(200, 230, 250); /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"  color: rgb(0, 0, 0); /* \351\200\211\344\270\255\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeWidget::item:hover {\n"
"  background-color: rgb(173, 218, 243); /* \346\202\254\345\201\234\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  background-color: #1e3c72;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  border: none;\n"
"  font-size: 14px;\n"
"  font-weight: bold;\n"
"}\n"
""));
        treeWidget->setAlternatingRowColors(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, treeWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1063, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_username->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        btn_main_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_create->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220\346\225\260\346\215\256", nullptr));
        btn_refresh->setText(QCoreApplication::translate("MainWindow", "\347\253\213\345\215\263\345\210\267\346\226\260\350\241\250\346\240\274", nullptr));
        checkBox_All->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240", nullptr));
        btn_change->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        btn_delete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
