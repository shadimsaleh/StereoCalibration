#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <qstring.h>
#include <qfiledialog.h>
#include <vector>
#include <qdiriterator.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#pragma once
class FileManager
{
public:
	FileManager();
	~FileManager();
	vector<QString> loadStereoImages();
	
};

#endif FILEMANAGER_H

