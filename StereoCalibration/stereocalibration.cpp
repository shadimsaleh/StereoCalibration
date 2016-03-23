#include "stereocalibration.h"

StereoCalibration::StereoCalibration(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonLoadImages, SIGNAL(clicked()), SLOT(onPushButtonLoadImagesClicked()));
	connect(ui.pushButtonPointsDetection, SIGNAL(clicked()), SLOT(pointDetectionAuto()));
	connect(ui.pushButtonNextFrame, SIGNAL(clicked()), SLOT(onPushButtonNextFrameClicked()));
	connect(ui.pushButtonStartDetection, SIGNAL(clicked()), SLOT(onPushButtonStartDetectionClicked()));

	//Parametre du pattern form
	connect(ui.numberOfRowLineEdit, SIGNAL(textEdited(QString)), SLOT(patternParametersMaj()));
	connect(ui.numberOfColumnsLineEdit, SIGNAL(textEdited(QString)), SLOT(patternParametersMaj()));

	readParameters();

	if (stereoImagesPath.size() != 0){
		ui.pushButtonStartDetection->setEnabled(true);
	}
}

StereoCalibration::~StereoCalibration()
{
	this->saveParameters();
}

void StereoCalibration::displayCurrentMat(){
	if (stereoImagesPath.size() != 0){
		Mat m = currentMat;
		ui.textBrowserLog->append("Mat type : " + QString::number(m.type()));
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

void StereoCalibration::loadImagePathAndDisplayFirstFrame(){
	if (stereoImagesPath.size() == 0){
		//Désactivation des bouttons
		ui.pushButtonNextFrame->setEnabled(false);
		ui.pushButtonPointsDetection->setEnabled(false);
	}
	else{
		ui.textBrowserLog->append(QString::number(stereoImagesPath.size()) + " Images loaded");

		currentMat = imread(stereoImagesPath.at(0).toStdString());
		displayCurrentMat();
		currentIndice = 0;
	}
}

void StereoCalibration::onPushButtonLoadImagesClicked(){
	FileManager fm = FileManager();
	stereoImagesPath = fm.loadStereoImages();
	loadImagePathAndDisplayFirstFrame();
}

void StereoCalibration::onPushButtonNextFrameClicked(){
	int numberOfPoints = (pattern.getCol()-1) * (pattern.getRow()-1);

	//Si sur l'image il y a le nombre de points nécéssaires
	if (numberOfPoints == currentPointsVector.size()){

		if (currentIndice == stereoImagesPath.size() - 2)
			ui.pushButtonNextFrame->setEnabled(false);

		if (currentIndice != stereoImagesPath.size() - 1)
		{
			//Enrrgistrement des points courrant dans le vecteur principal et nettoyage du vecteur courant
			calibrationPoints.push_back(currentPointsVector);
			currentPointsVector.clear();

			//incrémentation de l'image
			currentIndice++;
			currentMat = imread(stereoImagesPath.at(currentIndice).toStdString());
			displayCurrentMat();
		}
	}
	else{
		ui.textBrowserLog->append("Not enough points selected " + QString::number(currentPointsVector.size()) + "/" + QString::number(numberOfPoints));
		QMessageBox::warning(this, "Error", "Not enough points selected");
	}
}

void StereoCalibration::onPushButtonStartDetectionClicked(){
	//Désactivation des formulaires précédents
	ui.numberOfRowLineEdit->setEnabled(false);
	ui.sizeOfSquareMmLineEdit->setEnabled(false);
	ui.numberOfColumnsLineEdit->setEnabled(false);

	//Activation des autres formulaires
	ui.pushButtonPointsDetection->setEnabled(true);
	ui.pushButtonNextFrame->setEnabled(true);
}

//Mise à jour des paramètres du pattern quand ils sont modifiés dans le formulaire du pattern
void StereoCalibration::patternParametersMaj(){
	int r = ui.numberOfRowLineEdit->text().toInt();
	int c = ui.numberOfColumnsLineEdit->text().toInt();
	double s = ui.sizeOfSquareMmLineEdit->text().toDouble();
	pattern = Pattern(r, c, s);
}

//Détection automatique des points 
//Opencv findChessBoard pour trouvé l'echequier et le dessine par la suite
void StereoCalibration::pointDetectionAuto(){
	if (pattern.getCol() != 0 && pattern.getRow() != 0){
		cv::Size patternsize = cv::Size(pattern.getCol() - 1, pattern.getRow() - 1);
		bool colorFindChessBoard = findChessboardCorners(currentMat, patternsize, currentPointsVector, CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CV_CALIB_CB_FILTER_QUADS);
		if (colorFindChessBoard){
			drawChessboardCorners(currentMat, patternsize, Mat(currentPointsVector), colorFindChessBoard);
			displayCurrentMat();
		}
		else
		{
			QMessageBox::warning(this, "Error", "Can't find chessboard");
		}
	}
	else{
		QMessageBox::warning(this, "Error", "Fill ths pattern's fileds");
	}
	
}

//Fonction qui permet de lire le fichier xml qui est écrit lors de la fermeture de l'applciation
//Cela permet de configurer l'application avec les dernier paramètres enregistrés
void StereoCalibration::readParameters(){
	ParametersLoader pl = ParametersLoader();

	//Chargement des images
	stereoImagesPath = pl.getImagesPath();
	loadImagePathAndDisplayFirstFrame();

	//Chargement du pattern
	pattern = pl.getPattern();

	ui.numberOfRowLineEdit->setText(QString::number(pattern.getRow()));
	ui.numberOfColumnsLineEdit->setText(QString::number(pattern.getCol()));
	ui.sizeOfSquareMmLineEdit->setText(QString::number(pattern.getSize()));
}

//Fonction qui enreigstre les paramètres de l'application lors de la fermeture de celle ci
void StereoCalibration::saveParameters(){
	QString dataToSave = "";
	Xml xml("StereoCalibration");
	
	//Enregistrement des chemins des fichiers
	if (stereoImagesPath.size() != 0){
		
		if (stereoImagesPath.at(0).size() == stereoImagesPath.at(1).size()){
			xml.openBalise("imagesPath");
			for (int i = 0; i < stereoImagesPath.size(); i++){
				xml.addElement("Path", stereoImagesPath.at(i).toStdString());
			}
			xml.closeBalise();
		}
	}

	//Enregistrement du formulaire du pattern
	xml.openBalise("Pattern");
	xml.addElement("NumberOfRows", ui.numberOfRowLineEdit->text().toStdString());
	xml.addElement("NumberOfColumn", ui.numberOfColumnsLineEdit->text().toStdString());
	xml.addElement("SizeOfSqare", ui.sizeOfSquareMmLineEdit->text().toStdString());
	xml.closeBalise();
	
}


