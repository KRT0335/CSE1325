#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*
RobotPartDialog *robotPartsDialog;

class RobotPartDialog {
	public:
		RobotPartsDialog(){};

		RobotPartsDialog(
			Fl_Input p_torso,
			Fl_Input head,
			Fl_Input arm,
			Fl_Input locomotor,
			Fl_Input battery
			):

		{}


	private:
		Fl_Window *cRP;
		Fl_Input torso;
		Fl_Input head;
		Fl_Input arm;
		Fl_Input locomotor;
		Fl_Input battery;
		
};
*/

void  close_cb(Fl_Widget* w, void* windo){
	//Fl_Button  *but = (Fl_Button*)w;
	Fl_Window *win = (Fl_Window*)windo;
	delete win;
}

void createTorso_cb(Fl_Widget* create, void*){
	Fl_Window* cTorso = new Fl_Window(300, 550, "Create Torso");

	cTorso->begin();
	Fl_Input* nameTorso = new Fl_Input(50, 50, 200, 50, "Torso Name");
	Fl_Button* finTorso = new Fl_Button(50, 450, 200, 50, "Finish");
	finTorso->callback(close_cb, (void*)cTorso);
	cTorso->end();
	cTorso->show();
}

void createHead_cb(Fl_Widget* create, void*){
	Fl_Window* cHead = new Fl_Window(300, 550, "Create Head");
	
	cHead->begin();
	Fl_Input* nameHead = new Fl_Input(50, 50, 200, 50, "Head Name");
	Fl_Button* finHead = new Fl_Button(50, 450, 200, 50, "Finish");
	finHead->callback(close_cb, (void*)cHead);
	cHead->end();
	cHead->show();
}

void createArm_cb(Fl_Widget* create, void*){
	Fl_Window* cArm = new Fl_Window(300, 550, "Create Arm");

	cArm->begin();
	Fl_Input* nameArm = new Fl_Input(50, 50, 200, 50, "Arm Name");
	Fl_Button* finArm = new Fl_Button(50, 450, 200, 50, "Finish");
	finArm->callback(close_cb, (void*)cArm);
	cArm->end();
	cArm->show();
}

void createLocomotor_cb(Fl_Widget* create, void*){
	Fl_Window* cLocomotor = new Fl_Window(300, 550, "Create Locomotor");

	cLocomotor->begin();
	Fl_Input* nameLocomotor = new Fl_Input(50, 50, 200, 50, "Locomotor Name");
	Fl_Button* finLocomotor = new Fl_Button(50, 450, 200, 50, "Finish");
	finLocomotor->callback(close_cb, (void*)cLocomotor);
	cLocomotor->end();
	cLocomotor->show();
}

void createBattery_cb(Fl_Widget* create, void*){
	Fl_Window* cBattery = new Fl_Window(300, 550, "Create Battery");

	cBattery->begin();
	Fl_Input* nameBattery = new Fl_Input(50, 50, 200, 50, "Battery Name");
	Fl_Button* finBattery = new Fl_Button(50, 450, 200, 50, "Finish");
	finBattery->callback(close_cb, (void*)cBattery);
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

/* 
//Code used to test storing input later used ffor closing windows
//Wish I remember which forum helped me with this
#include <FL/Fl.H> 
#include <FL/Fl_Window.H> 
#include <FL/Fl_Input.H> 
#include <FL/Fl_Output.H> 

static void f_output(Fl_Widget *w, void *userdata)
{
	Fl_Input  *in = (Fl_Input*)w;                // get input widget from first argument 
	Fl_Output *out = (Fl_Output*)userdata;        // get output widget from userdata 
	out->value(in->value());                        // set value of output to value of input 
}

int main(int argc, char ** argv)
{
	Fl_Window *window;
	Fl_Input *input;
	Fl_Output *output;

	window = new Fl_Window(600, 400);
	input = new Fl_Input(100, 200, 260, 20, "Input:");
	output = new Fl_Output(100, 250, 260, 20, "Output:");

	// Set input's callback to invoke 'MyCallback' 
	// and pass a pointer to the output widget as 'userdata': 
	// 
	input->callback(f_output, (void*)output);
	//                 /|\            /|\                                 // 
	//                  |              |                                  // 
	//                  |              'user data' will be a pointer      // 
	//                  |              to the output widget               // 
	//                  |                                                 // 
	//                  The callback function (should not be a widget)    // 
	window->end();
	window->show(argc, argv);
	return(Fl::run());
}
*/
