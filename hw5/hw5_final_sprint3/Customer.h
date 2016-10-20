#ifndef __CUSTOMER_H
#define __CUSTOMER_H 201609

#include "RobotModels.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
	public:
		Customer(double p_bill,
			string p_customerName,
			int p_modelNumber):
			
			bill(p_bill),
			customerName(p_customerName),
			modelNumber(p_modelNumber),
			robotModels(RobotModels()) {}

		Customer():
			bill(0),
			customerNumber(0),
			customerName("no one"),
			modelNumber(0){}

		string get_customer_name(int index);
		int get_modelNumber(int index);

	private:
		FullModel fullModel;
		RobotModels robotModels;
		int modelNumber;
		double bill;
		int customerNumber;
		string customerName;
};

class Order {
	public:
		void printCustomerName(int index);
		void displayMenu();
		void catalog(int modelNumber);
		void makeOrder(int modelNumber);
		void addCustomerInfo(Customer c);
		//void printOrder(int index);

	private:
		FullModel fullModel;
		Component component;
		vector<Customer> customer;
		vector<RobotModels> robotModels;
		vector<RobotParts> robotParts;

};

#endif