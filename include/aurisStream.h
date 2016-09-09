#ifndef _AURISSTREAM_H
#define _AURISSTREAM_H

#include "motor.h"
#include "notes.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class AurisStream{

	public:
		AurisStream();

		list<Motor *> allRequisitions;
		vector<string> notesContent;
		
		//set list of motor with all informations of configurations archive and Midi Notes file
		bool setMotorList(string config_path, string midi_notes, int id_option);

		//generate file with auris format
		bool streamAurisGenerate(string out_name, string config_path, string midi_notes, 
                                 int id_option, string out_path);

		//set ids as default, without configuration file
		void setDefaultIds();

		void printMotorList(list<Motor *> *motor);

		void printMusicNotes();

		~AurisStream();	
};

#endif