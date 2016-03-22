#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

vector<vector<Mat>> FileManager::loadStereoImages(){
	vector<vector<Mat>> vecToReturn;

	//Chargement du répertoire contenant les images
	QString name = QFileDialog::getExistingDirectory(0, QObject::tr("Open Directory"), "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir directory = QDir(name);

	if (directory.exists()){
		vector<Mat> colorVector;
		vector<Mat> infraredVector;

		QDirIterator dirIte(directory);

		while (dirIte.hasNext()){
			QString fileName = dirIte.fileName();
			QStringList qsl = fileName.split("Color-");
			if (qsl.size() == 2){
				Mat m = imread(dirIte.path().toStdString());
				colorVector.push_back(m);
			}
			else{
				qsl = fileName.split("Infrared-");
				if (qsl.size() == 2){
					Mat m = imread(dirIte.path().toStdString(), CV_LOAD_IMAGE_GRAYSCALE);
					infraredVector.push_back(m);
				}
			}
			dirIte.next();
		}

		if (colorVector.size() == infraredVector.size()){
			vecToReturn.push_back(colorVector);
			vecToReturn.push_back(infraredVector);
		}
	}
	return vecToReturn;
}
