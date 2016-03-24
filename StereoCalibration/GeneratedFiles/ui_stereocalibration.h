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
    QPushButton *pushButtonStartDetection;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_2;
    QLabel *focalLengthXLabel;
    QLineEdit *focalLengthXLineEdit;
    QLabel *focalLengthYLabel;
    QLineEdit *focalLengthYLineEdit;
    QLabel *pointPrincipalXLabel;
    QLineEdit *pointPrincipalXLineEdit;
    QLabel *pointPrincipalYLabel;
    QLineEdit *pointPrincipalYLineEdit;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *focalLengthXLabel_2;
    QLineEdit *focalLengthXLineEdit_2;
    QLabel *focalLengthYLabel_2;
    QLineEdit *focalLengthYLineEdit_2;
    QLabel *pointPrincipalXLabel_2;
    QLineEdit *pointPrincipalXLineEdit_2;
    QLabel *pointPrincipalYLabel_2;
    QLineEdit *pointPrincipalYLineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StereoCalibrationClass)
    {
        if (StereoCalibrationClass->objectName().isEmpty())
            StereoCalibrationClass->setObjectName(QStringLiteral("StereoCalibrationClass"));
        StereoCalibrationClass->resize(1416, 833);
        centralWidget = new QWidget(StereoCalibrationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayLabel = new QLabel(centralWidget);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));
        displayLabel->setGeometry(QRect(400, 70, 512, 424));
        displayLabel->setAutoFillBackground(true);
        pushButtonNextFrame = new QPushButton(centralWidget);
        pushButtonNextFrame->setObjectName(QStringLiteral("pushButtonNextFrame"));
        pushButtonNextFrame->setEnabled(false);
        pushButtonNextFrame->setGeometry(QRect(1090, 320, 171, 71));
        textBrowserLog = new QTextBrowser(centralWidget);
        textBrowserLog->setObjectName(QStringLiteral("textBrowserLog"));
        textBrowserLog->setGeometry(QRect(400, 540, 512, 192));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(39, 440, 334, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxComputeIntrinsicsParameters = new QCheckBox(formLayoutWidget);
        checkBoxComputeIntrinsicsParameters->setObjectName(QStringLiteral("checkBoxComputeIntrinsicsParameters"));
        checkBoxComputeIntrinsicsParameters->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, checkBoxComputeIntrinsicsParameters);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 380, 201, 31));
        pushButtonLoadImages = new QPushButton(centralWidget);
        pushButtonLoadImages->setObjectName(QStringLiteral("pushButtonLoadImages"));
        pushButtonLoadImages->setGeometry(QRect(100, 60, 171, 71));
        pushButtonStartCalibration = new QPushButton(centralWidget);
        pushButtonStartCalibration->setObjectName(QStringLiteral("pushButtonStartCalibration"));
        pushButtonStartCalibration->setEnabled(false);
        pushButtonStartCalibration->setGeometry(QRect(100, 650, 171, 71));
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(1010, 50, 331, 101));
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
        numberOfRowLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, numberOfRowLineEdit);

        numberOfColumnsLabel = new QLabel(formLayoutWidget_2);
        numberOfColumnsLabel->setObjectName(QStringLiteral("numberOfColumnsLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, numberOfColumnsLabel);

        numberOfColumnsLineEdit = new QLineEdit(formLayoutWidget_2);
        numberOfColumnsLineEdit->setObjectName(QStringLiteral("numberOfColumnsLineEdit"));
        numberOfColumnsLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, numberOfColumnsLineEdit);

        sizeOfSquareMmLabel = new QLabel(formLayoutWidget_2);
        sizeOfSquareMmLabel->setObjectName(QStringLiteral("sizeOfSquareMmLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, sizeOfSquareMmLabel);

        sizeOfSquareMmLineEdit = new QLineEdit(formLayoutWidget_2);
        sizeOfSquareMmLineEdit->setObjectName(QStringLiteral("sizeOfSquareMmLineEdit"));
        sizeOfSquareMmLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, sizeOfSquareMmLineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1090, 10, 201, 31));
        label_2->setAlignment(Qt::AlignCenter);
        pushButtonPointsDetection = new QPushButton(centralWidget);
        pushButtonPointsDetection->setObjectName(QStringLiteral("pushButtonPointsDetection"));
        pushButtonPointsDetection->setEnabled(false);
        pushButtonPointsDetection->setGeometry(QRect(1090, 210, 171, 71));
        pushButtonStartDetection = new QPushButton(centralWidget);
        pushButtonStartDetection->setObjectName(QStringLiteral("pushButtonStartDetection"));
        pushButtonStartDetection->setEnabled(false);
        pushButtonStartDetection->setGeometry(QRect(100, 240, 171, 71));
        formLayoutWidget_3 = new QWidget(centralWidget);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(930, 560, 221, 141));
        formLayout_2 = new QFormLayout(formLayoutWidget_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        focalLengthXLabel = new QLabel(formLayoutWidget_3);
        focalLengthXLabel->setObjectName(QStringLiteral("focalLengthXLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, focalLengthXLabel);

        focalLengthXLineEdit = new QLineEdit(formLayoutWidget_3);
        focalLengthXLineEdit->setObjectName(QStringLiteral("focalLengthXLineEdit"));
        focalLengthXLineEdit->setEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, focalLengthXLineEdit);

        focalLengthYLabel = new QLabel(formLayoutWidget_3);
        focalLengthYLabel->setObjectName(QStringLiteral("focalLengthYLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, focalLengthYLabel);

        focalLengthYLineEdit = new QLineEdit(formLayoutWidget_3);
        focalLengthYLineEdit->setObjectName(QStringLiteral("focalLengthYLineEdit"));
        focalLengthYLineEdit->setEnabled(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, focalLengthYLineEdit);

        pointPrincipalXLabel = new QLabel(formLayoutWidget_3);
        pointPrincipalXLabel->setObjectName(QStringLiteral("pointPrincipalXLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pointPrincipalXLabel);

        pointPrincipalXLineEdit = new QLineEdit(formLayoutWidget_3);
        pointPrincipalXLineEdit->setObjectName(QStringLiteral("pointPrincipalXLineEdit"));
        pointPrincipalXLineEdit->setEnabled(false);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pointPrincipalXLineEdit);

        pointPrincipalYLabel = new QLabel(formLayoutWidget_3);
        pointPrincipalYLabel->setObjectName(QStringLiteral("pointPrincipalYLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, pointPrincipalYLabel);

        pointPrincipalYLineEdit = new QLineEdit(formLayoutWidget_3);
        pointPrincipalYLineEdit->setObjectName(QStringLiteral("pointPrincipalYLineEdit"));
        pointPrincipalYLineEdit->setEnabled(false);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, pointPrincipalYLineEdit);

        formLayoutWidget_4 = new QWidget(centralWidget);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(1180, 560, 221, 141));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        focalLengthXLabel_2 = new QLabel(formLayoutWidget_4);
        focalLengthXLabel_2->setObjectName(QStringLiteral("focalLengthXLabel_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, focalLengthXLabel_2);

        focalLengthXLineEdit_2 = new QLineEdit(formLayoutWidget_4);
        focalLengthXLineEdit_2->setObjectName(QStringLiteral("focalLengthXLineEdit_2"));
        focalLengthXLineEdit_2->setEnabled(false);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, focalLengthXLineEdit_2);

        focalLengthYLabel_2 = new QLabel(formLayoutWidget_4);
        focalLengthYLabel_2->setObjectName(QStringLiteral("focalLengthYLabel_2"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, focalLengthYLabel_2);

        focalLengthYLineEdit_2 = new QLineEdit(formLayoutWidget_4);
        focalLengthYLineEdit_2->setObjectName(QStringLiteral("focalLengthYLineEdit_2"));
        focalLengthYLineEdit_2->setEnabled(false);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, focalLengthYLineEdit_2);

        pointPrincipalXLabel_2 = new QLabel(formLayoutWidget_4);
        pointPrincipalXLabel_2->setObjectName(QStringLiteral("pointPrincipalXLabel_2"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, pointPrincipalXLabel_2);

        pointPrincipalXLineEdit_2 = new QLineEdit(formLayoutWidget_4);
        pointPrincipalXLineEdit_2->setObjectName(QStringLiteral("pointPrincipalXLineEdit_2"));
        pointPrincipalXLineEdit_2->setEnabled(false);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, pointPrincipalXLineEdit_2);

        pointPrincipalYLabel_2 = new QLabel(formLayoutWidget_4);
        pointPrincipalYLabel_2->setObjectName(QStringLiteral("pointPrincipalYLabel_2"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, pointPrincipalYLabel_2);

        pointPrincipalYLineEdit_2 = new QLineEdit(formLayoutWidget_4);
        pointPrincipalYLineEdit_2->setObjectName(QStringLiteral("pointPrincipalYLineEdit_2"));
        pointPrincipalYLineEdit_2->setEnabled(false);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, pointPrincipalYLineEdit_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1010, 530, 68, 19));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1260, 530, 68, 19));
        StereoCalibrationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StereoCalibrationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1416, 31));
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
        checkBoxComputeIntrinsicsParameters->setText(QApplication::translate("StereoCalibrationClass", "CV_CALIB_FIX_INTRINSIC ", 0));
        label->setText(QApplication::translate("StereoCalibrationClass", "Stereo calibration options", 0));
        pushButtonLoadImages->setText(QApplication::translate("StereoCalibrationClass", "Load images", 0));
        pushButtonStartCalibration->setText(QApplication::translate("StereoCalibrationClass", "Start calibration", 0));
        numberOfRowLabel->setText(QApplication::translate("StereoCalibrationClass", "Number of rows", 0));
        numberOfColumnsLabel->setText(QApplication::translate("StereoCalibrationClass", "Number of columns", 0));
        sizeOfSquareMmLabel->setText(QApplication::translate("StereoCalibrationClass", "Size of square (mm)", 0));
        label_2->setText(QApplication::translate("StereoCalibrationClass", "Pattern settings", 0));
        pushButtonPointsDetection->setText(QApplication::translate("StereoCalibrationClass", "Points detection auto", 0));
        pushButtonStartDetection->setText(QApplication::translate("StereoCalibrationClass", "Start detection", 0));
        focalLengthXLabel->setText(QApplication::translate("StereoCalibrationClass", "Focal length X", 0));
        focalLengthYLabel->setText(QApplication::translate("StereoCalibrationClass", "Focal length Y", 0));
        pointPrincipalXLabel->setText(QApplication::translate("StereoCalibrationClass", "Point principal X", 0));
        pointPrincipalYLabel->setText(QApplication::translate("StereoCalibrationClass", "Point principal Y", 0));
        focalLengthXLabel_2->setText(QApplication::translate("StereoCalibrationClass", "Focal length X", 0));
        focalLengthYLabel_2->setText(QApplication::translate("StereoCalibrationClass", "Focal length Y", 0));
        pointPrincipalXLabel_2->setText(QApplication::translate("StereoCalibrationClass", "Point principal X", 0));
        pointPrincipalYLabel_2->setText(QApplication::translate("StereoCalibrationClass", "Point principal Y", 0));
        label_3->setText(QApplication::translate("StereoCalibrationClass", "Camera 1", 0));
        label_4->setText(QApplication::translate("StereoCalibrationClass", "Camera 2", 0));
    } // retranslateUi

};

namespace Ui {
    class StereoCalibrationClass: public Ui_StereoCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCALIBRATION_H
