#include "ParametersLoader.h"


ParametersLoader::ParametersLoader()
{
	this->fileName = "StereoCalibrationParameters.xml";

	ifstream fichier(this->fileName.toStdString(), ios::in);

	FileContent = "";
	if (fichier){
		//Récupération du fichier 
		string ligne;
		while (getline(fichier, ligne))
		{
			FileContent.append(QString::fromStdString(ligne));
		}

		fichier.close();
	}
	
}


ParametersLoader::~ParametersLoader()
{
}

vector<QString> ParametersLoader::getImagesPath(){
	vector<QString> vecToReturn;
	
	if (FileContent != "")
	{
		if (FileContent.contains("</imagesPath>")){
			vector<QString> vec;
			//Obtention des premiers path (vector 1)
			QStringList qsl = FileContent.split("</imagesPath>");
			if (qsl.size() == 2){
				qsl = qsl.at(0).split("<imagesPath>");
				if (qsl.size() == 2){
					QStringList qsll = qsl.at(1).split("</Path>");
					for (int i = 0; i < qsll.size(); i++){
						QString path = qsll.at(i);
						path.replace(QString("	"), QString(""));
						path.replace(QString("<Path>"), QString(""));
						path.replace(QString("</Path>"), QString(""));
						if (path != ""){
							vec.push_back(path);
						}
					}
				}
			}
			return vec;
		}
	}
	else{
		//Log error
	}

	return vecToReturn;
}

Pattern ParametersLoader::getPattern(){
	if (FileContent != ""){
		if (FileContent.contains("</Pattern>")){
			QStringList qsl = FileContent.split("</Pattern>");
			if (qsl.size() == 2){
				qsl = qsl.at(0).split("<Pattern>");
				if (qsl.size() == 2){
					
					QStringList qsll;
					//Numéro de ligne
					qsll = qsl.at(1).split("</NumberOfRows>");
					QString rowString = qsll.at(0).split("<NumberOfRows>").at(1);
					int row = rowString.toInt();

					//Column
					qsll = qsl.at(1).split("</NumberOfColumn>");
					QString colString = qsll.at(0).split("<NumberOfColumn>").at(1);
					int col = colString.toInt();

					//SizeSqare
					qsll = qsl.at(1).split("</SizeOfSqare>");
					QString sizeSqareString = qsll.at(0).split("<SizeOfSqare>").at(1);
					double sizeSqare = sizeSqareString.toDouble();

					return Pattern(row, col, sizeSqare);
				}
			}
		}
	}
	return Pattern();
}
