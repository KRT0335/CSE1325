#ifndef __ROBOTMODELS_H
#define __ROBOTMODELS_H 201609

#include "RobotParts.h"

#include <iostream>
#include <string>
#include <vector>



class RobotModels {
	public:
		RobotModels(string p_modelName,
			int p_modelNumber,
			int p_numParts,
			int p_numTorso,
			int p_numHead,
			int p_numArm,
			int p_numLocomotor,
			double p_speed,
			int p_batteryCapacity,
			double p_energy,
			double p_totalWeight):
			
			modelName(p_modelName),
			modelNumber(p_modelNumber),
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
			modelName("None"),
			modelNumber(0),
			numParts(0),
			numTorso(0),
			numHead(0),
			numArm(0),
			numLocomotor(0),
			speed(0),
			batteryCapacity(0),
			energy(0),
			totalWeight(0){}

		double get_weight(int index);
		string modelName_to_string(int index);
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
		int modelNumber;
		int numParts;
		int batteryCapacity;
		int numTorso, numHead, numArm, numLocomotor;
		string modelName;
		RobotParts robotParts;
		Component component;

		
};

class FullModel {
	public:

		void createModel(int modelNumber);
		void checkInputInt(int inputInt);
		void checkInputDouble(double inputDouble);
		void add_model(RobotModels rm);

		void printModelName(int index);
		void print(int index);
		void printRM(int index);

	private:
		Component component;
		vector<RobotModels> robotModels;
		vector<RobotParts> robotParts;
		
};

#endif