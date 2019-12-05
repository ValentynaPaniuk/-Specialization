#include "AudioDisk.h"



AudioDisk::AudioDisk()
{
}

AudioDisk::AudioDisk(string nameDisk, string author, short yearPablic, double price)
{
	this->nameDisk = nameDisk;
	this->author = author;
	this->yearPablic = yearPablic;
	this->price = price;
}

void AudioDisk::ShowInfoDisk()
{
	cout << nameDisk << " Author: " << author << " Year of pablication: " << yearPablic << "\nPrice: " << price << endl;
}


AudioDisk::~AudioDisk()
{
}
