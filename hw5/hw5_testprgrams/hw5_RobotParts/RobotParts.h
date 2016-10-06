#ifndef __ROBOTPARTS_H
#define __ROBOTPARTS_H 201609

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Connect to Robot Model
class RobotParts {
	public:
		RobotParts(Torso p_t,
					Head p_h,
					Locomotor p_l,
					vector<Arm> p_a,
					vector<Battery> p_b):
					
					torso(p_t),
					head(p_h),
					locomotor(p_l),
					arm(p_a),
					battery(p_b){}
		
		/*
		void createTorso(Torso t);
		void createHead(Head h);
		void createLocomotor(Locomotor l);
		void createArm(Arm a);
		void createBattery(Battery b);
	    */
	private:
		Torso torso;
		Head head;
		Locomotor locomotor;
		vector<Arm> arm;
		vector<Battery> battery;
};

class Torso {
	public:
		/*
		Torso(int p_batteryCompartments):

		batteryCompartments(p_batteryCompartments) {}
		*/
		Torso(string p_nameTorso): nameTorso(p_nameTorso){}
		
	private:
		//int batteryCompartments;
		string nameTorso;

		
};

class Head {
		public:
			Head(string p_nameHead): nameHead(p_nameHead){}
		private:
			string nameHead;
};

class Arm {
	public:
		Arm(string p_nameArm) : nameArm(p_nameArm) {}
	private:
		string nameArm;
};

class Battery {
	public:
		Battery(string p_nameBat) : nameBat(p_nameBat) {}
	private:
		string nameBat;
};

class Locomotor {
	public:
		Locomotor(string p_nameLoc) : nameLoc(p_nameLoc) {}
	private:
		string nameLoc;
};

#endif