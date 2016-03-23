#include "Xml.h"

Xml::Xml()
{

}

Xml::Xml(string nameOfFile){

	string name = nameOfFile + "Parameters" + ".xml";

	this->nameOfFile = nameOfFile;
	
	this->fichier = ofstream(name, ios::out | ios::trunc);

	if (fichier) 
	{
		fichier << "<" + nameOfFile + ">" << endl;
	}
	else{
		//Log error
	}
}


Xml::~Xml()
{
	if (this->fichier)
	{
		fichier << "</" + nameOfFile + ">";
		fichier.close();
	}
}

void Xml::addElement(string b, string e){
	if (this->fichier){
		fichier << giveWhiteSpace() << "<" << b << ">" << e << "</" << b << ">" << endl;
	}
}

void Xml::closeBalise(){
	if (this->fichier && this->lastBalise.size() != 0){
		string balise = this->lastBalise.at(this->lastBalise.size() - 1);
		this->lastBalise.erase(this->lastBalise.begin() + this->lastBalise.size() - 1);
		fichier << giveWhiteSpace() << "</" << balise << ">" << endl;
	}
}

string Xml::giveWhiteSpace(){
	string tab = "	";
	string espace = tab;
	for (int i = 0; i < this->lastBalise.size(); i++)
		espace += tab;

	return espace;
}

void Xml::openBalise(string balise){
	if (this->fichier){
		fichier << giveWhiteSpace() << "<" << balise << ">" << endl;
		this->lastBalise.push_back(balise);
	}
}
