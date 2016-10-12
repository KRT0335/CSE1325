#ifndef __ROBOTPARTS_H
#define __ROBOTPARTS_H 201609



#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Connect to Robot Model
/*
Brainstorm:
Give Models of Arms and Head
Customer Customize values for Torso, Battery and Locomotor
*/

//vector<RobotParts> robotParts;


/*
List:
int batteryCompacity
*/
class Torso {
	public:
		/*
		Torso(int p_batteryCompartments):
			batteryCompartments(p_batteryCompartments) {}
		*/
		Torso(string p_nameTorso): nameTorso(p_nameTorso){}

		string to_string() {
			return nameTorso;
		}
		
	private:
		double weight;
		int batteryCompartments;
		string nameTorso;

		
};

/*
List:

*/
class Head {
		public:
			Head(string p_nameHead): nameHead(p_nameHead){}
			
			string to_string() {
				return nameHead;
			}

		private:
			double weight;
			string nameHead;
};

/*
List:

*/
class Arm {
	public:
		Arm(string p_nameArm) : nameArm(p_nameArm) {}

		string to_string() {
			return nameArm;
		}

	private:
		double weight;
		string nameArm;
};

class Arm1 {
public:
	Arm1(string p_nameArm1) : nameArm1(p_nameArm1) {}

	string to_string() {
		return nameArm1;
	}

private:
	double weight;
	string nameArm1;
};

/*
List:
double energy
double maxPower
*/
class Battery {
	public:
		Battery(string p_nameBat) : nameBat(p_nameBat) {}

		string to_string() {
			return nameBat;
		}

	private:
		double energy;
		double maxPower;
		string nameBat;
};

/*
List:
int maxSpeed

int powerComsume(int speed)
*/
class Locomotor {
	public:
		Locomotor(string p_nameLoc) : nameLoc(p_nameLoc) {}

		string to_string() {
			return nameLoc;
		}

	private:
		int maxSpeed;
		string nameLoc;
};

class RobotParts {
public:
	
	RobotParts(Torso p_t,
	Head p_h,
	Locomotor p_l,
	Arm p_a,
	Arm1 p_a2,
	Battery p_b) :



	torso(p_t),
	head(p_h),
	locomotor(p_l),
	arm(p_a),
	arm1(p_a2),
	battery(p_b){}

	RobotParts(): 
		torso("unknown"),
		head("unknown"),
		locomotor("unknown"),
		arm("unknown"),
		arm1("unknown"),
		battery("unknown"){}
	

	string to_string();

	string get_torso_name();
	string get_head_name();
	string get_arm_name();
	string get_arm1_name();
	string get_locomotor_name();
	string get_battery_name();

private:
	Torso torso;
	Head head;
	Locomotor locomotor;
	Arm arm;
	Arm1 arm1;
	Battery battery;
	/*
	string torso;
	string head;
	string locomotor;
	string arm;
	string battery;
	*/
	//Component component;
};

class Component {
public:
	void add_part(RobotParts rp);
	string parts_to_string(int index);

	void print_parts(int index);
	string get_torso_name(int index);
	string get_head_name(int index);
	string get_arm_name(int index);
	string get_arm1_name(int index);
	string get_locomotor_name(int index);
	string get_battery_name(int index);
private:
	vector<RobotParts> robotParts;
	//Torso torso;
	//Head head;
	//Locomotor locomotor;
	//Arm arm;
	//Battery battery;
};
#endif