#pragma once
#include <iostream>
#include "Shop.h"
class Shop;
using namespace std;
class Book
{
	friend Shop;
	string nameBook;
	string author;
	int pages;
	short yearPablic;
	double price;
	static int counterBook;
	int numberBook;
	


public:
	Book();
	Book(string nameBook, string author, int pages, short yearPablic, double price);
	void ShowInfoBook();
	int GetNumberBook();
	static int GetCounterBook();
	~Book();
};

