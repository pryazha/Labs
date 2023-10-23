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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *addCityButton;
    QPushButton *addRoadButton1;
    QPushButton *addRoadButton2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *cityNameLine;
    QLabel *label_2;
    QLineEdit *roadLengthLine;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *startingCityLine;
    QPushButton *solveButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *answerLabel;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(595, 349);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName(QString::fromUtf8("addCityButton"));
        addCityButton->setMinimumSize(QSize(0, 30));
        addCityButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(addCityButton);

        addRoadButton1 = new QPushButton(centralwidget);
        addRoadButton1->setObjectName(QString::fromUtf8("addRoadButton1"));
        addRoadButton1->setMinimumSize(QSize(250, 30));
        addRoadButton1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(addRoadButton1);

        addRoadButton2 = new QPushButton(centralwidget);
        addRoadButton2->setObjectName(QString::fromUtf8("addRoadButton2"));
        addRoadButton2->setMinimumSize(QSize(250, 30));
        addRoadButton2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(addRoadButton2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cityNameLine = new QLineEdit(centralwidget);
        cityNameLine->setObjectName(QString::fromUtf8("cityNameLine"));
        cityNameLine->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::FieldRole, cityNameLine);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        roadLengthLine = new QLineEdit(centralwidget);
        roadLengthLine->setObjectName(QString::fromUtf8("roadLengthLine"));
        roadLengthLine->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::FieldRole, roadLengthLine);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        horizontalLayout_2->addWidget(label_3);

        startingCityLine = new QLineEdit(centralwidget);
        startingCityLine->setObjectName(QString::fromUtf8("startingCityLine"));
        startingCityLine->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(startingCityLine);


        verticalLayout->addLayout(horizontalLayout_2);

        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName(QString::fromUtf8("solveButton"));
        solveButton->setMinimumSize(QSize(0, 30));
        solveButton->setStyleSheet(QString::fromUtf8(""));
        solveButton->setCheckable(false);
        solveButton->setAutoExclusive(true);
        solveButton->setFlat(false);

        verticalLayout->addWidget(solveButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        answerLabel = new QLabel(centralwidget);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));
        answerLabel->setFont(font);

        horizontalLayout->addWidget(answerLabel);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 4, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        graphicsView->setFont(font1);
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(graphicsView, 0, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        solveButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The Salesman Problem", nullptr));
        addCityButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", nullptr));
        addRoadButton1->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\264\320\275\320\276\321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\265\320\265 \321\200\320\265\320\261\321\200\320\276", nullptr));
        addRoadButton2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\262\321\203\321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\265\320\265 \321\200\320\265\320\261\321\200\320\276", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\203\320\267\320\273\320\260:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201 \321\200\320\265\320\261\321\200\320\260:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\203\320\267\320\265\320\273:", nullptr));
        solveButton->setText(QApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270 \320\272\320\276\320\274\320\274\320\270\320\262\320\276\321\217\320\266\320\265\321\200\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
        answerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
