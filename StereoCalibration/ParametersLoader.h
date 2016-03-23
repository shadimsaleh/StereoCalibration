#ifndef PARAMETERSLOADER_H
#define PARAMETERSLOADER_H

#include <qstring.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <qstringlist.h>
#include <qmessagebox.h>

using namespace std;

#pragma once
class ParametersLoader
{
public:
	ParametersLoader();
	~ParametersLoader();
	vector<vector<QString>> getImagesPath();

private:
	QString fileName;
};

#endif PARAMETERSLOADER_H

