#ifndef STEREOCALIBRATION_H
#define STEREOCALIBRATION_H

#include <QtWidgets/QMainWindow>
#include "ui_stereocalibration.h"
#include "FileManager.h"
#include "Xml.h"
#include "ParametersLoader.h"

#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

class StereoCalibration : public QMainWindow
{
	Q_OBJECT

public:
	StereoCalibration(QWidget *parent = 0);
	~StereoCalibration();
	void displayFrame(int indice);
	void loadImagePathAndDisplayFirstFrame(vector<vector<QString>> v);
	void readParameters();
	void saveParameters();
	

public slots:
	void onPushButtonLoadImagesClicked();

private:
	Ui::StereoCalibrationClass ui;

	//Contient les path des images
	vector<vector<QString>> stereoImagesPath;

};

#endif // STEREOCALIBRATION_H
