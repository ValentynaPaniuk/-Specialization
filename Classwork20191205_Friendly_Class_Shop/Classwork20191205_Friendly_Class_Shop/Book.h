#pragma once
#include <iostream>
#include "Shop.h"

using namespace std;
class Book
{
	friend Shop;
	string nameBook;
	string author;
	int pages;
	short yearPablic;
	double price;
	int numberBook;


public:
	Book();
	Book(string nameBook, string author, int pages, short yearPablic, double price);
	void ShowInfoBook();
	~Book();
};

