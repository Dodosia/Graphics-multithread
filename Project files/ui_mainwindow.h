/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_10;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_7;
    QLabel *label;
    QSpinBox *spinBox;
    QSpinBox *spinBox_4;
    QLabel *label_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_8;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_5;
    QLabel *label_3;
    QSpinBox *spinBox_9;
    QCustomPlot *widget;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1116, 657);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setIconSize(QSize(24, 24));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(-1, 0, 0, -1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        spinBox_10 = new QSpinBox(centralwidget);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));

        gridLayout_2->addWidget(spinBox_10, 4, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout_2->addWidget(spinBox_2, 0, 2, 1, 1);

        spinBox_7 = new QSpinBox(centralwidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));

        gridLayout_2->addWidget(spinBox_7, 3, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        gridLayout_2->addWidget(spinBox_4, 1, 2, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        spinBox_6 = new QSpinBox(centralwidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));

        gridLayout_2->addWidget(spinBox_6, 2, 2, 1, 1);

        spinBox_8 = new QSpinBox(centralwidget);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));

        gridLayout_2->addWidget(spinBox_8, 3, 2, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 9, 0, 0);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        tableWidget = new QTableWidget(widget_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 5, 0, 1, 3);

        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        gridLayout_2->addWidget(spinBox_3, 1, 1, 1, 1);

        spinBox_5 = new QSpinBox(centralwidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        gridLayout_2->addWidget(spinBox_5, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        spinBox_9 = new QSpinBox(centralwidget);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));

        gridLayout_2->addWidget(spinBox_9, 4, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(700, 0));
        widget->setMaximumSize(QSize(700, 16777215));
        widget->setBaseSize(QSize(9, 0));

        horizontalLayout_2->addWidget(widget);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\321\206\320\260 \342\204\2262               n, m:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\321\206\320\260 \342\204\2264               n, m:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\321\206\320\260 \342\204\2261               n, m:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\321\206\320\260 \342\204\2265               n, m:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\321\206\320\260 \342\204\2263               n, m:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
