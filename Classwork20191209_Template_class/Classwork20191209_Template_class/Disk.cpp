#include "Disk.h"



Disk::Disk()
{
}

Disk::Disk(string name, string singer, int number, double price, bool type)
{
	this->name = name;
	this->singer = singer;
	this->number = number;
	this->price = price;
	this->type = type;
	cout << "Overload constructor Disk" << this << endl;
}


Disk::~Disk()
{
}
