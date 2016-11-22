#define _CRT_SECURE_NO_WARNINGS
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include<vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

class listCustomer;
class Customer;
class showRobotModel;
class RobotModel;
class robotHead;
class Head;
class robotTorso;
class Torso;
class robotArm;
class Arm;
class robotLocomotor;
class Locomotor;
class robotBattery;
class Battery;

listCustomer *lC;
Customer *customer;
showRobotModel *sRM;
RobotModel *RM;
robotHead *rH;
Head *head;
robotTorso *rT;
Torso *torso;
robotArm *rA;
Arm *arm;
robotLocomotor *rL;
Locomotor *locomotor;
robotBattery *rB;
Battery *battery;

Fl_Window *winCata = 0;
Fl_Hold_Browser *brCata = 0;
Fl_Window *winRP = 0;
Fl_Hold_Browser *brRP = 0;
Fl_Group *groupRP[5] = { 0, 0, 0, 0, 0 }; //For each part
Fl_Input *nameRM;

Fl_Input *nameHead;
Fl_Int_Input *numHead;
Fl_Float_Input *weightHead;
Fl_Float_Input *costHead;
Fl_Input *nameTorso;

Fl_Input *nameArm;

Fl_Input *nameLocomotor;

Fl_Input *nameBattery;

Fl_Input *nameHeadRM;
Fl_Input *nameTorsoRM;
Fl_Input *nameArmRM;
Fl_Input *nameLocomotorRM;
Fl_Input *nameBatteryRM;

Fl_Input *nameCustomer;
Fl_Window* custWin;

Fl_Window* rmWin;
Fl_Window* headWin;
Fl_Window* torsoWin;
Fl_Window* armWin;
Fl_Window* locomotorWin;
Fl_Window* batteryWin;

char* printCustomer = new char[1000];
char* printRM = new char[1000];
char* printHead = new char[1000];
char* printTorso = new char[1000];
char* printArm = new char[1000];
char* printLocomotor = new char[1000];
char* printBattery = new char[1000];
//static int select = 0;

void cata(Fl_Widget* w, void* p);
void addCustomer(Fl_Widget* w, void* p);
void addRM(Fl_Widget* w, void* p);
void addHead(Fl_Widget* w, void* p);
void addTorso(Fl_Widget* w, void* p);
void addArm(Fl_Widget* w, void* p);
void addLocomotor(Fl_Widget* w, void* p);
void addBattery(Fl_Widget* w, void* p);

void  close_cb(Fl_Widget* w, void* windo) {
	Fl_Window *win = (Fl_Window*)windo;
	delete win;
}

void  bro(Fl_Widget* w, void* windo) {
	winRP = new Fl_Window(600, 600, "Robot Parts");

	winRP->begin();
	brRP = new Fl_Hold_Browser(50, 50, 100, 300);

	brRP->add("Head");

	brRP->add("Torso");
	brRP->add("Arm");
	brRP->add("Locomotor");
	brRP->add("Batteries");

	if (brRP->selected(0)) {
		groupRP[0] = new Fl_Group(150, 50, 400, 400, "Head");
		groupRP[0]->box(FL_ENGRAVED_BOX);
		groupRP[0]->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP);
		groupRP[0]->labelsize(24);
		nameHead = new Fl_Input(250, 80, 200, 20, "Head Name:");
		numHead = new Fl_Int_Input(250, 110, 200, 20, "Part Number:");

		groupRP[0]->end();
		groupRP[0]->show();
		winRP->redraw();
	}

	if (brRP->selected(1)) {
		groupRP[1] = new Fl_Group(150, 50, 400, 400, "Torso");
		groupRP[1]->box(FL_ENGRAVED_BOX);
		groupRP[1]->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP);
		groupRP[1]->labelsize(24);
		nameHead = new Fl_Input(250, 80, 200, 20, "Torso Name:");
		numHead = new Fl_Int_Input(250, 110, 200, 20, "Part Number:");

		groupRP[1]->end();
	}
	winRP->redraw();
	winRP->end();
	winRP->show();
}

void store(Fl_Widget* w, void* p) {


	char* res = new char[1000];

	Fl_Window *win = new Fl_Window(650, 480);       // create new win for display
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();    // make a buffer to display text
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");   // display box
	disp->buffer(buff);     // set buffer
							//win->resizable(*disp);  // make window resizable
	win->show();            //show window

	strcpy(res, "");
	strcat(res, nameHead->value());
	buff->text(res);

}




void createHead_cb(Fl_Widget* create, void* p) {
	Fl_Window* cHead = new Fl_Window(300, 550, "Create Head");

	cHead->begin();
	nameHead = new Fl_Input(50, 50, 200, 50, "Head Name");
	Fl_Button* finHead = new Fl_Button(50, 450, 200, 50, "Finish");
	finHead->callback(store);
	//finHead->callback(close_cb, (void*)cHead);
	cHead->end();
	cHead->show();
}







/*-------------------------------------/
----------------Customer---------------/
---------------------------------------*/

class Customer {
public:
	Customer() {};
	Customer(char* pnameC) : nameC(pnameC) {}
	//Customer(char* pnameC, vector<RobotModel>rm) : nameC(pnameC) {}

	char* get_nameC() { return nameC; }
private:
	char* nameC = new char[100];
};

class listCustomer {
public:
	listCustomer() {


		custWin = new Fl_Window(300, 400, "Customer Info");

		nameCustomer = new Fl_Input(50, 10, 250, 20, "Name:");


		createCustomer = new Fl_Button(120, 320, 120, 30, "Add");
		createCustomer->callback((Fl_Callback*)addCustomer);


		custWin->end();
		custWin->set_non_modal();
	}

	void showC() { custWin->show(); }
	void hideC() { custWin->hide(); }
	char* nameCustomerName() { return (char*)nameCustomer->value(); }
	int size() { return customer.size(); }

	char* nameCustomerVec(int i) { return customer[i].get_nameC(); }


	void get_customer(Customer c) {
		customer.push_back(c);
	}



private:
	Fl_Button* createCustomer;
	vector<Customer> customer;
};




/*-------------------------------------/
----------------Robot Model------------/
---------------------------------------*/
class RobotModel {
public:
	RobotModel() {}

	RobotModel(char* pnameRM, char* pnameHRM, char* pnameTRM, char* pnameARM, char* pnameLRM, char* pnameBRM) :
		nameRM(pnameRM), nameHRM(pnameHRM), nameTRM(pnameTRM), nameARM(pnameARM), nameLRM(pnameLRM), nameBRM(pnameBRM) {}

	/*
	RobotModel():
	nameRM("None"),
	nameH("None"),
	nameT("None"),
	nameA("None"),
	nameL("None"),
	nameB("None"){}
	*/

	char* get_nameRM() { return nameRM; }
	char* get_nameHRM() { return nameHRM; }
	char* get_nameTRM() { return nameTRM; }
	char* get_nameARM() { return nameARM; }
	char* get_nameLRM() { return nameLRM; }
	char* get_nameBRM() { return nameBRM; }

private:
	char* nameRM = new char[100];
	char* nameHRM = new char[100];
	char* nameTRM = new char[100];
	char* nameARM = new char[100];
	char* nameLRM = new char[100];
	char* nameBRM = new char[100];
};

class showRobotModel {
public:
	showRobotModel() {
		rmWin = new Fl_Window(500, 400, "RobotModel Info");

		nameRM = new Fl_Input(150, 10, 300, 20, "RobotModel Name:");
		nameHeadRM = new Fl_Input(150, 40, 300, 20, "Head Name:");
		nameTorsoRM = new Fl_Input(150, 70, 300, 20, "Torso Name:");
		nameArmRM = new Fl_Input(150, 100, 300, 20, "Arm Name:");
		nameLocomotorRM = new Fl_Input(150, 130, 300, 20, "Locomotor Name:");
		nameBatteryRM = new Fl_Input(150, 160, 300, 20, "Battery Name:");

		createRM = new Fl_Button(120, 320, 120, 30, "Create");
		createRM->callback((Fl_Callback*)addRM);


		rmWin->end();
		rmWin->set_non_modal();
	}

	void showRM() { rmWin->show(); }
	void hideRM() { rmWin->hide(); }

	char* nameRMName() { return (char*)nameRM->value(); }
	char* nameHeadNameRM() { return (char*)nameHeadRM->value(); }
	char* nameTorsoNameRM() { return (char*)nameTorsoRM->value(); }
	char* nameArmNameRM() { return (char*)nameArmRM->value(); }
	char* nameLocomotorNameRM() { return (char*)nameLocomotorRM->value(); }
	char* nameBatteryNameRM() { return (char*)nameBatteryRM->value(); }

	int size() { return RM.size(); }

	char* nameRMVec(int i) { return RM[i].get_nameRM(); }
	char* nameHeadVecRM(int i) { return RM[i].get_nameHRM(); }
	char* nameTorsoVecRM(int i) { return RM[i].get_nameTRM(); }
	char* nameArmVecRM(int i) { return RM[i].get_nameARM(); }
	char* nameLocomotorVecRM(int i) { return RM[i].get_nameLRM(); }
	char* nameBatteryVecRM(int i) { return RM[i].get_nameBRM(); }


	void get_rm(RobotModel rm) {
		RM.push_back(rm);
	}



private:
	Fl_Button* createRM;
	vector<Head> head;
	vector<Torso> torso;
	vector<Arm> arm;
	vector<Locomotor> locomotor;
	vector<Battery> battery;
	vector<RobotModel> RM;
};


/*-----------------Robot Parts Classes and Derived---------------*/
class Head {
public:
	Head() {};
	Head(char* pnameH) : nameH(pnameH) {}

	char* get_nameH() { return nameH; }
private:
	char* nameH = new char[100];
};

class Torso {
public:
	Torso() {};
	Torso(char* pnameT) : nameT(pnameT) {}

	char* get_nameT() { return nameT; }
private:
	char* nameT = new char[100];
};

class Arm {
public:
	Arm() {};
	Arm(char* pnameA) : nameA(pnameA) {}

	char* get_nameA() { return nameA; }
private:
	char* nameA = new char[100];
};

class Locomotor {
public:
	Locomotor() {};
	Locomotor(char* pnameL) : nameL(pnameL) {}

	char* get_nameL() { return nameL; }
private:
	char* nameL = new char[100];
};

class Battery {
public:
	Battery() {};
	Battery(char* pnameB) : nameB(pnameB) {}

	char* get_nameB() { return nameB; }
private:
	char* nameB = new char[100];
};

class robotHead {
public:
	robotHead() {


		headWin = new Fl_Window(300, 400, "Head Info");

		nameHead = new Fl_Input(50, 10, 250, 20, "Name:");


		createHead = new Fl_Button(120, 320, 120, 30, "Create");
		createHead->callback((Fl_Callback*)addHead);


		headWin->end();
		headWin->set_non_modal();
	}

	void showH() { headWin->show(); }
	void hideH() { headWin->hide(); }
	char* nameHeadName() { return (char*)nameHead->value(); }
	int size() { return head.size(); }

	char* nameHeadVec(int i) { return head[i].get_nameH(); }


	void get_head(Head h) {
		head.push_back(h);
	}



private:
	Fl_Button* createHead;
	vector<Head> head;
};

class robotTorso {
public:
	robotTorso() {


		torsoWin = new Fl_Window(300, 400, "Torso Info");

		nameTorso = new Fl_Input(50, 10, 250, 20, "Name:");


		createTorso = new Fl_Button(120, 320, 120, 30, "Create");
		createTorso->callback((Fl_Callback*)addTorso);


		torsoWin->end();
		torsoWin->set_non_modal();
	}

	void showT() { torsoWin->show(); }
	void hideT() { torsoWin->hide(); }
	char* nameTorsoName() { return (char*)nameTorso->value(); }
	int size() { return torso.size(); }

	char* nameTorsoVec(int i) { return torso[i].get_nameT(); }


	void get_torso(Torso t) {
		torso.push_back(t);
	}



private:
	Fl_Button* createTorso;
	vector<Torso> torso;
};

class robotArm {
public:
	robotArm() {


		armWin = new Fl_Window(300, 400, "Arm Info");

		nameArm = new Fl_Input(50, 10, 250, 20, "Name:");


		createArm = new Fl_Button(120, 320, 120, 30, "Create");
		createArm->callback((Fl_Callback*)addArm);


		armWin->end();
		armWin->set_non_modal();
	}

	void showA() { armWin->show(); }
	void hideA() { armWin->hide(); }
	char* nameArmName() { return (char*)nameArm->value(); }
	int size() { return arm.size(); }

	char* nameArmVec(int i) { return arm[i].get_nameA(); }


	void get_arm(Arm a) {
		arm.push_back(a);
	}



private:
	Fl_Button* createArm;
	vector<Arm> arm;
};

class robotLocomotor {
public:
	robotLocomotor() {


		locomotorWin = new Fl_Window(300, 400, "Locomotor Info");

		nameLocomotor = new Fl_Input(50, 10, 250, 20, "Name:");


		createLocomotor = new Fl_Button(120, 320, 120, 30, "Create");
		createLocomotor->callback((Fl_Callback*)addLocomotor);


		locomotorWin->end();
		locomotorWin->set_non_modal();
	}

	void showL() { locomotorWin->show(); }
	void hideL() { locomotorWin->hide(); }
	char* nameLocomotorName() { return (char*)nameLocomotor->value(); }
	int size() { return locomotor.size(); }

	char* nameLocomotorVec(int i) { return locomotor[i].get_nameL(); }


	void get_locomotor(Locomotor l) {
		locomotor.push_back(l);
	}



private:
	Fl_Button* createLocomotor;
	vector<Locomotor> locomotor;
};

class robotBattery {
public:
	robotBattery() {


		batteryWin = new Fl_Window(300, 400, "Battery Info");

		nameBattery = new Fl_Input(50, 10, 250, 20, "Name:");


		createBattery = new Fl_Button(120, 320, 120, 30, "Create");
		createBattery->callback((Fl_Callback*)addBattery);


		batteryWin->end();
		batteryWin->set_non_modal();
	}

	void showB() { batteryWin->show(); }
	void hideB() { batteryWin->hide(); }
	char* nameBatteryName() { return (char*)nameBattery->value(); }
	int size() { return battery.size(); }

	char* nameBatteryVec(int i) { return battery[i].get_nameB(); }


	void get_battery(Battery b) {
		battery.push_back(b);
	}



private:
	Fl_Button* createBattery;
	vector<Battery> battery;
};


/*-------------------------------------/
----------------CALLBACKS---------------/
---------------------------------------*/


void viewCatacb(Fl_Widget* w, void* p) {
	Fl_Hold_Browser *brCata2 = (Fl_Hold_Browser*)p;

	strcpy(printRM, "");

	int i = brCata2->value();
	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();

	strcat(printRM, sRM->nameRMVec(i-1));
	strcat(printRM, "\n");
	strcat(printRM, sRM->nameHeadVecRM(i - 1));
	strcat(printRM, "\n");
	strcat(printRM, sRM->nameTorsoVecRM(i - 1));
	strcat(printRM, "\n");
	strcat(printRM, sRM->nameArmVecRM(i - 1));
	strcat(printRM, "\n");
	strcat(printRM, sRM->nameLocomotorVecRM(i - 1));
	strcat(printRM, "\n");
	strcat(printRM, sRM->nameBatteryVecRM(i - 1));
	strcat(printRM, "\n\n");

	buff->text(printRM);


}

void cata(Fl_Widget* w, void* p) {
	winCata = new Fl_Window(600, 600, "Catalog");

	winCata->begin();
	brCata = new Fl_Hold_Browser(50, 50, 100, 500);

	int i;
	for (i = 0; i < sRM->size(); i++) {
		brCata->add(sRM->nameRMVec(i));
	}

	Fl_Button *viewButton = new Fl_Button(450, 500, 100, 50, "View");

	viewButton->callback((Fl_Callback*)viewCatacb, (void*)brCata);

	winCata->end();
	winCata->show();
}

void addCustomer(Fl_Widget* w, void* p) {

	char* resC = new char[1000];
	strcpy(resC, "");
	strcat(resC, nameCustomer->value());

	Customer insertCustomer(resC);
	lC->get_customer(insertCustomer);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < lC->size(); i++) {
		strcat(printCustomer, lC->nameCustomerVec(i));
		strcat(printCustomer, "\n");
	}
	buff->text(printCustomer);

	nameCustomer->value("");
	lC->hideC();
}

void addRM(Fl_Widget* w, void* p) {

	char* resRM = new char[1000];
	strcpy(resRM, "");
	strcat(resRM, nameRM->value());
	string sresRM = resRM;

	if (sresRM.length() < 1)
		strcpy(resRM, "Not Named");


	char* resH = new char[1000];

	strcpy(resH, "");
	strcat(resH, nameHeadRM->value());

	char* resT = new char[1000];
	strcpy(resT, "");
	strcat(resT, nameTorsoRM->value());

	char* resA = new char[1000];
	strcpy(resA, "");
	strcat(resA, nameArmRM->value());

	char* resL = new char[1000];
	strcpy(resL, "");
	strcat(resL, nameLocomotorRM->value());

	char* resB = new char[1000];
	strcpy(resB, "");
	strcat(resB, nameBatteryRM->value());


	RobotModel insertRM(resRM, resH, resT, resA, resL, resB);
	sRM->get_rm(insertRM);
	Head insertHead(resH);
	rH->get_head(insertHead);
	Torso insertTorso(resT);
	rT->get_torso(insertTorso);
	Arm insertArm(resA);
	rA->get_arm(insertArm);
	Locomotor insertLocomotor(resL);
	rL->get_locomotor(insertLocomotor);
	Battery insertBattery(resB);
	rB->get_battery(insertBattery);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < sRM->size(); i++) {
		strcat(printRM, sRM->nameRMVec(i));
		strcat(printRM, "\n");
		strcat(printRM, sRM->nameHeadVecRM(i));
		strcat(printRM, "\n");
		strcat(printRM, sRM->nameTorsoVecRM(i));
		strcat(printRM, "\n");
		strcat(printRM, sRM->nameArmVecRM(i));
		strcat(printRM, "\n");
		strcat(printRM, sRM->nameLocomotorVecRM(i));
		strcat(printRM, "\n");
		strcat(printRM, sRM->nameBatteryVecRM(i));
		strcat(printRM, "\n\n");
	}
	buff->text(printRM);

	nameRM->value("");
	nameHeadRM->value("");
	nameTorsoRM->value("");
	nameArmRM->value("");
	nameLocomotorRM->value("");
	nameBatteryRM->value("");
	sRM->hideRM();
}

void addHead(Fl_Widget* w, void* p) {

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameHead->value());

	Head insertHead(res);
	rH->get_head(insertHead);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rH->size(); i++) {
		strcat(printHead, rH->nameHeadVec(i));
		strcat(printHead, "\n");
	}
	buff->text(printHead);

	nameHead->value("");
	rH->hideH();
}

void addTorso(Fl_Widget* w, void* p) {

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameTorso->value());

	Torso insertTorso(res);
	rT->get_torso(insertTorso);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rT->size(); i++) {
		strcat(printTorso, rT->nameTorsoVec(i));
		strcat(printTorso, "\n");
	}
	buff->text(printTorso);

	nameTorso->value("");
	rT->hideT();
}

void addArm(Fl_Widget* w, void* p) {

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameArm->value());

	Arm insertArm(res);
	rA->get_arm(insertArm);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rA->size(); i++) {
		strcat(printArm, rA->nameArmVec(i));
		strcat(printArm, "\n");
	}
	buff->text(printArm);

	nameArm->value("");
	rA->hideA();
}

void addLocomotor(Fl_Widget* w, void* p) {

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameLocomotor->value());

	Locomotor insertLocomotor(res);
	rL->get_locomotor(insertLocomotor);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rL->size(); i++) {
		strcat(printLocomotor, rL->nameLocomotorVec(i));
		strcat(printLocomotor, "\n");
	}
	buff->text(printLocomotor);

	nameLocomotor->value("");
	rL->hideL();
}

void addBattery(Fl_Widget* w, void* p) {

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameBattery->value());

	Battery insertBattery(res);
	rB->get_battery(insertBattery);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rB->size(); i++) {
		strcat(printBattery, rB->nameBatteryVec(i));
		strcat(printBattery, "\n");
	}
	buff->text(printBattery);

	nameBattery->value("");
	rB->hideB();
}

void showCustomer(Fl_Widget* w, void* p) {
	strcpy(printCustomer, "");
	lC->showC();
}

void showRM(Fl_Widget* w, void* p) {
	strcpy(printRM, "");
	sRM->showRM();
}

void showHead(Fl_Widget* w, void* p) {
	strcpy(printHead, "");
	rH->showH();
}

void showTorso(Fl_Widget* w, void* p) {
	strcpy(printTorso, "");
	rT->showT();
}

void showArm(Fl_Widget* w, void* p) {
	strcpy(printArm, "");
	rA->showA();
}

void showLocomotor(Fl_Widget* w, void* p) {
	strcpy(printLocomotor, "");
	rL->showL();
}

void showBattery(Fl_Widget* w, void* p) {
	strcpy(printBattery, "");
	rB->showB();
}

void createRP_cb(Fl_Widget* create, void* p) {



	Fl_Window* cRP = new Fl_Window(300, 650, "Create Robot Parts");

	cRP->begin();

	//Fl_Output* outt = new Fl_Output(50, 550, 200, 50, "out");


	Fl_Button* headb = new Fl_Button(50, 150, 200, 50, "Head");
	headb->callback(showHead);

	Fl_Button* torsob = new Fl_Button(50, 50, 200, 50, "Torso");
	torsob->callback(showTorso);

	Fl_Button* armb = new Fl_Button(50, 250, 200, 50, "Arm");
	armb->callback(showArm);

	Fl_Button* locomotorb = new Fl_Button(50, 350, 200, 50, "Locomotor");
	locomotorb->callback(showLocomotor);

	Fl_Button* batteryb = new Fl_Button(50, 450, 200, 50, "Battery");
	batteryb->callback(showBattery);

	//outt->value("");


	cRP->end();
	cRP->show();
}

int main() {
	lC = new listCustomer();
	sRM = new showRobotModel();
	rH = new robotHead();
	rT = new robotTorso();
	rA = new robotArm();
	rL = new robotLocomotor();
	rB = new robotBattery();
	strcpy(printRM, "");
	strcpy(printHead, "");
	strcpy(printTorso, "");
	strcpy(printArm, "");
	strcpy(printLocomotor, "");
	strcpy(printBattery, "");

	Fl_Window win(600, 400, "Hw6");

	win.begin();

	Fl_Button createRP(50, 50, 150, 50, "Create Parts");
	Fl_Button createD(50, 150, 150, 50, "Catalog");
	Fl_Button createH(250, 50, 150, 50, "Create Head");
	Fl_Button createRM(250, 150, 150, 50, "Create Model");
	Fl_Button createC(50, 250, 150, 50, "Add Customer");
	//createRM.callback(createHead_cb);
	createRP.callback(createRP_cb);
	createD.callback(cata);
	createH.callback(showHead);
	createRM.callback(showRM);
	createC.callback(showCustomer);
	win.end();
	win.show();
	return (Fl::run());
}
