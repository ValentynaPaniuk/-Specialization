#include "Disk.h"

int Disk::counterDisk = 0;

Disk::Disk()
{
	this->className = "Disk";
	counterDisk++;
	cout << this->className << " " << counterDisk << " : " << endl;
	cout << "Enter name disk: ";		cin >> this->name;
	cout << "Enter singer: ";	cin >> this->singer;
	cout << "Enter number: ";	cin >> this->number;
	cout << "Enter price: ";	cin >> this->price;
	cout << endl;

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


void Disk::ShowInfo()
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
