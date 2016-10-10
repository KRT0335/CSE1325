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
			totalWeight(p_totalWeight){}

		
		

	private:
		double totalWeight;
		double energy;
		double speed;
		int numParts;
		int batteryCapacity;
		int numTorso, numHead, numArm, numLocomotor;
		vector<RobotParts> robotParts;
		Component component;
};

class FullModel {
	public:
		void createModel();
		void checkInputInt(int inputInt);
		void checkInputDouble(double inputDouble);
		void add_model(RobotModels rm);
	private:
		vector<RobotModels> robotModels;
};

#endif