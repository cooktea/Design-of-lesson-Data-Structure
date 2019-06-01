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
	type:输入车牌信息的方式
		1：手动输入
		2：随机生成
*/
void plate::setNumber(int type) {
	/*
		手动输入车牌号
	*/
	if (type == 1) {
		/*
			输入车牌号
		*/
		cout << "请输入车牌号（形如1AB12345）：";
		char number[9];
		cin >> number;
		if (number[8] != 0) {
			cout << "输入有误" << endl;
			return;
		}
		/*
			验证车牌号是否满足格式
		*/
		char basic[9] = "9ZZ99999";
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 2) {
				if (!(0 <= basic[i]-number[i] && 25>= basic[i]-number[i]))
				{
					cout << "输入有误" << endl;
					return;
				}
			}
			else
			{
				if (!(0 <= basic[i] - number[i] && 9 >= basic[i] - number[i])) {
					cout << "输入有误" << endl;
					return;
				}
			}
		}
		/*
			设置车牌号
		*/
		for (int i = 0; i < 9; i++) {
			this->number[i] = number[i];
		}
	}
	/*
		随机输入车牌号
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