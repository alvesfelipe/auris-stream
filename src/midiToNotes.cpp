#include "midiToNotes.h"

MidiToNotes::MidiToNotes(){}

bool MidiToNotes::midiNotes(string out_name, string midi_path, string out_path){
	
	string returned, aux;

	char const* auris_aux_home = getenv("AURIS_HOME_PATH");
	string auris_home(auris_aux_home);

	cout << "Processing..." << endl;
	
	string lib_path = "cd " + auris_home + "/auris-core/auris-stream/lib/midifile/bin && ";
	string exec = "./midi2notes " + midi_path + " > " + out_path + out_name + ".txt";

	if (!boost::filesystem::exists(midi_path)){
  		cout << "Can't find midi file!" << std::endl;
		return false;
	}

	//system call to midifile lib
	redi::ipstream in(lib_path + exec);   
	
	cout << "SUCCESS" << endl;
	return true;
}


MidiToNotes::~MidiToNotes(){}