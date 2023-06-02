/********************************************************************************
** Form generated from reading UI file 'patient_info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_INFO_H
#define UI_PATIENT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patient_info
{
public:
    QLabel *label;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *home_button;
    QTextEdit *textEdit;
    QToolBox *toolBox;
    QWidget *weight;
    QWidget *height;
    QListWidget *listWidget;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_gender;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_birth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *label_snils;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *label_registration;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLabel *label_current_adress;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLabel *label_work;

    void setupUi(QDialog *patient_info)
    {
        if (patient_info->objectName().isEmpty())
            patient_info->setObjectName(QString::fromUtf8("patient_info"));
        patient_info->resize(1280, 650);
        label = new QLabel(patient_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 311, 30));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        line = new QFrame(patient_info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(9, 45, 1262, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(patient_info);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 351, 181, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        home_button = new QPushButton(layoutWidget);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        QFont font1;
        font1.setPointSize(14);
        home_button->setFont(font1);

        verticalLayout->addWidget(home_button);

        textEdit = new QTextEdit(patient_info);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(530, 350, 741, 291));
        toolBox = new QToolBox(patient_info);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(200, 360, 321, 281));
        toolBox->setFont(font1);
        weight = new QWidget();
        weight->setObjectName(QString::fromUtf8("weight"));
        weight->setGeometry(QRect(0, 0, 321, 207));
        toolBox->addItem(weight, QString::fromUtf8("\320\234\320\260\321\201\321\201\320\260 \321\202\320\265\320\273\320\260"));
        height = new QWidget();
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(0, 0, 321, 207));
        toolBox->addItem(height, QString::fromUtf8("\320\240\320\276\321\201\321\202"));
        listWidget = new QListWidget(patient_info);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 60, 181, 281));
        QFont font2;
        font2.setPointSize(16);
        listWidget->setFont(font2);
        label_2 = new QLabel(patient_info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 60, 311, 30));
        label_2->setFont(font2);
        verticalLayoutWidget = new QWidget(patient_info);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 100, 321, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_4);

        label_gender = new QLabel(verticalLayoutWidget);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));
        label_gender->setTextFormat(Qt::AutoText);
        label_gender->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_gender);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_5);

        label_name = new QLabel(verticalLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setTextFormat(Qt::AutoText);
        label_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_name);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_6);

        label_birth = new QLabel(verticalLayoutWidget);
        label_birth->setObjectName(QString::fromUtf8("label_birth"));
        label_birth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_birth);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_9);

        label_snils = new QLabel(verticalLayoutWidget);
        label_snils->setObjectName(QString::fromUtf8("label_snils"));
        label_snils->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_snils);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_7);

        label_registration = new QLabel(verticalLayoutWidget);
        label_registration->setObjectName(QString::fromUtf8("label_registration"));
        label_registration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_registration);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_10);

        label_current_adress = new QLabel(verticalLayoutWidget);
        label_current_adress->setObjectName(QString::fromUtf8("label_current_adress"));
        label_current_adress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_current_adress);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_8);

        label_work = new QLabel(verticalLayoutWidget);
        label_work->setObjectName(QString::fromUtf8("label_work"));
        label_work->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_work);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(patient_info);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(patient_info);
    } // setupUi

    void retranslateUi(QDialog *patient_info)
    {
        patient_info->setWindowTitle(QApplication::translate("patient_info", "Dialog", nullptr));
        label->setText(QApplication::translate("patient_info", "\320\241\320\270\320\263\320\275\320\260\320\273\321\214\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        home_button->setText(QApplication::translate("patient_info", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276", nullptr));
        toolBox->setItemText(toolBox->indexOf(weight), QApplication::translate("patient_info", "\320\234\320\260\321\201\321\201\320\260 \321\202\320\265\320\273\320\260", nullptr));
        toolBox->setItemText(toolBox->indexOf(height), QApplication::translate("patient_info", "\320\240\320\276\321\201\321\202", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("patient_info", "\320\220\320\275\320\260\320\274\320\275\320\265\320\267 \320\266\320\270\320\267\320\275\320\270", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("patient_info", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\260", nullptr));
        label_4->setText(QApplication::translate("patient_info", "\320\237\320\276\320\273", nullptr));
        label_gender->setText(QString());
        label_5->setText(QApplication::translate("patient_info", "\320\244\320\230\320\236", nullptr));
        label_name->setText(QString());
        label_6->setText(QApplication::translate("patient_info", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_birth->setText(QString());
        label_9->setText(QApplication::translate("patient_info", "\320\241\320\235\320\230\320\233\320\241", nullptr));
        label_snils->setText(QString());
        label_7->setText(QApplication::translate("patient_info", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_registration->setText(QString());
        label_10->setText(QApplication::translate("patient_info", "\320\237\321\200\320\276\320\266\320\270\320\262\320\260\320\265\321\202", nullptr));
        label_current_adress->setText(QString());
        label_8->setText(QApplication::translate("patient_info", "\320\240\320\260\320\261\320\276\321\202\320\260", nullptr));
        label_work->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class patient_info: public Ui_patient_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_INFO_H
