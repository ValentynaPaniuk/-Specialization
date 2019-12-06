#include "Book.h"

int Book:: counterBook = 0;

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
	counterBook++;
	this->numberBook = counterBook;
	
}

void Book::ShowInfoBook()
{
	cout <<GetNumberBook()<<" "<<nameBook << " Author: " << author << "\nPages: " << pages << "\nYear of pablic: " << yearPablic << "\nPrice: " << price << endl;
}




int Book::GetNumberBook()
{
	return numberBook;
}


int Book::GetCounterBook()
{
	return counterBook;
}


Book::~Book()
{
} 

