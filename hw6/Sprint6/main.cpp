#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*
class RobotPart {
	public:
		RobotParts()
	protected:
		Fl_Window* RPwin;
		Fl_Input* rp_name;
		Fl_Input* rp_partnum;
		Fl_Input* rp_weight;
		Fl_
};
*/
void create_cb(Fl_Widget* create, void*) {
	Fl_Window* c = new Fl_Window(300, 550, "create");

	c->begin();
	Fl_Button* torso = new Fl_Button(50, 50, 200, 50, "Torso");
	Fl_Button* head = new Fl_Button(50, 150, 200, 50, "Head");
	Fl_Button* arm = new Fl_Button(50, 250, 200, 50, "Arm");
	Fl_Button* locomotor = new Fl_Button(50, 350, 200, 50, "Locomotor");
	Fl_Button* battery = new Fl_Button(50, 450, 200, 50, "Battery");
	//Fl_Input* in = new Fl_Input(50, 50, 100, 30, "asd");
	c->end();
	c->show();
}
	

int main() {

	Fl_Window win(600, 400, "Hw6");

	win.begin();
	Fl_Button create(50, 50, 50, 50, "Create");
	create.callback(create_cb);
	win.end();
	win.show();
	return (Fl::run());
}