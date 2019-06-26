#pragma once
#include<stdlib.h>
#include"palte.h"

class plateManager
{
public:
	plateManager();
	~plateManager();
	void insertPlate();
	void showPaltes();
	void sort();
	void sortOnce(int bit);
	void run();
public:
	int plateNumber = 0;
	plate* plates = NULL;
};

