#include "Book.h"
#include <iostream>

using namespace std;

Book::Book()
{
}

Book::Book(string name, string publHouse, string author, double price, bool type)
{
	this->name = name;
	this->publHouse = publHouse;
	this->author = author;
	this->price = price;
	this->type = type;
	cout << "Overload constructor Book" << this << endl;
}


void Book::ShowInfo()
{
	cout << name << "\tPublishing house: " << publHouse << "\tAuthor: " << author << "\tPrice: " << price << endl;
}

Book::~Book()
{
}
