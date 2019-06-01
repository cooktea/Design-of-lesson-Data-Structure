#pragma once

class plate
{
public:
	plate();
	~plate();
	void setNumber(int type);

public:
	char* number;
	plate* next;
};

