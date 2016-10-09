#include "RobotParts.h"
#include "HW5 CreateRobotParts.h"

using namespace std;


//test robotparts creation
int main()
{
	vector<RobotParts> robotParts;
	Component component;

	Torso torso("Torso");
	Head head("Head");
	Locomotor locomotor("Locomotor");
	Arm arm("Arm");
	Battery battery("Battery");

	RobotParts test(torso,  head,  locomotor,  arm,  battery); //Need to debug

	component.add_part(test);
	//RobotParts.

	cout << component.parts_to_string(0) << endl;
    return 0;
}

