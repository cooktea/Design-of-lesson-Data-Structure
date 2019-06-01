#include "plateManager.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


plateManager::plateManager()
{
	this->plates = new plate();
}

plateManager::~plateManager()
{

}

void plateManager::insertPlate()
{
	cout << "请选择输入数据的方式（1：手动输入/2：随机生成）：";
	int type;
	cin >> type;
	if (type == 1) {
		plate* next = new plate();
		next->setNumber(1);
		next->next = this->plates->next;
		this->plates->next = next;
	}
	else if (type == 2) {
		cout << "请输入你要随机生成牌照的数量：";
		int number;
		cin >> number;
		for (int i = 0; i < number; i++) {
			plate* next = new plate();
			next->setNumber(2);
			next->next = this->plates->next;
			this->plates->next = next;
		}
	}
	else {
		cout << "输入错误" << endl;
		this->insertPlate();
	}
}

void plateManager::showPaltes() {
	plate* p = this->plates->next;
	while (p) {
		cout << p->number << endl;
		p = p->next;
	}
}