#include "notes.h"

Notes::Notes(){}

void Notes::setNotesMidi(){

	vector<int> auxVector;

	//create and set vector with notes
	this->notes.push_back("C");
	this->notes.push_back("C#");
	this->notes.push_back("D");
	this->notes.push_back("D#");
	this->notes.push_back("E");
	this->notes.push_back("F");
	this->notes.push_back("F#");
	this->notes.push_back("G");
	this->notes.push_back("G#");
	this->notes.push_back("A");
	this->notes.push_back("A#");
	this->notes.push_back("B");

	int aux;

	//populating map with 
	for(int j=0; j<8; j++){
		aux = j;
		for(int i=0; i<11; i++){
			auxVector.push_back(aux);
			aux += 12;
		}
		this->notesMidi.insert ( std::pair<string,vector<int> >(this->notes.at(j), auxVector) );
		auxVector.clear();
	}

	for(int j=8; j<12; j++){
		aux = j;
		for(int i=0; i<10; i++){
			auxVector.push_back(aux);
			aux += 12;
		}
		this->notesMidi.insert ( std::pair<string,vector<int> >(this->notes.at(j), auxVector) );
		auxVector.clear();
	}
}

Notes::~Notes(){}