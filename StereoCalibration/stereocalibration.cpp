#include "stereocalibration.h"

StereoCalibration::StereoCalibration(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonLoadImages, SIGNAL(clicked()), SLOT(onPushButtonLoadImagesClicked()));

	readParameters();
}

StereoCalibration::~StereoCalibration()
{
	this->saveParameters();
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

void StereoCalibration::loadImagePathAndDisplayFirstFrame(vector<vector<QString>> v){
	stereoImagesPath = v;

	if (stereoImagesPath.size() != 2){
		ui.textBrowserLog->append("Can't load image, check your name's images (Color-number) and (Infrared-number)");
	}
	else{
		ui.textBrowserLog->append(QString::number(stereoImagesPath.at(0).size() + stereoImagesPath.at(1).size()) + " Images loaded");

		//Affichage de la premiere image à l'écran
		displayFrame(0);
	}
}

void StereoCalibration::onPushButtonLoadImagesClicked(){
	FileManager fm = FileManager();
	loadImagePathAndDisplayFirstFrame(fm.loadStereoImages());
}

void StereoCalibration::readParameters(){
	ParametersLoader pl = ParametersLoader();
	stereoImagesPath = pl.getImagesPath();
	loadImagePathAndDisplayFirstFrame(stereoImagesPath);
}

void StereoCalibration::saveParameters(){
	QString dataToSave = "";
	Xml xml("StereoCalibration");
	

	if (stereoImagesPath.size() == 2){
		//Enregistrement des chemins des fichiers
		
		
		if (stereoImagesPath.at(0).size() == stereoImagesPath.at(1).size()){
			xml.openBalise("firstVecotr");
			for (int i = 0; i < stereoImagesPath.at(0).size(); i++){
				xml.addElement("Path", stereoImagesPath.at(0).at(i).toStdString());
			}
			xml.closeBalise();

			xml.openBalise("secondVector");
			for (int i = 0; i < stereoImagesPath.at(0).size(); i++){
				xml.addElement("Path", stereoImagesPath.at(1).at(i).toStdString());
			}
			xml.closeBalise();
		}
	}
	
	
}


