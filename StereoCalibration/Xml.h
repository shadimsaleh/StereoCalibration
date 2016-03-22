#ifndef XML_H
#define XML_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#pragma once
using namespace std;

class Xml
{
public:
	Xml();
	Xml(string nameOfFile);
	~Xml();
	void addElement(string b, string e);
	void closeBalise();
	string giveWhiteSpace();
	void openBalise(string balise);
	
private:
	string nameOfFile;
	vector<string> lastBalise;
	ofstream fichier;
};

#endif XML_H

