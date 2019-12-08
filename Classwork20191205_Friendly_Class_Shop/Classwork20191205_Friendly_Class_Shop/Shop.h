#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"

using namespace std;
/*ООП
Постановка задачі
Є магазин "Веселка". В даному магазині продається наступна продукція:
книжки;
журнали;
аудіо диски.
Всі три види продукції представлені відповідними класами: Книга (Book), Журнал (Megazine), Аудіо диск (Audio). Програма має виводити наступні результати:
Виводити інформацію про всі книги, журнали і/або аудіо диски.
Виводити інформацію про найдорожчу книжку, журнал і/або аудіо диск.
Виводити інформацію про найдешевшу книжку, журнал і/або аудіо диск.
Виводити середню ціну книг, журналів і/або аудіо дисків.
Виводити нові книги, журнали і/або аудіо диски. */
class AudioDisk;
class Book;
class Magazine;

class Shop
{
	string nameShop;
	string addressShop;
	double receipts;

	
public:
	Shop();
	Shop(string nameShop, string addressShop, double receipts);

	void ShovInfoShop();

	void AllBooks(Book *&books, int counterBook);
	void AllMagazine(Magazine *&magazines, int counterMagazine);
	void AllDisk(AudioDisk *&disks, int counterAudioDisk);
		
	void MostExpensivePriceBook(Book *&books, int counterBook);
	void MostExpensivePriceMagazine(Magazine *&magazines, int counterMagazine);
	void MostExpensivePriceDisk(AudioDisk *&disks, int counterAudioDisk);

	void TheCheapestPriceBook(Book *&books, int counterBook);
	void TheCheapestPriceMagazine(Magazine *&magazines, int counterMagazine);
	void TheCheapestPriceDisk(AudioDisk *&disks, int counterAudioDisk);

	void AveragePriceBook(Book *&books, int counterBook);
	void AveragePriceMagazine(Magazine *&magazines, int counterMagazine);
	void AveragePriceDisk(AudioDisk *&disks, int counterAudioDisk);

	void AllNewBook(Book *&books, int counterBook);
	void AllNewMagazine(Magazine *&magazines, int counterMagazine);
	void AllNewDisk(AudioDisk *&disks, int counterAudioDisk);


	~Shop();
};

