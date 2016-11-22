/*
Kevin Tiller
11/22/2016
1001110335
CSE 1325 - 003
*/


#define _CRT_SECURE_NO_WARNINGS
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
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
#include <FL/Fl_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include<vector>
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

class listOrders;
class Orders;
class listSalesAs;
class SalesAs;
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

listOrders *lOrd;
Orders *orders;
listSalesAs *lSA;
SalesAs *SA;
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

Fl_Input *nameHead;
Fl_Int_Input *numHead;
Fl_Float_Input *weightHead;
Fl_Float_Input *costHead;
Fl_Input *nameTorso;

Fl_Input *nameArm;

Fl_Input *nameLocomotor;

Fl_Input *nameBattery;

Fl_Input *nameRM;
Fl_Input *nameHeadRM;
Fl_Input *nameTorsoRM;
Fl_Input *nameArmRM;
Fl_Input *nameLocomotorRM;
Fl_Input *nameBatteryRM;
Fl_Float_Input *totalWeightRM;
Fl_Float_Input *totalCostRM;


Fl_Input *nameCustomer;
Fl_Window* custWin;

Fl_Input *nameSalesAs;
Fl_Input *empnumSalesAs;
Fl_Window* saWin;

Fl_Input *nameOrders;
Fl_Window *ordWin;

Fl_Window* rmWin;
Fl_Window* headWin;
Fl_Window* torsoWin;
Fl_Window* armWin;
Fl_Window* locomotorWin;
Fl_Window* batteryWin;

Fl_Window* pWin;
Fl_Window* cWin;
Fl_Hold_Browser *brCust = 0;
Fl_Hold_Browser *brSA = 0;

Fl_Box* picbox;
Fl_JPEG_Image * picimage;

static int brIndexRM;
static int brIndexSA;
static int brIndexC;

char* printOrders = new char[1000];
char* printSalesAs = new char[1000];
char* printCustomer = new char[1000];
char* printRM = new char[1000];
char* printHead = new char[1000];
char* printTorso = new char[1000];
char* printArm = new char[1000];
char* printLocomotor = new char[1000];
char* printBattery = new char[1000];

void viewcb(Fl_Widget* w, void* p);
void cata(Fl_Widget* w, void* p); 
void addSalesAs(Fl_Widget* w, void* p);
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

void store(Fl_Widget* w, void* p){


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










/*-------------------------------------/
----------------Orders-----------------/
---------------------------------------*/

class Orders{
public:
	Orders(){};
	Orders(
		char* pnameSAO, 
		char* pnameSAenO, 
		char* pnameCustO, 
		char* pnameRMO, 
		char* pnameHO, 
		char* pnameTO, 
		char* pnameAO, 
		char* pnameLO, 
		char* pnameBO, 
		double pnameWO, 
		double pnameCO ) : 
		
		nameSAO(pnameSAO),
		nameSAenO(pnameSAenO),
		nameCustO(pnameCustO),
		nameRMO(pnameRMO),
		nameHO(pnameHO),
		nameTO(pnameTO),
		nameAO(pnameAO),
		nameLO(pnameLO),
		nameBO(pnameBO),
		nameWO(pnameWO),
		nameCO(pnameCO) {}

	char* get_nameSAO(){ return nameSAO; }
	char* get_nameSAenO(){ return nameSAenO; }
	char* get_nameCustO(){ return nameCustO; }
	char* get_nameRMO(){ return nameRMO; }
	char* get_nameHO(){ return nameHO; }
	char* get_nameTO(){ return nameTO; }
	char* get_nameAO(){ return nameAO; }
	char* get_nameLO(){ return nameLO; }
	char* get_nameBO(){ return nameBO; }
	double get_nameWO(){ return nameWO; }
	double get_nameCO(){ return nameCO; }

private:
	char* nameSAO = new char[100];
	char* nameSAenO = new char[100];
	char* nameCustO = new char[100];
	char* nameRMO = new char[100];
	char* nameHO = new char[100];
	char* nameTO = new char[100];
	char* nameAO = new char[100];
	char* nameLO = new char[100];
	char* nameBO = new char[100];
	double nameWO;
	double nameCO;
};

class listOrders{
public:
	/*listOrders(){


		ordWin = new Fl_Window(300, 400, "Customer Info");

		nameOrders = new Fl_Input(50, 10, 250, 20, "Name:");


		createOrders = new Fl_Button(120, 320, 120, 30, "Add");
		createOrders->callback((Fl_Callback*)addOrders);


		ordWin->end();
		ordWin->set_non_modal();
	}
	*/
	void showO(){ ordWin->show(); }
	void hideO(){ ordWin->hide(); }
	char* nameOrdersName(){ return (char*)nameOrders->value(); }
	int size(){ return orders.size(); }

	char* nameSAOrdersVec(int i){ return orders[i].get_nameSAO(); }
	char* nameSAenOrdersVec(int i){ return orders[i].get_nameSAenO(); }
	char* nameCustOrdersVec(int i){ return orders[i].get_nameCustO(); }
	char* nameRMOrdersVec(int i){ return orders[i].get_nameRMO(); }
	char* nameHOrdersVec(int i){ return orders[i].get_nameHO(); }
	char* nameTOrdersVec(int i){ return orders[i].get_nameTO(); }
	char* nameAOrdersVec(int i){ return orders[i].get_nameAO(); }
	char* nameLOrdersVec(int i){ return orders[i].get_nameLO(); }
	char* nameBOrdersVec(int i){ return orders[i].get_nameBO(); }
	double nameWOrdersVec(int i){ return orders[i].get_nameWO(); }
	double nameCOrdersVec(int i){ return orders[i].get_nameCO(); }


	void get_orders(Orders o){
		orders.push_back(o);
	}



private:
	Fl_Button* createOrders;
	vector<Orders> orders;
};




/*--------------------------------------------/
----------------Sales Associate---------------/
---------------------------------------------*/

class SalesAs{
public:
	SalesAs(){};
	SalesAs(char* pnameSA, char* pempnum) : nameSA(pnameSA), empnum(pempnum){}

	char* get_nameSA(){ return nameSA; }
	char* get_empnum(){ return empnum; }
private:
	char* nameSA = new char[100];
	char* empnum = new char[100];
};

class listSalesAs{
public:
	listSalesAs(){


		saWin = new Fl_Window(400, 300, "Sales Associate Info");

		nameSalesAs = new Fl_Input(130, 10, 250, 20, "Name:");
		empnumSalesAs = new Fl_Input(130, 40, 250, 20, "Employee Number:");

		createSalesAs = new Fl_Button(120, 220, 120, 30, "Add");
		createSalesAs->callback((Fl_Callback*)addSalesAs);


		saWin->end();
		saWin->set_non_modal();
	}

	void showSA(){ saWin->show(); }
	void hideSA(){ saWin->hide(); }
	char* nameSalesAsName(){ return (char*)nameSalesAs->value(); }
	char* empnumSalesAsName(){ return (char*)empnumSalesAs->value(); }
	int size(){ return SA.size(); }

	char* nameSalesAsVec(int i){ return SA[i].get_nameSA(); }
	char* empnumSalesAsVec(int i){ return SA[i].get_empnum(); }

	void get_SA(SalesAs sa){
		SA.push_back(sa);
	}



private:
	Fl_Button* createSalesAs;
	vector<SalesAs> SA;
};





/*-------------------------------------/
----------------Customer---------------/
---------------------------------------*/

class Customer{
public:
	Customer(){};
	Customer(char* pnameC) : nameC(pnameC){}

	char* get_nameC(){ return nameC; }
private:
	char* nameC = new char[100];
};

class listCustomer{
public:
	listCustomer(){


		custWin = new Fl_Window(300, 400, "Customer Info");

		nameCustomer = new Fl_Input(50, 10, 250, 20, "Name:");


		createCustomer = new Fl_Button(120, 320, 120, 30, "Add");
		createCustomer->callback((Fl_Callback*)addCustomer);


		custWin->end();
		custWin->set_non_modal();
	}

	void showC(){ custWin->show(); }
	void hideC(){ custWin->hide(); }
	char* nameCustomerName(){ return (char*)nameCustomer->value(); }
	int size(){ return customer.size(); }

	char* nameCustomerVec(int i){ return customer[i].get_nameC(); }


	void get_customer(Customer c){
		customer.push_back(c);
	}



private:
	Fl_Button* createCustomer;
	vector<Customer> customer;
};




/*-------------------------------------/
----------------Robot Model------------/
---------------------------------------*/
class RobotModel{
public:
	RobotModel(){}

	RobotModel(char* pnameRM, char* pnameHRM, char* pnameTRM, char* pnameARM, char* pnameLRM, char* pnameBRM, double pweightRM, double pcostRM) :
		nameRM(pnameRM), nameHRM(pnameHRM), nameTRM(pnameTRM), nameARM(pnameARM), nameLRM(pnameLRM), nameBRM(pnameBRM), weightRM(pweightRM), costRM(pcostRM) {}


	char* get_nameRM(){ return nameRM; }
	char* get_nameHRM(){ return nameHRM; }
	char* get_nameTRM(){ return nameTRM; }
	char* get_nameARM(){ return nameARM; }
	char* get_nameLRM(){ return nameLRM; }
	char* get_nameBRM(){ return nameBRM; }
	double get_weightRM(){ return weightRM; }
	double get_costRM(){ return costRM; }

private:
	char* nameRM = new char[100];
	char* nameHRM = new char[100];
	char* nameTRM = new char[100];
	char* nameARM = new char[100];
	char* nameLRM = new char[100];
	char* nameBRM = new char[100];
	double weightRM, costRM;
};

class showRobotModel{
public:
	showRobotModel(){
		rmWin = new Fl_Window(500, 400, "RobotModel Info");

		nameRM = new Fl_Input(150, 10, 200, 20, "RobotModel Name:");
		nameHeadRM = new Fl_Input(150, 40, 200, 20, "Head Name:");
		nameTorsoRM = new Fl_Input(150, 70, 200, 20, "Torso Name:");
		nameArmRM = new Fl_Input(150, 100, 200, 20, "Arm Name:");
		nameLocomotorRM = new Fl_Input(150, 130, 200, 20, "Locomotor Name:");
		nameBatteryRM = new Fl_Input(150, 160, 200, 20, "Battery Name:");
		totalWeightRM = new Fl_Float_Input(150, 190, 200, 20, "Total Weight:");
		totalCostRM = new Fl_Float_Input(150, 220, 200, 20, "Total Cost:$");

		createRM = new Fl_Button(120, 320, 120, 30, "Create");
		createRM->callback((Fl_Callback*)addRM);


		rmWin->end();
		rmWin->set_non_modal();
	}

	void showRM(){ rmWin->show(); }
	void hideRM(){ rmWin->hide(); }

	char* nameRMName(){ return (char*)nameRM->value(); }
	char* nameHeadNameRM(){ return (char*)nameHeadRM->value(); }
	char* nameTorsoNameRM(){ return (char*)nameTorsoRM->value(); }
	char* nameArmNameRM(){ return (char*)nameArmRM->value(); }
	char* nameLocomotorNameRM(){ return (char*)nameLocomotorRM->value(); }
	char* nameBatteryNameRM(){ return (char*)nameBatteryRM->value(); }
	//double getTotalWeightRM(){ return (double)totalWeightRM->value(); }

	int size(){ return RM.size(); }

	char* nameRMVec(int i)				{ return RM[i].get_nameRM(); }
	char* nameHeadVecRM(int i)			{ return RM[i].get_nameHRM(); }
	char* nameTorsoVecRM(int i)			{ return RM[i].get_nameTRM(); }
	char* nameArmVecRM(int i)			{ return RM[i].get_nameARM(); }
	char* nameLocomotorVecRM(int i)		{ return RM[i].get_nameLRM(); }
	char* nameBatteryVecRM(int i)		{ return RM[i].get_nameBRM(); }
	double totalWeightVecRM(int i)		{ return RM[i].get_weightRM(); }
	double totalCostVecRM(int i)		{ return RM[i].get_costRM(); }


	void get_rm(RobotModel rm){
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
class Head{
public:
	Head(){};
	Head(char* pnameH) : nameH(pnameH){}

	char* get_nameH(){ return nameH; }
private:
	char* nameH = new char[100];
};

class Torso{
public:
	Torso(){};
	Torso(char* pnameT) : nameT(pnameT){}

	char* get_nameT(){ return nameT; }
private:
	char* nameT = new char[100];
};

class Arm{
public:
	Arm(){};
	Arm(char* pnameA) : nameA(pnameA){}

	char* get_nameA(){ return nameA; }
private:
	char* nameA = new char[100];
};

class Locomotor{
public:
	Locomotor(){};
	Locomotor(char* pnameL) : nameL(pnameL){}

	char* get_nameL(){ return nameL; }
private:
	char* nameL = new char[100];
};

class Battery{
public:
	Battery(){};
	Battery(char* pnameB) : nameB(pnameB){}

	char* get_nameB(){ return nameB; }
private:
	char* nameB = new char[100];
};

class robotHead{
public:
	robotHead(){
		

		headWin = new Fl_Window(300, 400, "Head Info");

		nameHead = new Fl_Input(50, 10, 250, 20, "Name:");


		createHead = new Fl_Button(120, 320, 120, 30, "Create");
		createHead->callback((Fl_Callback*)addHead);
		

		headWin->end();
		headWin->set_non_modal();
	}

	void showH(){ headWin->show(); }
	void hideH(){ headWin->hide(); }
	char* nameHeadName(){ return (char*)nameHead->value(); }
	int size(){ return head.size(); }

	char* nameHeadVec(int i){ return head[i].get_nameH(); }


	void get_head(Head h){
		head.push_back(h);
	}



private:
	Fl_Button* createHead;
	vector<Head> head;
};

class robotTorso{
public:
	robotTorso(){


		torsoWin = new Fl_Window(300, 400, "Torso Info");

		nameTorso = new Fl_Input(50, 10, 250, 20, "Name:");


		createTorso = new Fl_Button(120, 320, 120, 30, "Create");
		createTorso->callback((Fl_Callback*)addTorso);


		torsoWin->end();
		torsoWin->set_non_modal();
	}

	void showT(){ torsoWin->show(); }
	void hideT(){ torsoWin->hide(); }
	char* nameTorsoName(){ return (char*)nameTorso->value(); }
	int size(){ return torso.size(); }

	char* nameTorsoVec(int i){ return torso[i].get_nameT(); }


	void get_torso(Torso t){
		torso.push_back(t);
	}



private:
	Fl_Button* createTorso;
	vector<Torso> torso;
};

class robotArm{
public:
	robotArm(){


		armWin = new Fl_Window(300, 400, "Arm Info");

		nameArm = new Fl_Input(50, 10, 250, 20, "Name:");


		createArm = new Fl_Button(120, 320, 120, 30, "Create");
		createArm->callback((Fl_Callback*)addArm);


		armWin->end();
		armWin->set_non_modal();
	}

	void showA(){ armWin->show(); }
	void hideA(){ armWin->hide(); }
	char* nameArmName(){ return (char*)nameArm->value(); }
	int size(){ return arm.size(); }

	char* nameArmVec(int i){ return arm[i].get_nameA(); }


	void get_arm(Arm a){
		arm.push_back(a);
	}



private:
	Fl_Button* createArm;
	vector<Arm> arm;
};

class robotLocomotor{
public:
	robotLocomotor(){


		locomotorWin = new Fl_Window(300, 400, "Locomotor Info");

		nameLocomotor = new Fl_Input(50, 10, 250, 20, "Name:");


		createLocomotor = new Fl_Button(120, 320, 120, 30, "Create");
		createLocomotor->callback((Fl_Callback*)addLocomotor);


		locomotorWin->end();
		locomotorWin->set_non_modal();
	}

	void showL(){ locomotorWin->show(); }
	void hideL(){ locomotorWin->hide(); }
	char* nameLocomotorName(){ return (char*)nameLocomotor->value(); }
	int size(){ return locomotor.size(); }

	char* nameLocomotorVec(int i){ return locomotor[i].get_nameL(); }


	void get_locomotor(Locomotor l){
		locomotor.push_back(l);
	}



private:
	Fl_Button* createLocomotor;
	vector<Locomotor> locomotor;
};

class robotBattery{
public:
	robotBattery(){


		batteryWin = new Fl_Window(300, 400, "Battery Info");

		nameBattery = new Fl_Input(50, 10, 250, 20, "Name:");


		createBattery = new Fl_Button(120, 320, 120, 30, "Create");
		createBattery->callback((Fl_Callback*)addBattery);


		batteryWin->end();
		batteryWin->set_non_modal();
	}

	void showB(){ batteryWin->show(); }
	void hideB(){ batteryWin->hide(); }
	char* nameBatteryName(){ return (char*)nameBattery->value(); }
	int size(){ return battery.size(); }

	char* nameBatteryVec(int i){ return battery[i].get_nameB(); }


	void get_battery(Battery b){
		battery.push_back(b);
	}



private:
	Fl_Button* createBattery;
	vector<Battery> battery;
};


/*----------------------------------------------------------------------------------------------/
----------------------------------------------CALLBACKS------------------------------------------/
-------------------------------------------------------------------------------------------------*/

void listingOrders(Fl_Widget* w, void* p){

	strcpy(printOrders, "");

	
	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Orders");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < lOrd->size(); i++){
		strcat(printOrders, "Sales Associate: ");
		strcat(printOrders, lOrd->nameSAOrdersVec(i));
		strcat(printOrders, "\nEmployee Number: ");
		strcat(printOrders, lOrd->nameSAenOrdersVec(i));
		strcat(printOrders, "\nCustomer: ");
		strcat(printOrders, lOrd->nameCustOrdersVec(i));
		strcat(printOrders, "\nRobot Model: ");
		strcat(printOrders, lOrd->nameRMOrdersVec(i));
		strcat(printOrders, "\nHead Part: ");
		strcat(printOrders, lOrd->nameHOrdersVec(i));
		strcat(printOrders, "\nTorso Part: ");
		strcat(printOrders, lOrd->nameTOrdersVec(i));
		strcat(printOrders, "\nArm Part: ");
		strcat(printOrders, lOrd->nameAOrdersVec(i));
		strcat(printOrders, "\nLocomotor Part: ");
		strcat(printOrders, lOrd->nameLOrdersVec(i));
		strcat(printOrders, "\nBattery :");
		strcat(printOrders, lOrd->nameBOrdersVec(i));
		strcat(printOrders, "\nTotal Weight: ");

		string con = to_string(lOrd->nameWOrdersVec(i));
		char* con2 = new char[con.length() + 1];
		strcpy(con2, con.c_str());

		strcat(printOrders, con2);
		strcat(printOrders, "\nTotal Cost :$");

		con = to_string(lOrd->nameCOrdersVec(i));
		con2 = new char[con.length() + 1];
		strcpy(con2, con.c_str());

		strcat(printOrders, con2);
		strcat(printOrders, "\n\n");
	}
	buff->text(printOrders);

}

void finalStep(Fl_Widget* w, void* p){
	Fl_Hold_Browser *brCata4 = (Fl_Hold_Browser*)p;

	brIndexC = brCata4->value() - 1; //Index for Models in the vector

	char* resSA = new char[1000];
	strcpy(resSA, "");
	strcat(resSA, lSA->nameSalesAsVec(brIndexSA));

	char* resSAen = new char[1000];
	strcpy(resSAen, "");
	strcat(resSAen, lSA->empnumSalesAsVec(brIndexSA));

	char* resCust = new char[1000];
	strcpy(resCust, "");
	strcat(resCust, lC->nameCustomerVec(brIndexC));

	char* resRM = new char[1000];
	strcpy(resRM, "");
	strcat(resRM, sRM->nameRMVec(brIndexRM));

	char* resH = new char[1000];
	strcpy(resH, "");
	strcat(resH, sRM->nameHeadVecRM(brIndexRM));

	char* resT = new char[1000];
	strcpy(resT, "");
	strcat(resT, sRM->nameTorsoVecRM(brIndexRM));

	char* resA = new char[1000];
	strcpy(resA, "");
	strcat(resA, sRM->nameArmVecRM(brIndexRM));

	char* resL = new char[1000];
	strcpy(resL, "");
	strcat(resL, sRM->nameLocomotorVecRM(brIndexRM));

	char* resB = new char[1000];
	strcpy(resB, "");
	strcat(resB, sRM->nameBatteryVecRM(brIndexRM));

	double resW = sRM->totalWeightVecRM(brIndexRM);
	double resC = sRM->totalCostVecRM(brIndexRM);

	Orders insertOrd(resSA, resSAen, resCust, resRM, resH, resT, resA, resL, resB, resW, resC);
	lOrd->get_orders(insertOrd);

	cWin->hide();
	pWin->hide();
	winCata->hide();
}

void verifyCust(Fl_Widget* w, void* p){
	Fl_Hold_Browser *brCata3 = (Fl_Hold_Browser*)p;

	brIndexSA = brCata3->value() - 1; //Index for Models in the vector

	cWin = new Fl_Window(600, 600);
	cWin->begin();
	brCust = new Fl_Hold_Browser(50, 50, 100, 500, "Customer");

	int i;
	for (i = 0; i < lC->size(); i++){
		brCust->add(lC->nameCustomerVec(i));
	}
	if (lC->size() > 0){
		brCust->select(1);
		Fl_Button *nextButton = new Fl_Button(350, 500, 100, 50, "Purchase");

		nextButton->callback((Fl_Callback*)finalStep, (void*)brCust);
	}

	cWin->end();
	cWin->show();

}

void mkPurchase(Fl_Widget* w, void* p){
	Fl_Hold_Browser *brCata2 = (Fl_Hold_Browser*)p;

	brIndexRM = brCata2->value() - 1; //Index for Models in the vector

	pWin = new Fl_Window(600, 600);
	pWin->begin();
	brSA = new Fl_Hold_Browser(50, 50, 100, 500, "Sales Associate");

	int i;
	for (i = 0; i < lSA->size(); i++){
		brSA->add(lSA->nameSalesAsVec(i));
	}
	if (lSA->size() > 0){
		brSA->select(1);
		Fl_Button *nextButton = new Fl_Button(350, 500, 100, 50, "Choose Customer");
		
		nextButton->callback((Fl_Callback*)verifyCust, (void*)brSA);
	}

	pWin->end();
	pWin->show();

}

void viewcb(Fl_Widget* w, void* p){
	Fl_Hold_Browser *brCata2 = (Fl_Hold_Browser*)p;

	strcpy(printRM, "");

	int i = brCata2->value()-1;
	Fl_Window *win = new Fl_Window(1050, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 140, 480 - 140, "Checkout Summary");

	picimage = new Fl_JPEG_Image("full_orange_can.jpg");
	picbox = new Fl_Box(600, 20, picimage->w(), picimage->h()); //Size best at 250 x 250 pixels
	

	

	picbox->image(picimage);
	picbox->redraw();
	disp->buffer(buff);
	win->show();

	strcat(printRM, "Model Name: ");
	strcat(printRM, sRM->nameRMVec(i));
	strcat(printRM, "\nHead Name: ");
	strcat(printRM, sRM->nameHeadVecRM(i));
	strcat(printRM, "\nTorso Name: ");
	strcat(printRM, sRM->nameTorsoVecRM(i));
	strcat(printRM, "\nArm Name: ");
	strcat(printRM, sRM->nameArmVecRM(i));
	strcat(printRM, "\nLocomotor Name: ");
	strcat(printRM, sRM->nameLocomotorVecRM(i));
	strcat(printRM, "\nBattery Name: ");
	strcat(printRM, sRM->nameBatteryVecRM(i));
	strcat(printRM, "\nTotal Weight: ");

	string con = to_string(sRM->totalWeightVecRM(i));
	char* con2 = new char[con.length() + 1];
	strcpy(con2, con.c_str());

	strcat(printRM, con2); //Weight
	strcat(printRM, "\nTotal Cost: $");

	con = to_string(sRM->totalCostVecRM(i));
	con2 = new char[con.length() + 1];
	strcpy(con2, con.c_str());

	strcat(printRM, con2); //Cost

	strcat(printRM, "\n\n");
	
	buff->text(printRM);

	
}

void  cata(Fl_Widget* w, void* p) {
	winCata = new Fl_Window(600, 600, "Catalog");

	winCata->begin();
	brCata = new Fl_Hold_Browser(50, 50, 100, 500, "Robot Models");

	int i;
	for (i = 0; i < sRM->size(); i++){
		brCata->add(sRM->nameRMVec(i));
	}
	if (sRM->size() > 0){
		brCata->select(1);
		Fl_Button *viewButton = new Fl_Button(450, 500, 100, 50, "View");
		Fl_Button *buyButton = new Fl_Button(350, 500, 100, 50, "Purchase");

		viewButton->callback((Fl_Callback*)viewcb, (void*)brCata);
		buyButton->callback((Fl_Callback*)mkPurchase, (void*)brCata);
	}
	
	winCata->end();
	winCata->show();
}

void addSalesAs(Fl_Widget* w, void* p){
	strcpy(printSalesAs, "");

	char* resSA = new char[1000];
	strcpy(resSA, "");
	strcat(resSA, nameSalesAs->value());

	char* resSAen = new char[1000];
	strcpy(resSAen, "");
	strcat(resSAen, empnumSalesAs->value());

	SalesAs insertSA(resSA, resSAen);
	lSA->get_SA(insertSA);


	/*
	Fl_Window *win = new Fl_Window(850, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Added Sales Associate");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < lSA->size(); i++){
		strcat(printSalesAs, lSA->nameSalesAsVec(i));
		strcat(printSalesAs, "\n");
		strcat(printSalesAs, lSA->empnumSalesAsVec(i));
		strcat(printSalesAs, "\n\n");
	}
	buff->text(printSalesAs);
	*/
	nameSalesAs->value("");
	empnumSalesAs->value("");
	lSA->hideSA();
}

void addCustomer(Fl_Widget* w, void* p){

	char* resC = new char[1000];
	strcpy(resC, "");
	strcat(resC, nameCustomer->value());

	Customer insertCustomer(resC);
	lC->get_customer(insertCustomer);


	/*
	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Show Customer");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < lC->size(); i++){
		strcat(printCustomer, lC->nameCustomerVec(i));
		strcat(printCustomer, "\n");
	}
	buff->text(printCustomer);
	*/
	nameCustomer->value("");
	lC->hideC();
}

void addRM(Fl_Widget* w, void* p){
	strcpy(printRM, "");

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

	double resW = atof(totalWeightRM->value());
	double resC = atof(totalCostRM->value());


	RobotModel insertRM(resRM, resH, resT, resA, resL, resB, resW, resC);
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


	/*
	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Checkout Summary");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < sRM->size(); i++){
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
		strcat(printRM, "\n");

		string con = to_string(sRM->totalWeightVecRM(i));
		char* con2 = new char[con.length() + 1];
		strcpy(con2, con.c_str());

		strcat(printRM, con2); //Weight
		strcat(printRM, "\n");

		con = to_string(sRM->totalCostVecRM(i));
		con2 = new char[con.length() + 1];
		strcpy(con2, con.c_str());

		strcat(printRM, con2); //Cost
		strcat(printRM, "\n\n");
	}
	buff->text(printRM);
	*/
	nameRM->value("");
	nameHeadRM->value("");
	nameTorsoRM->value("");
	nameArmRM->value("");
	nameLocomotorRM->value("");
	nameBatteryRM->value("");
	totalWeightRM->value("");
	totalCostRM->value("");
	sRM->hideRM();
}

void addHead(Fl_Widget* w, void* p){
	
	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameHead->value());

	Head insertHead(res);
	rH->get_head(insertHead);
	
	

	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Heads");  
	disp->buffer(buff);    
	win->show();            
	int i;
	for (i = 0; i < rH->size(); i++){
		strcat(printHead, rH->nameHeadVec(i));
		strcat(printHead, "\n");
	}
	buff->text(printHead);

	nameHead->value("");
	rH->hideH();
}

void addTorso(Fl_Widget* w, void* p){

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameTorso->value());

	Torso insertTorso(res);
	rT->get_torso(insertTorso);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Torsos");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rT->size(); i++){
		strcat(printTorso, rT->nameTorsoVec(i));
		strcat(printTorso, "\n");
	}
	buff->text(printTorso);

	nameTorso->value("");
	rT->hideT();
}

void addArm(Fl_Widget* w, void* p){

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameArm->value());

	Arm insertArm(res);
	rA->get_arm(insertArm);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Arms");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rA->size(); i++){
		strcat(printArm, rA->nameArmVec(i));
		strcat(printArm, "\n");
	}
	buff->text(printArm);

	nameArm->value("");
	rA->hideA();
}

void addLocomotor(Fl_Widget* w, void* p){

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameLocomotor->value());

	Locomotor insertLocomotor(res);
	rL->get_locomotor(insertLocomotor);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Locomotors");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rL->size(); i++){
		strcat(printLocomotor, rL->nameLocomotorVec(i));
		strcat(printLocomotor, "\n");
	}
	buff->text(printLocomotor);

	nameLocomotor->value("");
	rL->hideL();
}

void addBattery(Fl_Widget* w, void* p){

	char* res = new char[1000];
	strcpy(res, "");
	strcat(res, nameBattery->value());

	Battery insertBattery(res);
	rB->get_battery(insertBattery);



	Fl_Window *win = new Fl_Window(650, 480);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650 - 40, 480 - 40, "Batteries");
	disp->buffer(buff);
	win->show();
	int i;
	for (i = 0; i < rB->size(); i++){
		strcat(printBattery, rB->nameBatteryVec(i));
		strcat(printBattery, "\n");
	}
	buff->text(printBattery);

	nameBattery->value("");
	rB->hideB();
}

void showSAs(Fl_Widget* w, void* p){
	strcpy(printSalesAs, "");
	lSA->showSA();
}

void showCustomer(Fl_Widget* w, void* p){
	strcpy(printCustomer, "");
	lC->showC();
}

void showRM(Fl_Widget* w, void* p){
	strcpy(printRM, "");
	sRM->showRM();
}

void showHead(Fl_Widget* w, void* p){
	strcpy(printHead, "");
	rH->showH();
}

void showTorso(Fl_Widget* w, void* p){
	strcpy(printTorso, "");
	rT->showT();
}

void showArm(Fl_Widget* w, void* p){
	strcpy(printArm, "");
	rA->showA();
}

void showLocomotor(Fl_Widget* w, void* p){
	strcpy(printLocomotor, "");
	rL->showL();
}

void showBattery(Fl_Widget* w, void* p){
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

int main(){
	lOrd = new listOrders;
	lSA = new listSalesAs;
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
	Fl_Button createH(250, 50, 150, 50, "Add Sales Associate");
	Fl_Button createRM(250, 150, 150, 50, "Create Model");
	Fl_Button createC(50, 250, 150, 50, "Add Customer");
	Fl_Button createO(250, 250, 150, 50, "View Orders");
	//createRM.callback(createHead_cb);
	createRP.callback(createRP_cb);
	createD.callback(cata);
	createH.callback(showSAs);
	createRM.callback(showRM);
	createC.callback(showCustomer);
	createO.callback(listingOrders);
	win.end();
	win.show();
	return (Fl::run());
}
