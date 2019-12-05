#pragma once
#include "Shop.h"
using namespace std;

class Magazine
{
	friend Shop;
	string nameMagazine;
	string publHouse;
	int pages;
	short int yearPablic;
	double price;
	int numberMagazine;

public:
	Magazine();
	Magazine(string nameMagazine, string publHouse, int pages, short int yearPablic, double price);
	void ShowInfoMagazine();
	~Magazine();
};

