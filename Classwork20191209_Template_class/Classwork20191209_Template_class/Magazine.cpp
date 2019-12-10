#include "Magazine.h"
#include <iostream>
#include <string>

using namespace std;

int Magazine::counterMagazine = 0;
Magazine::Magazine()
{

}

Magazine::Magazine(string name, int price, bool type)
{
	this->className = "Magazine";
	this->name = name;
	this->price = price;
	this->type = type;
	counterMagazine++;
}

void Magazine::ShowInfo()
{
	cout << this->name << "\tPrice: " << this->price << endl;
}

int Magazine::GetCounterMagazine()
{
	return counterMagazine;
}

string Magazine::GetClassName()
{
	return this->className;
}

int Magazine::GetPrice()
{
	return this->price;
}


Magazine::~Magazine()
{
}
