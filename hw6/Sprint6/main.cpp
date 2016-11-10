#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



void  close_cb(Fl_Widget* w, void*){
	exit(0);
}

void createTorso_cb(Fl_Widget* create, void*){
	Fl_Window* cTorso = new Fl_Window(300, 550, "Create Torso");

	cTorso->begin();
	Fl_Input* nameTorso = new Fl_Input(50, 50, 200, 50, "Torso Name");
	Fl_Button* finTorso = new Fl_Button(50, 450, 200, 50, "Finish");
	finTorso->callback(close_cb);
	cTorso->end();
	cTorso->show();
}

void createHead_cb(Fl_Widget* create, void*){
	Fl_Window* cHead = new Fl_Window(300, 550, "Create Head");

	cHead->begin();
	Fl_Input* nameHead = new Fl_Input(50, 50, 200, 50, "Head Name");
	Fl_Button* finHead = new Fl_Button(50, 450, 200, 50, "Finish");
	finHead->callback(close_cb);
	cHead->end();
	cHead->show();
}

void createArm_cb(Fl_Widget* create, void*){
	Fl_Window* cArm = new Fl_Window(300, 550, "Create Arm");

	cArm->begin();
	Fl_Input* nameArm = new Fl_Input(50, 50, 200, 50, "Arm Name");
	Fl_Button* finArm = new Fl_Button(50, 450, 200, 50, "Finish");
	finArm->callback(close_cb);
	cArm->end();
	cArm->show();
}

void createLocomotor_cb(Fl_Widget* create, void*){
	Fl_Window* cLocomotor = new Fl_Window(300, 550, "Create Locomotor");

	cLocomotor->begin();
	Fl_Input* nameLocomotor = new Fl_Input(50, 50, 200, 50, "Locomotor Name");
	Fl_Button* finLocomotor = new Fl_Button(50, 450, 200, 50, "Finish");
	finLocomotor->callback(close_cb);
	cLocomotor->end();
	cLocomotor->show();
}

void createBattery_cb(Fl_Widget* create, void*){
	Fl_Window* cBattery = new Fl_Window(300, 550, "Create Battery");

	cBattery->begin();
	Fl_Input* nameBattery = new Fl_Input(50, 50, 200, 50, "Battery Name");
	Fl_Button* finBattery = new Fl_Button(50, 450, 200, 50, "Finish");
	finBattery->callback(close_cb);
	cBattery->end();
	cBattery->show();
}


void createRP_cb(Fl_Widget* create, void*) {
	Fl_Window* cRP = new Fl_Window(300, 550, "Create Robot Parts");

	cRP->begin();

	Fl_Button* torso = new Fl_Button(50, 50, 200, 50, "Torso");
	torso->callback(createTorso_cb);

	Fl_Button* head = new Fl_Button(50, 150, 200, 50, "Head");
	head->callback(createHead_cb);

	Fl_Button* arm = new Fl_Button(50, 250, 200, 50, "Arm");
	arm->callback(createArm_cb);

	Fl_Button* locomotor = new Fl_Button(50, 350, 200, 50, "Locomotor");
	locomotor->callback(createLocomotor_cb);

	Fl_Button* battery = new Fl_Button(50, 450, 200, 50, "Battery");
	battery->callback(createBattery_cb);
	
	cRP->end();
	cRP->show();
}

void createRM_cb(Fl_Widget* create, void*) {
	Fl_Window* cRM = new Fl_Window(300, 550, "Create Robot Model");

	cRM->begin();
	Fl_Input* modelName = new Fl_Input(50, 50, 200, 50, "Robot Model Name");
	Fl_Button* createParts = new Fl_Button(50, 150, 200, 50, "Create Parts");
	createParts->callback(createRP_cb);
	Fl_Return_Button* finish = new Fl_Return_Button(50, 250, 200, 50, "Finish");
	finish->callback(close_cb);
	cRM->end();
	cRM->show();
}


int main() {

	Fl_Window win(600, 400, "Hw6");

	win.begin();
	Fl_Button createRM(50, 50, 50, 50, "Create");
	createRM.callback(createRM_cb);
	win.end();
	win.show();
	return (Fl::run());
}
