#include "stereocalibration.h"

StereoCalibration::StereoCalibration(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonLoadImages, SIGNAL(clicked()), SLOT(onPushButtonLoadImagesClicked()));
}

StereoCalibration::~StereoCalibration()
{

}

void StereoCalibration::displayFrame(int indice){
	if (stereoImagesPath.size() == 2){
		Mat m;
		if (indice % 2 == 0){
			m = imread(stereoImagesPath.at(0).at(indice / 2).toStdString());
			ui.textBrowserLog->append(stereoImagesPath.at(0).at(indice / 2));
		}
		else{
			m = imread(stereoImagesPath.at(1).at(indice / 2).toStdString());
		}
		ui.textBrowserLog->append(QString::number(m.type()));
		if (m.type() == CV_8UC3){
			//Affichage de la color
			QImage img((uchar*)m.data, m.cols, m.rows, m.step, QImage::Format_RGB888);
			ui.displayLabel->setPixmap(QPixmap::fromImage(img));
		}
		else{
			//Affichage de l'IR
			QImage img((uchar*)m.data, m.cols, m.rows, m.step, QImage::Format_Indexed8);
			ui.displayLabel->setPixmap(QPixmap::fromImage(img));
		}
	}
}

void StereoCalibration::onPushButtonLoadImagesClicked(){
	FileManager fm = FileManager();

	stereoImagesPath = fm.loadStereoImages();

	if (stereoImagesPath.size() != 2){
		ui.textBrowserLog->append("Can't load image, check your name's images (Color-number) and (Infrared-number)");
	}
	else{
		ui.textBrowserLog->append(QString::number(stereoImagesPath.at(0).size() + stereoImagesPath.at(1).size()) + " Images loaded");

		//Affichage de la premiere image à l'écran
		displayFrame(0);
	}
}


