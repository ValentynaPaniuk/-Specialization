#pragma once
#include "Shop.h"

using namespace std;
class AudioDisk
{
	friend Shop;
	string nameDisk;
	string author;
	short yearPablic;
	double price;
	int numberDisk;

public:
	AudioDisk();
	AudioDisk(string nameDisk, string author, short yearPablic, double price);
	void ShowInfoDisk();

	~AudioDisk();
};

