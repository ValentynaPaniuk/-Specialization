#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"



using namespace std;

Shop::Shop()
{
}

Shop::Shop(string nameShop, string addressShop, double receipts)
{
	this->nameShop = nameShop;
	this->addressShop = addressShop;
	this->receipts = receipts;
}

void Shop::ShovInfoShop()
{
	cout << "*******************************************************" << endl;
	cout << "\tName shop: " << nameShop << "\tAddress: " << addressShop << "\tReceipt: " << receipts << endl;
	cout << "*******************************************************" << endl;
}

void Shop::AllMagazine(Magazine *& magazines, int counterMagazine)
{
	cout << "               ****   MAGAZINES: ****  " << endl;
	for (int i = 0; i < counterMagazine; i++)
	{
		magazines[i].ShowInfoMagazine();
	}
	cout << endl;
}

void Shop::AllDisk(AudioDisk *& disks, int counterAudioDisk)
{
	cout << "              ****   DISKS: ****  " << endl;
	for (int i = 0; i < counterAudioDisk; i++)
	{
		disks[i].ShowInfoDisk();
	}
	cout << endl;
}

void Shop::MostExpensivePriceBook(Book *& books, int counterBook)
{
	cout << "Most expensive book = >>>>>> ";
	double maxPrice = 0; 
	for (int i = 0; i < counterBook; i++)
	{
		if (maxPrice < books[i].price)
		{
			maxPrice = books[i].price;
		}
	}
	cout << maxPrice << endl;
}

void Shop::MostExpensivePriceMagazine(Magazine *& magazines, int counterMagazine)
{
	cout << "Most expensive Magazine = >>>>>> ";
	double maxPrice = 0;
	for (int i = 0; i < counterMagazine; i++)
	{
		if (maxPrice < magazines[i].price)
		{
			maxPrice = magazines[i].price;
		}
	}
	cout << maxPrice << endl;
}

void Shop::MostExpensivePriceDisk(AudioDisk *& disks, int counterAudioDisk)
{
	cout << "Most expensive Disk = >>>>>> ";
	double maxPrice = 0;
	for (int i = 0; i < counterAudioDisk; i++)
	{
		if (maxPrice < disks[i].price)
		{
			maxPrice = disks[i].price;
		}
	}
	cout << maxPrice << endl;
}

void Shop::AllBooks(Book *& books, int counterBook)
{
	cout << "              ****   BOOKS: ****  " << endl;
	for (int i = 0; i < counterBook; i++)
	{
		books[i].ShowInfoBook();
	}
	cout << endl;
}





Shop::~Shop()
{
}

