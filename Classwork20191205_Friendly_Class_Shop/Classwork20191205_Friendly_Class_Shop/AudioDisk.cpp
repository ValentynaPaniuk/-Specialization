#include "AudioDisk.h"

int AudioDisk::counterAudioDisk = 0;

AudioDisk::AudioDisk()
{
}

AudioDisk::AudioDisk(string nameDisk, string author, short yearPablic, double price)
{
	this->nameDisk = nameDisk;
	this->author = author;
	this->yearPablic = yearPablic;
	this->price = price;
	counterAudioDisk++;
	numberDisk = counterAudioDisk;
}

void AudioDisk::ShowInfoDisk()
{
	cout << nameDisk << " Author: " << author << " Year of pablication: " << yearPablic << "\nPrice: " << price << endl;
}

int AudioDisk::GetNumberDisk()
{
	return numberDisk;
}

int AudioDisk::GetCounterDisk()
{
	return counterAudioDisk;
}


AudioDisk::~AudioDisk()
{
}
