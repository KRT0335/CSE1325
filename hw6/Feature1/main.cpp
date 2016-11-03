#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void makeOrder_cb(Fl_Widget*, void*);
void placeOrder_cb(Fl_Widget*, void*);
void close_cb(Fl_Widget*, void*);
void make_window();


int main() {

	make_window();
	return Fl::run();
}


void make_window() {

	Fl_Window* win = new Fl_Window(300, 200, "HW6_GUI1");
	win->begin();
	Fl_Button*  makeOrder = new Fl_Button(10, 10, 70, 30, "&Order");
	Fl_Button* quit = new Fl_Button(100, 10, 70, 30, "&Quit"); 
	//Fl_Input*       inp = new Fl_Input(50, 50, 140, 30, "In");
	//Fl_Output*    out = new Fl_Output(50, 100, 140, 30, "Out"); 
	win->end();
	makeOrder->callback(makeOrder_cb);
	quit->callback(close_cb);
	win->show();
}


void makeOrder_cb(Fl_Widget* makeOrder, void*) {
	string instr = "Test";
	Fl_Button* b = (Fl_Button*)makeOrder;
	Fl_Window* ord = new Fl_Window(300, 200, "Make Order");
	ord->begin();
	Fl_Button*  placeOrder = new Fl_Button(10, 10, 70, 30, "&Place Order");
	Fl_Input*       inp = new Fl_Input(50, 50, 140, 30, "In");
	Fl_Output*    out = new Fl_Output(50, 100, 140, 30, "Out");
	ord->end();
	placeOrder->callback(placeOrder_cb);
	//instr = inp->value();
	
	//out.value(instr);
	//out->value(inp->value());
	ord->show();
	//Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	//Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	//ow->value(iw->value());
}

void placeOrder_cb(Fl_Widget* placeOrder, void*){
	Fl_Button* b = (Fl_Button*)placeOrder;
	Fl_Input* iw = (Fl_Input*)b->parent()->child(1);
	Fl_Output* ow = (Fl_Output*)b->parent()->child(2);
	ow->value(iw->value());
}


void close_cb(Fl_Widget* quit, void*) {

	exit(0);
}