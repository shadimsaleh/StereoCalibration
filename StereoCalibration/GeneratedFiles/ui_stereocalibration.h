/********************************************************************************
** Form generated from reading UI file 'stereocalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOCALIBRATION_H
#define UI_STEREOCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoCalibrationClass
{
public:
    QWidget *centralWidget;
    QLabel *displayLabel;
    QPushButton *pushButtonNextFrame;
    QTextBrowser *textBrowserLog;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QCheckBox *checkBoxComputeIntrinsicsParameters;
    QLabel *label;
    QPushButton *pushButtonLoadImages;
    QPushButton *pushButtonStartCalibration;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *numberOfRowLabel;
    QLineEdit *numberOfRowLineEdit;
    QLabel *numberOfColumnsLabel;
    QLineEdit *numberOfColumnsLineEdit;
    QLabel *sizeOfSquareMmLabel;
    QLineEdit *sizeOfSquareMmLineEdit;
    QLabel *label_2;
    QPushButton *pushButtonPointsDetection;
    QPushButton *pushButtonIntrinsicsParameters;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StereoCalibrationClass)
    {
        if (StereoCalibrationClass->objectName().isEmpty())
            StereoCalibrationClass->setObjectName(QStringLiteral("StereoCalibrationClass"));
        StereoCalibrationClass->resize(1086, 897);
        centralWidget = new QWidget(StereoCalibrationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayLabel = new QLabel(centralWidget);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));
        displayLabel->setGeometry(QRect(80, 70, 512, 424));
        displayLabel->setAutoFillBackground(true);
        pushButtonNextFrame = new QPushButton(centralWidget);
        pushButtonNextFrame->setObjectName(QStringLiteral("pushButtonNextFrame"));
        pushButtonNextFrame->setGeometry(QRect(750, 410, 171, 71));
        textBrowserLog = new QTextBrowser(centralWidget);
        textBrowserLog->setObjectName(QStringLiteral("textBrowserLog"));
        textBrowserLog->setGeometry(QRect(80, 610, 521, 192));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(679, 550, 334, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxComputeIntrinsicsParameters = new QCheckBox(formLayoutWidget);
        checkBoxComputeIntrinsicsParameters->setObjectName(QStringLiteral("checkBoxComputeIntrinsicsParameters"));

        formLayout->setWidget(0, QFormLayout::LabelRole, checkBoxComputeIntrinsicsParameters);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 520, 201, 31));
        pushButtonLoadImages = new QPushButton(centralWidget);
        pushButtonLoadImages->setObjectName(QStringLiteral("pushButtonLoadImages"));
        pushButtonLoadImages->setGeometry(QRect(750, 20, 171, 71));
        pushButtonStartCalibration = new QPushButton(centralWidget);
        pushButtonStartCalibration->setObjectName(QStringLiteral("pushButtonStartCalibration"));
        pushButtonStartCalibration->setGeometry(QRect(760, 750, 171, 71));
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(680, 149, 331, 101));
        formLayout_3 = new QFormLayout(formLayoutWidget_2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        numberOfRowLabel = new QLabel(formLayoutWidget_2);
        numberOfRowLabel->setObjectName(QStringLiteral("numberOfRowLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, numberOfRowLabel);

        numberOfRowLineEdit = new QLineEdit(formLayoutWidget_2);
        numberOfRowLineEdit->setObjectName(QStringLiteral("numberOfRowLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, numberOfRowLineEdit);

        numberOfColumnsLabel = new QLabel(formLayoutWidget_2);
        numberOfColumnsLabel->setObjectName(QStringLiteral("numberOfColumnsLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, numberOfColumnsLabel);

        numberOfColumnsLineEdit = new QLineEdit(formLayoutWidget_2);
        numberOfColumnsLineEdit->setObjectName(QStringLiteral("numberOfColumnsLineEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, numberOfColumnsLineEdit);

        sizeOfSquareMmLabel = new QLabel(formLayoutWidget_2);
        sizeOfSquareMmLabel->setObjectName(QStringLiteral("sizeOfSquareMmLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, sizeOfSquareMmLabel);

        sizeOfSquareMmLineEdit = new QLineEdit(formLayoutWidget_2);
        sizeOfSquareMmLineEdit->setObjectName(QStringLiteral("sizeOfSquareMmLineEdit"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, sizeOfSquareMmLineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 120, 201, 31));
        pushButtonPointsDetection = new QPushButton(centralWidget);
        pushButtonPointsDetection->setObjectName(QStringLiteral("pushButtonPointsDetection"));
        pushButtonPointsDetection->setGeometry(QRect(750, 300, 171, 71));
        pushButtonIntrinsicsParameters = new QPushButton(centralWidget);
        pushButtonIntrinsicsParameters->setObjectName(QStringLiteral("pushButtonIntrinsicsParameters"));
        pushButtonIntrinsicsParameters->setGeometry(QRect(760, 650, 171, 71));
        StereoCalibrationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StereoCalibrationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1086, 31));
        StereoCalibrationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StereoCalibrationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StereoCalibrationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StereoCalibrationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StereoCalibrationClass->setStatusBar(statusBar);

        retranslateUi(StereoCalibrationClass);

        QMetaObject::connectSlotsByName(StereoCalibrationClass);
    } // setupUi

    void retranslateUi(QMainWindow *StereoCalibrationClass)
    {
        StereoCalibrationClass->setWindowTitle(QApplication::translate("StereoCalibrationClass", "StereoCalibration", 0));
        displayLabel->setText(QString());
        pushButtonNextFrame->setText(QApplication::translate("StereoCalibrationClass", "Next Frame", 0));
        checkBoxComputeIntrinsicsParameters->setText(QApplication::translate("StereoCalibrationClass", "Compute intrinsics parameters", 0));
        label->setText(QApplication::translate("StereoCalibrationClass", "Stereo calibration option", 0));
        pushButtonLoadImages->setText(QApplication::translate("StereoCalibrationClass", "Load images", 0));
        pushButtonStartCalibration->setText(QApplication::translate("StereoCalibrationClass", "Start calibration", 0));
        numberOfRowLabel->setText(QApplication::translate("StereoCalibrationClass", "Number of rows", 0));
        numberOfColumnsLabel->setText(QApplication::translate("StereoCalibrationClass", "Number of columns", 0));
        sizeOfSquareMmLabel->setText(QApplication::translate("StereoCalibrationClass", "Size of square (mm)", 0));
        label_2->setText(QApplication::translate("StereoCalibrationClass", "Pattern settings", 0));
        pushButtonPointsDetection->setText(QApplication::translate("StereoCalibrationClass", "Points detection auto", 0));
        pushButtonIntrinsicsParameters->setText(QApplication::translate("StereoCalibrationClass", "Intrinsics parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class StereoCalibrationClass: public Ui_StereoCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCALIBRATION_H
