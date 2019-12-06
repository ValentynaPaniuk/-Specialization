#include "Magazine.h"


int Magazine ::counterMagazine = 0;

Magazine::Magazine()
{
}

Magazine::Magazine(string nameMagazine, string publHouse, int pages, short int yearPablic, double price)
{
	this->nameMagazine = nameMagazine;
	this->publHouse = publHouse;
	this->pages = pages;
	this->yearPablic = yearPablic;
	this->price = price;
	counterMagazine++;
	numberMagazine = counterMagazine;
}

void Magazine::ShowInfoMagazine()
{
	cout <<GetNumberMagazine()<<" "<<nameMagazine << "\tPublic house: " << publHouse << "\nPages: " << pages << "\nYear of public: " << yearPablic << "\nPrice: " << price << endl;
}

int Magazine::GetNumberMagazine()
{
	return numberMagazine;
}

int Magazine::GetCounterMagazine()
{
	return counterMagazine;
}


Magazine::~Magazine()
{
}
