#include "Book.h"



Book::Book()
{
}

Book::Book(string nameBook, string author, int pages, short yearPablic, double price)
{
	this->nameBook = nameBook;
	this->author = author;
	this->pages = pages;
	this->yearPablic = yearPablic;
	this->price = price;
	
}

void Book::ShowInfoBook()
{
	cout << nameBook << " Author: " << author << "\nPages: " << pages << "\nYear of pablic: " << yearPablic << "\nPrice: " << price << endl;
}


Book::~Book()
{
} 
