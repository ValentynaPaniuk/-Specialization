#pragma once
#include "Shop.h"
using namespace std;
class Shop;
class Magazine
{
	friend Shop;
	string nameMagazine;
	string publHouse;
	int pages;
	short int yearPablic;
	double price;
	static int counterMagazine;
	int numberMagazine;
	

public:
	Magazine();
	Magazine(string nameMagazine, string publHouse, int pages, short int yearPablic, double price);
	void ShowInfoMagazine();
	int GetNumberMagazine();
	static int GetCounterMagazine();
	~Magazine();
};

