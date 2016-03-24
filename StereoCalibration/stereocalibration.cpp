#include "stereocalibration.h"

StereoCalibration::StereoCalibration(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonLoadImages, SIGNAL(clicked()), SLOT(onPushButtonLoadImagesClicked()));
	connect(ui.pushButtonPointsDetection, SIGNAL(clicked()), SLOT(pointDetectionAuto()));
	connect(ui.pushButtonNextFrame, SIGNAL(clicked()), SLOT(onPushButtonNextFrameClicked()));
	connect(ui.pushButtonStartDetection, SIGNAL(clicked()), SLOT(onPushButtonStartDetectionClicked()));
	connect(ui.pushButtonStartCalibration, SIGNAL(clicked()), SLOT(onPushStartCalibrationClicked()));

	//Parametre du pattern form
	connect(ui.numberOfRowLineEdit, SIGNAL(textEdited(QString)), SLOT(patternParametersMaj()));
	connect(ui.numberOfColumnsLineEdit, SIGNAL(textEdited(QString)), SLOT(patternParametersMaj()));

	//
	readParameters();

	if (stereoImagesPath.size() != 0){
		ui.pushButtonStartDetection->setEnabled(true);
	}
}

StereoCalibration::~StereoCalibration()
{
	this->saveParameters();
}

void StereoCalibration::onComputeIntrinsicsParametersChanged(){

}

void StereoCalibration::displayCurrentMat(){
	if (stereoImagesPath.size() != 0){
		Mat m = currentMat;
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

		if (currentIndice == stereoImagesPath.size() - 2){
			ui.pushButtonNextFrame->setEnabled(false);
			ui.pushButtonStartCalibration->setEnabled(true);
		}
			
		if (currentIndice != stereoImagesPath.size() - 1)
		{
			//Enrrgistrement des points courrant dans le vecteur principal et nettoyage du vecteur courant
			currentPointsVector.clear();

			//incrémentation de l'image
			currentIndice++;
			currentMat = imread(stereoImagesPath.at(currentIndice).toStdString());
			displayCurrentMat();

			ui.pushButtonNextFrame->setEnabled(false);
			ui.pushButtonPointsDetection->setEnabled(true);
		}
	}
	else{
		ui.textBrowserLog->append("Not enough points selected " + QString::number(currentPointsVector.size()) + "/" + QString::number(numberOfPoints));
		QMessageBox::warning(this, "Error", "Not enough points selected");
	}
}

void StereoCalibration::onPushStartCalibrationClicked(){
	//Calcul du nombre de points pour savoir si il y a le nombre de point nécéssaire à la calibration
	int nbPointSupose = stereoImagesPath.size() * (pattern.getRow() - 1) * (pattern.getCol() - 1);
	int nbPointReel = 0;

	for (int i = 0; i < calibrationPoints.size(); i++){
		nbPointReel += calibrationPoints.at(i).size();
	}

	if (nbPointSupose == nbPointReel){
		ui.textBrowserLog->append("Starting compute stereo calibration");

		vector<vector<Point3f> > objectPoints;

		int noOfStereoPairs = stereoImagesPath.size()/2;
		objectPoints.resize(noOfStereoPairs);

		for (int i = 0; i<noOfStereoPairs; i++) {
			for (int j = 0; j<pattern.getRow() - 1; j++) {
				for (int k = 0; k<pattern.getCol() - 1; k++) {
					objectPoints[i].push_back(Point3f(float(k), float(j), 0.0));
				}
			}
		}
		int half_size = stereoImagesPath.size() / 2;
		vector<vector<Point2f>> split_lo(calibrationPoints.begin(), calibrationPoints.begin() + half_size);
		vector<vector<Point2f>> split_hi(calibrationPoints.begin() + half_size, calibrationPoints.end());

		ui.textBrowserLog->append(QString::number(split_lo.size()));
		ui.textBrowserLog->append(QString::number(split_hi.size()));

		Mat cameraMatrix[2], distCoeffs[2];
		cameraMatrix[0] = Mat::eye(3, 3, CV_64F);
		cameraMatrix[1] = Mat::eye(3, 3, CV_64F);
		Mat R, T, E, F;

		double rms = stereoCalibrate(objectPoints, split_lo, split_hi, cameraMatrix[0], distCoeffs[0], cameraMatrix[1], distCoeffs[1], Size(currentMat.cols, currentMat.rows), R, T, E, F);

		ui.textBrowserLog->append("RMS : " +QString::number(rms));

		ofstream fichier("mystereocalib.txt", ios::out | ios::trunc);

		if (fichier){
			fichier << "RMS Error: " << rms << endl;
			fichier << "CM1 : Color" << cameraMatrix[0] << endl;
			fichier << "CM2 : Infrared" << cameraMatrix[1] << endl;
			fichier << "D1 : Color" << distCoeffs[0] << endl;
			fichier << "D2 : Infrared" << distCoeffs[1] << endl;
			fichier << "R" << R << endl;
			fichier << "T" << T << endl;
			fichier << "E" << E << endl;
			fichier << "F" << F << endl;

			


			Mat R1, R2, P1, P2, Q;
			stereoRectify(cameraMatrix[0], distCoeffs[0], cameraMatrix[1], distCoeffs[1], Size(currentMat.cols, currentMat.rows), R, T, R1, R2, P1, P2, Q);
			fichier << "R1" << R1 << endl;
			fichier << "R2" << R2 << endl;
			fichier << "P1" << P1 << endl;
			fichier << "P2" << P2 << endl;
			fichier << "Q" << Q << endl;
		}
		ui.textBrowserLog->append("End of stereo calibration");
	}
	else{
		QMessageBox::warning(this, "Error", "Not enough points");
		ui.textBrowserLog->append(QString::number(nbPointReel) + "/" + QString::number(nbPointSupose) + " Points");
	}
}

void StereoCalibration::onPushButtonStartDetectionClicked(){
	//Désactivation des formulaires précédents
	ui.numberOfRowLineEdit->setEnabled(false);
	ui.sizeOfSquareMmLineEdit->setEnabled(false);
	ui.numberOfColumnsLineEdit->setEnabled(false);

	//Activation des autres formulaires
	ui.pushButtonPointsDetection->setEnabled(true);
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
			calibrationPoints.push_back(currentPointsVector);

			//Si c'est la derniere image on n'autorise plus d'aller à la frame suivante
			if (currentIndice == stereoImagesPath.size() - 1){
				ui.pushButtonPointsDetection->setEnabled(false);
			}
			else{
				ui.pushButtonNextFrame->setEnabled(true);
				ui.pushButtonPointsDetection->setEnabled(false);
			}
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


