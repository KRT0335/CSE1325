#ifndef __ROBOTMODELS_H
#define __ROBOTMODELS_H 201609

#include "RobotParts.h"

#include <iostream>
#include <string>
#include <vector>



class RobotModels {
	public:
		RobotModels(int p_numParts,
			int p_numTorso,
			int p_numHead,
			int p_numArm,
			int p_numLocomotor,
			double p_speed,
			int p_batteryCapacity,
			double p_energy,
			double p_totalWeight):
			
			numParts(p_numParts),
			numTorso(p_numTorso),
			numHead(p_numHead),
			numArm(p_numArm),
			numLocomotor(p_numLocomotor),
			speed(p_speed),
			batteryCapacity(p_batteryCapacity),
			energy(p_energy),
			totalWeight(p_totalWeight),
			robotParts(RobotParts()){}

		RobotModels():
			numParts(0),
			numTorso(0),
			numHead(0),
			numArm(0),
			numLocomotor(0),
			speed(0),
			batteryCapacity(0),
			energy(0),
			totalWeight(0){}

		

		string numParts_to_string(int index);
		string numTorso_to_string(int index);
		string numHead_to_string(int index);
		string numArm_to_string(int index);
		string numLocomotor_to_string(int index);
		string speed_to_string(int index);
		string batteryCapacity_to_string(int index);
		string energy_to_string(int index);
		string totalWeight_to_string(int index);
		

	private:
		double totalWeight;
		double energy;
		double speed;
		int numParts;
		int batteryCapacity;
		int numTorso, numHead, numArm, numLocomotor;
		RobotParts robotParts;
		Component component;

		
};

class FullModel {
	public:

		void createModel();
		void checkInputInt(int inputInt);
		void checkInputDouble(double inputDouble);
		void add_model(RobotModels rm);

		string model_to_string(int index);

		void print(int index);
		void printRM(int index);

	private:
		Component component;
		vector<RobotModels> robotModels;
		vector<RobotParts> robotParts;
		//Torso torso;
};

#endif