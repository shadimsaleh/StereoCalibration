#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <qstring.h>
#include <qfiledialog.h>
#include <vector>
#include <qdiriterator.h>


using namespace std;

#pragma once
class FileManager
{
public:
	FileManager();
	~FileManager();
	vector<vector<QString>> loadStereoImages();
};

#endif FILEMANAGER_H

