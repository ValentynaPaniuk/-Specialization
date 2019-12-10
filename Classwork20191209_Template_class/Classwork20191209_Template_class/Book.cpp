#include "Book.h"
#include <iostream>

using namespace std;
int Book::counterBook = 0;
Book::Book()
{
	this->className = "Book";
	counterBook++;
	cout << this->className << " " << counterBook << " : " << endl;
	cout << "Enter title: ";			cin >> name;
	cout << "Enter public house: ";		cin >> publHouse;
	cout << "Enter author: ";			cin >> author;
	cout << "Enter price: ";			cin >> price;
	cout<<endl;
}

Book::Book(string name, string publHouse, string author, int price, bool type)
{
	this->className = "Book";
	this->name = name;
	this->publHouse = publHouse;
	this->author = author;
	this->price = price;
	this->type = type;
	counterBook++;
	cout << "Overload constructor Book" << this << endl;
}


void Book::ShowInfo()
{
	cout << this->name << "\tPublishing house: " << this->publHouse << "\tAuthor: " << this->author << "\tPrice: " << this->price << endl;
}

int Book::GetPrice()
{
	return this->price;
}

string Book::GetClassName()
{
	return this->className;
}

int Book::GetCounterBook()
{
	return counterBook;
}

Book::~Book()
{
}
