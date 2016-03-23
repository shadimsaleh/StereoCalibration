#ifndef STEREOCALIBRATION_H
#define STEREOCALIBRATION_H

#include <QtWidgets/QMainWindow>
#include "ui_stereocalibration.h"
#include "FileManager.h"
#include "Xml.h"
#include "ParametersLoader.h"
#include "Pattern.h"
#include <opencv2\opencv.hpp>
#include <qmessagebox.h>

using namespace std;
using namespace cv;

class StereoCalibration : public QMainWindow
{
	Q_OBJECT

public:
	StereoCalibration(QWidget *parent = 0);
	~StereoCalibration();
	void displayCurrentMat();
	void loadImagePathAndDisplayFirstFrame();
	void readParameters();
	void saveParameters();
	

public slots:
	void onPushButtonLoadImagesClicked();
	void onPushButtonNextFrameClicked();
	void onPushButtonStartDetectionClicked();

	void patternParametersMaj();
	void pointDetectionAuto();


private:
	Ui::StereoCalibrationClass ui;

	//Contient les path des images
	vector<QString> stereoImagesPath;

	//Sauvegarde des poitns 
	vector<vector<Point2f>> calibrationPoints;
	Pattern pattern;

	Mat currentMat;

	int currentIndice;

	vector<Point2f> currentPointsVector;

};

#endif // STEREOCALIBRATION_H
