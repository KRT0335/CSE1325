#include "Customer.h"




void Order::addCustomerInfo(Customer c) {
	customer.push_back(c);
}

int Customer::get_modelNumber(int index) {
	return modelNumber;
}



string Customer::get_customer_name(int index) {
	return customerName;
}

void Order::printCustomerName(int index) {
	cout << customer[index].get_customer_name(index);
}

/*
void Order::printOrder(int modelNumber) {
	int rmNumber;

	if (modelNumber > 0) {
		cout << "List of Orders: " << endl;
		for (rmNumber = 0; rmNumber < modelNumber; rmNumber++) {
			cout << '[' << std::to_string(rmNumber + 1) << "] ";
			fullModel.printModelName(rmNumber);
			cout << ' ';
			printCustomerName(rmNumber);
			cout << endl<<endl;
		}
	}
	else {
		cout << "No Orders are in." << endl;
	}
}
*/
void Order::catalog(int modelNumber) {
	vector<RobotModels> robotModels;
	int select = 0;
	int rmNumber;
	string rmName = "test";

	if (modelNumber > 0) {
		for (rmNumber = 0; rmNumber < modelNumber; rmNumber++) {
			cout << '[' << std::to_string(rmNumber + 1) << "] ";
			fullModel.printModelName(rmNumber);
			cout << endl;
			//fullModel.print(rmNumber);
		}

		cout << "[-1] Leave Catalog" << endl;

		while (select != -1) {
			cout << "Which Model to view?" << endl;

			cin >> select;
			fullModel.checkInputInt(select);
			cin.ignore();

			if (select != -1) {
				if (select > rmNumber + 1 || select < 1) {
					cout << "Invalid Input" << endl;
				}
				else {
					cout << endl;
					fullModel.print(select - 1);
				}
			}

		}

	}
	else {
		cout << "There are no Models in the catalog." << endl
			<< "The catalog is made up of Models custom made." << endl
			<< "Create a Model to start up the catalog and knowing you are FIRST." << endl;
	}
}

void Order::makeOrder(int modelNumber) {
	int modelCount = modelNumber;
	string customerName;
	int cataBuy = 0;
	double price; //$1.50 for every weight

	cout << "Name?" << endl;
	getline(cin, customerName);

	if (cataBuy == 1) {
		price = (1.5*(robotModels[modelNumber].get_weight(modelNumber)));
		Customer insertC(price, customerName, modelNumber);
		addCustomerInfo(insertC);
	}
	else{
		fullModel.createModel(modelNumber);
		if (modelCount != modelNumber) {
			price = (1.5*(robotModels[modelNumber].get_weight(modelNumber)));
			Customer insertC(price, customerName, modelNumber);
			addCustomerInfo(insertC);
		}
	}
	modelNumber = modelCount;
	//return modelNumber;
}


void Order::displayMenu() {
	int select = 0, countModel = 0, countCus = 0;
	int modelNumber = 0, cataBuy = 0;
	int modelCount = 0;
	string customerName;
	double price = 0; //$1.50 for every weight

	while (select != -1) {

		cout << "[1] Order a Robot Model" << endl
			<< "[2] Browse Catalog" << endl
			//<< "[3] Print All Orders" << endl //WIP
			<< "[-1] End Program" << endl
			<< "Select: " << endl;

		cin >> select;
		fullModel.checkInputInt(select);
		cin.ignore();

		switch (select) {
		case 1:
			makeOrder(countModel);
			countModel++;
			break;
		case 2:
			catalog(countModel);
			break;
		//case 3:
			//printOrder(countModel);
			//break;
		case -1:
			break;
		default:
			cout << "Invalid Input" << endl;
			select = 0;
		}
	}


}