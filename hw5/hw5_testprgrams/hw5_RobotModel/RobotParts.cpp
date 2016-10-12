#include "RobotParts.h"

#include <iostream>
#include <string>
#include <vector>

//using namespace std;

void Component::print_parts(int index) {
	cout << parts_to_string(index) << endl;
}

string RobotParts::to_string() {
	string com = "Torso: " + torso.to_string() + ", Head: " + head.to_string() + ", Arm: " + arm.to_string() + ", Arm2: " + arm1.to_string() + ", Battery: " + battery.to_string() + ", Locomotor: " + locomotor.to_string();
	return com;
}

string Component::parts_to_string(int index) {
	return robotParts[index].to_string();
}

void Component::add_part(RobotParts rb) {
	robotParts.push_back(rb);
}

//TORSO
string RobotParts::get_torso_name() {
	return torso.to_string();
}

string Component::get_torso_name(int index) {
	return robotParts[index].get_torso_name();
}

//HEAD
string RobotParts::get_head_name() {
	return head.to_string();
}

string Component::get_head_name(int index) {
	return robotParts[index].get_head_name();
}

//ARM
string RobotParts::get_arm_name() {
	return arm.to_string();
}

string Component::get_arm_name(int index) {
	return robotParts[index].get_arm_name();
}

//ARM1
string RobotParts::get_arm1_name() {
	return arm1.to_string();
}

string Component::get_arm1_name(int index) {
	return robotParts[index].get_arm1_name();
}

//LOCOMOTOR
string RobotParts::get_locomotor_name() {
	return locomotor.to_string();
}

string Component::get_locomotor_name(int index) {
	return robotParts[index].get_locomotor_name();
}

//BATTERY
string RobotParts::get_battery_name() {
	return battery.to_string();
}

string Component::get_battery_name(int index) {
	return robotParts[index].get_battery_name();
}