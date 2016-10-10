#include "RobotParts.h"
#include "RobotModels.h"

#include <iostream>
#include <string>
#include <vector>

void FullModel::checkInputInt(int x) {
	while (cin.fail()) {
		cerr << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x;
	}
}

void FullModel::checkInputDouble(double y) {
	while (cin.fail()) {
		cerr << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> y;
	}
}

void FullModel::add_model(RobotModels rm) {
	robotModels.push_back(rm);
}

void FullModel::createModel() {
	int select = 0, countParts = 0;
	int numTorso = 0, numArm = 0, numLocomotor = 0, numHead = 0, numBattery = 0;
	int batteryCapacity = 0;
	double weight, totalWeight = 0;
	double energy = 0;
	double speed = 0;
	string modelName;

	while (select != -1) {
		cout << "Select: " << endl << "[1] Add Torso"
			<< endl << "[2] Add Head" << endl
			<< "[3] Add Arm" << endl
			<< "[4] Locomotor" << endl
			<< "[5] Add Battery" << endl;
		cin >> select;
		checkInputInt(select);
		switch (select) {
		case 1://Torso
			if (numTorso >= 1) {
				cout << "You already have a Torso in the model." << endl;
				break;
			}

			
			cout << "Adding torso:" << endl << "Weight? ";
			cin >> weight;
			checkInputDouble(weight);
			//cin.ignore;
			totalWeight += weight;
			cout << "Battery Capacity? ";
			cin >> batteryCapacity;
			checkInputInt(batteryCapacity);
			cin.ignore();
			select = 0;
			countParts += 1;
			numTorso += 1;
			break;

		case 2://Head
			if (numTorso == 0) {
				cout << "Its best to add the Torso first." << endl;
				break;
			}
			else if (numHead >= 1) {
				cout << "You already have a Head in the model." << endl;
				break;
			}

			
			cout << "Adding Head:" << endl << "Weight? ";
			cin >> weight;
			checkInputDouble(weight);
			cin.ignore();
			totalWeight += weight;
			select = 0;
			countParts += 1;
			numHead += 1;
			break;

		case 3://Arm
			if (numTorso == 0) {
				cout << "Its best to add the Torso first." << endl;
				break;
			}
			else if (numArm >= 2) {
				cout << "You already have 2 Arms in the model." << endl;
				break;
			}

			
			cout << "Adding Arm:" << endl << "Weight? ";
			cin >> weight;
			checkInputDouble(weight);
			cin.ignore();
			totalWeight += weight;
			select = 0;
			countParts += 1;
			numArm += 1;
			break;

		case 4://Locomotor
			if (numTorso == 0) {
				cout << "Its best to add the Torso first." << endl;
				break;
			}
			else if (numLocomotor >= 1) {
				cout << "You already have a Locomotor in the model." << endl;
				break;
			}

			cout << "Speed of the motor?";
			cin >> speed;
			checkInputDouble(speed);
			cin.ignore();
			cout << "Adding Locomotor:" << endl << "Weight? ";
			cin >> weight;
			checkInputDouble(weight);
			cin.ignore();
			totalWeight += weight;
			select = 0;
			countParts += 1;
			numLocomotor += 1;
			break;

		case 5://Battery
			if (numTorso == 0) {
				cout << "Its best to add the Torso first." << endl;
				break;
			}
			else if (numBattery >= 1) {
				cout << "You already have " + to_string(batteryCapacity) + " Batteries in the model." << endl;
				break;
			}

			cout << "What is the Energy of these Batteries?" << endl;
			cin >> energy;
			checkInputDouble(energy);
			cin.ignore();
			select = 0;
			countParts += batteryCapacity;
			numBattery += 1;
			break;

		case -1://Finish Model
			break;
		default:
			cout << "Invalid Input" << endl;
			select = 0;
		}

		RobotModels insert(countParts, numTorso, numHead, numArm, numLocomotor, speed, batteryCapacity, energy, totalWeight);
		add_model(insert);
	}

}