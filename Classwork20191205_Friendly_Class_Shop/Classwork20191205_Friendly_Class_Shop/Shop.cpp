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

void Shop::TheCheapestPriceBook(Book *& books, int counterBook)
{
	cout << "The cheapest book = >>>>>> ";
	double minPrice = 0;
	for (int i = 0; i < counterBook; i++)
	{
		minPrice = books[0].price;
		if (books[i].price < minPrice)
		{
			minPrice = books[i].price;
		}
		
	}
	cout << minPrice << endl;


}

void Shop::TheCheapestPriceMagazine(Magazine *& magazines, int counterMagazine)
{
	cout << "The cheapest magazine = >>>>>> ";
	double minPrice = 0;
	for (int i = 0; i < counterMagazine; i++)
	{
		minPrice = magazines[0].price;
		if (magazines[i].price < minPrice)
		{
			minPrice = magazines[i].price;
		}

	}
	cout << minPrice << endl;

}

void Shop::TheCheapestPriceDisk(AudioDisk *& disks, int counterAudioDisk)
{
	cout << "The cheapest disk = >>>>>> ";
	double minPrice = 0;
	for (int i = 0; i < counterAudioDisk; i++)
	{
		minPrice = disks[0].price;
		if (disks[i].price < minPrice)
		{
			minPrice = disks[i].price;
		}

	}
	cout << minPrice << endl;
}

void Shop::AveragePriceBook(Book *& books, int counterBook)
{
	double sum = 0;
	double avarage = 0;
	for (int i = 0; i < counterBook; i++)
	{
		sum += books[i].price;
		avarage = sum / counterBook;
	}
	cout << "Avarage price of book: " << avarage << endl;
}

void Shop::AveragePriceMagazine(Magazine *& magazines, int counterMagazine)
{
	double sum = 0;
	double avarage = 0;
	for (int i = 0; i < counterMagazine; i++)
	{
		sum += magazines[i].price;
		avarage = sum / counterMagazine;
	}
	cout << "Avarage price of magazine: " << avarage << endl;
}

void Shop::AveragePriceDisk(AudioDisk *& disks, int counterAudioDisk)
{

	double sum = 0;
	double avarage = 0;
	for (int i = 0; i < counterAudioDisk; i++)
	{
		sum += disks[i].price;
		avarage = sum / counterAudioDisk;
	}
	cout << "Avarage price of disk: " << avarage << endl;
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

