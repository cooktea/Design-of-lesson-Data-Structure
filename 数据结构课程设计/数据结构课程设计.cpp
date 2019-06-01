#include <iostream>
#include <stdlib.h>

using namespace std;

class plate
{
public:
	plate()
	{
		this->next = NULL;
	}

	void insertNextPlate(char *data) {
		plate *next = new plate();
		next->next = this->next;
		this->next = next;
		next->data = data;
	}
	~plate() {
		if (this->next) {
			delete this->next;
		}
	}

public:
	char *data;
	plate* next;
};

int main()
{
	plate* Plate = new plate();
	char data[9] = "ABCD1234";
	Plate->insertNextPlate(data);
	scanf_s("%s", data);
	Plate->insertNextPlate(data);
	while (Plate) {
		cout << Plate->data << endl;
		Plate = Plate->next;
	}
	return 0;
}
