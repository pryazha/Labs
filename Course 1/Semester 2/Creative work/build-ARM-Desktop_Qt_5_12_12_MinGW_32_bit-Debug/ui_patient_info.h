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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patient_info
{
public:
    QLabel *label;
    QFrame *line;
    QToolBox *toolBox;
    QWidget *weight;
    QWidget *height;
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
    QPushButton *home_button;
    QTableWidget *tableWidget_exams;
    QFrame *line_2;
    QComboBox *comboBox_recommendations;
    QPushButton *saveButton;
    QDateEdit *dateEdit_exam;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line_4;
    QLineEdit *lineEdit_diagnosis;
    QLabel *label_13;
    QPlainTextEdit *plainTextEdit_treatment;
    QLabel *label_14;
    QLabel *label_15;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_3;
    QLabel *label_photo;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *changePhoto_button;
    QLabel *label_17;

    void setupUi(QDialog *patient_info)
    {
        if (patient_info->objectName().isEmpty())
            patient_info->setObjectName(QString::fromUtf8("patient_info"));
        patient_info->resize(1280, 650);
        label = new QLabel(patient_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 491, 30));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        line = new QFrame(patient_info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 1262, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        toolBox = new QToolBox(patient_info);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 300, 201, 131));
        QFont font1;
        font1.setPointSize(8);
        toolBox->setFont(font1);
        weight = new QWidget();
        weight->setObjectName(QString::fromUtf8("weight"));
        weight->setGeometry(QRect(0, 0, 201, 77));
        toolBox->addItem(weight, QString::fromUtf8("\320\234\320\260\321\201\321\201\320\260 \321\202\320\265\320\273\320\260"));
        height = new QWidget();
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(0, 0, 201, 77));
        toolBox->addItem(height, QString::fromUtf8("\320\240\320\276\321\201\321\202"));
        label_2 = new QLabel(patient_info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 311, 30));
        QFont font2;
        font2.setPointSize(16);
        label_2->setFont(font2);
        verticalLayoutWidget = new QWidget(patient_info);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 100, 341, 191));
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

        home_button = new QPushButton(patient_info);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        home_button->setGeometry(QRect(10, 610, 179, 31));
        QFont font3;
        font3.setPointSize(14);
        home_button->setFont(font3);
        tableWidget_exams = new QTableWidget(patient_info);
        if (tableWidget_exams->columnCount() < 4)
            tableWidget_exams->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_exams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_exams->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_exams->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_exams->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_exams->setObjectName(QString::fromUtf8("tableWidget_exams"));
        tableWidget_exams->setGeometry(QRect(370, 370, 451, 271));
        QFont font4;
        font4.setPointSize(10);
        tableWidget_exams->setFont(font4);
        tableWidget_exams->setSelectionMode(QAbstractItemView::SingleSelection);
        line_2 = new QFrame(patient_info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(350, 50, 20, 591));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        comboBox_recommendations = new QComboBox(patient_info);
        comboBox_recommendations->setObjectName(QString::fromUtf8("comboBox_recommendations"));
        comboBox_recommendations->setGeometry(QRect(530, 290, 311, 21));
        comboBox_recommendations->setFont(font4);
        saveButton = new QPushButton(patient_info);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(850, 290, 75, 23));
        saveButton->setFont(font4);
        dateEdit_exam = new QDateEdit(patient_info);
        dateEdit_exam->setObjectName(QString::fromUtf8("dateEdit_exam"));
        dateEdit_exam->setGeometry(QRect(530, 110, 141, 31));
        label_3 = new QLabel(patient_info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 340, 261, 21));
        QFont font5;
        font5.setPointSize(13);
        label_3->setFont(font5);
        label_11 = new QLabel(patient_info);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(370, 60, 901, 21));
        QFont font6;
        font6.setPointSize(12);
        label_11->setFont(font6);
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(patient_info);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(370, 110, 131, 31));
        label_12->setFont(font6);
        line_4 = new QFrame(patient_info);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(360, 80, 911, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        lineEdit_diagnosis = new QLineEdit(patient_info);
        lineEdit_diagnosis->setObjectName(QString::fromUtf8("lineEdit_diagnosis"));
        lineEdit_diagnosis->setGeometry(QRect(530, 150, 741, 21));
        lineEdit_diagnosis->setFont(font4);
        label_13 = new QLabel(patient_info);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(370, 150, 71, 21));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setFont(font6);
        plainTextEdit_treatment = new QPlainTextEdit(patient_info);
        plainTextEdit_treatment->setObjectName(QString::fromUtf8("plainTextEdit_treatment"));
        plainTextEdit_treatment->setGeometry(QRect(530, 180, 741, 101));
        plainTextEdit_treatment->setFont(font4);
        label_14 = new QLabel(patient_info);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(370, 180, 81, 21));
        label_14->setFont(font6);
        label_15 = new QLabel(patient_info);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(370, 290, 111, 21));
        label_15->setFont(font6);
        line_5 = new QFrame(patient_info);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(510, 90, 16, 241));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(patient_info);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(360, 320, 911, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(patient_info);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(990, 330, 20, 311));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_photo = new QLabel(patient_info);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(220, 300, 131, 131));
        label_photo->setStyleSheet(QString::fromUtf8("background: rgb(130, 130, 130)"));
        deleteButton = new QPushButton(patient_info);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(830, 370, 161, 31));
        deleteButton->setFont(font4);
        editButton = new QPushButton(patient_info);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(830, 410, 161, 31));
        editButton->setFont(font4);
        changePhoto_button = new QPushButton(patient_info);
        changePhoto_button->setObjectName(QString::fromUtf8("changePhoto_button"));
        changePhoto_button->setGeometry(QRect(220, 440, 131, 31));
        label_17 = new QLabel(patient_info);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1010, 340, 261, 21));

        retranslateUi(patient_info);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(patient_info);
    } // setupUi

    void retranslateUi(QDialog *patient_info)
    {
        patient_info->setWindowTitle(QApplication::translate("patient_info", "Dialog", nullptr));
        label->setText(QApplication::translate("patient_info", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\265", nullptr));
        toolBox->setItemText(toolBox->indexOf(weight), QApplication::translate("patient_info", "\320\234\320\260\321\201\321\201\320\260 \321\202\320\265\320\273\320\260", nullptr));
        toolBox->setItemText(toolBox->indexOf(height), QApplication::translate("patient_info", "\320\240\320\276\321\201\321\202", nullptr));
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
        home_button->setText(QApplication::translate("patient_info", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_exams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("patient_info", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_exams->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("patient_info", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_exams->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("patient_info", "\320\233\320\265\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_exams->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("patient_info", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\320\270", nullptr));
        saveButton->setText(QApplication::translate("patient_info", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("patient_info", "\320\241\320\273\321\203\321\207\320\260\320\270 \320\274\320\265\320\264\320\270\321\206\320\270\320\275\321\201\320\272\320\276\320\263\320\276 \320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
        label_11->setText(QApplication::translate("patient_info", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\201\320\274\320\276\321\202\321\200\320\260 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\260", nullptr));
        label_12->setText(QApplication::translate("patient_info", "\320\224\320\260\321\202\320\260 \320\276\321\201\320\274\320\276\321\202\321\200\320\260 ", nullptr));
        label_13->setText(QApplication::translate("patient_info", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        label_14->setText(QApplication::translate("patient_info", "\320\233\320\265\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_15->setText(QApplication::translate("patient_info", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\320\270", nullptr));
        label_photo->setText(QString());
        deleteButton->setText(QApplication::translate("patient_info", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\273\321\203\321\207\320\260\320\271 \320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
        editButton->setText(QApplication::translate("patient_info", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        changePhoto_button->setText(QApplication::translate("patient_info", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216", nullptr));
        label_17->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class patient_info: public Ui_patient_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_INFO_H
