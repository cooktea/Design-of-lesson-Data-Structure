#include <iostream>
#include "plateManager.h"

using namespace std;

int main()
{
	plateManager Manager;
	Manager.insertPlate();
	cout << "-----------排序前-----------" << endl;
	Manager.showPaltes();
	Manager.sort();
	cout << "-----------排序后-----------" << endl;
	Manager.showPaltes();
	return 0;
}
