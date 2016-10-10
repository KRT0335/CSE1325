#include "RobotParts.h"

#include <iostream>
#include <string>
#include <vector>

//using namespace std;

string RobotParts::to_string() {
	string com = "Torso: " + torso.to_string() + ", Head: " + head.to_string() + ", Arm: " + arm.to_string() + ", Battery: " + battery.to_string() + ", Locomotor: " + locomotor.to_string();
	return com;
}

string Component::parts_to_string(int index) {
	return robotParts[index].to_string();
}

void Component::add_part(RobotParts rb) {
	robotParts.push_back(rb);
}