#include "palte.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

int random(int x) {
	return rand() % x;
}

plate::plate()
{
	this->number = (char*)malloc(sizeof(char) * 9);
	next = NULL;
}

plate::~plate()
{
}

/*
	type:���복����Ϣ�ķ�ʽ
		1���ֶ�����
		2���������
*/
void plate::setNumber(int type) {
	/*
		�ֶ����복�ƺ�
	*/
	if (type == 1) {
		/*
			���복�ƺ�
		*/
		cout << "�����복�ƺţ�����1AB12345����";
		char number[9];
		cin >> number;
		if (number[8] != 0) {
			cout << "��������" << endl;
			return;
		}
		/*
			��֤���ƺ��Ƿ������ʽ
		*/
		char basic[9] = "9ZZ99999";
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 2) {
				if (!(0 <= basic[i]-number[i] && 25>= basic[i]-number[i]))
				{
					cout << "��������" << endl;
					return;
				}
			}
			else
			{
				if (!(0 <= basic[i] - number[i] && 9 >= basic[i] - number[i])) {
					cout << "��������" << endl;
					return;
				}
			}
		}
		/*
			���ó��ƺ�
		*/
		for (int i = 0; i < 9; i++) {
			this->number[i] = number[i];
		}
	}
	/*
		������복�ƺ�
	*/
	else
	{
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 2) {
				do
				{
					this->number[i] = random(91);
				} while (this->number[i]<65);
			}
			else {
				do
				{
					this->number[i] = random(58);
				} while (this->number[i] < 48);
			}
			//cout << this->number[i];
		}
		this->number[8] = 0;
		//cout << endl;
	}
}