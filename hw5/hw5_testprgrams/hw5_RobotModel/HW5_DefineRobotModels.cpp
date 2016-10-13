#include "RobotParts.h"
#include "RobotModels.h"

using namespace std;


int main()
{
	FullModel fullModel;
	vector<RobotModels> robotModels;
	vector<RobotParts> robotParts;
	Component component;

	int select = 1, count = 0;

	while (select != -1) {
		
		cout << "Select?" << endl;
		cin >> select;
		if (select != -1) {
			fullModel.createModel();
			fullModel.print(count);
			fullModel.printRM(count);
			count++;
		}
	}

    //return 0;
}


