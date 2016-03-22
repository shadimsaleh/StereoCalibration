#ifndef STEREOCALIBRATION_H
#define STEREOCALIBRATION_H

#include <QtWidgets/QMainWindow>
#include "ui_stereocalibration.h"

class StereoCalibration : public QMainWindow
{
	Q_OBJECT

public:
	StereoCalibration(QWidget *parent = 0);
	~StereoCalibration();

private:
	Ui::StereoCalibrationClass ui;
};

#endif // STEREOCALIBRATION_H
