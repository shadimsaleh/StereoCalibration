#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

vector<vector<QString>> FileManager::loadStereoImages(){
	vector<vector<QString>> vecToReturn;

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
			vecToReturn.push_back(colorVector);
			vecToReturn.push_back(infraredVector);
		}
	}
	return vecToReturn;
}

