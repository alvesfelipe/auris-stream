#include "aurisStream.h"

AurisStream::AurisStream(){}

bool AurisStream::setMotorList(string config_path, string midi_notes, int id_option){
	
    Notes *nt = new Notes();
	
    ifstream config_file(config_path.c_str());
	ifstream midi_file(midi_notes.c_str());

	string column1, column2;
	bool flag1=false, flag2=false;

	int on, off, midi;
	
	nt->setNotesMidi();

	if(!config_file.is_open()){
		config_file.clear();
        config_file.close();

    	cout << "UNABLE TO OPEN CONFIGURATION FILE" << endl;

        delete nt;
    	return false;
    }
    
    if(!midi_file.is_open()){
		midi_file.clear();
        midi_file.close();

        cout << "UNABLE TO OPEN MIDI FILE" << endl;

        delete nt;
        return false;
    }

    //read midi file with melody of music
    while(midi_file >> midi >> on >> off){
    	//scans the map and each of its vectors to set notes of motors
        for(map<string, vector<int> >::iterator it=nt->notesMidi.begin(); it!=nt->notesMidi.end(); ++it){
			for(vector<int>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2){
				if(*it2 == midi){
					this->allRequisitions.push_back(new Motor(midi, -1, "", it->first, on, off, -1));	
				    if((find(this->notesContent.begin(), this->notesContent.end(), it->first)
                        != this->notesContent.end()) == false)                       
                        this->notesContent.push_back(it->first);
                }       
			}
		}	
    }
    midi_file.close();

    //ids can be seted as defaul or from configure archive
    if(id_option == 0)
        setDefaultIds();

    //read configuration file
    while(config_file >> column1 >> column2){
    	//set id and type of motor by configure archive if id_option=1   	
    	if(flag1 == true && column2.compare("frequencyrange") != 0){	
    		for(list<Motor *>::iterator it=this->allRequisitions.begin(); it != this->allRequisitions.end(); ++it){
    			if((*it)->getNote().compare(column2) == 0){
    				if(id_option == 1){
                        (*it)->setIdMotor(atoi(column1.c_str()));
                    }
    				(*it)->setTypeMotor("note");
    			}
    		}
    	}
    	//set vibration level of motor
    	if(flag2 == true){
    		for(list<Motor *>::iterator it=this->allRequisitions.begin(); it != this->allRequisitions.end(); ++it){
    			if((*it)->getNote().compare(column1) == 0)
    				(*it)->setVibrationLevel(atoi(column2.c_str()));
    		}
    	}
    	//check delimiters
    	if(column2.compare("note") == 0){
    		flag1 = true;
    	}
    	if(column2.compare("frequencyrange") == 0){
    		flag2 = true;
    		flag1 = false;
    	}
    	//end of check delimiters
    }
    config_file.close();

    delete nt;
    return true;
}

bool AurisStream::streamAurisGenerate(string out_name, string config_path, string midi_notes, 
                                     int id_option, string out_path){
    
    ofstream out_stream((out_path + out_name + ".txt").c_str());
    
    if (!out_stream.is_open()){
        cout << "UNABLE TO GENERATE AURIS STREAM" << endl;
        return false;
    }

    setMotorList(config_path, midi_notes, id_option);
    //write list of motors in archive
    for(list<Motor *>::iterator it=this->allRequisitions.begin(); it != this->allRequisitions.end(); ++it){
        out_stream << std::to_string((*it)->getIdMotor()) + " " + to_string((*it)->getTimeOn()) +  " " + 
                      to_string((*it)->getTimeOff()) + " " + to_string((*it)->getVibrationLevel()) + "\n";
    }
    
    out_stream.close();    

    return true;
}

void AurisStream::setDefaultIds(){
    int cont = 0;    
    //scans the motor list and notes presents on melody for set each id motor automatically
    for(list<Motor *>::iterator it=this->allRequisitions.begin(); it != this->allRequisitions.end(); ++it){
        for(vector<string>::iterator it2=this->notesContent.begin(); it2 != this->notesContent.end(); ++it2){
            if((*it)->getNote() == (*it2)){
                (*it)->setIdMotor(cont);
            }
            cont ++;
        }
        cont = 0;
    }
}

void AurisStream::printMotorList(list<Motor *> *motor){
	for(list<Motor *>::iterator it=motor->begin(); it != motor->end(); ++it){
		cout << "Midi Note: " << (*it)->getMidiNote() << endl;
		cout << "Id Motor: " << (*it)->getIdMotor() << endl;
		cout << "Type Motor: " << (*it)->getTypeMotor() << endl;
		cout << "Time On: " <<(*it)->getTimeOn() << endl;
		cout << "Time Off:  " << (*it)->getTimeOff() << endl;
		cout << "Vibration Level: " << (*it)->getVibrationLevel() << endl;
		cout << "Note: " << (*it)->getNote() << endl;
		cout << "---------------------------" << endl;
	}
}

void AurisStream::printMusicNotes(){

    for(vector<string>::iterator it2=this->notesContent.begin(); it2 != this->notesContent.end(); ++it2){
        cout << "Note: " << *it2 << endl;
    }
    cout << "Number of Notes: " << this->notesContent.size() << endl;
}

AurisStream::~AurisStream(){}