#ifndef PARAMETERSLOADER_H
#define PARAMETERSLOADER_H

#include <qstring.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <qstringlist.h>
#include <qmessagebox.h>
#include "Pattern.h"

using namespace std;

#pragma once
class ParametersLoader
{
public:
	ParametersLoader();
	~ParametersLoader();
	vector<QString> getImagesPath();
	Pattern getPattern();

private:
	QString fileName;
	QString FileContent;
};

#endif PARAMETERSLOADER_H

