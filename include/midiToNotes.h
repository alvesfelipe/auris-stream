#ifndef _MIDITONOTES_H
#define _MIDITONOTES_H

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <pstream.h>

using namespace std;

class MidiToNotes{

	private:

	public:	
		MidiToNotes();
		
		//convert melody midi file to notes/duration file
		bool midiNotes(string out_name, string midi_path, string out_path);

		~MidiToNotes();
};

#endif