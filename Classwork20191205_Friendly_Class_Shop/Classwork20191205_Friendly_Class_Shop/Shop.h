#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"



using namespace std;
class Shop
{
	static int counterBook;
	static int counterMagazine;
	static int counterAudioDisk;
	static int choice;
	
	string nameShop;
	string addressShop;
	double receipts;

	
public:
	Shop();
	Shop(string nameShop, string addressShop, double receipts);

	void ShovInfoShop();



	~Shop();
};

