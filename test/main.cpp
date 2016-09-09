#include "midiToNotes.h"
#include "aurisStream.h"

int main(){

	MidiToNotes *mtn = new MidiToNotes();
	AurisStream *as = new AurisStream();
	
	char const* tmp_home = getenv("HOME");
	string home(tmp_home);

	mtn->midiNotes("midi_notes", home + "/midiMelody.mid", home + "/");
	/*as->setMotorList(home + "/music_for_deaf/auris-core/auris-stream/file/configure.txt", 
								home + "/midi_notes.txt", 0);*/
	as->streamAurisGenerate("auris_stream", home + "/music_for_deaf/auris-core/auris-stream/file/configure.txt",
						   home + "/midi_notes.txt", 0, home + "/");

	as->printMotorList(&as->allRequisitions);
	as->printMusicNotes();

	delete as;
	delete mtn;
	return 0;
}