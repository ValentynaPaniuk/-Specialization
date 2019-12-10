#include "Disk.h"

int Disk::counterDisk = 0;

Disk::Disk()
{
}

Disk::Disk(string name, string singer, int number, int price, bool type)
{
	this->className = "Disk";
	this->name = name;
	this->singer = singer;
	this->number = number;
	this->price = price;
	this->type = type;
	counterDisk++;
	cout << "Overload constructor Disk" << this << endl;
}


void Disk::Showinfo()
{
	cout << name << "\tSinger: " << singer << "\tNumber: " << number << "\tPrice: " << price << endl;
}

int Disk::GetCounterDisk()
{
	return counterDisk;
}

string Disk::GetClassName()
{
	return this->className;
}

int Disk::GetPrice()
{
	return this->price;
}

Disk::~Disk()
{
}
