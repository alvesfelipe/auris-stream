#ifndef _NOTES_H
#define _NOTES_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Notes{

	private:  

	public:

		//map for set midi notes
		map<string, vector <int> > notesMidi;
		//vector for notes
		vector<string> notes;

		//set notes midi
		void setNotesMidi();

		//constructor
		Notes();	

		//destructor
		~Notes();

};

#endif