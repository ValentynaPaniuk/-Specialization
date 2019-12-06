#pragma once
#include "Shop.h"
using namespace std;
class Shop;

class AudioDisk
{
	friend Shop;
	string nameDisk;
	string author;
	short yearPablic;
	double price;
	static int counterAudioDisk;
	int numberDisk;

public:
	AudioDisk();
	AudioDisk(string nameDisk, string author, short yearPablic, double price);
	void ShowInfoDisk();
	int GetNumberDisk();
	static int GetCounterDisk();

	~AudioDisk();
};

