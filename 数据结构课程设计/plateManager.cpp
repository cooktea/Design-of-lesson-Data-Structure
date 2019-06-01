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
	cout << "��ѡ���������ݵķ�ʽ��1���ֶ�����/2��������ɣ���";
	int type;
	cin >> type;
	if (type == 1) {
		plate* next = new plate();
		next->setNumber(1);
		next->next = this->plates->next;
		this->plates->next = next;
	}
	else if (type == 2) {
		cout << "��������Ҫ����������յ�������";
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
		cout << "�������" << endl;
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