#ifndef _MOTOR_H
#define _MOTOR_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Motor{
	
	private:
		int idMotor; //motor id
		string typeMotor; //motor type
		string note;
		double timeOn; 
		double timeOff;
		int vibrationLevel;	
		int midiNote;
	public: 
		//Setters
		void setMidiNote(int midiNote);
		void setIdMotor(int idMotor);
		void setTypeMotor(string typeMotor);
		void setTimeOn(double timeOn);
		void setTimeOff(double timeOff);
		void setVibrationLevel(int vibrationLevel);
		void setNote(string note);

		//Getters
		int getMidiNote();	
		int getIdMotor();
		string getTypeMotor();
		double getTimeOn();
		double getTimeOff();
		int getVibrationLevel();
		string getNote();

		//Constructor
		Motor(int midiNote, int idMotor, string typeMotor, string note, double timeOn, double timeOff, int vibrationLevel);
		//Empty constructor
		Motor();
		//Destructor
		~Motor();

		//print
		void toString();
};

#endif