#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"

using namespace std;
/*���
���������� ������
� ������� "�������". � ������ ������� ��������� �������� ���������:
������;
�������;
���� �����.
�� ��� ���� ��������� ����������� ���������� �������: ����� (Book), ������ (Megazine), ���� ���� (Audio). �������� �� �������� ������� ����������:
�������� ���������� ��� �� �����, ������� �/��� ���� �����.
�������� ���������� ��� ���������� ������, ������ �/��� ���� ����.
�������� ���������� ��� ���������� ������, ������ �/��� ���� ����.
�������� ������� ���� ����, ������� �/��� ���� �����.
�������� ��� �����, ������� �/��� ���� �����. */
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

	void TheCheapestPriceBook();
	void TheCheapestPriceMagazine();
	void TheCheapestPriceDisk();

	void AveragePriceBook();
	void AveragePriceMagazine();
	void AveragePriceDisk();

	void AllNewBook();
	void AllNewMagazine();
	void AllNewDisk();


	~Shop();
};

