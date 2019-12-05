#include "Magazine.h"




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
}

void Magazine::ShowInfoMagazine()
{
	cout << nameMagazine << "\tPublic house: " << publHouse << "\nPages: " << pages << "\nYear of public: " << yearPablic << "\nPrice: " << price << endl;
}


Magazine::~Magazine()
{
}
