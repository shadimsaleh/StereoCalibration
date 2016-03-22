#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <qstring.h>
#include <qfiledialog.h>
#include <vector>
#include <qdiriterator.h>

#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#pragma once
class FileManager
{
public:
	FileManager();
	~FileManager();
	vector<vector<Mat>> loadStereoImages();
};

#endif FILEMANAGER_H

