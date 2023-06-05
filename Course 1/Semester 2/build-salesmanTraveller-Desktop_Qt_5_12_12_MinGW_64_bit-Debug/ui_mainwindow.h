/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_9;
    QTableWidget *tableWidget_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_4;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_7;
    QPushButton *pushButton_7;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox_8;
    QPushButton *pushButton_8;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_6;
    QPushButton *pushButton_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(764, 476);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 491, 371));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 190, 80, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 660, 801, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 690, 811, 16));
        tableWidget_2 = new QTableWidget(centralwidget);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(180, 390, 571, 71));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(510, 130, 160, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(510, 70, 241, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(gridLayoutWidget_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        comboBox_3 = new QComboBox(gridLayoutWidget_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_2->addWidget(comboBox_3, 0, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(510, 10, 225, 51));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox_4 = new QComboBox(gridLayoutWidget_3);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        gridLayout_3->addWidget(comboBox_4, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        comboBox_5 = new QComboBox(gridLayoutWidget_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        gridLayout_3->addWidget(comboBox_5, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 1, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(510, 260, 160, 31));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox_7 = new QComboBox(gridLayoutWidget_4);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        gridLayout_4->addWidget(comboBox_7, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_4->addWidget(pushButton_7, 0, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(510, 220, 160, 31));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_8 = new QComboBox(gridLayoutWidget_5);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        gridLayout_5->addWidget(comboBox_8, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget_5);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_5->addWidget(pushButton_8, 0, 1, 1, 1);

        gridLayoutWidget_6 = new QWidget(centralwidget);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 390, 160, 31));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_6 = new QComboBox(gridLayoutWidget_6);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        gridLayout_6->addWidget(comboBox_6, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_6->addWidget(pushButton_6, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Choose Vertex:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete Vertex", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Choose Edge:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Delete Edge", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Weight:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Choose Edge:", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add Edge", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Weight:", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "execute DFS", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "execute BFS", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "execute Dijktra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
