#include "RobotParts.h"
#include "RobotModels.h"

#include <iostream>
#include <string>
#include <vector>





//Test the cout for the parts name
void FullModel::print(int index) {
	cout << component.parts_to_string(index) << endl;
	cout << "Torso Name: " << component.get_torso_name(index) << endl;
	cout << "Head Name: " << component.get_head_name(index) << endl;
	cout << "Arm Name: " << component.get_arm_name(index) << endl;
	cout << "Arm2 Name: " << component.get_arm1_name(index) << endl;
	cout << "Locomotor Name: " << component.get_locomotor_name(index) << endl;
	cout << "Battery Name: " << component.get_battery_name(index) << endl;
}

string RobotModels::numParts_to_string(int index) {
	string mod = "Your Robot's number of Parts: " + std::to_string(numParts);
	return mod;
}

string RobotModels::numTorso_to_string(int index) {
	string mod = "Your Robot's number of Torsos: " + std::to_string(numTorso);
	return mod;
}

string RobotModels::numHead_to_string(int index) {
	string mod = "Your Robot's number of Heads: " + std::to_string(numHead);
	return mod;
}

string RobotModels::numArm_to_string(int index) {
	string mod = "Your Robot's number of Arms: " + std::to_string(numArm);
	return mod;
}

string RobotModels::numLocomotor_to_string(int index) {
	string mod = "Your Robot's number of Locomotors: " + std::to_string(numLocomotor);
	return mod;
}

string RobotModels::speed_to_string(int index) {
	string mod = "Your Locomotor's speed: " + std::to_string(speed);
	return mod;
}

string RobotModels::batteryCapacity_to_string(int index) {
	string mod = "Your Robot's Battery Capacity: " + std::to_string(batteryCapacity);
	return mod;
}

string RobotModels::energy_to_string(int index) {
	string mod = "Your Battery's energy: " + std::to_string(energy);
	return mod;
}

string RobotModels::totalWeight_to_string(int index) {
	string mod = "Your Robot's Total Weight: " + std::to_string(totalWeight);
	return mod;
}

//Print Robot Model values
void FullModel::printRM(int index) {
	cout << robotModels[index].numParts_to_string(index) << endl;
	cout << robotModels[index].numTorso_to_string(index) << endl;
	cout << robotModels[index].numHead_to_string(index) << endl;
	cout << robotModels[index].numArm_to_string(index) << endl;
	cout << robotModels[index].numLocomotor_to_string(index) << endl;
	cout << robotModels[index].speed_to_string(index) << endl;
	cout << robotModels[index].batteryCapacity_to_string(index) << endl;
	cout << robotModels[index].energy_to_string(index) << endl;
	cout << robotModels[index].totalWeight_to_string(index) << endl;
}

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
	//vector<RobotParts> robotParts;

	int select = 0, countParts = 0;
	int numTorso = 0, numArm = 0, numLocomotor = 0, numHead = 0, numBattery = 0;
	int batteryCapacity = 0;
	int modelTest = 0;
	double weight, totalWeight = 0;
	double energy = 0;
	double speed = 0;
	string modelName;
	Torso torso = "None";
	Head head = "None";
	Arm arm = "None";
	Arm1 arm1 = "None";
	Locomotor locomotor = "None";
	Battery battery = "None";

	while (select != -1) {
		cout << "Select: " << endl << "[1] Add Torso"
			<< endl << "[2] Add Head" << endl
			<< "[3] Add Arm" << endl
			<< "[4] Locomotor" << endl
			<< "[5] Add Battery(s)" << endl
			<< "[-1] Finish Model" << endl;
		cin >> select;
		checkInputInt(select);
		

		switch (select) {
		case 1://Torso
			if (numTorso >= 1) {
				cout << "You already have a Torso in the model." << endl;
				break;
			}

			cin.ignore();
			cout << "Torso Name:" << endl;
			getline(cin, modelName);
			torso = modelName;
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
			countParts++;
			numTorso += 1;
			modelTest = 1;
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

			cin.ignore();
			cout << "Head Name:" << endl;
			getline(cin, modelName);
			head = modelName;
			cout << "Adding Head:" << endl << "Weight? ";
			cin >> weight;
			checkInputDouble(weight);
			cin.ignore();
			totalWeight += weight;
			select = 0;
			countParts++;
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

			cin.ignore();

			if (numArm == 0) {
				cout << "1st Arm Name:" << endl;
				getline(cin, modelName);
				arm = modelName;
			}
			else if (numArm == 1) {
				cout << "2nd Arm Name:" << endl;
				getline(cin, modelName);
				arm1 = modelName;
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

			cin.ignore();
			cout << "Locomotor Name:" << endl;
			getline(cin, modelName);
			locomotor = modelName;
			cout << "Adding Locomotor:" << endl << "Speed of the motor? ";
			cin >> speed;
			checkInputDouble(speed);
			cin.ignore();
			cout << "Weight? ";
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

			cin.ignore();
			cout << "Battery Name/Type:" << endl;
			getline(cin, modelName);
			battery = modelName;
			//cout << endl << battery.to_string() << endl << endl;
			cout << "What is the Energy of these Batteries? " << endl;
			cin >> energy;
			checkInputDouble(energy);
			cin.ignore();
			select = 0;
			countParts += batteryCapacity;
			numBattery += 1;
			break;

		case -1://Finish Model
			if (modelTest == 1) {
			cout << "Final Robot Model Finished." << endl;
			//cout << countParts<< "     123445"<<endl;
			//cout << robotModels[0].numParts_string(countParts) << "\tDASAAD"<<endl;
			
		}
			else
				cout << "The Model lacks a Torso so the Model is Incomplete." << endl;
			break;

		default:
			cout << "Invalid Input" << endl;
			select = 0;
		}
		
	}
	//cout << countParts;
	RobotParts insertRP(torso, head, locomotor, arm, arm1, battery);
	component.add_part(insertRP);
	cout << component.parts_to_string(0) << endl;
	RobotModels insertRM(countParts, numTorso, numHead, numArm, numLocomotor, speed, batteryCapacity, energy, totalWeight);
	add_model(insertRM);
}