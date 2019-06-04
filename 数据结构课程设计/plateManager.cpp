#include "plateManager.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

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
		next->next->before = next;
		next->before = this->plates;
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
			if (next->next) {
				next->next->before = next;
			}
			next->before = this->plates;
		}
	}
	else {
		cout << "输入错误" << endl;
		this->insertPlate();
	}
}

void plateManager::showPaltes() {
	plate* p = this->plates->next;
	int count = 1;
	while (p) {
		cout << count << ":\t" << p->number << "\t";
		p = p->next;
		count++;
	}
	cout << endl;
}

void plateManager::sortOnce(int bit) {
	plate* plates = this->plates;
	plate* result = new plate();
	plate* endPoint = result;
	if ((int)plates->next->number[bit] <= 57) {
		for (int i = 0; i < 10; i++) {
			plate* temp = plates->next;
			while (temp) {
				if (temp->number[bit] - 48 == i) {
					endPoint->next = temp;
					endPoint = temp;
					temp->before->next = temp->next;
					if (temp->next) {
						temp->next->before = temp->before;
					}
					temp = temp->next;
					endPoint->next = NULL;
					continue;
				}
				temp = temp->next;
			}
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			plate* temp = plates->next;
			while (temp) {
				if (temp->number[bit] - 65 == i) {
					endPoint->next = temp;
					endPoint = temp;
					temp->before->next = temp->next;
					if (temp->next) {
						temp->next->before = temp->before;
					}
					temp = temp->next;
					endPoint->next = NULL;
					continue;
				}
				temp = temp->next;
			}
		}
	}
	plate* temp = result;
	while (temp) {
		if (temp->next) {
			temp->next->before = temp;
		}
		temp = temp->next;
	}
	this->plates = result;
}

void plateManager::sort() {
	for (int i = 7; i >= 0; i--) {
		this->sortOnce(i);
	}
}