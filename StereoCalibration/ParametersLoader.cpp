#include "ParametersLoader.h"


ParametersLoader::ParametersLoader()
{
	this->fileName = "StereoCalibrationParameters.xml";
}


ParametersLoader::~ParametersLoader()
{
}

vector<vector<QString>> ParametersLoader::getImagesPath(){
	vector<vector<QString>> vecToReturn;
	ifstream fichier(this->fileName.toStdString(), ios::in); 

	if (fichier)
	{
		//Récupération du fichier 
		QString file = "";
		string ligne;
		while (getline(fichier, ligne))
		{
			file.append(QString::fromStdString(ligne));
		}

		if (file.contains("</firstVecotr>") && file.contains("</secondVector>")){
			vector<QString> vecUn, vecDeux;
			//Obtention des premiers path (vector 1)
			QStringList qsl = file.split("</firstVecotr>");
			if (qsl.size() == 2){
				qsl = qsl.at(0).split("<firstVecotr>");
				if (qsl.size() == 2){
					QStringList qsll = qsl.at(1).split("</Path>");
					for (int i = 0; i < qsll.size(); i++){
						QString path = qsll.at(i);
						path.replace(QString("	"), QString(""));
						path.replace(QString("<Path>"), QString(""));
						path.replace(QString("</Path>"), QString(""));
						if (path != ""){
							vecUn.push_back(path);
						}
					}
				}
			}

			//Deuxieme vecotr
			qsl = file.split("</secondVector>");
			if (qsl.size() == 2){
				qsl = qsl.at(0).split("<secondVector>");
				if (qsl.size() == 2){
					QStringList qsll = qsl.at(1).split("</Path>");
					for (int i = 0; i < qsll.size(); i++){
						QString path = qsll.at(i);
						path.replace(QString("	"), QString(""));
						path.replace(QString("<Path>"), QString(""));
						path.replace(QString("</Path>"), QString(""));
						if (path != ""){
							vecDeux.push_back(path);
						}
					}
				}
			}

			vecToReturn.push_back(vecUn);
			vecToReturn.push_back(vecDeux);
		}
		
		fichier.close();
	}
	else{
		//Log error
	}

	return vecToReturn;
}
