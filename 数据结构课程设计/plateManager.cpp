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
	cout << "��ѡ���������ݵķ�ʽ��1���ֶ�����/2��������ɣ���";
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
		cout << "��������Ҫ����������յ�������";
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
		cout << "�������" << endl;
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
	cout << "����ʼ..." << endl;
	for (int i = 7; i >= 0; i--) {
		this->sortOnce(i);
	}
	cout << "�������..." << endl;
}

void plateManager::run() {
	int type = 0;
	do {
		cout << "��ѡ����Ҫ�Ĳ���" << endl;
		cout << "1��¼����Ϣ" << endl;
		cout << "2������" << endl;
		cout << "3�����������Ϣ" << endl;
		//cout << "" << endl;
		cout << "0���˳�ϵͳ" << endl;
		cin >> type;
		switch(type) {
			case 1:
				this->insertPlate();
				break;
			case 2:
				this->sort();
				break;
			case 3:
				this->showPaltes();
				break;
		}
	} while (type != 0);
}