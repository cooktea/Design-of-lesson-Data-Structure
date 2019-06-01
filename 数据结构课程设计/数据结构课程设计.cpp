#include <iostream>
#include <stdlib.h>
#include "plateManager.h"

using namespace std;


int main()
{
	plateManager* manager = new plateManager();
	manager->insertPlate();
	manager->showPaltes();
	//for (int i = 0; i < 100; i++) {
	//	cout << rand() % 100 << endl;
	//}
	return 0;
}
