#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"



using namespace std;



int Shop::counterBook = 0;
int Shop::counterMagazine = 0;
int Shop::counterAudioDisk = 0;
int Shop::choice = 0;

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
	cout << "Name shop: " << nameShop << "\nAddress: " << addressShop << "\nReceipt: " << receipts << endl;
}


Shop::~Shop()
{
}
