#include "motor.h"

Motor::Motor(int midiNote, int idMotor, string typeMotor, string note, double timeOn, double timeOff, int vibrationLevel){

	this->midiNote = midiNote;
	this->idMotor = idMotor;
	this->typeMotor = typeMotor;
	this->note = note;
	this->timeOn = timeOn;
	this->timeOff = timeOff;
	this->vibrationLevel = vibrationLevel;
}

Motor::Motor(){}

void Motor::setMidiNote(int midiNote){

	this->midiNote = midiNote;
}

int Motor::getMidiNote(){

	return this->midiNote;
}

void Motor::setIdMotor(int idMotor){

	this->idMotor = idMotor;
}

int Motor::getIdMotor(){

	return this->idMotor;
}

void Motor::setTypeMotor(string typeMotor){

	this->typeMotor = typeMotor;
}

string Motor::getTypeMotor(){

	return this->typeMotor;
}

void Motor::setNote(string note){

	this->note = note;
}

string Motor::getNote(){

	return this->note;
}

void Motor::setTimeOn(double timeOn){

	this->timeOn = timeOn;
}

double Motor::getTimeOn(){

	return this->timeOn;
}

void Motor::setTimeOff(double timeOff){

	this->timeOff = timeOff;
}

double Motor::getTimeOff(){

	return this->timeOff;
}

void Motor::setVibrationLevel(int vibrationLevel){

	this->vibrationLevel = vibrationLevel;
}

int Motor::getVibrationLevel(){

	return this->vibrationLevel;
}

Motor::~Motor(){}

void Motor::toString(){
	std::cout << "Motor ID:" << this->idMotor << "\n" << "On Motor:" << this->timeOn << "\n" << "Motor Off:" << this->timeOff << "\n" << "Vibration Level:" << this->vibrationLevel << endl;
}
