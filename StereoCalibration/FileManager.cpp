#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

vector<QString> FileManager::loadStereoImages(){
	vector<QString> vecToReturn;

	//Chargement du répertoire contenant les images
	QString name = QFileDialog::getExistingDirectory(0, QObject::tr("Open Directory"), "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir directory = QDir(name);

	if (directory.exists()){
		vector<QString> colorVector;
		vector<QString> infraredVector;

		QDirIterator dirIte(directory);

		while (dirIte.hasNext()){
			QString fileName = dirIte.fileName();
			QStringList qsl = fileName.split("Color-");
			if (qsl.size() == 2){
				colorVector.push_back(dirIte.filePath());
			}
			else{
				qsl = fileName.split("Infrared-");
				if (qsl.size() == 2){
					infraredVector.push_back(dirIte.filePath());
				}
			}
			dirIte.next();
		}

		if (colorVector.size() == infraredVector.size()){
			vecToReturn.insert(vecToReturn.end(), colorVector.begin(), colorVector.end());
			vecToReturn.insert(vecToReturn.end(), infraredVector.begin(), infraredVector.end());
		}
	}
	return vecToReturn;
}

